#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//framebuffer size callback (those are certianly some words) for making the program know what size the window is.
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);


int main()
{
    //Initalizing and configuring GLFW.
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    //create the window
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    //tell GLFW we want to call framebuffer_size_callback every time the window is resized.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



    //initialize GLAD. GLFW gives *glfwGetProcAddress* which defines the correct
    //funcion based on which os the program is compiled for.
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    //set dimentions of the viewport window. first 2 parameters set the location of the lower left corner
    //the last 2 parameters set the width and height in pixels.
    glViewport(0, 0, 800, 600);


    //The glfwWindowShouldClose function checks at the start of each loop iteration if GLFW has been instructed to close.
    //If so, the function returns true and the render loop stops running, after which we can close the application.

    /*
    while (!glfwWindowShouldClose(window))
    {
        //glfwSwapBuffers swaps the color buffer, which is a 2d buffer with color values for every pixel.
        glfwSwapBuffers(window);
        //The glfwPollEvents function checks if any events are triggered (like keyboard input),
        //updates the window state, and calls the corresponding functions
        glfwPollEvents();
    }
    */

    //render loop
    while (!glfwWindowShouldClose(window))
    {
        //input
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        //check and call events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }




    //clean/delete all of GLFW's resources that were allocated.
    glfwTerminate();
    return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //make sure the viewport matches the new window dimensions.
    //i dont have a retina display so i do not care.
    glViewport(0, 0, width, height);
}


void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) ==  GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}