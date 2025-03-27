/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "BinaryData.h"

//==============================================================================
/**
*/
class AcoAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AcoAudioProcessorEditor (AcoAudioProcessor&, juce::AudioProcessorValueTreeState& vts);
    ~AcoAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void designKnob(AcoGui::SliderComponent& sliderComp, juce::Colour color = juce::Colours::white);

    juce::AudioProcessorValueTreeState& apvtsRef;

    AcoGui::SliderComponent
        mixSliderComponent{ apvtsRef, mix_id.getParamID() };

    //Add Image before creating Button
    AcoGui::AcoImageButtonComponent
        bypassButtonComponent{ apvtsRef, bypass_id.getParamID() };

    AcoAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AcoAudioProcessorEditor)
};
