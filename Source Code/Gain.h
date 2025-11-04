/*
  ==============================================================================

    Gain.h
    Created: 28 Oct 2025 11:13:49am
    Author:  Admin

  ==============================================================================
*/

#pragma once
class Gain
{
    public:
    Gain();
    ~Gain();
    
    void setGain(float gain);
    float getGain();
    void initiliase(float gain);
    void process(float& leftsample, float& rightsample);
    
    private:
    float m_gain;
};
