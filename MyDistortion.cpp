#include "MyDistortion.h"
#include "IPlug_include_in_plug_src.h"
#include "IGraphics/Controls/IVectorKnobControl.h"
#include "IGraphics/Controls/IBackgroundControl.h"
#include <cmath>

MyDistortion::MyDistortion(const iplug::InstanceInfo& info)
: PLUG_CLASS_NAME(info, MakeConfig(3, 3))
{
  // Параметры
  GetParam(kDrive)->InitDouble("Drive", 0.5, 0.0, 1.0, 0.01, "%");
  GetParam(kTone)->InitDouble("Tone", 0.5, 0.0, 1.0, 0.01, "%");
  GetParam(kMix)->InitDouble("Mix", 1.0, 0.0, 1.0, 0.01, "%");
  
  mMakePresetFunc = MakePresetFunc;
}

void MyDistortion::OnReset()
{
  mDrive = 0.5f;
  mTone = 0.5f;
  mMix = 1.0f;
}

void MyDistortion::OnIdle()
{
  mDrive = static_cast<float>(GetParam(kDrive)->Value());
  mTone = static_cast<float>(GetParam(kTone)->Value());
  mMix = static_cast<float>(GetParam(kMix)->Value());
}

float MyDistortion::ProcessSample(float sample)
{
  // Drive
  float driven = sample * (1.0f + mDrive * 4.0f);
  
  // Tanh distortion
  float distorted = std::tanh(driven);
  
  // Простой LPF для Tone
  static float filterState = 0.0f;
  float cutoff = 0.1f + mTone * 0.8f;
  float filtered = cutoff * distorted + (1.0f - cutoff) * filterState;
  filterState = filtered;
  
  // Mix
  return sample * (1.0f - mMix) + filtered * mMix;
}

void MyDistortion::ProcessBlock(float** inputs, float** outputs, int nFrames)
{
  const int nChans = NChansConnected();
  
  for (int s = 0; s < nFrames; s++)
  {
    for (int c = 0; c < nChans; c++)
    {
      if (inputs[c] && outputs[c])
      {
        outputs[c][s] = ProcessSample(inputs[c][s]);
      }
      else if (outputs[c])
      {
        outputs[c][s] = 0.f;
      }
    }
  }
}

void MyDistortion::OnParamChange(int paramIdx)
{
  switch (paramIdx)
  {
    case kDrive: mDrive = static_cast<float>(GetParam(kDrive)->Value()); break;
    case kTone: mTone = static_cast<float>(GetParam(kTone)->Value()); break;
    case kMix: mMix = static_cast<float>(GetParam(kMix)->Value()); break;
  }
}

IGraphics* MyDistortion::CreateGraphics()
{
  IGraphics* pGraphics = CreatePlatformGraphics(*this);
  
  // Фон
  pGraphics->LoadBitmap("back.png");
  pGraphics->AttachControl(new IBackgroundControl(pGraphics->LoadBitmap("back.png"), IRECT()));
  
  // Ручки
  IColor knobColor = IColor(255, 200, 50, 50);
  IColor handleColor = IColor(255, 255, 255, 255);
  
  float knobSize = 100.0f;
  float spacing = 150.0f;
  float startX = (pGraphics->Width() - spacing * 2) / 2.0f;
  float y = 200.0f;
  
  pGraphics->AttachControl(new IVectorKnobControl(IRECT(startX, y, startX + knobSize, y + knobSize), kDrive, "Drive", knobColor, handleColor));
  pGraphics->AttachControl(new IVectorKnobControl(IRECT(startX + spacing, y, startX + spacing + knobSize, y + knobSize), kTone, "Tone", knobColor, handleColor));
  pGraphics->AttachControl(new IVectorKnobControl(IRECT(startX + spacing * 2, y, startX + spacing * 2 + knobSize, y + knobSize), kMix, "Mix", knobColor, handleColor));
  
  return pGraphics;
}
