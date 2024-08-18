struct Bullet {
    Entity entity;
    GameObjectType owner;
};

Bullet createBullet(GameObjectType owner) {
    Bullet bullet;

    bullet.owner = owner;

    Entity entity = createEntity(GameObjectType::BULLET, 10.0f, 10.0f, glm::vec3(0.0f, 0.0f, 0.0f));

    bullet.entity = entity;

    bullet.entity.glAttributes.stride = 3;
    bullet.entity.glAttributes.offset = 0;

    genGLAttributes(&bullet.entity);

    setVelocity(&bullet.entity, glm::vec3(0.0f, 6.0f, 0.0f));

    return bullet;
}

void updateBullet(Bullet& bullet) {
    resetTransform(&bullet.entity);

    // entityPrintValues(bullet.entity);

    bullet.entity.position.x += bullet.entity.velocity.x;
    bullet.entity.position.y += bullet.entity.velocity.y;
}