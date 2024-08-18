// EVENTS

// TODO: MAKE MORE GENERIC
struct ShootBuffer {
    float buffer;
    float elaspedFrames;
    bool ready;
};

void updateShootBuffer(ShootBuffer& shootBuffer) {
    shootBuffer.elaspedFrames += 1.0f;

    if(shootBuffer.elaspedFrames == shootBuffer.buffer) {
        shootBuffer.ready = true;

        shootBuffer.elaspedFrames = 0.0f;
    }
}

ShootBuffer playerShootBuffer = {50.0f, 0.0f, true};

void playerShoot(std::vector<Bullet>& bullets) {
    if(key.space && playerShootBuffer.ready) {
        playerShootBuffer.ready = false;

        Bullet bullet = createBullet(GameObjectType::PLAYER);

        bullets.push_back(bullet);
    }
    else {
        updateShootBuffer(playerShootBuffer);
    }
}

void playerBulletCollision(CollisionEntity& entity, GameEntities& gameEntities) {
    if(entity.gameObjectType == GameObjectType::PLAYER) {
        for(Entity& player : gameEntities.player) {
            setPosition(&player, glm::vec3(0.0f, 0.0f, 0.0f));
        }

    }
    else {

    }
}