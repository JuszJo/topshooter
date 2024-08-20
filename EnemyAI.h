void seekPlayer(Entity& enemy, Entity& player) {
    if(player.position.y > 100.0f) {
        switchEnemyAttackState(EnemyAttackState::SHOOTING);
    }
    else {
        switchEnemyAttackState(EnemyAttackState::NONE);
    }
}