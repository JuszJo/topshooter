void seekPlayer(Entity& enemy, Entity& player) {
    if(player.position.y > 100.0f) {
        switchEnemyAttackState(EnemyAttackState::SHOOTING);
    }
    else {
        switchEnemyAttackState(EnemyAttackState::NONE);
    }

    if(
        enemy.position.x + (enemy.size.x) / 2.0f > player.position.x &&
        enemy.position.x + (enemy.size.x) / 2.0f < player.position.x + player.size.x
    ) {
        switchEnemyAttackState(EnemyAttackState::SHOOTING);
    }
}

float enemyMovementBuffer = floor(random(20.0f, 100.0f));
float elaspedEnemyMovementFrames = 0.0f;

void changeMovement() {    
    if(enemyMovementState == EnemyMovementState::LEFT) {
        // printf("changing to right\n");
        enemyMovementState = EnemyMovementState::RIGHT;
    }
    else if(enemyMovementState == EnemyMovementState::RIGHT) {
        // printf("changing to left\n");
        enemyMovementState = EnemyMovementState::LEFT;
    }
    else if(enemyMovementState == EnemyMovementState::IDLE) {
        enemyMovementState = EnemyMovementState::RIGHT;
    }
}

void moveEnemy() {
    // printf("uhm: %f, jk: %f\n", elaspedEnemyMovementFrames, enemyMovementBuffer);
    // printf("jk: %f\n", enemyMovementBuffer);
    // printf("buff: %f, ef: %f, mod: %f\n", enemyMovementBuffer, elaspedEnemyMovementFrames, fmod(elaspedEnemyMovementFrames, enemyMovementBuffer));
    if(fmod(elaspedEnemyMovementFrames, enemyMovementBuffer) == 0.0f) {
        // printf("fm: %f\n", fmod(elaspedEnemyMovementFrames, enemyMovementBuffer));
        elaspedEnemyMovementFrames = 0;

        enemyMovementBuffer = floor(random(20.0f, 100.0f));

        changeMovement();
    }

    ++elaspedEnemyMovementFrames;
}
