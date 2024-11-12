#define _USE_MATH_DEFINES
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

//#include <portaudio.h>
#include <stdio.h>
#define MINIAUDIO_IMPLEMENTATION
//#include "miniaudio.h"
#include <math.h>
#include <iostream>
#include <vector>

#include "Engine.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Define PortAudio callback function for streaming audio data to the sound card ------------
typedef int PaStreamCallback (const void* input, // points to incoming audio data
	                          void* output, // points to the buffer where to write the outgoing audio data
	                          unsigned long frameCount, // number of frames the sound card is requesting
	                          const PaStreamCallbackTimeInfo* timeInfo, // provides time information for the current audio callback
	                          PaStreamCallbackFlags statusFlags, // contains flags that indicate whether input and/or output buffers have been inserted or will be dropped
	                          void* userData); // A custom pointer that is passed to the callback function
// -----------------------------------------------------------------------------------------
	// --------------------------------------------------------------------------------------------
    // NEXT STEPS:
    // 1. load audio file
	// 2. play audio file using realtime audio callback
	// 3. load audio in an event frame (just one for now)
	// 4. Throw Audio callback into AudioThread class
    // 5. Play multiple audio files with multiple voices
	// --------------------------------------------------------------------------------------------

// This needs to be removed and replaced with a class that will handle the audio callback ---------
// Load audio file
void loadAudio(const char* filename, // name of audio file
	std::vector<float>& audioData, // file's audio data
	ma_uint64& totalFrames, // total number of frames in the audio file (determines the length of the audio file)
	ma_uint32& channels, // number of channels the audio file uses
	ma_uint32& sampleRate) // audio file's sample rate
{
	ma_result result; // varible that checks if operation was successful or not
	ma_decoder decoder; // variable that decodes the audio file

	// Initialize decoder 
    result = ma_decoder_init_file(filename, NULL, &decoder);
    if (result != MA_SUCCESS)
    {
		    std::cerr << "Failed to initialize decoder while loading: " << filename 
              << ". Error code: " << result << std::endl;
            return;
	}

	if (result = ma_decoder_get_length_in_pcm_frames(&decoder, &totalFrames)) // get the total number of frames in the audio file
    {
        std::cerr << "Failed to initialize audio file: " << filename 
              << ". Error code: " << result << std::endl;
            return;
    }

	channels = decoder.outputChannels; // set channels to the number of channels in the audio file
	sampleRate = decoder.outputSampleRate; // set sample rate to the audio file's sample rate

	// Resize audio data buffer to fit the audio data
    audioData.resize(totalFrames * channels);		
    
    // Prepare buffer for audio data
    std::cout << "- Audio data check within loadAudio function ----------------------" << std::endl;
	std::cout << "File loaded: " << filename << std::endl;
	std::cout << "Total frames in loadAudio: " << totalFrames << std::endl;
	std::cout << "Channels in loadAudio: " << channels << std::endl;
	std::cout << "Sample rate in loadAudio: " << sampleRate << std::endl;
	std::cout << "Audio data size in loadAudio: " << audioData.size() << std::endl;
    std::cout << "-------------------------------------------------------------------\n" << std::endl;

    // Read audio data from audio file into buffer
	result = ma_decoder_read_pcm_frames(&decoder, audioData.data(), totalFrames, &totalFrames);
	if (result != MA_SUCCESS)
	{
        std::cerr << "Failed to read PCM frames" << std::endl;
		ma_decoder_uninit(&decoder);
        return;
    }

	// Cleanup decoder
	ma_decoder_uninit(&decoder);
}

	
//// create test wave. I'm keeping this just in case ------------------------------
//typedef struct {
//    float left_phase;
//    float right_phase;
//} paTestData;

static int paWaveCallback(const void *inputBuffer, void *outputBuffer,
                          unsigned long framesPerBuffer,
                          const PaStreamCallbackTimeInfo* timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData) {
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;

    const float frequency = 440.0f;
	const float sampleRate = 44100.0f;

	// Generate a simple sine wave
    for (i = 0; i < framesPerBuffer; i++) {
        // Calculate the sine wave for the left and right channels
        *out++ = 0.5f * sinf(data->left_phase * 2.0f * M_PI * frequency);  // Left channel
        *out++ = 0.5f * sinf(data->right_phase * 2.0f * M_PI * frequency); // Right channel

        // Increment the phase for the sine wave
        data->left_phase += 1.0f / sampleRate; // Increment phase for left channel
        data->right_phase += 1.0f / sampleRate; // Increment phase for right channel

        // Optionally wrap around the phase to avoid overflow
        if (data->left_phase >= 1.0f) data->left_phase -= 1.0f;
        if (data->right_phase >= 1.0f) data->right_phase -= 1.0f;
    }
	//Pa_Sleep(1000); // Sleep for 1 second
    
	//// Generate a simple saw wave
    //for (i = 0; i < framesPerBuffer; i++) {
    //    *out++ = data->left_phase;  // Left channel
    //    *out++ = data->right_phase; // Right channel
    //
    //    // Simple phase increment (for saw wave example)
    //    data->left_phase += 0.01f;
    //    data->right_phase += 0.01f;
    //
    //    if (data->left_phase >= 1.0f) data->left_phase -= 2.0f;
    //    if (data->right_phase >= 1.0f) data->right_phase -= 2.0f;
    //}
    return paContinue;
}
// -----------------------------------------------------------------------

