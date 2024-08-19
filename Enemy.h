Entity createEnemy() {
    Entity entity = createEntity(GameObjectType::ENEMY, 30.0f, 30.0f, glm::vec3(0.0f, 0.0f, 0.0f));

    entity.glAttributes.stride = 3;
    entity.glAttributes.offset = 0;

    genGLAttributes(&entity);

    setPosition(&entity, glm::vec3(200.0f, 430.0f, 0.0f));

    return entity;
}

void updateEnemy(Entity* enemy) {
    resetTransform(enemy);
    
    enemy->position.x += enemy->velocity.x;
    enemy->position.y += enemy->velocity.y;
}