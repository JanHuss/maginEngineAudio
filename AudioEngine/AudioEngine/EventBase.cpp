#include "EventBase.h"

EventBase::EventBase()
{
	// shove the next event down the y axis...
	// have a delete button in the event frame....
}

EventBase::~EventBase()
{
}

void EventBase::Update()
{
}

void EventBase::Render()
{
	//Initialise eventbase frame from ImGui
	ImGui::BeginChild("Event Frame", ImVec2(150, 150), true);
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
	ImGui::Button("Load File");
	// if file loaded display current file name
	// otherwise display "No file loaded"

	// Volume and pitch sliders. NOTE!!!! Second parameter needs to be pulled from the audio data
	ImGui::Text("Volume slider here");
	ImGui::Text("Pitch slider here");
	//ImGui::SliderFloat("Volume", 0, 0.0f, 1.0f);
	//ImGui::SliderFloat("Pitch", 0, 0.0f, 1.0f);
	

	ImGui::EndChild();
}
