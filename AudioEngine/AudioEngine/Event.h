#pragma once
#include "iostream"

#include "UI.h"

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
public:
	Event(UI* ui);
	~Event();

	void update();
	void render();

private:
	// Pointers
	UI* uiPtr;

	int eventID;
	std::string eventName;
};

