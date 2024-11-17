#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "iostream"

#include "VoiceFrameUI.h"
#include "VoiceManager.h"
#include "EventManager.h"

class EventFrameUI
{
private:
	int voiceID; // this var needs to be removed and replaced with the UI voiceFrameVect[i] value that still needs to be setup

	//VoiceManager* voiceManager;
	EventManager* eventManager;

public:
	EventFrameUI(EventManager* eventMan);
	~EventFrameUI();

	void renderEventFrame(int eventID); // contains the frame of an Event. Event Buttons and other features will be in seperate function

	// Pointers
	std::vector<class VoiceFrameUI*> voiceFrameUIvec;

};

