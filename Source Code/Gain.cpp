/*
  ==============================================================================

    Gain.cpp
    Created: 28 Oct 2025 11:13:49am
    Author:  Admin

  ==============================================================================
*/

#include "Gain.h"
#include "PluginEditor.h"
Gain::Gain()
{
    
}

Gain::~Gain()
{
    
}

void Gain::setGain(float gain){ // stores a gain value from the PluginProcessor.cpp file into the class
    m_gain = gain;
}

float Gain::getGain(){ // returns the gain value in use to user if needed
    return m_gain;
}

void Gain::initiliase(float gain) // Initialises the gain at the start of the program running
{
    setGain(gain);
}

void Gain::process(float &leftSample, float &rightSample){ // Takes in the sample being processed, and multiplies it by the gain value
    leftSample = leftSample * m_gain;
    rightSample = rightSample * m_gain;
}
