// EVENTS

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

        setColor(&bullet.entity, glm::vec3(0.2f, 0.4f, 0.8f));

        setPosition(&bullet.entity, glm::vec3(x, y, 0.0f));

        // printf("created bullet, owner: %d\n", bullet.owner);

        // bullets.push_back(bullet);
        addBullet(bullet, bullets);

        // printf("size: %d\n", bullets.size());
    }

    if(!playerShootBuffer.ready) {
        updateShootBuffer(playerShootBuffer);
    }
}

void playerBulletCollision(Entity& player, Bullet& bullet) {
    // PLAYER
    setPosition(&player, glm::vec3((640.0f / 2.0f) - (player.size.x / 2.0f), 0.0f, 0.0f));

    // BULLET
    bullet.entity.active = false;
}

// ENEMY

void enemyShoot(Enemy& enemy, std::vector<Bullet>& bullets) {
    if(enemy.enemyAttackState == EnemyAttackState::SHOOTING && enemy.enemyShootBuffer.ready) {
        // printf("Shoot %f\n", enemy.enemyShootBuffer.elaspedFrames);

        enemy.enemyShootBuffer.ready = false;

        Bullet bullet = createBullet(GameObjectType::ENEMY);

        float x = enemy.entity.position.x + (enemy.entity.size.x / 2.0f) - (bullet.entity.size.x / 2.0f);
        float y = enemy.entity.position.y - 5.0f;

        setColor(&bullet.entity, glm::vec3(0.6f, 0.1f, 0.2f));

        setPosition(&bullet.entity, glm::vec3(x, y, 0.0f));

        // printf("enemy created bullet, owner: %d\n", bullet.owner);

        // bullets.push_back(bullet);
        addBullet(bullet, bullets);

        // printf("size: %d\n", bullets.size());
    }

    if(!enemy.enemyShootBuffer.ready) {
        updateShootBuffer(enemy.enemyShootBuffer);
    }
}

void enemyBulletCollision(Enemy& enemy, Bullet& bullet) {
    // ENEMY
    enemy.entity.active = false;

    // BULLET
    bullet.entity.active = false;
}


// BULLET

void bulletWallCollision(Bullet& bullet) {
    bullet.entity.active = false;
}


// LEVEL

void checkNextLevel(GameEntities& gameEntities) {
    int enemyTotal = gameEntities.enemies.size();

    if(enemyTotal == 0) {
        Level nextLevel = {++currentLevel.enemyTotal};

        currentLevel = nextLevel;

        for(int i = 0; i < nextLevel.enemyTotal; ++i) {
            Enemy enemy = createEnemy();

            gameEntities.enemies.push_back(enemy);
        }
    }
}