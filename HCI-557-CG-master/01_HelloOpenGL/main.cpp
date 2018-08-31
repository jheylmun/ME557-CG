//
//  main.cpp
//  OpenGL4Test
//
//  Created by Rafael Radkowski on 5/28/15.
//  Copyright (c) 2015 -. All rights reserved.
//

// stl include
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

// GLEW include
#include <GL/glew.h>

// GLM include files
#define GLM_FORCE_INLINE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


// glfw includes
#include <GLFW/glfw3.h>


using namespace std;

static const string vs_string =
    "#version 410 core                                                 \n"
    "                                                                   \n"
    "uniform mat4 projectionMatrix;                                    \n"
    "uniform mat4 viewMatrix;                                           \n"
    "uniform mat4 modelMatrix;                                          \n"
    "in vec3 in_Position;                                               \n"
    "                                                                   \n"
    "in vec3 in_Color;                                                  \n"
    "out vec3 pass_Color;                                               \n"
    "                                                                  \n"
    "void main(void)                                                   \n"
    "{                                                                 \n"
    "    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_Position, 1.0);  \n"
    "    pass_Color = in_Color;                                         \n"
    "}                                                                 \n";

// Fragment shader source code. This determines the colors in the fragment generated in the shader pipeline. In this case, it colors the inside of our triangle specified by our vertex shader.
static const string fs_string  =
    "#version 410 core                                                 \n"
    "                                                                  \n"
    "in vec3 pass_Color;                                                 \n"
    "out vec4 color;                                                    \n"
    "void main(void)                                                   \n"
    "{                                                                 \n"
    "    color = vec4(pass_Color, 1.0);                               \n"
    "}                                                                 \n";


glm::mat4 projectionMatrix; // Store the projection matrix
glm::mat4 viewMatrix; // Store the view matrix
glm::mat4 modelMatrix; // Store the model matrix

static glm::vec3 pts[20] =
{
    glm::vec3(2.0, 0.0, 0.0),
    glm::vec3(3.0, 0.0, 0.0),
    glm::vec3(0.0, 2.0, 0.0),
    glm::vec3(2.0, 2.0, 0.0),
    glm::vec3(3.0, 2.0, 0.0),
    glm::vec3(0.0, 3.0, 0.0),
    glm::vec3(2.0, 3.0, 0.0),
    glm::vec3(3.0, 3.0, 0.0),
    glm::vec3(2.0, 0.0, 1.0),
    glm::vec3(3.0, 0.0, 1.0),
    glm::vec3(0.0, 2.0, 1.0),
    glm::vec3(2.0, 2.0, 1.0),
    glm::vec3(3.0, 2.0, 1.0),
    glm::vec3(0.0, 3.0, 1.0),
    glm::vec3(2.0, 3.0, 1.0),
    glm::vec3(3.0, 3.0, 1.0),
    glm::vec3(2.0, 2.0, 2.0),
    glm::vec3(3.0, 2.0, 2.0),
    glm::vec3(2.0, 3.0, 2.0),
    glm::vec3(3.0, 3.0, 2.0)
};


// Define some of the global variables we're using for this sample
GLuint program;
GLuint vao;

unsigned int vaoID[1]; // Our Vertex Array Object

unsigned int vboID[2]; // Our Vertex Buffer Object


// This is the callback we'll be registering with GLFW for errors.
// It'll just print out the error to the STDERR stream.
void error_callback(int error, const char* description) {
    fputs(description, stderr);
}


// This is the callback we'll be registering with GLFW for keyboard handling.
// The only thing we're doing here is setting up the window to close when we press ESC
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void setVector(float* points, int i, int pti)
{
    int index = 3*i;
    points[index] = pts[pti][0];
    points[index + 1] = pts[pti][1];
    points[index + 2] = pts[pti][2];
}

