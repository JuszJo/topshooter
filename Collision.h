// struct Game;

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

void checkWallCollision(GameEntities& gameEntities) {
    for(Entity& player : gameEntities.player) {
        // printf("x: %f, y: %f\n", entity.x, entity.y);
        if(player.position.x < 0.0f) {
            player.position.x = 0.0f;
        }
        if(player.position.x + player.size.x > 640.0f) {
            player.position.x = 640.0f - player.size.x;
        }
        if(player.position.y < 0.0f) {
            player.position.y = 0.0f;
        }
        if(player.position.y + player.size.y > 480.0f) {
            player.position.y = 480.0f - player.size.y;
        }
    }

    for(Bullet& bullet : gameEntities.bullets) {
        // printf("x: %f, y: %f\n", entity.x, entity.y);
        if(bullet.entity.position.x < 0.0f) {
            bullet.entity.position.x = 0.0f;
        }
        if(bullet.entity.position.x + bullet.entity.size.x > 640.0f) {
            bullet.entity.position.x = 640.0f - bullet.entity.size.x;
        }
        if(bullet.entity.position.y < 0.0f) {
            bullet.entity.position.y = 0.0f;
        }
        if(bullet.entity.position.y + bullet.entity.size.y > 480.0f) {
            // bullet.entity.position.y = 480.0f - bullet.entity.size.y;
            bulletWallCollision(bullet);
        }
    }
}

/* void resolveCollision(CollisionEntity& entity1, CollisionEntity& entity2, GameEntities& gameEntities) {
    std::map<GameObjectType, bool> collisionMap;

    collisionMap[entity1.gameObjectType] = true;
    collisionMap[entity2.gameObjectType] = true;

    if(collisionMap[GameObjectType::PLAYER] && collisionMap[GameObjectType::BULLET]) {
        playerBulletCollision(entity1, gameEntities);
        playerBulletCollision(entity2, gameEntities);
    }
} */

void collisionUpdate(GameEntities& gameEntities) {
    // PLAYER BULLET
    for(Entity& player : gameEntities.player) {
        for(Bullet& bullet : gameEntities.bullets) {
            float x1 = player.position.x;
            float y1 = player.position.y;
            float w1 = player.size.x;
            float h1 = player.size.y;

            float x2 = bullet.entity.position.x;
            float y2 = bullet.entity.position.y;
            float w2 = bullet.entity.size.x;
            float h2 = bullet.entity.size.y;
            
            bool collisionOccured = didCollide(x1, y1, w1, h1, x2, y2, w2, h2);

            if(collisionOccured) {
                playerBulletCollision(player, bullet);
            }
        }
    }
}