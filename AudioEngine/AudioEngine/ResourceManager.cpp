#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "ResourceManager.init function called\n" << std::endl;
    std::cout << "--------------------------------------" << std::endl;


}

ResourceManager::~ResourceManager()
{
}

std::shared_ptr<AudioAsset> ResourceManager::getAsset(const std::string& assetName) // string parameter retrieves the asset's name as a smart pointer
{
	// check and see if the assetName exists within cache
	auto iterator = assetCache.find(assetName); // search for the audio asset within the cache 
	if (iterator != assetCache.end()) // if the iterator has not reached the end of the `assetCache` 
		return iterator->second; // then the assetName has been found and can be returned

	// if the assetName doesn't exist in cache then load a new asset
	auto newAsset = std::make_shared<AudioAsset>(assetName); 
	if (!newAsset->load())
	{
		std::cerr << "Failed to load asset: " << assetName << std::endl;
		return nullptr;
	}

	assetCache[assetName] = newAsset;

	return newAsset;
}

void ResourceManager::releaseAsset(const std::string& assetName)
{
	auto iterator = assetCache.find(assetName);
	if (iterator != assetCache.end())
	{
		assetCache.erase(iterator);
	}
}

void ResourceManager::unloadUnusedAssets()
{
	for (auto aC = assetCache.begin(); aC != assetCache.end();)
	{
		if (aC != assetCache.end())
		{
			aC = assetCache.erase(aC);
		}
		else
		{
			aC++;
		}
	}
}

