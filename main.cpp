#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include <iostream>
#include <vector>
#include <random>

// SOURCE
// #include "Entity.h"
#include "Game.h"
// #include "Square.h"



float random(float lb, float ub) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_real_distribution<float> dist(lb, std::nextafter(ub, FLT_MAX));

    float rand = dist(gen);

    return rand;
}

// glm::mat4 projection;
int screenWidth = 640;
int screenHeight = 480;

const char* vs = R"(
    #version 330 core

    layout (location = 0) in vec3 pos;

    uniform mat4 projection;
    uniform mat4 model;

    uniform vec3 color;

    out vec3 fragColor;

    void main() {
        gl_Position =  projection * model * vec4(pos, 1.0);
        fragColor = color;
    }

)";

const char* fs = R"(
    #version 330 core

    in vec3 fragColor;
    out vec4 FragColor;

    void main() {
        // FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
        FragColor = vec4(fragColor, 1.0f);
    }

)";

// Function to compile shaders
unsigned int compileShader(unsigned int type, const char* source);

// Function to create shader program
unsigned int createShaderProgram(const char* vertexSource, const char* fragmentSource);

int main() {
    GLFWwindow* window;

    if (!glfwInit()) return -1;

    window = glfwCreateWindow(screenWidth, screenHeight, "Top Down", NULL, NULL);

    if (!window) {
        glfwTerminate();

        return -1;
    }

    glfwMakeContextCurrent(window);

    // GLEW initialization code
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwTerminate();
        return -1;
    }

    GLuint shaderProgram = createShaderProgram(vs, fs);

    Game TopDownGame = createGame();

    TopDownGame.screenWidth = &screenWidth;
    TopDownGame.screenHeight = &screenHeight;

    glUseProgram(shaderProgram);

    glm::mat4 projection = glm::mat4(1.0f);

    while (!glfwWindowShouldClose(window)) {
        glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
        glViewport(0, 0, screenWidth, screenHeight);

        glfwPollEvents();
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        projection = glm::ortho(0.0f, (float)screenWidth, 0.0f, (float)screenHeight, -10.0f, 10.0f);

        int projectionLocation = glGetUniformLocation(shaderProgram, "projection");
        glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

        // UPDATE
        GameUpdate(TopDownGame);

        // RENDER
        GameRender(TopDownGame, shaderProgram);

        glfwSwapBuffers(window);

    }

    glfwTerminate();
    
    return 0;
}

unsigned int compileShader(unsigned int type, const char* source) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    // Check for compilation errors
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader compilation error:\n" << infoLog << std::endl;
    }

    return shader;
}

// Function to create shader program
unsigned int createShaderProgram(const char* vertexSource, const char* fragmentSource) {
    unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
    unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for linking errors
    int success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "Shader linking error:\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}