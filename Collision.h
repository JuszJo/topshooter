struct Game;

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

void collisionUpdate(Game& game, std::vector<CollisionEntity>& collisionEntities) {
    for(int i = 0; i < collisionEntities.size(); ++i) {
        float x1 = collisionEntities.at(i).x;
        float y1 = collisionEntities.at(i).y;
        float w1 = collisionEntities.at(i).width;
        float h1 = collisionEntities.at(i).height;

        for(int j = i + 1; j < collisionEntities.size(); ++j) {
            float x2 = collisionEntities.at(j).x;
            float y2 = collisionEntities.at(j).y;
            float w2 = collisionEntities.at(j).width;
            float h2 = collisionEntities.at(j).height;

            bool collisionOccured = didCollide(x1, y1, w1, h1, x2, y2, w2, h2);

            if(collisionOccured) {
                // printf("Collision Occured\n");
            }
        }
    }
}