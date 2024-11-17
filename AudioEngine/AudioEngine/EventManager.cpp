#include "EventManager.h"

EventManager::EventManager(/*UI* ui*/)//: uiPtr(ui)
{
	//init();
	//std::cout << "EventManager Constructor - uiPtr: " << uiPtr << std::endl;
	// for testing one event frame
	//if (events.size() < 1)
		//events.push_back(Event(uiPtr));
	maxEventsAllowed = 2;
       
	for(int i = 0; i < maxEventsAllowed; i++)
	{
		events.push_back(new Event);
		events[i]->init();
	}

	
   
}

EventManager::~EventManager()
{
}

void EventManager::init()
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Calling EventManager.init()" << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

void EventManager::render()
{
	//std::cout << "----------------------------------" << std::endl;
	//std::cout << "Calling EventManager.render()" << std::endl;
	//std::cout << "----------------------------------" << std::endl;

	// if (!events.empty()) 
    //{
    //    for (int i = 0; i < events.size(); i++)
    //    {
	//		ImVec2 position(10, 30 + i * 150);
	//
	//if (uiPtr)
	for (int i = 0; i < events.size(); i++)
		events[i]->render();
	        //events[i].render(); // this function call needs to be replaced with 
								// renderEventFrame(). In order to do this, I think I need to 
								// setup the event class so that one event may be called which
								// then calls renderEventFrame() in some form
   //    }
   //}
}

std::vector<class Event*>  EventManager::getEvents()
{
		return events;
}
