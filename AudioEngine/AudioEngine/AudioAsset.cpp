#include "AudioAsset.h"

AudioAsset::AudioAsset(const std::string& aFilePath)
{
	filePath = aFilePath;
	
	totalFrames = 0;
	channels = 0;
	sampleRate = 0;
	loaded = false;


}

AudioAsset::~AudioAsset()
{
	unload();
}

bool AudioAsset::load()
{
	if (loaded)
	{
		std::cerr << "Audio asset already loaded: " << filePath << std::endl;
		return true;
	}

	ma_result result; // varible that checks if operation was successful or not
	//ma_decoder decoder; // variable that decodes the audio file
	std::cout << "AudioAsset: filepath: " << filePath.c_str() << std::endl;
	// Initialize decoder 
    result = ma_decoder_init_file(filePath.c_str(), NULL, &decoder);
    if (result != MA_SUCCESS)
    {
		    std::cerr << "Audio Asset: Failed to initialize decoder while loading: " << filePath 
              << ". Error code: " << result << std::endl;
            return false;
	}

	// get the total number of frames in the audio file
	if (result = ma_decoder_get_length_in_pcm_frames(&decoder, &totalFrames)) 
    {
        std::cerr << "Failed to initialize audio file: " << filePath 
              << ". Error code: " << result << std::endl;
            return false;
    }

	channels = decoder.outputChannels; // set channels to the number of channels in the audio file
	sampleRate = decoder.outputSampleRate; // set sample rate to the audio file's sample rate

	// Resize audio data buffer to fit the audio data
    audioData.resize(totalFrames * channels);		
	
	// Read audio data from audio file into buffer
	result = ma_decoder_read_pcm_frames(&decoder, audioData.data(), totalFrames, &totalFrames);
	if (result != MA_SUCCESS)
	{
        std::cerr << "Failed to read PCM frames for" << filePath << std::endl;
		ma_decoder_uninit(&decoder);
        return false;
    }


	// Check to ensure all data within asset is correct
    std::cout << "- Audio data check within audioAsset.load() ----------------------" << std::endl;
	std::cout << "File loaded: " << filePath << std::endl;
	std::cout << "Total frames in audioAsset.load(): " << totalFrames << std::endl;
	std::cout << "Channels in audioAsset.load(): " << channels << std::endl;
	std::cout << "Sample rate in audioAsset.load(): " << sampleRate << std::endl;
	std::cout << "Audio data size in audioAsset.load(): " << audioData.size() << std::endl;
    std::cout << "-------------------------------------------------------------------\n" << std::endl;

	// Cleanup decoder
	ma_decoder_uninit(&decoder);
    loaded = true;
    return true;
}

void AudioAsset::unload()
{
	if (loaded)
	{
		audioData.clear();
		totalFrames = 0;
		channels = 0;
		sampleRate = 0;
		loaded = false;
		std::cout << "Unloaded audio file: " << filePath << std::endl;
	}
}

const std::vector<float>& AudioAsset::getAudioData()
{
	return audioData;
}

ma_uint64 AudioAsset::getTotalFrames()
{
	return totalFrames;
}

ma_uint32 AudioAsset::getChannels()
{
	return channels;
}

ma_uint32 AudioAsset::getSampleRate()
{
	return sampleRate;
}

bool AudioAsset::isLoaded()
{
	return loaded;
}



