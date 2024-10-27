#pragma once

#include "imgui.h"
#include "iostream"
#include "vector"
#include "EventBase.h"
#include "AudioThread.h" // not sure if this is where to include this

class EngineBase
{
private:
	std::vector<class EventBase> events;

	AudioThread audioThread; // not sure if this is where to include this. I only need one instance of this class for the engine,
							 // therefore it makes sense to include it here
public:
	EngineBase();
	~EngineBase();

	void Update();
	void Render();
};

