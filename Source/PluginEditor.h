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
    juce::AudioProcessorValueTreeState& apvtsRef;

    AcoAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AcoAudioProcessorEditor)
};
