#include "Event.h"

Event::Event(Playback* pb) : playback(pb)
{
	// shove the next event down the y axis...
	// have a delete button in the event frame....
	eventID = 0;
	//std::cout << "Event Constructor - uiPtr: " << uiPtr << std::endl;

	voiceManager = new VoiceManager(playback);

	//init();
	voiceManager->init();
}

Event::~Event()
{
}

void Event::init()
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Calling Event.init()" << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

void Event::render()
{
	//std::cout << "----------------------------------" << std::endl;
	//std::cout << "Calling Event.render()" << std::endl;
	//std::cout << "----------------------------------" << std::endl;

	//if (uiPtr)
	//	uiPtr->renderEventFrame();
}
