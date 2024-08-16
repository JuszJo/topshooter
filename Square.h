#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>


#include "Entity.h"

// struct Entity {
//     GLAttributes glAttributes;
//     std::vector<glm::vec3> vertices;
//     glm::vec3 position;
//     glm::vec3 velocity;
//     glm::vec3 color;
//     glm::mat4 model;
//     GLuint VAO, VBO, EBO;
// };

Entity createSquare() {
    Entity entity;

    entity.glAttributes.stride = 3;
    entity.glAttributes.offset = 0;

    entity.position = glm::vec3(0.0f, 0.0f, 0.0f);
    entity.velocity = glm::vec3(0.0f, 0.0f, 0.0f);
    entity.color = glm::vec3(0.0f, 0.0f, 0.0f);
    entity.model = glm::mat4(1.0f);

    entity.vertices = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(20.0, 0.0f, 0.0f),
        glm::vec3(0.0f, 20.0f, 0.0f),
        glm::vec3(20.0f, 20.0f, 0.0f),
    };

    genGLAttributes(&entity);

    return entity;
}

// VALIDATION & ERROR CHECKING

void printVec3(const char* name, glm::vec3 vec) {
    std::cout << name << ": " << vec.x << " " << vec.y << " " << vec.z << "\n";
}

void printMat4(const char* name, glm::mat4 mat) {
    std::cout << name << ": " << glm::to_string(mat) << "\n";
}

void entityPrintValues(Entity entity) {
    printVec3("Position", entity.position);
    printVec3("Velocity", entity.velocity);
    printVec3("Color", entity.color);
    printMat4("model", entity.model);

    for(glm::vec3 vertex : entity.vertices) {
        printVec3("Vertex Data", vertex);
    }
}

/* void setColor(Circle* circle, glm::vec3 newColor) {
    circle->color = newColor;
}

void setPosition(Circle* circle, glm::vec3 newPosition) {
    circle->position = newPosition;
}

void setVelocity(Circle* circle, glm::vec3 newVelocity) {
    circle->velocity = newVelocity;
}

void applyTransform(Circle* circle) {
    circle->model = glm::translate(circle->model, circle->position);
}

void resetTransform(Circle* circle) {
    circle->model = glm::mat4(1.0f);
} */