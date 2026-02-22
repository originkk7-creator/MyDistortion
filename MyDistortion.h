#pragma once

#include "IPlug_include_in_plug_hdr.h"
#include "IGraphics/IGraphics.h"
#include "IGraphics/Controls/IVectorKnobControl.h"
#include "config.h"

class MyDistortion : public iplug::IPlug
{
public:
  MyDistortion(const iplug::InstanceInfo& info);
  
  void ProcessBlock(float** inputs, float** outputs, int nFrames) override;
  void OnReset() override;
  void OnIdle() override;
  
  void OnParamChange(int paramIdx) override;
  
  IGraphics* CreateGraphics() override;
  
private:
  float mDrive = 0.5f;
  float mTone = 0.5f;
  float mMix = 1.0f;
  
  float ProcessSample(float sample);
};
