/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Gain.h"


//==============================================================================
/**
*/
class GainierthanThouAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GainierthanThouAudioProcessorEditor (GainierthanThouAudioProcessor&);
    ~GainierthanThouAudioProcessorEditor() override
    ;
    
    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    GainierthanThouAudioProcessor& audioProcessor;
    
    juce::Slider loudnessSlider; // Define the silder
    
    juce::Label versionNumber;
    
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainierthanThouAudioProcessorEditor)
};
