#include "Voice.h"

Voice::Voice(std::shared_ptr<AudioAsset> asset) : audioAsset(asset)
{


	init();
	
	//isLoaded = false;
	playhead = 0;
	playing = false;
}

Voice::~Voice()
{
	//if (isLoaded) 
	//	ma_decoder_uninit(&decoder);
}

void Voice::init()
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Calling Voice.init()" << std::endl;
	//std::cout << "Playback address check: " << playback << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

//void Voice::assignVoice(std::string assetName, std::shared_ptr<AudioAsset> asset)
//{
//	std::cout << "----------------------------------" << std::endl;
//	std::cout << "Asset name in voice: " << assetName << std::endl;
//	std::cout << "Calling Voice.assignVoice()" << std::endl;
//	std::cout << "Asset variable address in Voice: " << asset << std::endl;
//	//loadedSound = asset;
//	//std::cout << "Getting asset frames: " << loadedSound->getTotalFrames() << std::endl;
//	//std::cout << "Getting asset channels: " << loadedSound->getChannels() << std::endl;
//	//std::cout << "Getting asset sample rate: " << loadedSound->getSampleRate() << std::endl;
//	//std::cout << "----------------------------------" << std::endl;
//
//}

//bool Voice::loadIntoBuffer(const char* filePath)
//{
//	//if (ma_decoder_init_file(filePath, NULL, &decoder) != MA_SUCCESS) {
//    //        std::cerr << "Failed to load audio file: " << filePath << std::endl;
//    //        return false;
//    //    }
//    //    isLoaded = true;
//    //    return true;
//}

void Voice::render()
{
}

bool Voice::isPlaying() const
{
	return playing;
}

void Voice::play()
{
	playing = true;
	playhead = 0;
}

void Voice::stop()
{
	playing = false;
	playhead = 0;
}

const std::vector<float>& Voice::getAudioData() const
{
	return audioAsset->getAudioData();
}

ma_uint64 Voice::getAudioPlayhead() const
{
	return playhead;
}

void Voice::setAudioPlayhead(ma_uint64 newPlayhead)
{
	playhead = newPlayhead;
}

// Retrieve audio properties
    //int Voice::getChannels() const 
	//{ 
	//	return decoder.outputChannels;
	//}
    //ma_format Voice::getFormat() const 
	//{ 
	//	return decoder.outputFormat; 
	//}
    //ma_uint32 Voice::getSampleRate() const 
	//{ 
	//	return decoder.outputSampleRate; 
	//}
	//// Register this voice with playback
    //void Voice::registerWithPlayback(Playback& playback) 
	//{
	//	std::cout << "----------------------------------" << std::endl;
	//	std::cout << "Calling Voice.RegisterwithPlayback: " << &playback << std::endl;
	//	std::cout << "----------------------------------" << std::endl;
    //    playback.registerVoice(this);
    //}
	//
    //// Process audio and mix it into the buffer
    //void Voice::processAudio(std::vector<float>& mixBuffer, ma_uint32 frameCount) 
	//{
    //    //if (!isLoaded) return;
	//	ma_decoder decoder = loadedSound->decoder;
	//
    //    std::vector<float> tempBuffer(frameCount * decoder.outputChannels);
    //    ma_decoder_read_pcm_frames(&decoder, tempBuffer.data(), frameCount, NULL);
	//
    //    // Mix this voice's audio into the mix buffer
    //    for (size_t i = 0; i < tempBuffer.size(); ++i) {
    //        mixBuffer[i] += tempBuffer[i];
    //    }
    //}