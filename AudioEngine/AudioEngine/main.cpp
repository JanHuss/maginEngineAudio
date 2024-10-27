#define _USE_MATH_DEFINES
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <portaudio.h>
#include <math.h>
#include <iostream>
#include <vector>

#include "EventBase.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Create PortAudio callback function for streaming audio data to the sound card ------------
typedef int PaStreamCallback (const void* input, // points to incoming audio data
	                          void* output, // points to the buffer where to write the outgoing audio data
	                          unsigned long frameCount, // number of frames the sound card is requesting
	                          const PaStreamCallbackTimeInfo* timeInfo, // provides time information for the current audio callback
	                          PaStreamCallbackFlags statusFlags, // contains flags that indicate whether input and/or output buffers have been inserted or will be dropped
	                          void* userData); // A custom pointer that is passed to the callback function
// -----------------------------------------------------------------------------------------
	
// create test wave. I'm keeping this just in case for testing ------------------------------
typedef struct {
    float left_phase;
    float right_phase;
} paTestData;

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
		std::vector<EventBase> events;

	    // PortAudio initialization and test ----------------------------------------------------------
        PaError err = Pa_Initialize();
        paTestData data = { 0 };  // Initialize phase data for the sine wave

        if (err != paNoError) {
            std::cout << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
            return -1;
        }
        std::cout << "PortAudio initialized successfully!" << std::endl;


	    // Open an audio stream
	    PaStream* stream;
	    err = Pa_OpenDefaultStream(&stream, 0, 2, paFloat32, 44100, 256, paWaveCallback, &data);

	    if (err != paNoError) throw std::runtime_error(Pa_GetErrorText(err));

	    // Start the stream
	    err = Pa_StartStream(stream);
	    if (err != paNoError) throw std::runtime_error(Pa_GetErrorText(err));
	
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

			// Engine Frame
		    ImGui::Begin("Engine"); // shouldn't be able to see the title bar
		    ImGui::SetWindowSize(ImVec2(640, 500));
		    ImGui::SetWindowPos(ImVec2(0, -20)); // hide the title bar with a negative y value
		    ImGui::Text("Build Event here");
			// Buttons for the engine frame here -----------------------------------------------------



            // Adding Events to vector when button is pressed ----------------------------------------
			if(ImGui::Button("Add Event"))
			{
				// Add event to engine frame
				events.push_back(EventBase());
				//std::cout << "Amount of events called: " << events.size() << std::endl;
			}
            if (!events.empty()) 
            {
                for (auto& ev : events)
			        ev.Render();
            }
            // --------------------------------------------------------------------------------------

			

		    ImGui::End();
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

        // Cleanup PortAudio
	    Pa_StopStream(stream);
	    Pa_CloseStream(stream);
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

