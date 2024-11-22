#include "VoiceManager.h"

VoiceManager::VoiceManager(Playback* pb) : playback(pb)
{
	maxVoicesAllowed = 2;

	for (int i = 0; i < maxVoicesAllowed; i++)
		voices.push_back(new Voice(playback));
	//init();
	//voice->init();
}

VoiceManager::~VoiceManager()
{
}

void VoiceManager::init()
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Calling VoiceManager.init()" << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

void VoiceManager::render()
{
	//for (int i = 0; i < voices.size(); i++)
	//	voices[i]->render();
}

std::vector<class Voice*> VoiceManager::getVoices()
{
	return voices;
}
