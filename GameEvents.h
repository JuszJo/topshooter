bool dont = false;

void playerShoot(std::vector<Bullet>& bullets) {
    if(key.space && !dont) {
        dont = true;
        Bullet bullet = createBullet(GameObjectType::PLAYER);

        bullets.push_back(bullet);
    }
}