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

void Voice::render()
{
}
