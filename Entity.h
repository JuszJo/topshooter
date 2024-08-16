#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum GameObjectType {
    PLAYER,
    ENEMY
};

struct GLAttributes {
    int stride;
    int offset;
};

struct Entity {
    GLAttributes glAttributes;
    GameObjectType gameObjectType;
    std::vector<glm::vec3> vertices;
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 color;
    glm::mat4 model;
    GLuint VAO, VBO, EBO;
};

void genGLAttributes(Entity* entity) {
    glGenBuffers(1, &entity->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, entity->VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * entity->vertices.size(), &entity->vertices[0], GL_STATIC_DRAW); // FOR entity

    glGenVertexArrays(1, &entity->VAO);
    glBindVertexArray(entity->VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, entity->glAttributes.stride * sizeof(float), (void*)(entity->glAttributes.offset * sizeof(float)));
    glEnableVertexAttribArray(0);

    /* glGenBuffers(1, &entity->EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, entity->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * entity->indices.size(), &entity->indices[0], GL_STATIC_DRAW); */
}

// VALIDATION & ERROR CHECKING

void printVec3(const char* name, glm::vec3 vec) {
    std::cout << name << ": " << vec.x << " " << vec.y << " " << vec.z << "\n";
}

void printMat4(const char* name, glm::mat4 mat) {
    std::cout << name << ": " << glm::to_string(mat) << "\n";
}

void entityPrintValues(Entity entity) {
    printf("Type: %d\n", entity.gameObjectType);

    printVec3("Position", entity.position);
    printVec3("Velocity", entity.velocity);
    printVec3("Color", entity.color);
    printMat4("model", entity.model);

    for(glm::vec3 vertex : entity.vertices) {
        printVec3("Vertex Data", vertex);
    }
}