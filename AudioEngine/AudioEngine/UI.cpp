#include "UI.h"

UI::UI()
{
	eventID = 0;
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
	 
	// --------------------------------------------------------------------------------------
	// for testing one event frame
	//	if (events.size() < 1)
    //        events.push_back(Event());
    //if (!events.empty()) 
    //{
    //    for (int i = 0; i < events.size(); i++)
    //    {
	//		ImVec2 position(10, 30 + i * 150);
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

void UI::renderEventFrame()
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Calling UI.renderEventFrame()" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	ImGui::PushID(eventID);
	//Initialise event frame from ImGui
	ImGui::BeginChild("Event Frame", ImVec2(300, 100), true);
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.5f, 0.0f, 1.0f));
	ImGui::Text("Event Frame");
    ImGui::PopStyleColor();
	ImGui::SetCursorPos(ImVec2(10, 30));
    ImGui::Text("Build buttons here");
	// Buttons for the event frame here -----------------------------------------------------
	// Transport buttons
	ImGui::Button("Play");
	ImGui::SameLine();
	ImGui::Button("Pause");
	ImGui::SameLine();
	ImGui::Button("Stop");
	ImGui::SameLine();
	ImGui::Text("Volume slider here");
	ImGui::Button("Load File");
	ImGui::SameLine();
	ImGui::Text("Pitch slider here");
	// if file loaded display current file name
	// otherwise display "No file loaded"
	
	
	ImGui::EndChild();
	ImGui::PopID();
}

void UI::renderVoiceFrame()
{
}
