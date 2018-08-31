//
//  main.cpp
//  OpenGL4Test
//
//  Created by Rafael Radkowski on 5/28/15.
//  Copyright (c) 2015 -. All rights reserved.
//

// stl include
#include <iostream>
#include <string>

// GLEW include
#include <GL/glew.h>

// GLM include files
#define GLM_FORCE_INLINE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


// glfw includes
#include <GLFW/glfw3.h>


// include local files
#include "controls.h"
#include "HCI557Common.h"


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




/// Camera control matrices
glm::mat4 projectionMatrix; // Store the projection matrix
glm::mat4 viewMatrix; // Store the view matrix
glm::mat4 modelMatrix; // Store the model matrix

//- Define points and function to set verticies by point
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
void setVector(float* points, int i, int pti)
{
    int index = 3*i;
    points[index] = pts[pti][0];
    points[index + 1] = pts[pti][1];
    points[index + 2] = pts[pti][2];
}


// The handle to the window object
GLFWwindow*         window;


// Define some of the global variables we're using for this sample
GLuint program;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Fill this functions with your model code.

// USE THESE vertex array objects to define your objects
unsigned int vaoID[2];


/*!
 ADD YOUR CODE TO CREATE THE TRIANGLE STRIP MODEL TO THIS FUNCTION
 */
unsigned int createTriangleStripModel(void)
{
    // use the vertex array object vaoID[0] for this model representation
    int nVertices = 15;
    int nCmpts = nVertices*3;
    float *vertices = new float[nCmpts];  // Vertices for our square
    float *colors = new float[nCmpts]; // Colors for our vertices
    setVector(vertices, 0, 5);
    setVector(vertices, 1, 13);
    setVector(vertices, 2, 2);
    setVector(vertices, 3, 10);
    setVector(vertices, 4, 3);
    setVector(vertices, 5, 11);
    setVector(vertices, 6, 0);
    setVector(vertices, 7, 8);
    setVector(vertices, 8, 1);
    setVector(vertices, 9, 9);
    setVector(vertices, 10, 4);
    setVector(vertices, 11, 12);
    setVector(vertices, 12, 7);
    setVector(vertices, 13, 15);
    setVector(vertices, 14, 6);
    setVector(vertices, 15, 14);
    setVector(vertices, 16, 5);
    setVector(vertices, 17, 13);


    //- bottom surface
    nVertices = 9
    nCmpts = nVertices*3
    vertices = new float[nCmpts];  // Vertices for our square
    colors = new float[nCmpts]; // Colors for our vertices

    setVector(vertices, 0, 1);
    setVector(vertices, 1, 0);
    setVector(vertices, 2, 4);
    setVector(vertices, 3, 3);
    setVector(vertices, 4, 7);
    setVector(vertices, 5, 6);
    setVector(vertices, 6, 3);
    setVector(vertices, 7, 5);
    setVector(vertices, 8, 2);

    //- top surfaces
    nVertices = 15
    nCmpts = nVertices*3
    vertices = new float[nCmpts];  // Vertices for our square
    colors = new float[nCmpts]; // Colors for our vertices
    setVector(vertices, 0, 13);
    setVector(vertices, 1, 10);
    setVector(vertices, 2, 14);
    setVector(vertices, 3, 11);
    setVector(vertices, 4, 18);
    setVector(vertices, 5, 14);
    setVector(vertices, 6, 19);
    setVector(vertices, 7, 15);
    setVector(vertices, 8, 17);
    setVector(vertices, 9, 12);
    setVector(vertices, 10, 9);
    setVector(vertices, 11, 17);
    setVector(vertices, 12, 8);
    setVector(vertices, 13, 16);
    setVector(vertices, 14, 11);

    //TODO:
    vaoID[0];

    return 1;
}

/*!
 ADD YOUR CODE TO CREATE A MODEL USING PRIMITIVES OF YOUR CHOISE TO THIS FUNCTION
 */