void createSquare(void)
{
    int nVertices = 108;
    int nCmpts = nVertices*3;
    float *vertices = new float[nCmpts];  // Vertices for our square
    float *colors = new float[nCmpts]; // Colors for our vertices

//     vertices[0] = -0.5; vertices[1] = -0.5; vertices[2] = 0.5; // Bottom left corner
//     colors[0] = 1.0; colors[1] = 1.0; colors[2] = 1.0; // Bottom left corner
//
//     vertices[3] = -0.5; vertices[4] = 0.5; vertices[5] = 0.5; // Top left corner
//     colors[3] = 1.0; colors[4] = 0.0; colors[5] = 0.0; // Top left corner
//
//     vertices[6] = 0.5; vertices[7] = 0.5; vertices[8] = 0.5; // Top Right corner
//     colors[6] = 0.0; colors[7] = 1.0; colors[8] = 0.0; // Top Right corner
//
//     vertices[9] = 0.5; vertices[10] = -0.5; vertices[11] = 0.5; // Bottom right corner
//     colors[9] = 0.0; colors[10] = 0.0; colors[11] = 1.0; // Bottom right corner
//
//     vertices[12] = -0.5; vertices[13] = -0.5; vertices[14] = 0.5; // Bottom left corner
//     colors[12] = 1.0; colors[13] = 1.0; colors[14] = 1.0; // Bottom left corner
//
//     vertices[15] = 0.5; vertices[16] = 0.5; vertices[17] = 0.5; // Top Right corner
//     colors[15] = 0.0; colors[16] = 1.0; colors[17] = 0.0; // Top Right corner

    //- bottom walls
//     setVector(vertices, 0, 5);
//     setVector(vertices, 1, 13);
//     setVector(vertices, 2, 2);
//     setVector(vertices, 3, 10);
//     setVector(vertices, 4, 3);
//     setVector(vertices, 5, 11);
//     setVector(vertices, 6, 0);
//     setVector(vertices, 7, 8);
//     setVector(vertices, 8, 1);
//     setVector(vertices, 9, 9);
//     setVector(vertices, 10, 4);
//     setVector(vertices, 11, 12);
//     setVector(vertices, 12, 7);
//     setVector(vertices, 13, 15);
//     setVector(vertices, 14, 6);
//     setVector(vertices, 15, 14);
//     setVector(vertices, 16, 5);
//     setVector(vertices, 17, 13);
//
//     //- bottom surface
//     setVector(vertices, 0, 1);
//     setVector(vertices, 1, 0);
//     setVector(vertices, 2, 4);
//     setVector(vertices, 3, 3);
//     setVector(vertices, 4, 7);
//     setVector(vertices, 5, 6);
//     setVector(vertices, 6, 3);
//     setVector(vertices, 7, 5);
//     setVector(vertices, 8, 2);
//
//     //- top surfaces
//     setVector(vertices, 0, 13);
//     setVector(vertices, 1, 10);
//     setVector(vertices, 2, 14);
//     setVector(vertices, 3, 11);
//     setVector(vertices, 4, 18);
//     setVector(vertices, 5, 14);
//     setVector(vertices, 6, 19);
//     setVector(vertices, 7, 15);
//     setVector(vertices, 8, 17);
//     setVector(vertices, 9, 12);
//     setVector(vertices, 10, 9);
//     setVector(vertices, 11, 17);
//     setVector(vertices, 12, 8);
//     setVector(vertices, 13, 16);
//     setVector(vertices, 14, 11);

    //- Triangles
    setVector(vertices, 0, 5);
    setVector(vertices, 1, 13);
    setVector(vertices, 2, 2);
    setVector(vertices, 3, 13);
    setVector(vertices, 4, 2);
    setVector(vertices, 5, 10);
    setVector(vertices, 6, 2);
    setVector(vertices, 7, 10);
    setVector(vertices, 8, 3);
    setVector(vertices, 9, 3);
    setVector(vertices, 10, 11);
    setVector(vertices, 11, 0);
    setVector(vertices, 12, 0);
    setVector(vertices, 13, 11);
    setVector(vertices, 14, 8);
    setVector(vertices, 15, 0);
    setVector(vertices, 16, 1);
    setVector(vertices, 17, 8);
    setVector(vertices, 18, 1);
    setVector(vertices, 19, 8);
    setVector(vertices, 20, 9);
    setVector(vertices, 21, 1);
    setVector(vertices, 22, 9);
    setVector(vertices, 23, 4);
    setVector(vertices, 24, 9);
    setVector(vertices, 25, 4);
    setVector(vertices, 26, 12);
    setVector(vertices, 27, 4);
    setVector(vertices, 28, 12);
    setVector(vertices, 29, 7);
    setVector(vertices, 30, 7);
    setVector(vertices, 31, 12);
    setVector(vertices, 32, 15);
    setVector(vertices, 33, 7);
    setVector(vertices, 34, 15);
    setVector(vertices, 35, 6);
    setVector(vertices, 36, 6);
    setVector(vertices, 37, 15);
    setVector(vertices, 38, 14);
    setVector(vertices, 39, 6);
    setVector(vertices, 40, 14);
    setVector(vertices, 41, 5);
    setVector(vertices, 42, 5);
    setVector(vertices, 43, 14);
    setVector(vertices, 44, 13);
    setVector(vertices, 105, 3);
    setVector(vertices, 106, 11);
    setVector(vertices, 107, 10);

    setVector(vertices, 45, 2);
    setVector(vertices, 46, 5);
    setVector(vertices, 47, 3);
    setVector(vertices, 48, 3);
    setVector(vertices, 49, 5);
    setVector(vertices, 50, 6);

    setVector(vertices, 51, 3);
    setVector(vertices, 52, 6);
    setVector(vertices, 53, 4);
    setVector(vertices, 54, 4);
    setVector(vertices, 55, 6);
    setVector(vertices, 56, 7);

    setVector(vertices, 57, 0);
    setVector(vertices, 58, 3);
    setVector(vertices, 59, 1);
    setVector(vertices, 60, 1);
    setVector(vertices, 61, 3);
    setVector(vertices, 62, 4);

    setVector(vertices, 63, 10);
    setVector(vertices, 64, 13);
    setVector(vertices, 65, 14);
    setVector(vertices, 66, 10);
    setVector(vertices, 67, 14);
    setVector(vertices, 68, 11);

    setVector(vertices, 69, 8);
    setVector(vertices, 70, 16);
    setVector(vertices, 71, 11);
    setVector(vertices, 72, 11);
    setVector(vertices, 73, 16);
    setVector(vertices, 74, 18);
    setVector(vertices, 75, 11);
    setVector(vertices, 76, 18);
    setVector(vertices, 77, 14);
    setVector(vertices, 78, 18);
    setVector(vertices, 79, 14);
    setVector(vertices, 80, 19);
    setVector(vertices, 81, 14);
    setVector(vertices, 82, 15);
    setVector(vertices, 83, 19);
    setVector(vertices, 84, 19);
    setVector(vertices, 85, 15);
    setVector(vertices, 86, 17);
    setVector(vertices, 87, 15);
    setVector(vertices, 88, 17);
    setVector(vertices, 89, 12);
    setVector(vertices, 90, 12);
    setVector(vertices, 91, 17);
    setVector(vertices, 92, 9);

    setVector(vertices, 93, 8);
    setVector(vertices, 94, 17);
    setVector(vertices, 95, 9);
    setVector(vertices, 96, 8);
    setVector(vertices, 97, 16);
    setVector(vertices, 98, 17);
    setVector(vertices, 99, 16);
    setVector(vertices, 100, 18);
    setVector(vertices, 101, 19);
    setVector(vertices, 102, 16);
    setVector(vertices, 103, 19);
    setVector(vertices, 104, 17);



    for (int i = 0; i < nCmpts; i++)
    {
        colors[i] = 1.0f;
        vertices[i] /= 10.0f;
    }
    for (int i = 0; i < nVertices; i++)
    {
        std::cout
            << vertices[i*3] << ", "
            << vertices[i*3 + 1] << ", "
            << vertices[i*3 + 2] << "\n";
    }
    std::cout<<pts[13][0]<<"\n";
    glGenVertexArrays(2, &vaoID[0]); // Create our Vertex Array Object
    glBindVertexArray(vaoID[0]); // Bind our Vertex Array Object so we can use it


    glGenBuffers(2, vboID); // Generate our Vertex Buffer Object

    // vertices
    glBindBuffer(GL_ARRAY_BUFFER, vboID[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, nCmpts*sizeof(GLfloat), vertices, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW

    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Disable our Vertex Array Object


    //Color
    glBindBuffer(GL_ARRAY_BUFFER, vboID[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, nCmpts*sizeof(GLfloat), colors, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW

    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array

    glBindVertexArray(0); // Disable our Vertex Buffer Object


    delete [] vertices; // Delete our vertices from memory
}


void setupScene(void) {
    createSquare();
}




int main(int argc, const char * argv[])
{
    // Initialize GLFW, and if it fails to initialize for any reason, print it out to STDERR.
    if (!glfwInit()) {
        fprintf(stderr, "Failed initialize GLFW.");
        exit(EXIT_FAILURE);
    }

    // Set the error callback, as mentioned above.
    glfwSetErrorCallback(error_callback);

    // Set up OpenGL options.
    // Use OpenGL verion 4.1,
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    // GLFW_OPENGL_FORWARD_COMPAT specifies whether the OpenGL context should be forward-compatible, i.e. one where all functionality deprecated in the requested version of OpenGL is removed.
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // Indicate we only want the newest core profile, rather than using backwards compatible and deprecated features.
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Make the window resize-able.
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a window to put our stuff in.
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello OpenGL", NULL, NULL);

    // If the window fails to be created, print out the error, clean up GLFW and exit the program.
    if(!window) {
        fprintf(stderr, "Failed to create GLFW window.");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Use the window as the current context (everything that's drawn will be place in this window).
    glfwMakeContextCurrent(window);

    // Set the keyboard callback so that when we press ESC, it knows what to do.
    glfwSetKeyCallback(window, key_callback);

    printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));

    // Makes sure all extensions will be exposed in GLEW and initialize GLEW.
    glewExperimental = GL_TRUE;
    glewInit();

    // Shaders is the next part of our program. Notice that we use version 410 core. This has to match our version of OpenGL we are using, which is the core profile in version 4.1, thus 410 core.

    // Vertex shader source code. This draws the vertices in our window. We have 3 vertices since we're drawing an triangle.
    // Each vertex is represented by a vector of size 4 (x, y, z, w) coordinates.
    static const string vertex_code = vs_string;
    static const char * vs_source = vertex_code.c_str();

    // Fragment shader source code. This determines the colors in the fragment generated in the shader pipeline. In this case, it colors the inside of our triangle specified by our vertex shader.
    static const string fragment_code = fs_string;
    static const char * fs_source = fragment_code.c_str();

    // This next section we'll generate the OpenGL program and attach the shaders to it so that we can render our triangle.
    program = glCreateProgram();

    // We create a shader with our fragment shader source code and compile it.
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fs_source, NULL);
    glCompileShader(fs);

    // We create a shader with our vertex shader source code and compile it.
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vs_source, NULL);
    glCompileShader(vs);

    // We'll attach our two compiled shaders to the OpenGL program.
    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);

    // Generate vertex arrays for our program. More explanation on this will come in the future.
    //glGenVertexArrays(1, &vao);
    //glBindVertexArray(vao);

    // We'll specify that we want to use this program that we've attached the shaders to.
    glUseProgram(program);


    // Set up our green background color
    static const GLfloat clear_color[] = { 0.6f, 0.7f, 1.0f, 1.0f };



    projectionMatrix = glm::perspective(1.57f, (float)800 / (float)600, 0.1f, 100.f);
   // viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.f)); // Create our view matrix which will translate us back 5 units
    modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)); // Create our model matrix which will halve the size of our model
    viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, -1.f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    int projectionMatrixLocation = glGetUniformLocation(program, "projectionMatrix"); // Get the location of our projection matrix in the shader
    int viewMatrixLocation = glGetUniformLocation(program, "viewMatrix"); // Get the location of our view matrix in the shader
    int modelMatrixLocation = glGetUniformLocation(program, "modelMatrix"); // Get the location of our model matrix in the shader


    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projectionMatrix[0][0]); // Send our projection matrix to the shader
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // Send our view matrix to the shader
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader



    setupScene();
    glBindAttribLocation(program, 0, "in_Position");
    glBindAttribLocation(program, 1, "in_Color");


    // This is our render loop. As long as our window remains open (ESC is not pressed), we'll continue to render things.
    while(!glfwWindowShouldClose(window))
    {

        // Clear the entire buffer with our green color (sets the background to be green).
        glClearBufferfv(GL_COLOR, 0, clear_color);

        // Draw our triangles
        //glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(program);

        glBindVertexArray(vaoID[0]); // Bind our Vertex Array Object

        glDrawArrays(GL_TRIANGLES, 0, 108); // Draw our square should be 6 for cube

        glBindVertexArray(0); // Unbind our Vertex Array Object

        glUseProgram(0);

        // Swap the buffers so that what we drew will appear on the screen.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Program clean up when the window gets closed.
    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(program);
}

