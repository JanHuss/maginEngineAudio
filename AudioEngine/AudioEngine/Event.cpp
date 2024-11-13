#include "Event.h"

Event::Event(UI* ui): uiPtr(ui)
{
	// shove the next event down the y axis...
	// have a delete button in the event frame....
	eventID = 0;
	std::cout << "Event Constructor - uiPtr: " << uiPtr << std::endl;
}

Event::~Event()
{
}

void Event::update()
{
}

void Event::render()
{
	//std::cout << "----------------------------------" << std::endl;
	//std::cout << "Calling Event.render()" << std::endl;
	//std::cout << "----------------------------------" << std::endl;

	if (uiPtr)
		uiPtr->renderEventFrame();
}
