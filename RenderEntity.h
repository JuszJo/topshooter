struct RenderEntity {
    GameObjectType type;
    glm::vec3 color;
    glm::mat4 model;
    GLuint VAO;
};

RenderEntity createRenderEntity(GameObjectType type, glm::vec3 color, glm::mat4 model, GLuint VAO) {
    RenderEntity renderEntity = {type, color, model, VAO};

    return renderEntity;
}