#pragma once

#include <iostream>

#include "ResourceManager.h"
#include "Playback.h"

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

class Voice
{
private:
	std::shared_ptr<AudioAsset> loadedSound;
	

public:
	Voice();
	~Voice();

	void init();
	void assignVoice(std::string assetName, std::shared_ptr<AudioAsset> asset);
	void render();

	// transport 
	void play();
	void stop();
};

