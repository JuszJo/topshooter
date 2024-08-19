#include "GameObjects.h"

struct Game {
    int* screenWidth;
    int* screenHeight;

    // GAME Entities
    GameEntities gameEntities;
};

Game createGame() {
    Game game;

    Entity square = createSquare();
    Entity enemy = createEnemy();

    game.gameEntities.player.push_back(square);
    game.gameEntities.enemies.push_back(enemy);

    return game;
}

void GameUpdate(Game& game) {
    playerShoot(game.gameEntities.player.at(0), game.gameEntities.bullets);

    for(Entity& player : game.gameEntities.player) {
        updateSquare(&game.gameEntities.player.at(0));
    }

    for(Entity& enemy : game.gameEntities.enemies) {
        updateEnemy(&enemy);
    }

    for(Bullet& bullet : game.gameEntities.bullets) {
        updateBullet(bullet);
    }

    // TODO: (MAYBE) PUT IN RESPECTIVE ENTITIES UPDATE METHOD
    
    checkWallCollision(game.gameEntities);

    collisionUpdate(game.gameEntities);

    removeInactive(game.gameEntities);

    // printf("b size: %d\n", game.gameEntities.bullets.size());
}

void GameRender(Game& game, GLuint shaderProgram) {
    std::vector<RenderEntity> renderEntities;

    for(Entity& player : game.gameEntities.player) {
        applyTransform(&player);

        RenderEntity renderEntity = createRenderEntity(player.gameObjectType, player.color, player.model, player.VAO);

        renderEntities.push_back(renderEntity);
    }
    
    for(Entity& enemy : game.gameEntities.enemies) {
        applyTransform(&enemy);

        RenderEntity renderEntity = createRenderEntity(enemy.gameObjectType, enemy.color, enemy.model, enemy.VAO);

        renderEntities.push_back(renderEntity);
    }

    for(Bullet& bullet : game.gameEntities.bullets) {
        applyTransform(&bullet.entity);

        RenderEntity renderEntity = createRenderEntity(bullet.entity.gameObjectType, bullet.entity.color, bullet.entity.model, bullet.entity.VAO);

        renderEntities.push_back(renderEntity);
    }

    for(RenderEntity renderEntity : renderEntities) {
        int modelLocation = glGetUniformLocation(shaderProgram, "model");
        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(renderEntity.model));

        int colorLocation = glGetUniformLocation(shaderProgram, "color");
        glUniform3fv(colorLocation, 1, glm::value_ptr(renderEntity.color));

        glBindVertexArray(renderEntity.VAO);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
}