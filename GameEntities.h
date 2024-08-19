struct GameEntities {
    // GAME ENTITIES
    std::vector<Entity> player;
    std::vector<Entity> enemies;
    std::vector<Bullet> bullets;
};

void removeInactive(GameEntities& gameEntities) {
    // int elementsRemoved = 0;

    for(size_t i = 0; i < gameEntities.player.size(); ++i) {
        if(gameEntities.player.at(i).active == false) {
            gameEntities.player.erase(gameEntities.player.begin() + i);
            
            --i;
        }
    }

    for(size_t i = 0; i < gameEntities.enemies.size(); ++i) {
        if(gameEntities.enemies.at(i).active == false) {
            gameEntities.enemies.erase(gameEntities.enemies.begin() + i);
            
            --i;
        }
    }

    for(size_t i = 0; i < gameEntities.bullets.size(); ++i) {
        if(gameEntities.bullets.at(i).entity.active == false) {
            gameEntities.bullets.erase(gameEntities.bullets.begin() + i);
            
            --i;
        }
    }
}