#pragma once

#define NULL 0

class Utils {
public:
	Utils() { }
	~Utils() { }

	static void unloadAsset(void* asset) {
		delete asset;
		asset = NULL;
	}
};