enum EnemyAttackState {
    NONE,
    SHOOTING
};

enum EnemyMovementState {
    IDLE,
    LEFT,
    RIGHT
};

struct Enemy {
    Entity entity;
    float enemyMovementBuffer = floor(random(20.0f, 100.0f));
    float elaspedEnemyMovementFrames = 0.0f;
    EnemyMovementState enemyMovementState = EnemyMovementState::IDLE;
    EnemyAttackState enemyAttackState = EnemyAttackState::NONE;
    ShootBuffer enemyShootBuffer = {20.0f, 0.0f, true};
};

Enemy createEnemy() {
    Enemy enemy;

    enemy.enemyMovementBuffer = floor(random(20.0f, 100.0f));
    enemy.elaspedEnemyMovementFrames = 0.0f;
    enemy.enemyMovementState = EnemyMovementState::IDLE;
    enemy.enemyAttackState = EnemyAttackState::NONE;
    enemy.enemyShootBuffer = {20.0f, 0.0f, true};

    Entity entity = createEntity(GameObjectType::ENEMY, 30.0f, 30.0f, glm::vec3(0.0f, 0.0f, 0.0f));

    entity.glAttributes.stride = 3;
    entity.glAttributes.offset = 0;

    genGLAttributes(&entity);

    setPosition(&entity, glm::vec3(200.0f, 430.0f, 0.0f));

    enemy.entity = entity;

    return enemy;
}

void switchEnemyMovementState(Enemy& enemy, EnemyMovementState movementState) {
    if(enemy.enemyMovementState != movementState) {
        enemy.enemyMovementState = movementState;
    }
}

void switchEnemyAttackState(Enemy& enemy, EnemyAttackState attackState) {
    if(enemy.enemyAttackState != attackState) {
        enemy.enemyAttackState = attackState;
    }
}

// TODO: SET SHOOT VARIABLE THEN HANDLE IN EVENTS

void checkEnemyState(Enemy* enemy) {
    if(enemy->enemyMovementState == EnemyMovementState::IDLE) {
        // switchEnemyMovementState(EnemyMovementState::IDLE);
        enemy->entity.velocity.x = 0.0f;
        enemy->entity.velocity.y = 0.0f;
    }
    else if(enemy->enemyMovementState == EnemyMovementState::LEFT) {
        // switchEnemyMovementState(EnemyMovementState::LEFT);
        enemy->entity.velocity.x = -4.0f;
    }
    else if(enemy->enemyMovementState == EnemyMovementState::RIGHT) {
        // switchEnemyMovementState(EnemyMovementState::RIGHT);
        enemy->entity.velocity.x = 4.0f;
    }
    
    // if(enemyAttackState == EnemyAttackState::NONE) {
    //     // switchEnemyAttackState(EnemyAttackState::IDLE);
    // }
    // else if(enemyAttackState == EnemyAttackState::SHOOTING) {
    //     // switchEnemyAttackState(EnemyAttackState::SHOOTING);
    // }
}

void updateEnemy(Enemy* enemy) {
    resetTransform(&enemy->entity);

    checkEnemyState(enemy);

    enemy->entity.position.x += enemy->entity.velocity.x;
    enemy->entity.position.y += enemy->entity.velocity.y;
}