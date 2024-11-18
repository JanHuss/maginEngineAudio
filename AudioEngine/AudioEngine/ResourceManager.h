#pragma once

#include "AudioAsset.h"

/// <ResourceManager Summary>
/// ==========================================================
/// This class handles the loading and unloading of audio 
/// assets. 
/// 
/// It will load files on request of a Voice to be ready for 
/// playback. An audio asset will only be loaded once to 
/// ensure that memory and CPU stay at a minimum. A loaded 
/// asset is triggerable by multiple Voices (i.e. footsteps, 
/// swords clashing, etc.)
/// 
/// The ResourceManager will also handle if an audio asset is
/// processed (not sure that is the right word) through
/// stream and compression/decompression.
/// 
/// ==========================================================
/// <\ResourceManager Summary>

class ResourceManager
{
private:

public:
	ResourceManager();
	~ResourceManager();

};

