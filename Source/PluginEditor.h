/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

struct CustomRotarySlider : juce::Slider
{
    CustomRotarySlider() : juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox)
    {

    }
};

//==============================================================================
/**
*/
class SimpleeqAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimpleeqAudioProcessorEditor (SimpleeqAudioProcessor&);
    ~SimpleeqAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleeqAudioProcessor& audioProcessor;

    CustomRotarySlider peakFreqSlider, peakGainSlider, peakQualitySlider;
    CustomRotarySlider lowCutFreqSlider, lowCutSlopeSlider;
    CustomRotarySlider highCutFreqSlider, highCutSlopeSlider;

    using APVTS = juce::AudioProcessorValueTreeState;
    using Attachment = APVTS::SliderAttachment;

    Attachment peakFreqSliderAttachment, peakGainSliderAttachment, peakQualitySliderAttachment;
    Attachment lowCutFreqSliderAttachment, lowCutSlopeSliderAttachment;
    Attachment highCutFreqSliderAttachment, highCutSlopeSliderAttachment;

    std::vector<juce::Component*> getComps();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleeqAudioProcessorEditor)
};
