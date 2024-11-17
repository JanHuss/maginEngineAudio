#pragma once
#include "iostream"

//#include "UI.h"
#include "VoiceManager.h"

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

class Event
{
private:
	// Pointers
	//UI* uiPtr;

	int eventID;
	std::string eventName;


public:
	Event(/*UI* ui*/);
	~Event();

	void init();
	void render();

	VoiceManager* voiceManager;
	// Getters
	

};

