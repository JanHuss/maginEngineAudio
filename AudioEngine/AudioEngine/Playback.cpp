#include "Playback.h"


Playback::Playback()
{
	init();

	ma_device_config deviceConfig = ma_device_config_init(ma_device_type_playback); // initialise device
	deviceConfig.playback.format   = ma_format_f32;   // Set to ma_format_unknown to use the device's native format.
    deviceConfig.playback.channels = 2;               // Set to 0 to use the device's native channel count.
    deviceConfig.sampleRate        = 48000;           // Set to 0 to use the device's native sample rate.
    deviceConfig.dataCallback      = audioCallback;   // This function will be called when miniaudio needs more data.
    //config.pUserData         = pMyCustomData;   // Can be accessed from the device object (device.pUserData).
	

}

Playback::~Playback()
{
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

void Playback::audioCallback(ma_device* device, void* output, const void* input, ma_uint32 frameCount)
{
	float* out = (float*)output;
    for (ma_uint32 i = 0; i < frameCount; ++i) {
        if (bufferReadIndex < audioBuffer.size()) {
            out[i] = audioBuffer[bufferReadIndex++]; // Read data from buffer
        } else {
            out[i] = 0.0f; // Silence if the buffer is empty
        }
    }
}