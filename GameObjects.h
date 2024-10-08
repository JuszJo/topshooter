#include <iostream>
#include <vector>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

struct ShootBuffer {
    float buffer;
    float elaspedFrames;
    bool ready;
};

#include "Entity.h"
#include "Square.h"
#include "Enemy.h"
#include "EnemyAI.h"
#include "Bullet.h"
#include "RenderEntity.h"
#include "CollisionEntity.h"

#include "GameEntities.h"

#include "BulletManager.h"

#include "Level.h"

#include "GameEvents.h"

#include "Collision.h"