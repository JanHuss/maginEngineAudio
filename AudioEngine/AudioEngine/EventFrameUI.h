#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "iostream"

class EventFrameUI
{
private:
	//int eventID; // this var needs to be removed and replaced with the UI eventFrameVect[i] value
public:
	EventFrameUI();
	~EventFrameUI();

	void renderEventFrame(int eventID); // contains the frame of an Event. Event Buttons and other features will be in seperate function
};

