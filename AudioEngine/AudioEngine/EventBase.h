#pragma once
#include "imgui.h"
#include "iostream"

class EventBase
{
private:
	int eventID;
	std::string eventName;

public:
	EventBase(int iD, std::string evNa);
	~EventBase();

	void Update();
	void Render();
};

