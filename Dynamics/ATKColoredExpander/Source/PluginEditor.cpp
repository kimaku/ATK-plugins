/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ATKColoredExpanderAudioProcessorEditor::ATKColoredExpanderAudioProcessorEditor (ATKColoredExpanderAudioProcessor& p, AudioProcessorValueTreeState& paramState)
: AudioProcessorEditor (&p), processor (p), paramState(paramState), power(paramState, "power"), attackrelease(paramState, "attack", "release"), expander(paramState, "threshold", "slope", "softness", "color", "quality", "maxreduc"), makeup(paramState, "makeup", "Make-up"), drywet(paramState, "drywet")

{
  addAndMakeVisible(power);
  addAndMakeVisible(attackrelease);
  addAndMakeVisible(expander);
  addAndMakeVisible(makeup);
  addAndMakeVisible(drywet);
  
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize (1100, 200);
}

ATKColoredExpanderAudioProcessorEditor::~ATKColoredExpanderAudioProcessorEditor()
{
}

void ATKColoredExpanderAudioProcessorEditor::paint (Graphics& g)
{
  // (Our component is opaque, so we must completely fill the background with a solid colour)
  g.fillAll(getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
  g.setFont(Font("Times New Roman", 30.0f, Font::bold | Font::italic));
  g.setColour(Colours::whitesmoke);
  g.drawText("Colored Expander", 20, 10, 400, 30, Justification::verticallyCentred);
}

void ATKColoredExpanderAudioProcessorEditor::resized()
{
  const int nb_elements = 11;
  power.setBoundsRelative(0, 1. / 4, 1. / nb_elements, 3. / 4);
  attackrelease.setBoundsRelative(1. / nb_elements, 1. / 4, 2. / nb_elements, 3. / 4);
  expander.setBoundsRelative(3. / nb_elements, 1. / 4, 6. / nb_elements, 3. / 4);
  makeup.setBoundsRelative(9. / nb_elements, 1. / 4, 1. / nb_elements, 3. / 4);
  drywet.setBoundsRelative(10. / nb_elements, 1. / 4, 1. / nb_elements, 3. / 4);
}

