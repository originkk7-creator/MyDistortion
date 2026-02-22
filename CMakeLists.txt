cmake_minimum_required(VERSION 3.20)
project(MyDistortion VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# iPlug2
set(IPLUG2_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../iPlug2")
include(${IPLUG2_ROOT}/iPlug2.cmake)

# Проект
add_plugin(MyDistortion
  NAME MyDistortion
  MANUFACTURER_ID MyCo
  PRODUCT_ID MyD0
  MANUFACTURER_NAME "MyCompany"
  PLUGIN_NAME "MyDistortion"
  BUNDLE_ID com.mycompany.mydistortion
  VERSION 1.0.0
  DO_ISYNC 0
  DO_MIDI_IN 0
  DO_MIDI_OUT 0
  DO_MPE 0
  CHANNEL_STR "stereo"
  PLUG_CATEGORY "fx"
  PLUG_TYPE FX
  AAX_CATEGORY kPlugCategoryEffect
  VST3_CATEGORIES "Fx|Distortion"
  AU_MAIN_TYPE kAudioUnitType_Effect
  AU_SUBTYPE MyD0
  VST2_CATEGORIES "Fx"
  CLAP_CATEGORIES "distortion" "fx"
)

target_include_directories(MyDistortion PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(MyDistortion PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/MyDistortion.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/MyDistortion.h
  ${CMAKE_CURRENT_SOURCE_DIR}/parameters.h
  ${CMAKE_CURRENT_SOURCE_DIR}/config.h
)

# Ресурсы (фон)
if(WIN32)
  target_compile_definitions(MyDistortion PRIVATE
    PLUG_NAME="MyDistortion"
    PLUG_MFR="MyCompany"
    PLUG_VERSION_HEX=0x00010000
    PLUG_UNIQUE_ID='MyD0'
    PLUG_MFR_ID='MyCo'
    PLUG_MAX_CHANNELS=2
  )
elseif(LINUX)
  target_compile_definitions(MyDistortion PRIVATE
    PLUG_NAME="MyDistortion"
    PLUG_MFR="MyCompany"
    PLUG_VERSION_HEX=0x00010000
    PLUG_UNIQUE_ID='MyD0'
    PLUG_MFR_ID='MyCo'
    PLUG_MAX_CHANNELS=2
    PLUG_DOES_MIDI_IN=0
    PLUG_DOES_MIDI_OUT=0
  )
elseif(APPLE)
  target_compile_definitions(MyDistortion PRIVATE
    PLUG_NAME="MyDistortion"
    PLUG_MFR="MyCompany"
    PLUG_VERSION_HEX=0x00010000
    PLUG_UNIQUE_ID='MyD0'
    PLUG_MFR_ID='MyCo'
    PLUG_MAX_CHANNELS=2
  )
endif()
