/// <Voice Summary>
/// ==========================================================
/// This class handles the tracking of voice playback 
/// positions and transport controls.
/// 
/// It also takes data of the audio assets from a "Resource 
/// Manager" class that is yet to be incorporated into the 
/// structural diagram.
/// 
/// Variables to keep track of the Voice's playback position 
/// will be set in this class. The Voice Manager class will 
/// take this information to keep track of "virtual" and 
/// "real" Voices.
/// 
/// The audio assets data will be sent to the Buffer Manager
/// class which will populate the buffers based on the length
/// of the audio asset.
/// 
/// This class will communicate with the Budget class and will
/// pass on the memory and CPU usage within a voice. 
/// The Budget Class will also provide information on the
/// provided Budget set for this application.
/// 
/// ==========================================================
/// </Voice Summary>

#pragma once

#include <iostream>

#include "ResourceManager.h"
#include "miniaudio.h"


class Voice
{
private:
	// Pointers
	std::shared_ptr<AudioAsset> audioAsset;
	ma_uint64 playhead;
	//ma_decoder decoder;   // Manages audio decoding
 //   bool isLoaded;        // Indicates whether an audio file is loaded
	
	// Variables
	bool playing;

public:
	Voice(std::shared_ptr<AudioAsset> asset);
	~Voice();

	void init();
	//void assignVoice(std::string assetName, std::shared_ptr<AudioAsset> asset);
	//bool loadIntoBuffer(const char* filePath);

	// transport 
	void play();
	void stop();
	bool isPlaying() const;

	const std::vector<float>& getAudioData() const;
	ma_uint64 getAudioPlayhead() const;
	void setAudioPlayhead(ma_uint64 newPlayhead);

	//int getChannels() const;
	//ma_format getFormat() const;
	//ma_uint32 getSampleRate() const;

	//void registerWithPlayback(Playback& playback);
	//void processAudio(std::vector<float>& mixBuffer, ma_uint32 frameCount); 
	
	void render();
};

