#include "Playback.h"


Playback::Playback()
{
   
}

Playback::~Playback()
{
    stop(); 
}

void Playback::init()
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Calling Playback.init()" << std::endl;
	std::cout << "----------------------------------" << std::endl;

    // Configuring playback device
    // comments are from miniaudio documentation. change when playback functional
	ma_device_config deviceConfig = ma_device_config_init(ma_device_type_playback); // initialise device
	deviceConfig.playback.format   = ma_format_f32;   // Set to ma_format_unknown to use the device's native format.
    deviceConfig.playback.channels = 2;               // Set to 0 to use the device's native channel count.
    deviceConfig.sampleRate        = 44100;           // Set to 0 to use the device's native sample rate.
    deviceConfig.dataCallback      = Playback::audioCallback;   // This function will be called when miniaudio needs more data.
    deviceConfig.pUserData         = this;   // Can be accessed from the device object (device.pUserData).


    if(ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS)
    {
        std::cout << "----------------------------------" << std::endl;
        std::cerr << "Failed to initialise playback device" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        return;
    }

}

void Playback::audioCallback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
	auto* playback = static_cast<Playback*>(pDevice->pUserData);
    auto* out = static_cast<float*>(pOutput);

    // clear output buffer
    std::fill(out, out + (frameCount * pDevice->playback.channels), 0.0f);

    // mix audio from active voices
    for (auto& voice : playback->activeVoices)
    {
        if (!voice->isPlaying())
            continue;

        const auto& audioData = voice->getAudioData();
        ma_uint64 audioCursor = voice-> getAudioPlayhead();
        ma_uint64 totalFrames = audioData.size() / pDevice->playback.channels;

        for (ma_uint32 frame = 0; frame < frameCount; frame++)
        {
            if (audioCursor >= totalFrames)
            {
                voice->stop();
                break;
            }
            
            for (ma_uint32 channel = 0; channel < pDevice->playback.channels; channel++)
            {
                out[frame * pDevice->playback.channels +channel] += audioData[audioCursor * pDevice->playback.channels + channel];
            }
            audioCursor++;
        }
    }
}


// Register a voice for playback
void Playback::registerVoice(std::shared_ptr<Voice> voice) 
{
    activeVoices.push_back(voice);
}

// Unregister a voice
void Playback::unregisterVoice(std::shared_ptr<Voice> voice) 
{
    activeVoices.erase(std::remove(activeVoices.begin(), activeVoices.end(), voice), activeVoices.end());
}

// Start playback
void Playback::start() 
{
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Calling playback->start" << std::endl;
    std::cout << "----------------------------------" << std::endl;

    if (ma_device_start(&device) != MA_SUCCESS)
    {
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
        std::cout << "Failed to start playback device" << std::endl;
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    }

}

// Stop playback
void Playback::stop() 
{
    ma_device_uninit(&device);
}