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

ShootBuffer playerShootBuffer = {20.0f, 0.0f, true};

void playerShoot(Entity& player, std::vector<Bullet>& bullets) {
    if(key.space && playerShootBuffer.ready) {
        // printf("Shoot %f\n", playerShootBuffer.elaspedFrames);

        playerShootBuffer.ready = false;

        Bullet bullet = createBullet(GameObjectType::PLAYER);

        float x = player.position.x + (player.size.x / 2.0f) - (bullet.entity.size.x / 2.0f);
        float y = player.position.y + player.size.y + 5.0f;

        setPosition(&bullet.entity, glm::vec3(x, y, 0.0f));

        bullets.push_back(bullet);
    }

    if(!playerShootBuffer.ready) {
        updateShootBuffer(playerShootBuffer);
    }
}

void playerBulletCollision(Entity& player, Bullet& bullet) {
    // PLAYER
    setPosition(&player, glm::vec3(0.0f, 0.0f, 0.0f));

    // BULLET
    bullet.entity.active = false;
}

// ENEMY

void enemyShoot() {
    
}


// BULLET

void bulletWallCollision(Bullet& bullet) {
    bullet.entity.active = false;
}