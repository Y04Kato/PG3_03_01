#include "Bullet.h"

Bullet::Bullet() {
	bullet.pos = { 0.0f,0.0f };
	bullet.speed = 10.0f;
	bullet.radius = 16.0f;
	bulletIsShot = false;
}

Bullet::~Bullet() {

}

void Bullet::Update() {
	if (bulletIsShot == true) {
		bullet.pos.y -= bullet.speed;
	}
	else {
		bullet.pos = { 0.0f,0.0f };
	}
	if (bullet.pos.y < 0.0f) {
		bulletIsShot = false;
	}
}

void Bullet::Draw() {
	if (bulletIsShot == true) {
		Novice::DrawEllipse((int)bullet.pos.x, (int)bullet.pos.y, (int)bullet.radius, (int)bullet.radius, 0.0f, RED, kFillModeSolid);
	}
}