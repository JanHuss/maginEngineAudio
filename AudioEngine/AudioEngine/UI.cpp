#include "UI.h"

UI::UI(EventManager* eventMan) : eventManager(eventMan)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Calling UI constructor" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// the number of event frames that will be set based on the size of the Event manager `events` vector
	for (int i = 0; i < eventManager->getEvents().size(); i++)
		eventFrameUIvec.push_back(new EventFrameUI(eventManager)); 

	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "Current amount of eventframes in UI vector: " << eventFrameUIvec.size() << std::endl;
	std::cout << "------------------------------------------------" << std::endl;


	// not sure about this: 
	// the voices keep matching the amount of maximum events rather than the maximum value of voices per event.
	// if I increase the voices then I go out of bounds. 
	// the below code was originally within the EventFrameUI class constructor but also caused issues. I think 
	// it needs to be placed back in there but code designed differently
	//for(int i = 0; i < eventFrameUIvec.size(); i++)
	//{
	//	for (int j = 0; j < eventManager->getEvents()[i]->voiceManager->getVoices().size(); j++)
	//	{
	//		std::cout << "eventManager->getEvents()["<< i << "]->voiceManager->getVoices().size(): " << eventManager->getEvents()[i]->voiceManager->getVoices().size() << std::endl;
	//		eventFrameUIvec[j]->voiceFrameUIvec.push_back(new VoiceFrameUI);
	//	}
	//}
}

UI::~UI()
{

}

// contains the frame of the Engine. Global Buttons and other features will be in seperate function
void UI::renderEngineFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
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



	// this check will need to call an EventFrame class to create an event frame object which 
	// will share an ID with an Event distributed by the EventManager class
	//if (eventManager->getEvents())
	//{
		// render event frame

	for (int i = 0; i < eventFrameUIvec.size(); i++)
	{
		int eventID = i;
		eventFrameUIvec[0]->renderEventFrame(eventID);  
		// move next event frame position down
		eventFramePosition = ImVec2(10, 30 + i * 150);		
	}

	//}
	
	
	
	// --------------------------------------------------------------------------------------
	// for testing one event frame
	//	if (events.size() < 1)
    //        events.push_back(Event());
    //if (!events.empty()) 
    //{
    //    for (int i = 0; i < events.size(); i++)
    //    {
	//        //events[i].render(); // this function call needs to be replaced with 
	//							// renderEventFrame(). In order to do this, I think I need to 
	//							// setup the event class so that one event may be called which
	//							// then calls renderEventFrame() in some form
    //    }
    //}
    // --------------------------------------------------------------------------------------

	ImGui::End();

    //ImGui::ShowDemoWindow(); // Show demo window! :)
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}



void UI::renderVoiceFrame()
{
}
