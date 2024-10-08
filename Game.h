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
    Enemy enemy = createEnemy();
    // Enemy enemy2 = createEnemy();

    // setPosition(&enemy2.entity, glm::vec3(10.0f, 430.0f, 0.0f));

    game.gameEntities.player.push_back(square);
    game.gameEntities.enemies.push_back(enemy);
    // game.gameEntities.enemies.push_back(enemy2);

    return game;
}

// TODO: NEW GAME IDEA
// INSTEAD OF SHOOTER TYPE
// MAKE DOGDGING BULLETS TYPE WITH TIMERS
// GIVE PLAYER 3 LIVES
// WHEN TIMER ELAPSES REFILL AND MAKE NEXT LEVEL MORE DIFFICULT
// MAYBE ADD BOOSTS AFTER FINISHING LEVEL

void GameUpdate(Game& game) {
    // printf("player before shoot: %d\n", game.gameEntities.bullets.size());
    //playerShoot(game.gameEntities.player.at(0), game.gameEntities.bullets);
    // printf("player after shoot: %d\n", game.gameEntities.bullets.size());

    for(Entity& player : game.gameEntities.player) {
        updateSquare(&game.gameEntities.player.at(0));
    }

    for(Enemy& enemy : game.gameEntities.enemies) {
        moveEnemy(enemy);

        // printf("enemy before shoot: %d\n", game.gameEntities.bullets.size());
        enemyShoot(enemy, game.gameEntities.bullets);
        // printf("enemy after shoot: %d\n", game.gameEntities.bullets.size());

        seekPlayer(enemy, game.gameEntities.player.at(0));

        updateEnemy(&enemy);
    }

    for(Bullet& bullet : game.gameEntities.bullets) {
        updateBullet(bullet);
    }

    // TODO: (MAYBE) PUT IN RESPECTIVE ENTITIES UPDATE METHOD
    
    checkWallCollision(game.gameEntities);

    collisionUpdate(game.gameEntities);

    /* for(Bullet bullet : game.gameEntities.bullets) {
        printf("ENUM: %d\n\n", bullet.owner);
    } */

    removeInactive(game.gameEntities);

    checkNextLevel(game.gameEntities);

    // printf("b size: %d\n", game.gameEntities.bullets.size());
}

void GameRender(Game& game, GLuint shaderProgram) {
    std::vector<RenderEntity> renderEntities;

    for(Entity& player : game.gameEntities.player) {
        applyTransform(&player);

        RenderEntity renderEntity = createRenderEntity(player.gameObjectType, player.color, player.model, player.VAO);

        renderEntities.push_back(renderEntity);
    }
    
    for(Enemy& enemy : game.gameEntities.enemies) {
        applyTransform(&enemy.entity);

        RenderEntity renderEntity = createRenderEntity(enemy.entity.gameObjectType, enemy.entity.color, enemy.entity.model, enemy.entity.VAO);

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
