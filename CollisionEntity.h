struct CollisionEntity {
    GameObjectType gameObjectType;
    float& x;
    float& y;
    float width;
    float height;
};

CollisionEntity createCollisionEntity(GameObjectType gameObjectType, glm::vec3& position, glm::vec2& size) {
    CollisionEntity collisionEntity = {gameObjectType, position.x, position.y, size.x, size.y};

    return collisionEntity;
}