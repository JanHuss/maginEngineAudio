#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


int main(void)
{


    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Audio Engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
   
	gladLoadGL();

	glViewport(0, 0, 640, 480);

	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
	    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

		ImGui::Begin("Engine"); // shouldn't be able to see the title bar
		ImGui::SetWindowSize(ImVec2(640, 500));
		ImGui::SetWindowPos(ImVec2(0, -20)); // hide the title bar with a negative y value
		ImGui::Text("Build Event here");
		ImGui::End();

        //ImGui::ShowDemoWindow(); // Show demo window! :)
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

	glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}