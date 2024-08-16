#include "GameObjects.h"

struct Game {
    int* screenWidth;
    int* screenHeight;

    // GAME OBJECTS
    std::vector<Entity> player;
};

Game createGame() {
    Game game;

    Entity square = createSquare();

    game.player.push_back(square);

    return game;
}

void GameUpdate(Game game) {

}

void GameRender(Game game, GLuint shaderProgram) {
    std::vector<RenderEntity> renderEntities;

    for(Entity& player : game.player) {
        RenderEntity renderEntity = createRenderEntity(player.gameObjectType, player.color, player.model, player.VAO);

        renderEntities.push_back(renderEntity);
    }

    for(RenderEntity renderEntity : renderEntities) {
        std::cout << "Key D: " << key.d << "\n";
        
        int modelLocation = glGetUniformLocation(shaderProgram, "model");
        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(renderEntity.model));

        int colorLocation = glGetUniformLocation(shaderProgram, "color");
        glUniform3fv(colorLocation, 1, glm::value_ptr(renderEntity.color));

        glBindVertexArray(renderEntity.VAO);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
}