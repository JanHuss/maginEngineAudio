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

#pragma once

#include <string>
#include <vector>

#include "Event.h"
#include "Playback.h"
//#include "UI.h"


class EventManager
{
private:
	//std::vector<class Event> events;
	// Pointers
	//UI* uiPtr;
	Playback* playback;
	int maxEventsAllowed;
	std::vector<class Event*> events;

public:
	EventManager(Playback* pb);
	~EventManager();

	void init();
	void render();

	// Setters

	// Getters
	std::vector<class Event*> getEvents(); // this will contain a vector of events rather than an instance. make sure that it's a vector of event pointers

};

