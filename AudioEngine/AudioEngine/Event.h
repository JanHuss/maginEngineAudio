/// <Event Summary>
/// ==========================================================
/// This Class defines the functionality of multiple voices.
/// 
/// Each event contains an instance of the Voice Manager class
/// and handles transport controls as well as pitch, pan and
/// volume controls through communicating with the UI class.
/// 
/// ==========================================================
/// </Event Summary>

#pragma once
#include "iostream"

//#include "UI.h"
#include "VoiceManager.h"
#include "Playback.h"

class Event
{
private:
	// Pointers
	Playback* playback;

	int eventID;
	std::string eventName;


public:
	Event(Playback* pb);
	~Event();

	void init();
	void render();

	VoiceManager* voiceManager;
	// Getters
	

};

