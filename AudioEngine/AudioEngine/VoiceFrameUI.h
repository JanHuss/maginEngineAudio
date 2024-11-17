#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>
#include <string>
#include <vector>


class VoiceFrameUI
{
private:


public:
	VoiceFrameUI();
	~VoiceFrameUI();

	void renderVoiceFrameUI(int voiceID, int eventID);
};

