#pragma once

/// <Effect Chain Summary>
/// ==========================================================
/// This class can hold a container of "Effect" class 
/// instances. 
/// This class may make use of the object pool design pattern.
/// 
/// The audio data from a Voice is passed into this class and 
/// is passed through the container processing the signal
/// procedurally and are returned back to the EffectsChain 
/// class to either process the signal through the next effect
/// or output the signal to the sound card.
/// 
/// This class will also need to communicate with the Buffer
/// Manager as the length of the voice will change if a delay
/// or a reverb is used.
/// 
/// The UI class will display the chosen effect's parameters
/// including a function to bypass an effect.
/// 
/// A `noAudioEffect` function will be triggered if no effect
/// is applied to a Voice and will output the signal 
/// unprocessed to the soundcard.
/// 
/// ==========================================================
/// </Effect Chain Summary>

class EffectChain
{
};

