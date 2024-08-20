Entity createEnemy() {
    Entity entity = createEntity(GameObjectType::ENEMY, 30.0f, 30.0f, glm::vec3(0.0f, 0.0f, 0.0f));

    entity.glAttributes.stride = 3;
    entity.glAttributes.offset = 0;

    genGLAttributes(&entity);

    setPosition(&entity, glm::vec3(200.0f, 430.0f, 0.0f));

    return entity;
}

enum EnemyAttackState {
    NONE,
    SHOOTING
};

enum EnemyMovementState {
    IDLE,
    LEFT,
    RIGHT
};

EnemyMovementState enemyMovementState = EnemyMovementState::IDLE;
EnemyAttackState enemyAttackState = EnemyAttackState::NONE;

void switchEnemyMovementState(EnemyMovementState movementState) {
    if(enemyMovementState != movementState) {
        enemyMovementState = movementState;
    }
}

void switchEnemyAttackState(EnemyAttackState attackState) {
    if(enemyAttackState != attackState) {
        enemyAttackState = attackState;
    }
}

// TODO: SET SHOOT VARIABLE THEN HANDLE IN EVENTS

void checkEnemyState(Entity* enemy) {
    if(enemyMovementState == EnemyMovementState::IDLE) {
        // switchEnemyMovementState(EnemyMovementState::IDLE);
        enemy->velocity.x = 0.0f;
        enemy->velocity.y = 0.0f;
    }
    else if(enemyMovementState == EnemyMovementState::LEFT) {
        // switchEnemyMovementState(EnemyMovementState::LEFT);
        enemy->velocity.x = -4.0f;
    }
    else if(enemyMovementState == EnemyMovementState::RIGHT) {
        // switchEnemyMovementState(EnemyMovementState::RIGHT);
        enemy->velocity.x = 4.0f;
    }
    
    // if(enemyAttackState == EnemyAttackState::NONE) {
    //     // switchEnemyAttackState(EnemyAttackState::IDLE);
    // }
    // else if(enemyAttackState == EnemyAttackState::SHOOTING) {
    //     // switchEnemyAttackState(EnemyAttackState::SHOOTING);
    // }
}

void updateEnemy(Entity* enemy) {
    resetTransform(enemy);

    checkEnemyState(enemy);

    enemy->position.x += enemy->velocity.x;
    enemy->position.y += enemy->velocity.y;
}