int main(void)
{
	try // try block for error handling - if an error occurs, the catch block will be executed
		// VERY new to this method but I find it interesting and useful for error handling
    {   
		// Initialise EventBase class. This will change and be initialised in a future application class
		Engine engine; 
        engine.init();
        engine.run(); // needs to be moved into while loop when code has been moved to Engine
	    // PortAudio initialization and test ----------------------------------------------------------
        //PaError err = Pa_Initialize();
        //paTestData data = { 0 };  // Initialize phase data for the sine wave
        //
        //
        //if (err != paNoError) {
        //    std::cout << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
        //    return -1;
        //}
		//std::cout << "- Library check ---------------------------------------------------" << std::endl;
        //std::cout << "PortAudio initialized successfully!" << std::endl;
        //
		//// Display PortAudio version
		//std::cout << "PortAudio version: " << Pa_GetVersionText() << std::endl;

        //// MiniAudio message
		//std::cout << "MiniAudio installed" << std::endl;
		//std::cout << "MiniAudio version: " << MA_VERSION_STRING << std::endl;
		//std::cout << "-------------------------------------------------------------------\n" << std::endl;
        
		// Create audio data variables
		std::vector<float> audioData;
        ma_uint64 totalFrames = 0;
		ma_uint32 channels = 0;
		ma_uint32 sampleRate = 0;

		// Load audio file
		const char* fileName = "assets/audio/BigWave.wav"; // set file path here
		loadAudio(fileName, audioData, totalFrames, channels, sampleRate);
		// Check if audio file loaded successfully
		if (!audioData.empty())
        {
		    std::cout << "Loaded audio file in main: " << fileName << std::endl;
		    std::cout << "Total frames in main: " << totalFrames << std::endl;
            std::cout << "Channels in main: " << channels << std::endl;
            std::cout << "Sample rate in main: " << sampleRate << std::endl;
        }


	    //// Open an audio stream
	    //PaStream* stream;
	    //err = Pa_OpenDefaultStream(&stream, 0, 2, paFloat32, 44100, 256, paWaveCallback, &data);
        //
	    //if (err != paNoError) throw std::runtime_error(Pa_GetErrorText(err));
        //
	    //// Start the stream
	    //err = Pa_StartStream(stream);
	    //if (err != paNoError) throw std::runtime_error(Pa_GetErrorText(err));
	
        // --------------------------------------------------------------------------------------------
       
	    // GLFW initialization and test ---------------------------------------------------------------
        GLFWwindow* window;

        // Initialize the library 
        if (!glfwInit())
            return -1;

        // Create a windowed mode window and its OpenGL context
        window = glfwCreateWindow(640, 480, "Audio Engine", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        // Make the window's context current
        glfwMakeContextCurrent(window);
   
	    gladLoadGL();

	    glViewport(0, 0, 640, 480);

	    glClear(GL_COLOR_BUFFER_BIT);
	    glfwSwapBuffers(window);

	    // Dear ImGui initialization ------------------------------------------------------------------
	    IMGUI_CHECKVERSION();
	    ImGui::CreateContext();
	    ImGuiIO& io = ImGui::GetIO(); (void)io;
	    ImGui::StyleColorsDark();
	    ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");
	    // --------------------------------------------------------------------------------------------
        // Dear ImGui image loading

        
		// Simulate an error for testing the catch block
        // throw std::runtime_error("Artificial error for testing catch block");

        // Loop until the user closes the window 
        while (!glfwWindowShouldClose(window))
        {
	        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
            // Render here
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

			engine.render(); // core application

            //ImGui::ShowDemoWindow(); // Show demo window! :)
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	

            // Swap front and back buffers
            glfwSwapBuffers(window);

            // Poll for and process events
            glfwPollEvents();
	
			// Close applicaiton
            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);
        }

		// Cleanup and Close PortAudio to free resources
	    //Pa_StopStream(stream);
	    //Pa_CloseStream(stream);
        Pa_Terminate(); 

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
        Pa_Terminate(); // PortAudio
		ImGui_ImplOpenGL3_Shutdown(); // ImGui possibly need to add these back in for cleanup later
		ImGui_ImplGlfw_Shutdown();  // ImGui
		ImGui::DestroyContext(); // ImGui
		glfwTerminate(); // GLFW

		return -1;
    }
    return 0;
}

