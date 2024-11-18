#pragma once

#include "vector"
#include "string"
#include "iostream"

#include "miniaudio.h"

/// <AudioAsset Summary>
/// ==========================================================
/// This class works allong with the ResourceManager and loads
/// and unloads audio assets upon request.
/// 
/// It is also the layer in which the asset's length is 
/// sourced and passed through to the voice for tracking. 
/// 
/// ==========================================================
/// <\AudioAsset Summary>

class AudioAsset
{
private:
	// Create audio data variables
	std::string filePath;
	std::vector<float> audioData;
    ma_uint64 totalFrames;
	ma_uint32 channels;
	ma_uint32 sampleRate;
	bool loaded;

public:
	explicit AudioAsset(const std::string& aFilePath); // Try removing this when multiple assets are loaded. Interested what would happen.
							// The explicit keyword in C++ prevents a constructor 
							// from being used for implicit conversions or copy-initialization. 
							// It's particularly useful when you have a constructor that takes a 
							// single argument, as it ensures that the constructor is only called 
							// explicitly, avoiding unintended or surprising conversions.
	~AudioAsset();

	bool load();
	void unload();

	// Getters for audio data variables
	const std::vector<float>& getAudioData();
	ma_uint64 getTotalFrames();
	ma_uint32 getChannels();
	ma_uint32 getSampleRate();
	bool isLoaded();
};

