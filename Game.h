#include "GameObjects.h"

struct Game {
    int* screenWidth;
    int* screenHeight;

    // GAME OBJECTS
    std::vector<Entity> player;
    std::vector<Bullet> bullets;
};

Game createGame() {
    Game game;

    Entity square = createSquare();

    game.player.push_back(square);

    return game;
}

void GameUpdate(Game& game) {
    updateSquare(&game.player.at(0));

    std::vector<CollisionEntity> collisionEntities;

    for(Entity& player : game.player) {
        CollisionEntity collisionEntity = createCollisionEntity(player.gameObjectType, player.position, player.size);

        collisionEntities.push_back(collisionEntity);
    }

    checkWallCollision(collisionEntities);

    applyTransform(&game.player.at(0));
}

void GameRender(Game& game, GLuint shaderProgram) {
    std::vector<RenderEntity> renderEntities;

    for(Entity& player : game.player) {
        RenderEntity renderEntity = createRenderEntity(player.gameObjectType, player.color, player.model, player.VAO);

        renderEntities.push_back(renderEntity);
    }

    for(Bullet& bullet : game.bullets) {
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