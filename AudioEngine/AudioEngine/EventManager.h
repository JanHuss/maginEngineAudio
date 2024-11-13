#pragma once

#include <string>
#include <vector>

#include "Event.h"
#include "UI.h"

/// <Event Manager Summary>
/// ==========================================================
/// This class handles the amount of Event classes that can 
/// be initialised during runtime. 
/// This class may make use of the object pool design pattern
/// to reduce memory and CPU by reusing code. However events
/// should not be deleted unless the scene within a game 
/// changes which is outside of the intended scope of this
/// project at the time.
/// 
/// Each event is stored in a container and is tracked by an 
/// "eventID" for maintainability.
/// 
/// This class comunicates with the budget class. It passes on
/// information on memory and CPU usage and recieves 
/// information from the budget class as to how much memory 
/// and CPU is provided.
/// 
/// ==========================================================
/// </Event Manager Summary>

class EventManager
{
public:
	EventManager(UI* ui);
	~EventManager();

	void init();
	void render();

private:
	//std::vector<class Event> events;
	// Pointers
	UI* uiPtr;
	Event* eventssss;
};

