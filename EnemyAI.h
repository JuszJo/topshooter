void seekPlayer(Entity& enemy, Entity& player) {
    if(player.position.y > 100.0f) {
        switchEnemyAttackState(EnemyAttackState::SHOOTING);
    }
    else {
        switchEnemyAttackState(EnemyAttackState::NONE);
    }
}

float enemyMovementBuffer = floor(random(0.0f, 100.0f));
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
    if(fmod(elaspedEnemyMovementFrames, enemyMovementBuffer) == 0.0f) {
        // printf("fm: %f\n", fmod(elaspedEnemyMovementFrames, enemyMovementBuffer));
        elaspedEnemyMovementFrames = 0;

        enemyMovementBuffer = floor(random(0.0f, 100.0f));

        changeMovement();
    }

    ++elaspedEnemyMovementFrames;
}