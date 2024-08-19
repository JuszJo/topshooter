Entity createSquare() {
    Entity entity = createEntity(GameObjectType::PLAYER, 30.0f, 30.0f, glm::vec3(0.0f, 0.0f, 0.0f));

    entity.glAttributes.stride = 3;
    entity.glAttributes.offset = 0;

    genGLAttributes(&entity);

    return entity;
}

void updateSquare(Entity* square) {
    resetTransform(square);
    
    if(key.w) {
        square->velocity.y = 4.0f;
    }
    if(key.s) {
        square->velocity.y = -4.0f;
    }
    if(key.a) {
        square->velocity.x = -4.0f;
    }
    if(key.d) {
        square->velocity.x = 4.0f;
    }
    if(!key.a && !key.d) {
        square->velocity.x = 0.0f;
    }
    if(!key.w && !key.s) {
        square->velocity.y = 0.0f;
    }

    float mag = std::sqrt((square->velocity.x * square->velocity.x + square->velocity.y * square->velocity.y));

    if(mag > 4.0f) {
        float nx = square->velocity.x / mag;
        float ny = square->velocity.y / mag;

        float fx = nx * 4;
        float fy = ny * 4;

        square->velocity.x = fx;
        square->velocity.y = fy;
    }

    // mag = std::sqrt((square->velocity.x * square->velocity.x + square->velocity.y * square->velocity.y));

    // printf("x: %f, y: %f mag: %f\n", square->velocity.x, square->velocity.y, mag);

    square->position.x += square->velocity.x;
    square->position.y += square->velocity.y;
}