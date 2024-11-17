#include "VoiceFrameUI.h"

VoiceFrameUI::VoiceFrameUI()
{
}

VoiceFrameUI::~VoiceFrameUI()
{
}

void VoiceFrameUI::renderVoiceFrameUI(int voiceID, int eventID)
{
	ImGui::PushID(voiceID);
	ImGui::BeginChild("Voice Frame", ImVec2(300, 100), true);
	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.5f, 0.0f, 1.0f));
	ImGui::Text("Voice Frame"); // maybe add the voice ID here for reference?
	ImGui::PopStyleColor();
	ImGui::SetCursorPos(ImVec2(10, 30));
    ImGui::Text("Build buttons here");

	if (ImGui::Button("Test"))
		std::cout << "Event: "<< eventID << " - Test was pressed in voice: " << voiceID << std::endl;

	ImGui::EndChild();
	ImGui::PopID();
}
