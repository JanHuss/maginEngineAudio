#pragma once

#include "iostream"
#include <string>
#include <vector>
#include "miniaudio.h"

class Playback
{
private:

	ma_device_config deviceConfig;
	ma_audio_buffer_config bufferConfig;

	std::vector<float> audioBuffer;
	size_t bufferReadIndex = 0;
    
	ma_device device; // audio playback device
	ma_decoder decoder; // reads audio from loaded file
	bool isPlaying; // flag to check playback state

public:
	Playback();
	~Playback();

	int init();

	// callback is called by the system which is requesting a certain amount of audio data which is stored 
	// in a buffer which is filled by callback......(I think)
	static void audioCallback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
};