unsigned int createMyModel(void)
{
    // use the vertex array object vaoID[1] for this model representation
    int nVertices = 15;
    int nCmpts = nVertices*3;
    float *vertices = new float[nCmpts];  // Vertices for our square
    float *colors = new float[nCmpts]; // Colors for our vertices

    //     //- Triangles
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


    //TODO:
    vaoID[1];

    return 1;
}



/*!
 ADD YOUR CODE TO RENDER THE TRIANGLE STRIP MODEL TO THIS FUNCTION
 */
void renderTriangleStripModel(void)
{


}

/*!
 ADD YOUR CODE TO RENDER YOUR MODEL TO THIS FUNCTION
 */
void renderMyModel(void)
{



}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*!
 This function creates the two models
 */
void setupScene(void) {

    createTriangleStripModel();
    createMyModel();

}




int main(int argc, const char * argv[])
{

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// Init glfw, create a window, and init glew

    // Init the GLFW Window
    window = initWindow();


    // Init the glew api
    initGlew();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// The Shader Program starts here

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

    // We'll specify that we want to use this program that we've attached the shaders to.
    glUseProgram(program);

    //// The Shader Program ends here
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /// IGNORE THE NEXT PART OF THIS CODE
    /// IGNORE THE NEXT PART OF THIS CODE
    /// IGNORE THE NEXT PART OF THIS CODE
    // It controls the virtual camera

    // Set up our green background color
    static const GLfloat clear_color[] = { 0.6f, 0.7f, 1.0f, 1.0f };
    static const GLfloat clear_depth[] = { 1.0f, 1.0f, 1.0f, 1.0f };


    projectionMatrix = glm::perspective(1.1f, (float)800 / (float)600, 0.1f, 100.f);
    modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)); // Create our model matrix which will halve the size of our model
    viewMatrix = glm::lookAt(glm::vec3(1.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    int projectionMatrixLocation = glGetUniformLocation(program, "projectionMatrix"); // Get the location of our projection matrix in the shader
    int viewMatrixLocation = glGetUniformLocation(program, "viewMatrix"); // Get the location of our view matrix in the shader
    int modelMatrixLocation = glGetUniformLocation(program, "modelMatrix"); // Get the location of our model matrix in the shader


    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projectionMatrix[0][0]); // Send our projection matrix to the shader
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // Send our view matrix to the shader
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader


    glBindAttribLocation(program, 0, "in_Position");
    glBindAttribLocation(program, 1, "in_Color");

    //// The Shader Program ends here
    //// START TO READ AGAIN
    //// START TO READ AGAIN
    //// START TO READ AGAIN
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    // this creates the scene
    setupScene();



    // Enable depth test
    // ignore this line, it allows us to keep the distance value after we proejct each object to a 2d canvas.
    glEnable(GL_DEPTH_TEST);

    // This is our render loop. As long as our window remains open (ESC is not pressed), we'll continue to render things.
    while(!glfwWindowShouldClose(window))
    {

        // Clear the entire buffer with our green color (sets the background to be green).
        glClearBufferfv(GL_COLOR , 0, clear_color);
        glClearBufferfv(GL_DEPTH , 0, clear_depth);




        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //// This generate the object
        // Enable the shader program
        glUseProgram(program);

        // this changes the camera location
        glm::mat4 rotated_view = viewMatrix * trackball.getRotationMatrix();
        glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &rotated_view[0][0]); // send the view matrix to our shader

        // This moves the model to the right
        modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(2.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader

        renderTriangleStripModel();

        // This moves the model to the left
        modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-2.0f, -0.0f, 0.0f));
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader

        renderMyModel();


        glUseProgram(0);
        //// This generate the object
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        // Swap the buffers so that what we drew will appear on the screen.
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    // Program clean up when the window gets closed.
    glDeleteVertexArrays(2, vaoID);
    glDeleteProgram(program);
}

