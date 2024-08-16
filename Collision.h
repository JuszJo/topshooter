 bool didCollide(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
    if(
        x1 + w1 > x2 &&
        x1 < x2 + w2 &&
        y1 + h1 > y2 &&
        y1 < y2 + h2
    ) {
        return true;
    }
    else {
        return false;
    }
}

void checkWallCollision(std::vector<CollisionEntity>& collisionEntities) {
    for(CollisionEntity& entity : collisionEntities) {
        // printf("x: %f, y: %f\n", entity.x, entity.y);
        if(entity.x < 0.0f) {
            entity.x = 0.0f;
        }
        if(entity.x + entity.width > 640.0f) {
            entity.x = 640.0f - entity.width;
        }
        if(entity.y < 0.0f) {
            entity.y = 0.0f;
        }
        if(entity.y + entity.height > 480.0f) {
            entity.y = 480.0f - entity.height;
        }
    }
}