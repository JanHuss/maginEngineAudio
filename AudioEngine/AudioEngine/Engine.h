#pragma once

#include "imgui.h"
#include "iostream"
#include "vector"
#include "EventBase.h"

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

class Engine
{
public:
	Engine();
	~Engine();

	void update();
	void render();

private:
	std::vector<class EventBase> events;
};

