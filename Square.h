#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include "Entity.h"

Entity createSquare() {
    Entity entity;

    entity.glAttributes.stride = 3;
    entity.glAttributes.offset = 0;

    entity.gameObjectType = PLAYER;

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