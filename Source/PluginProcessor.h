/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

const juce::ParameterID bypass_id = juce::ParameterID("bypass", 1);
const juce::ParameterID mix_id = juce::ParameterID("Drive", 1);

//==============================================================================
/**
*/
class AcoAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    AcoAudioProcessor();
    ~AcoAudioProcessor() override;

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

    juce::AudioProcessorParameter* getBypassParameter() const override
    {
        return apvts.getParameter(bypass_id.getParamID());
    }

private:
    juce::AudioProcessorValueTreeState apvts;

    std::atomic<float>
        * bypassParameter,
        * mixParameter;

    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
    {
        juce::AudioProcessorValueTreeState::ParameterLayout layout;

        layout.add(std::make_unique<juce::AudioParameterFloat>(mix_id, "Mix", juce::NormalisableRange<float>(0.f, 2.f, 0.01f), 0.f, juce::AudioParameterFloatAttributes().withStringFromValueFunction(stringFromPercent)));
        layout.add(std::make_unique<juce::AudioParameterBool>(bypass_id, "Bypass", false));

        return layout;
    }

    static juce::String stringFromPercent(float value, int)
    {
        return juce::String(int(100.f*value)) + "%";
    }

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AcoAudioProcessor)
};
