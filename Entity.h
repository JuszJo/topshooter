#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct GLAttributes {
    int stride;
    int offset;
};

struct Entity {
    GLAttributes glAttributes;
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