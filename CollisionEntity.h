struct CollisionEntity {
    GameObjectType type;
    float& x;
    float& y;
    float width;
    float height;
};

CollisionEntity createCollisionEntity(GameObjectType type, glm::vec3& position, glm::vec2& size) {
    CollisionEntity collisionEntity = {type, position.x, position.y, size.x, size.y};

    return collisionEntity;
}