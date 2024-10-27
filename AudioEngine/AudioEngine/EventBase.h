#pragma once
#include "imgui.h"

class EventBase
{


public:
	EventBase(/*Pass through imgui pointer to this class*/);
	~EventBase();

	void Update();
	void Render();
};

