/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Gain.h"

//==============================================================================
/**
*/
enum Parameters // this is just used to update the gain parameters from PluginEditor
{
    kgain,
    value
};

class GainierthanThouAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    GainierthanThouAudioProcessor();
    ~GainierthanThouAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //==============================================================================
    float gainSlider;
    void updateParameters(int param, float value);
    
private:
    //==============================================================================
    Gain m_GainInstance;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainierthanThouAudioProcessor)
};
