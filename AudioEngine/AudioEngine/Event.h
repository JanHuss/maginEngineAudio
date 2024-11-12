#pragma once
#include "imgui.h"
#include "iostream"

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
	int eventID;
	std::string eventName;

public:
	Event(int iD, std::string evNa);
	~Event();

	void update();
	void render();
};

