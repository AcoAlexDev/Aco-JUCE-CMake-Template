#include <JuceHeader.h>

namespace DSP
{
    static float clipSample(float inputSample)
    {
        return juce::jlimit(-1.0f, 1.0f, inputSample);
    }
}