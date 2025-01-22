#include "Engine.h"

Engine::Engine()
{
    // initialise libraries, classes and parameters
	
    // Pointer initialisation
    playback = new Playback();
    eventManager = new EventManager(playback);
	uI = new UI(eventManager);
    resourceManager = new ResourceManager();

    enterPressed = false;

    init();
    loadSound();
}

Engine::~Engine()
{
   uI = nullptr;
   delete uI;
   
   eventManager = nullptr;
   delete eventManager;

   resourceManager = nullptr;
   delete resourceManager;

   playback = nullptr;
   delete playback;

   std::cout << "*****************************" << std::endl;
   std::cout << "--- Shutting down engine ---" << std::endl;
   std::cout << "*****************************" << std::endl;
}

void Engine::init()
{
    std::cout << "-----------------------------" << std::endl;
	std::cout << "Engine Init function called\n" << std::endl;
    std::cout << "Playback address check: " << playback << std::endl;
    std::cout << "-----------------------------" << std::endl;


    eventManager->init();
	
	// MiniAudio Initialise
    miniAudioInitialise();
	// GLFW initialise
    glfwInitialise();
	// Dear ImGui initialise
	imguiInitialise();

    playback->init();
    playback->start();

    // assign audio to voice
    std::shared_ptr<AudioAsset> asset = resourceManager->getAsset("assets/audio/BigWave.wav");
    auto voice = std::make_shared<Voice>(asset);

    eventManager->getEvents()[0]->voiceManager->addVoice(voice);
    playback->registerVoice(voice);
    eventManager->getEvents()[0]->voiceManager->getVoices()[0]->play();
	
	//asset = resourceManager->getAsset("assets/audio/TrapDoor.wav");
	//voice = std::make_shared<Voice>(asset);
	//eventManager->getEvents()[0]->voiceManager->addVoice(voice);
	//playback->registerVoice(voice);
	//eventManager->getEvents()[0]->voiceManager->getVoices()[1]->play();
}

int Engine::run()
{
    try // try block for error handling - if an error occurs, the catch block will be executed
		// VERY new to this method but I find it interesting and useful for error handling
    {  
    std::cout << "----------------------------------" << std::endl;
	std::cout << "Calling Engine.run()" << std::endl;
	std::cout << "----------------------------------" << std::endl;

    //handleAssets();
    
    // Loop that displays all UI information and allows for changes to parameters during runtime
	while (!glfwWindowShouldClose(window)) 
    {
	    glClearColor(0.07f, 0.13f, 0.17f, 1.0f); // sets window colour. not important really
        glClear(GL_COLOR_BUFFER_BIT);
        // Update functions here. pass through delta time as dt if needed
		
        // Render here
		uI->renderEngineFrame(); 	
        eventManager->render();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
	
       //if (glfwGetKey(window, GLFW_KEY_ENTER) && !enterPressed)
       //{
       //    enterPressed = true;
       //    std::cout << "Enter was pressed" << std::endl;
       //    playbackStart();
       //}

		// Close applicaiton
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
    }

    //playbackStop();
	//Pa_Terminate(); 
    playback->stop();
	// Cleanup ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

	// Cleanup GLFW
	glfwDestroyWindow(window);
    glfwTerminate();
    }
    catch  (const std::runtime_error &e)
    {
		// Exeption handling
		std::cerr << "Exeption handling - An error occurred: " << e.what() << std::endl;

		// Cleanup if an error occurs
        //Pa_Terminate(); // PortAudio
		ImGui_ImplOpenGL3_Shutdown(); // ImGui possibly need to add these back in for cleanup later
		ImGui_ImplGlfw_Shutdown();  // ImGui
		ImGui::DestroyContext(); // ImGui
		glfwTerminate(); // GLFW

		return -1;
    }

	return 0;
}

//int Engine::portAudioInitialise()
//{
//    // PortAudio Initialise
//	PaError err = Pa_Initialize();
//    paTestData data = { 0 };  // Initialize phase data for the sine wave
//
//
//    if (err != paNoError) {
//        std::cout << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
//        return InitialisationError;
//    }
//	std::cout << "- Library check ---------------------------------------------------" << std::endl;
//    std::cout << "PortAudio initialized successfully!" << std::endl;
//
//	// Display PortAudio version
//	std::cout << "PortAudio version: " << Pa_GetVersionText() << std::endl;
//}

void Engine::miniAudioInitialise()
{
    // MiniAudio message
	std::cout << "MiniAudio installed" << std::endl;
	std::cout << "MiniAudio version: " << MA_VERSION_STRING << std::endl;
	std::cout << "-------------------------------------------------------------------\n" << std::endl;
}

int Engine::glfwInitialise()
{
    // Initialize the library 
    if (!glfwInit())
        return InitialisationError;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Audio Engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return InitialisationError;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
   
	gladLoadGL();

	glViewport(0, 0, 640, 480);

	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
    return 0;
}

void Engine::imguiInitialise()
{
    IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void Engine::loadSound()
{
    // load an asset in the resource manager
    auto asset = resourceManager->getAsset("assets/audio/BigWave.wav");

    if (asset && asset->isLoaded())
        std::cout << "Sound 1 loaded" << std::endl;

    // assign an asset to a voice
    //assetName = "Big Wave";
    //eventManager->getEvents()[0]->voiceManager->getVoices()[0]->assignVoice(assetName, asset);

 //// load an asset in the resource manager
 //asset = resourceManager->getAsset("assets/audio/TrapDoor.wav");
 //assetName = "TrapDoor";
 //if (asset && asset->isLoaded())
 //    std::cout << "Sound 2 loaded" << std::endl;
 //// assign an asset to a voice
 //eventManager->getEvents()[0]->voiceManager->getVoices()[1]->assignVoice(assetName, asset);
}

//int Engine::playbackInitialise()
//{
//    std::cout << "----------------------------------------" << std::endl;
//	std::cout << "Calling playback->initialise from engine" << std::endl;
//	std::cout << "----------------------------------------" << std::endl;
//    // initialise playback with desired audio settings
//    if (!playback->initialize(2, ma_format_f32, 44100)) {
//        return -1;
//    }
//    return 0;
//}

//void Engine::playbackRegister()
//{
//    std::cout << "------------------------------------------------------------------------------------" << std::endl;
//	std::cout << "Calling registerWithPlayback from engine and passing through *playback: " << playback << std::endl;
//	std::cout << "------------------------------------------------------------------------------------" << std::endl;
//    eventManager->getEvents()[0]->voiceManager->getVoices()[0]->registerWithPlayback(*playback);
//}

//int Engine::playbackStart()
//{
//    std::cout << "-----------------------------------" << std::endl;
//	std::cout << "Calling playback->start from engine" << std::endl;
//	std::cout << "-----------------------------------" << std::endl;
//    // Start playback
//    if (!playback->start()) {
//        return -1;
//    }
//    return 0;
//}

//void Engine::playbackStop()
//{
//    std::cout << "-----------------------------------" << std::endl;
//	std::cout << "Calling playback->stop from engine" << std::endl;
//	std::cout << "-----------------------------------" << std::endl;
//    // Stop playback
//    playback->stop();
//}

//void Engine::handleAssets()
//{
//    //loadSound();
//
//    playbackInitialise();
//
//    playbackRegister();
//
//    playbackStart();
//}
