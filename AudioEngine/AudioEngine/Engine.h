#pragma once

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "iostream"
#include "vector"
#include "Event.h"
#include <portaudio.h>
#include <cmath>

#include "miniaudio.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

// Define PortAudio callback function for streaming audio data to the sound card ------------
typedef int PaStreamCallback (const void* input, // points to incoming audio data
	                          void* output, // points to the buffer where to write the outgoing audio data
	                          unsigned long frameCount, // number of frames the sound card is requesting
	                          const PaStreamCallbackTimeInfo* timeInfo, // provides time information for the current audio callback
	                          PaStreamCallbackFlags statusFlags, // contains flags that indicate whether input and/or output buffers have been inserted or will be dropped
	                          void* userData); // A custom pointer that is passed to the callback function

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

	// functions that need to be moved to other classes
	void loadAudio(const char* filename, // name of audio file
					std::vector<float>& audioData, // file's audio data
					ma_uint64& totalFrames, // total number of frames in the audio file (determines the length of the audio file)
					ma_uint32& channels, // number of channels the audio file uses
					ma_uint32& sampleRate); // audio file's sample rate

	static int paWaveCallback(const void *inputBuffer, void *outputBuffer,
                          unsigned long framesPerBuffer,
                          const PaStreamCallbackTimeInfo* timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData);

private:
	// Pointers
	GLFWwindow* window;

	std::vector<class Event> events;

	// Create audio data variables
	std::vector<float> audioData;
    ma_uint64 totalFrames;
	ma_uint32 channels;
	ma_uint32 sampleRate;
};

