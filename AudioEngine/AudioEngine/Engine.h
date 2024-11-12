#pragma once

#include "imgui.h"
#include "iostream"
#include "vector"
#include "Event.h"
#include <portaudio.h>

#include "miniaudio.h"

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

	int init();
	int run();
	void update();
	void render();

private:
	std::vector<class Event> events;
};

