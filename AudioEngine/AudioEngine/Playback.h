#pragma once

#include "miniaudio.h"
#include "Voice.h"

#include <iostream>
#include <string>
#include <vector>

class Playback
{
private:

	ma_device device; // audio playback device
	ma_device_config deviceConfig; // audio playback device configuration
	std::vector<std::shared_ptr<Voice>> activeVoices;      // Registered voices ready for playback

public:
	Playback();
	~Playback();

	void init();
	// callback is called by the system which is requesting a certain amount of audio data which is stored 
	// in a buffer which is filled by callback......(I think)
	static void audioCallback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
	void registerVoice(std::shared_ptr<Voice> voice);
	void unregisterVoice(std::shared_ptr<Voice> voice);

	void start();
	void stop();	
};

