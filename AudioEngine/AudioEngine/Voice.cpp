#include "Voice.h"

Voice::Voice()
{
	init();
}

Voice::~Voice()
{
}

void Voice::init()
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Calling Voice.init()" << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

void Voice::assignVoice(std::shared_ptr<AudioAsset> asset)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Calling Voice.assignVoice()" << std::endl;
	std::cout << "Asset variable address in Voice: " << asset << std::endl;
	auto loadedSound = asset;
	std::cout << "Getting asset frames: " << loadedSound->getTotalFrames() << std::endl;
	std::cout << "Getting asset channels: " << loadedSound->getChannels() << std::endl;
	std::cout << "Getting asset sample rate: " << loadedSound->getSampleRate() << std::endl;
	std::cout << "----------------------------------" << std::endl;

}

void Voice::render()
{
}
