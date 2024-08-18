struct CollisionEntity {
    GameObjectType gameObjectType;
    float& x;
    float& y;
    float width;
    float height;
    bool& active;
};

CollisionEntity createCollisionEntity(GameObjectType gameObjectType, glm::vec3& position, glm::vec2& size, bool& active) {
    CollisionEntity collisionEntity = {gameObjectType, position.x, position.y, size.x, size.y, active};

    return collisionEntity;
}