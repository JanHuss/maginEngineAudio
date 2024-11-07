#pragma once

/// <Buffer Manager Summary>
/// ==========================================================
/// This class manages a pool of buffers using an object pool
/// design pattern. This way the memory and CPU can stay at a
/// minimum by recycling code.
/// 
/// The idea is to create a "Dynmamic Buffer System" in which 
/// a set amount of buffers will be initialised on start up.
/// This class will recieve "real" Voice data from the Voice
/// class. Depending on the length of the Voice data, a buffer
/// will be "checked out" from the pool and Voice data will be
/// fed into the assigned buffer which will be in a seperate 
/// thread. 
/// 
/// Once the Voice stops making use of the buffer, the buffer
/// will be notified and returned to the available pool of 
/// buffers.
/// 
/// NOTE OF CAUTION:	It is important that the buffer is 
///						always larger than what the Sound card
///						is requesting. Otherwise the assigned 
///						buffer will not be able to keep up and 
///						create inconsistencies during playback
///						resulting in glitches, stutters or 
///						silence between buffer loads.					
/// 
/// ==========================================================
/// </Buffer Manager Summary>

class BufferManager
{
};

