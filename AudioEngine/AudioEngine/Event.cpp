#include "Event.h"

Event::Event(int iD, std::string evNa)
{
	// shove the next event down the y axis...
	// have a delete button in the event frame....
}

Event::~Event()
{
}

void Event::update()
{
}

void Event::render()
{
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
