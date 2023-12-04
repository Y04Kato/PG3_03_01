#include "Player.h"

Player::Player() {
	player.pos = { 620,400 };
	player.radius = 32;
	player.speed = 6;
	playerIsAlive = true;

	input_ = Input::GetInstance();
}

Player::~Player() {

}

void Player::Update() {

}

void Player::Draw() {
	if (playerIsAlive == true) {
		Novice::DrawEllipse((int)player.pos.x, (int)player.pos.y, (int)player.radius, (int)player.radius, 0.0f, BLUE, kFillModeSolid);
	}
}

void Player::MoveRight() {
	player.pos.x += player.speed;
}

void Player::MoveLeft() {
	player.pos.x -= player.speed;
}