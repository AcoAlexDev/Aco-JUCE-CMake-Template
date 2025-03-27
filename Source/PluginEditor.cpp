/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "BinaryData.h"

//==============================================================================
AcoAudioProcessorEditor::AcoAudioProcessorEditor (AcoAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p), apvtsRef (vts)
{
    setSize (400, 300);
}


AcoAudioProcessorEditor::~AcoAudioProcessorEditor()
{
}

//==============================================================================
void AcoAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black.brighter(0.1f));
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void AcoAudioProcessorEditor::resized()
{

}
