/// <Engine Core Summary>
/// ==========================================================
/// This class holds the entire audio engine together.
/// It would be considered as the "Application" class
///	for other software. 
/// 
/// The only other classes that are recieving information
/// from this class are "main.cpp" for being able to run
/// the application and "UI" for passing "Engine parameters".
/// 
/// Otherwise, this class will act as a parent to most
/// of the audio engine classes (Check EngineCore folder).
/// ==========================================================
/// </Engine Core Summary>

#pragma once

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// might be able to be removed if imgui has been moved to UI class---
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
// ------

#include "iostream"
#include "vector"
#include <portaudio.h>
#include <cmath>

#include "miniaudio.h"

#include "EventManager.h"
#include "Event.h"
#include "UI.h"
#include "VoiceManager.h"
#include "ResourceManager.h"
#include "Playback.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


enum EngineStatus
{
	Success = 0,
	GeneralFailure = -1,
	InitialisationError = -2
};

// create test wave. I'm keeping this just in case ------------------------------
typedef struct {
    float left_phase;
    float right_phase;
} paTestData;

class Engine
{
public:
	Engine();
	~Engine();

	void init();
	int run();

	// init functions
	int portAudioInitialise();
	void miniAudioInitialise();
	int glfwInitialise();
	void imguiInitialise();

	// load and play sounds. needs to be moved into input handler when functional
	void loadSound();
	int playbackInitialise();
	void playbackRegister();
	int playbackStart();
	void playbackStop();

	void handleAssets();

private:
	// Pointers
	GLFWwindow* window;
	UI* uI;
	EventManager* eventManager;
	Voice* voice;
	ResourceManager* resourceManager;
	Playback* playback;

	// Variables
	std::string assetName;
	bool enterPressed; // test var
};

