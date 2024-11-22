#include "EventFrameUI.h"

EventFrameUI::EventFrameUI(EventManager* eventMan) : eventManager(eventMan)
{

	//voiceID = 1;

	//std::cout << "------------------------------------------------" << std::endl;
	////std::cout << "VoiceManager getvoices.size() called from EventFrameUI: " << voiceManager->getVoices().size() << std::endl;
	//std::cout << "VoiceManager getvoices.size() called from EventFrameUI: " << voiceManager->voice << std::endl;
	//std::cout << "------------------------------------------------" << std::endl;

	// VoiceFrameUI Setup --------------------------------------------------------------------------------------------------
	// In order to setup a hierarchy that would work in tandem with the EventManager system, the VoiceFrames need to called
	// from the eventManager's vector. This will first check for the current event, then it will check for the event's
	// amount of voices in the voices vector and push back a VoiceFrameUI for easier handling in the UI class.
	// 
	// This is a basic framework for now, assuming that every event has the same amount of loaded audio assets.
	// To create a more dynamic system, consider to render only when checking how many voices within an event are loaded 
	// with an asset.
	// ---------------------------------------------------------------------------------------------------------------------

	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "eventManager->getEvents().size(): " << eventManager->getEvents().size() << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	
	//for (int j = 0; j < eventManager->getEvents().size()[]->voiceManager->getVoices().size(); j++)
	//{
		//std::cout << "eventManager->getEvents()["<< i << "]->voiceManager->getVoices().size(): " << eventManager->getEvents()[i]->voiceManager->getVoices().size() << std::endl;
		
	// This block is a placeholder to ensure that the amount of voices loaded in the UI are a set amount.`
	voiceFrameUIvec.push_back(new VoiceFrameUI);
	voiceFrameUIvec.push_back(new VoiceFrameUI);
	//voiceFrameUIvec.push_back(new VoiceFrameUI);
	//voiceFrameUIvec.push_back(new VoiceFrameUI);
	//}
	

	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "Current amount of voiceframes in EventFrameUI vector: " << voiceFrameUIvec.size() << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
}

EventFrameUI::~EventFrameUI()
{
}

void EventFrameUI::renderEventFrame(int eventID)
{
	//std::cout << "---------------------------------------" << std::endl;
	//std::cout << "Calling EventFrameUI.renderEventFrame()" << std::endl;
	//std::cout << "---------------------------------------" << std::endl;

	ImGui::PushID(eventID); // eventID is the size of the vector of Event pointers `eventFrameUIvec` in the UI class 
	//Initialise event frame from ImGui
	ImGui::BeginChild("Event Frame", ImVec2(500, 350), true); // if time, perhaps adjust the size of the event frame to the amount of voices created within the event.
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.5f, 0.0f, 1.0f));
	ImGui::Text("Event Frame");
    ImGui::PopStyleColor();
	ImGui::SetCursorPos(ImVec2(10, 30));
    ImGui::Text("Build buttons here");
	// Buttons for the event frame here -----------------------------------------------------
	// Transport buttons
	if(ImGui::Button("Play"))
		std::cout << "Play was pressed in " << eventID<< std::endl;
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
	
	// Voice Frame UI frame here ----------------------------------------------------------------
	// voice UI stuff here. change to calling voiceFrameUI class instead. probably something like 
	for (int i = 0; i < voiceFrameUIvec.size(); i++)
		voiceFrameUIvec[i]->renderVoiceFrameUI(i, eventID);
	// ------------------------------------------------------------------------------------------
	
	ImGui::EndChild();
	ImGui::PopID();
}