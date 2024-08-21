void seekPlayer(Enemy& enemy, Entity& player) {
    if(player.position.y > 100.0f) {
        switchEnemyAttackState(enemy, EnemyAttackState::SHOOTING);
    }
    else {
        switchEnemyAttackState(enemy, EnemyAttackState::NONE);
    }

    if(
        enemy.entity.position.x + (enemy.entity.size.x) / 2.0f > player.position.x &&
        enemy.entity.position.x + (enemy.entity.size.x) / 2.0f < player.position.x + player.size.x
    ) {
        switchEnemyAttackState(enemy, EnemyAttackState::SHOOTING);
    }
}

void changeMovement(Enemy& enemy) {    
    if(enemy.enemyMovementState == EnemyMovementState::LEFT) {
        // printf("changing to right\n");
        switchEnemyMovementState(enemy, EnemyMovementState::RIGHT);
    }
    else if(enemy.enemyMovementState == EnemyMovementState::RIGHT) {
        // printf("changing to left\n");
        switchEnemyMovementState(enemy, EnemyMovementState::LEFT);
    }
    else if(enemy.enemyMovementState == EnemyMovementState::IDLE) {
        switchEnemyMovementState(enemy, EnemyMovementState::RIGHT);
    }
}

void moveEnemy(Enemy& enemy) {
    // printf("uhm: %f, jk: %f\n", enemy.elaspedEnemyMovementFrames, enemy.enemyMovementBuffer);
    // printf("jk: %f\n", enemy.enemyMovementBuffer);
    // printf("buff: %f, ef: %f, mod: %f\n", enemy.enemyMovementBuffer, enemy.elaspedEnemyMovementFrames, fmod(enemy.elaspedEnemyMovementFrames, enemy.enemyMovementBuffer));
    if(fmod(enemy.elaspedEnemyMovementFrames, enemy.enemyMovementBuffer) == 0.0f) {
        // printf("fm: %f\n", fmod(enemy.elaspedEnemyMovementFrames, enemy.enemyMovementBuffer));
        enemy.elaspedEnemyMovementFrames = 0;

        enemy.enemyMovementBuffer = floor(random(20.0f, 100.0f));

        changeMovement(enemy);
    }

    ++enemy.elaspedEnemyMovementFrames;
}
