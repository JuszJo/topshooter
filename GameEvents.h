// struct Game;

bool dont = false;

void playerShoot(std::vector<Bullet>& bullets) {
    if(key.space && !dont) {
        dont = true;
        Bullet bullet = createBullet(GameObjectType::PLAYER);

        bullets.push_back(bullet);
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