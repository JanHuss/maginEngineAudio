#pragma once

#include "iostream"
#include <string>
#include <vector>
#include <mutex>
#include "miniaudio.h"
#include "Voice.h"

class Voice;

class Playback
{
private:

	ma_device_config deviceConfig;
	ma_audio_buffer_config bufferConfig;

	std::vector<float> audioBuffer;
	size_t bufferReadIndex = 0;
    
	ma_device device; // audio playback device
	std::vector<Voice*> activeVoices;      // Registered voices
    std::mutex voiceMutex;                 // Protects the activeVoices list
    std::vector<float> mixBuffer;          // Buffer for mixing audio
    bool isInitialized;                    // Flag to indicate playback readiness



	//ma_decoder decoder; // reads audio from loaded file
	bool isPlaying; // flag to check playback state

public:
	Playback();
	~Playback();

	int init();

	// callback is called by the system which is requesting a certain amount of audio data which is stored 
	// in a buffer which is filled by callback......(I think)
	static void audioCallback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
	void mixAudioBuffer(float* output, ma_uint32 frameCount);
	bool initialize(int channels, ma_format format, ma_uint32 sampleRate);
	
	bool start();
	void stop();
	void registerVoice(Voice* voice);
	void unregisterVoice(Voice* voice);
	
};

