struct Bullet {
    Entity entity;
    GameObjectType owner;
};

Bullet createBullet() {
    Bullet bullet;

    bullet.entity.glAttributes.stride = 3;
    bullet.entity.glAttributes.offset = 0;

    bullet.entity.gameObjectType = BULLET;

    bullet.entity.size = glm::vec2(10.0f, 10.0f);
    bullet.entity.position = glm::vec3(0.0f, 0.0f, 0.0f);
    bullet.entity.velocity = glm::vec3(0.0f, 0.0f, 0.0f);
    bullet.entity.color = glm::vec3(0.0f, 0.0f, 0.0f);
    bullet.entity.model = glm::mat4(1.0f);

    bullet.entity.vertices = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(bullet.entity.size.x, 0.0f, 0.0f),
        glm::vec3(0.0f, bullet.entity.size.y, 0.0f),
        glm::vec3(bullet.entity.size.x, bullet.entity.size.y, 0.0f),
    };

    genGLAttributes(&bullet.entity);

    return bullet;
}