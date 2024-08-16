Entity createSquare() {
    Entity entity;

    entity.glAttributes.stride = 3;
    entity.glAttributes.offset = 0;

    entity.gameObjectType = PLAYER;

    entity.size = glm::vec2(30.0f, 30.0f);
    entity.position = glm::vec3(0.0f, 0.0f, 0.0f);
    entity.velocity = glm::vec3(0.0f, 0.0f, 0.0f);
    entity.color = glm::vec3(0.0f, 0.0f, 0.0f);
    entity.model = glm::mat4(1.0f);

    entity.vertices = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(entity.size.x, 0.0f, 0.0f),
        glm::vec3(0.0f, entity.size.y, 0.0f),
        glm::vec3(entity.size.x, entity.size.y, 0.0f),
    };

    genGLAttributes(&entity);

    return entity;
}