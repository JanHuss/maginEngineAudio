#include "Engine.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

int Engine::init()
{
	std::cout << "Engine Init function called" << std::endl;

	// PortAudio Initialise
	PaError err = Pa_Initialize();
    paTestData data = { 0 };  // Initialize phase data for the sine wave


    if (err != paNoError) {
        std::cout << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
        return InitialisationError;
    }
	std::cout << "- Library check ---------------------------------------------------" << std::endl;
    std::cout << "PortAudio initialized successfully!" << std::endl;

	// Display PortAudio version
	std::cout << "PortAudio version: " << Pa_GetVersionText() << std::endl;


	// MiniAudio Initialise
	// MiniAudio message
	std::cout << "MiniAudio installed" << std::endl;
	std::cout << "MiniAudio version: " << MA_VERSION_STRING << std::endl;
	std::cout << "-------------------------------------------------------------------\n" << std::endl;
}

int Engine::run()
{
	std::cout << "Engine Run function called" << std::endl;

	return 0;
}

void Engine::update()
{
}

void Engine::render()
{
	// variables
	std::string eventName;

	// Engine Frame
	ImGui::Begin("Engine"); // shouldn't be able to see the title bar
	ImGui::SetWindowSize(ImVec2(640, 500));
	ImGui::SetWindowPos(ImVec2(0, -20)); // hide the title bar with a negative y value
	ImGui::Text("Build Event here");
	// Buttons for the engine frame here -----------------------------------------------------

    // Adding Events to vector when button is pressed ----------------------------------------
	// This is probably a way to add events when the user can save and close the application
	
	//if(ImGui::Button("Add Event"))
	//{
	//	// quick and dirty way to add event names
    //    //std::cin >> eventName;
	//	// Add event to engine frame
	//	events.push_back(Event(events.size(), eventName));
	//	//std::cout << "Amount of events called: " << events.size() << std::endl;
	//}
	 
	// --------------------------------------------------------------------------------------
	// for testing one event frame
		if (events.size() < 1)
            events.push_back(Event(events.size(), eventName));
    if (!events.empty()) 
    {
        for (int i = 0; i < events.size(); i++)
        {
			ImVec2 position(10, 30 + i * 150);
	        events[i].render();
        }
    }
    // --------------------------------------------------------------------------------------

	ImGui::End();
}
