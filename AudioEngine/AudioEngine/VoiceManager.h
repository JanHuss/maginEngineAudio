#pragma once

/// <Voice Manager Summary>
/// ==========================================================
/// This class manages a container of Voice classes. The 
/// maximum amount of Voice elements is defined by the Event 
/// class. 
/// 
/// When a new Voice is added to the container, the Voice
/// is assigned a "voice ID" and a weighting of importance.
/// The importance value will determine if the voice is set 
/// to be "virtual" or "real" depending if the maximum value 
/// of real voices has been reached.
/// To reduce memory and CPU cost, an object pool design
/// pattern will be used to "check out" and reassign Voices.
/// 
/// If the maximum value has been reached, and the Voice has
/// a lower priority than any of the "real" Voices, then set
/// the voice to be "virtual".
/// If the importance is higher than other "real" Voices, 
/// then replace the lowest valued Voice with the new Voice
/// and convert the lowest valued voice to a "virtual" voice.
/// 
/// The importance will keep track of availability within the
/// "real" Voice pool and convert "virtual" Voices to "real"
/// Voices when available or when importance in a "virtual"
/// Voice is high enough.
/// 
/// This class will also check if the Voice will be assigned 
/// an effect. If so, the voice ID and the name of the effect
/// will be passed on to the Voice along with a boolean to
/// confirm the effect assignment. The variable for the name 
/// of the effect will either be an enum or a string. As
/// string values are more expensive, it will most likely be 
/// an enum.
/// 
/// It would be wise to consider a drop down menu containing
/// the different effects available to apply an effect to a
/// Voice. 
/// 
/// The Voice Manager class will provide memory and CPU 
/// consumption to the Budget class while the Budget class
/// will provide information on the currently set budget to 
/// the Voice Manager class
/// 
/// ==========================================================
/// </Voice Manager Summary>

class VoiceManager
{
};

