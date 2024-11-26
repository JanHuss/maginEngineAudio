#include "VoiceManager.h"

#include <vector>


VoiceManager::VoiceManager(Playback* pb) : playback(pb)
{
	maxVoicesAllowed = 2;

	//for (int i = 0; i < maxVoicesAllowed; i++)
	//	voices.push_back(new Voice(playback));
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

void VoiceManager::addVoice(std::shared_ptr<Voice> voice)
{
	voices.push_back(voice);
}

void VoiceManager::render()
{
	//for (int i = 0; i < voices.size(); i++)
	//	voices[i]->render();
}

std::vector<std::shared_ptr<Voice>>& VoiceManager::getVoices()
{
	return voices;
}
