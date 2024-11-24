#include "Playback.h"


Playback::Playback()
{
	init();

	//ma_device_config deviceConfig = ma_device_config_init(ma_device_type_playback); // initialise device
	//deviceConfig.playback.format   = decoder.outputFormat;   // Set to ma_format_unknown to use the device's native format.
    //deviceConfig.playback.channels = decoder.outputChannels;               // Set to 0 to use the device's native channel count.
    //deviceConfig.sampleRate        = decoder.outputSampleRate;           // Set to 0 to use the device's native sample rate.
    //deviceConfig.dataCallback      = audioCallback;   // This function will be called when miniaudio needs more data.
    //deviceConfig.pUserData         = &decoder;   // Can be accessed from the device object (device.pUserData).
	
    isInitialised = false;
}

Playback::~Playback()
{
     if (isInitialised) {
            ma_device_uninit(&device);
        }
}

int Playback::init()
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Calling Playback.init()" << std::endl;
	std::cout << "----------------------------------" << std::endl;


	if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS) 
	{
		std::cout << "----------------------------------" << std::endl;
		std::cout << "failed to initialise device" << std::endl;
		std::cout << "----------------------------------" << std::endl;
		return -1;  // Failed to initialize the device.
    }
	ma_device_start(&device); // The device is sleeping by default so you'll need to start it manually.

    // Do something here. Probably your program's main loop.

    ma_device_uninit(&device);
    return 0;
}

void Playback::audioCallback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
	//ma_decoder* pDecoder = (ma_decoder*) device->pUserData;
	//
	//std::vector<float>buffer(frameCount * pDecoder->outputChannels);
	//
	//ma_decoder_read_pcm_frames(pDecoder, buffer.data(), frameCount, NULL);
	//
	//memcpy(output, buffer.data(), frameCount * pDecoder->outputChannels * sizeof(float));

    //std::cout << "----------------------------------" << std::endl;
    //std::cout << "Calling Playback.audioCallback() device: " << pDevice->sampleRate << std::endl;
    //std::cout << "Calling Playback.audioCallback() pOutput: " << pOutput << std::endl;
	//std::cout << "Calling Playback.audioCallback() framecount: " << frameCount << std::endl;
	//std::cout << "----------------------------------" << std::endl;


	Playback* playback = (Playback*)pDevice->pUserData;  // Retrieve Playback instance
        playback->mixAudioBuffer((float*)pOutput, frameCount);
}

// Mix audio data from all registered voices
    void Playback::mixAudioBuffer(float* output, ma_uint32 frameCount) 
    {
        if (activeVoices.empty()) 
        {
        // Output silence if no voices are active
        memset(output, 0, frameCount * sizeof(float));
        return;
        }

        // Clear the mix buffer (assumed to be pre-allocated)
        std::fill(mixBuffer.begin(), mixBuffer.end(), 0.0f);

        // Mix audio from each voice
        for (Voice* voice : activeVoices) 
        {
            voice->processAudio(mixBuffer, frameCount);  // Delegate audio processing to Voice
        }

        // Copy the mixed audio data to the output buffer
        std::memcpy(output, mixBuffer.data(), frameCount * activeVoices[0]->getChannels() * sizeof(float));

    }

    // Initialize playback device
    bool Playback::initialize(int channels, ma_format format, ma_uint32 sampleRate) 
    {
        std::cout << "----------------------------------" << std::endl;
	    std::cout << "Calling Playback.initialise() channels: " << channels << std::endl;
        std::cout << "Calling Playback.initialise() format: " << format << std::endl;
        std::cout << "Calling Playback.initialise() initialise: " << sampleRate << std::endl;
	    std::cout << "----------------------------------" << std::endl;

        ma_device_config deviceConfig = ma_device_config_init(ma_device_type_playback);
        deviceConfig.playback.format = format;
        deviceConfig.playback.channels = channels;
        deviceConfig.sampleRate = sampleRate;
        deviceConfig.dataCallback = audioCallback;
        deviceConfig.pUserData = this;

        if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS) {
            std::cerr << "Failed to initialize playback device." << std::endl;
            return false;
        }

        isInitialised = true;
        return true;
    }

    // Start playback
    bool Playback::start() 
    {
        std::cout << "----------------------------------" << std::endl;
	    std::cout << "Calling playback->start" << std::endl;
	    std::cout << "----------------------------------" << std::endl;
        if (!isInitialised) return false;
            return ma_device_start(&device) == MA_SUCCESS;
    }

    // Stop playback
    void Playback::stop() 
    {
        if (isInitialised) ma_device_stop(&device);
    }

    // Register a voice for playback
    void Playback::registerVoice(Voice* voice) 
    {
        activeVoices.push_back(voice);
    }

    // Unregister a voice
    void Playback::unregisterVoice(Voice* voice) 
    {
        std::lock_guard<std::mutex> lock(voiceMutex);
        activeVoices.erase(std::remove(activeVoices.begin(), activeVoices.end(), voice), activeVoices.end());
    }