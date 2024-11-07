#pragma once

/// <Data Manager Summary>
/// ==========================================================
/// For simplicity, classes 
/// 
/// This class contains all the data that needs to be passed
/// on from Budget to the classes it needs to communicate the
/// given threshold to.
/// 
/// It also contains all the data on memory and CPU usage from
/// all the other classes which need to be sent to the Budget
/// class.
/// 
/// This way the engine is avoiding circular dependencies and
/// this class can act as a "Core class" that contains getters
/// and setters updating the information provided.
/// 
/// This class is initialised by the Engine class.
/// 
/// ==========================================================
/// </Data Manager Summary>

class DataManager
{
};

