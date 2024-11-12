#define MINIAUDIO_IMPLEMENTATION
#define _USE_MATH_DEFINES

#include "Engine.h"

	// --------------------------------------------------------------------------------------------
    // NEXT STEPS:
    // 1. load audio file
	// 2. play audio file using realtime audio callback
	// 3. load audio in an event frame (just one for now)
	// 4. Throw Audio callback into AudioThread class
    // 5. Play multiple audio files with multiple voices
	// --------------------------------------------------------------------------------------------

int main(void)
{
	// Initialise EventBase class. This will change and be initialised in a future application class
	Engine engine; 
    engine.run(); // needs to be moved into while loop when code has been moved to Engine
	
    return 0;
}

