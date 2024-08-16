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
    for(Entity& player : game.player) {
        int modelLocation = glGetUniformLocation(shaderProgram, "model");
        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(player.model));

        int colorLocation = glGetUniformLocation(shaderProgram, "color");
        glUniform3fv(colorLocation, 1, glm::value_ptr(player.color));

        glBindVertexArray(player.VAO);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
}