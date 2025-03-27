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
    designKnob(mixSliderComponent);

    addAndMakeVisible(bypassButtonComponent);
    bypassButtonComponent.setupImageButton(BinaryData::bypass_image_png, BinaryData::bypass_image_pngSize, juce::Colours::red, juce::Colours::green);

    setSize (400, 300);
}

void AcoAudioProcessorEditor::designKnob(AcoGui::SliderComponent& sliderComp, juce::Colour color)
{
    addAndMakeVisible(sliderComp);
    sliderComp.slider.setColour(juce::Slider::rotarySliderFillColourId, color);
    sliderComp.labelIsText = true;
}

AcoAudioProcessorEditor::~AcoAudioProcessorEditor()
{
}

//==============================================================================
void AcoAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (AcoColors::Main::background);
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText("ACO Audio Processor", getLocalBounds(), juce::Justification::centred, 1);
}

void AcoAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();

    mixSliderComponent.setBounds(bounds.removeFromTop(bounds.getHeight() / 2));
    bypassButtonComponent.setBounds(bounds);
}
