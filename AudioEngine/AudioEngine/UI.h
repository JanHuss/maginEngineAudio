#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>
#include <string>
#include <vector>

//#include "Event.h"


/// <UI Summary>
/// ==========================================================
/// This class handles all UI parameters when the engine is 
/// running as an application rather than during gameplay.
/// 
/// This is to test audio playback and controls when gameplay
/// isn't needed. 
/// 
/// One thing to consider for now is that when the parameters
/// have been changed during runtime the parameters will not
/// have been altered within code. 
/// As a current work around, it might be wise to display the
/// float value of the parameters down to 2 decimal points 
/// next to the parameter itself. that way, users can take
/// note of the parameters and adjust them accordingly.
/// 
/// I will look into saving parameter changes after the 
/// honours project deadline has past.
/// 
/// Budget parameters should be changeable within the UI as	
/// well. Either, make it accessible to change each budget as
/// a percentile value (eg. memory, CPU, storage). Or have set
/// templates based on the hardware of the current device or
/// current gen platforms and then set the percentage based on
/// the maximum availability of that template.
/// 
/// The GUI used for this engine is Dear ImGui which runs on
/// the GLFW framework.
/// 
/// ==========================================================
/// </UI Summary>


class UI
{
public: 
	UI();
	~UI();

	void renderEngineFrame();// contains the frame of the Engine. Global Buttons and other features will be in seperate function
	void renderEventFrame(); // contains the frame of an Event. Event Buttons and other features will be in seperate function
	void renderVoiceFrame(); // contains the frame of a Voice. Event Buttons and other features will be in seperate function
	

private:
	//std::vector<class Event> events;
	int eventID;
	std::string eventName;
};

