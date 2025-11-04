/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainierthanThouAudioProcessorEditor::GainierthanThouAudioProcessorEditor (GainierthanThouAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (350, 400);
    addAndMakeVisible(loudnessSlider);                                              // Making slider visable and making it  *~ pretty ~*
    loudnessSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    loudnessSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 30);
    loudnessSlider.setRange(0, 5);
    loudnessSlider.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::greenyellow);
    loudnessSlider.setDoubleClickReturnValue(true, 1);
    loudnessSlider.setValue(1);
    
    // Fuck the listener function, just ask it to check when the value changes
    loudnessSlider.onValueChange = [this]{
        audioProcessor.updateParameters(kgain, loudnessSlider.getValue()); // then update paramaters accordingly
    };
    
    addAndMakeVisible(versionNumber);
    versionNumber.setText("version: 1.0", juce::dontSendNotification);
    versionNumber.setColour(juce::Label::textColourId, juce::Colours::wheat);
    

}

GainierthanThouAudioProcessorEditor::~GainierthanThouAudioProcessorEditor()
{
    
}
        
//==============================================================================
void GainierthanThouAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Graphic Design is my passion
    
    g.fillAll(juce::Colours::black.brighter(0.15));
    
    g.setColour(juce::Colours::wheat); // sets font colour
    g.setFont(35.0); // sets font size
    g.drawFittedText("Gainier than Thou", getLocalBounds(), juce::Justification::centredTop, 1); // tells us what we want to write and where we want it

}


void GainierthanThouAudioProcessorEditor::resized()
{
    
    // Using getWidth and getHeight to ensure that the dial is central every time, helps if the GUI will be rescaled, which mine shall not be
    
    auto leftMargin = (getWidth() * 0.5) - 150;
    auto topMargin = (getHeight() * 0.5) - 150;
    loudnessSlider.setBounds(leftMargin, topMargin, 300, 300);
    
    auto versionMarginL = (getWidth() - 100);
    auto versionMarginT = (getHeight() - 375);
    versionNumber.setBounds(versionMarginL, versionMarginT, 100, 25);

}
