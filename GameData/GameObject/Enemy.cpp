#include "Enemy.h"

Enemy::Enemy() {
	enemy.pos = { 300.0f,300.0f };
	enemy.radius = 32.0f;
	enemy.speed = 0.2f;
	enemyIsAlive = true;
	enemySpawnTimer = 2000;
}

Enemy::~Enemy() {

}

void Enemy::Update() {
	enemy.pos.x += enemy.speed;

	if (enemy.pos.x + enemy.radius >= 1280.0f) {
		enemy.speed = enemy.speed * -1.0f;
	}
	if (enemy.pos.x - enemy.radius <= 0.0f) {
		enemy.speed = enemy.speed * -1.0f;
	}

	if (enemyIsAlive == false) {
		enemySpawnTimer--;
	}
	if (enemySpawnTimer <= 0) {
		enemyIsAlive = true;
		enemySpawnTimer = 2000;
	}
}

void Enemy::Draw() {
	if (enemyIsAlive == true) {
		Novice::DrawEllipse((int)enemy.pos.x, (int)enemy.pos.y, (int)enemy.radius, (int)enemy.radius, 0.0f, BLACK, kFillModeSolid);
	}
}