#include "Engine.h"

Engine::Engine()
{
}

Engine::~Engine()
{
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
	//	events.push_back(EventBase(events.size(), eventName));
	//	//std::cout << "Amount of events called: " << events.size() << std::endl;
	//}
	 
	// --------------------------------------------------------------------------------------
	// for testing one event frame
		if (events.size() < 1)
            events.push_back(EventBase(events.size(), eventName));
    if (!events.empty()) 
    {
        for (int i = 0; i < events.size(); i++)
        {
			ImVec2 position(10, 30 + i * 150);
	        events[i].Render();
        }
    }
    // --------------------------------------------------------------------------------------

	ImGui::End();
}
