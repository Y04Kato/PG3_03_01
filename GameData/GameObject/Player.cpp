#include "Player.h"

Player::Player() {
	player.pos = { 620,400 };
	player.radius = 32;
	player.speed = 6;
	playerIsAlive = true;
	enemyDeadCount = 0;

	input_ = Input::GetInstance();

	for (int i = 0; i < 32; i++) {
		bullet[i] = new Bullet();
	}

	enemy = new Enemy();
}

Player::~Player() {
	for (int i = 0; i < 32; i++) {
		delete bullet[i];
	}

	delete enemy;
}

void Player::Update() {
	if (input_->PushKey(DIK_W)) player.pos.y -= player.speed;
	if (input_->PushKey(DIK_S)) player.pos.y += player.speed;
	if (input_->PushKey(DIK_A)) player.pos.x -= player.speed;
	if (input_->PushKey(DIK_D)) player.pos.x += player.speed;

	for (int i = 0; i < 32; i++) {
		if (input_->TriggerKey(DIK_SPACE) && bullet[i]->bulletIsShot == false) {
			bullet[i]->bulletIsShot = true;
			bullet[i]->bullet.pos = player.pos;
		}

		if (input_->TriggerKey(DIK_SPACE) && bullet[i]->bulletIsShot == false) {
			bullet[i]->bulletIsShot = true;
			bullet[i]->bullet.pos = player.pos;
		}

		if (CircleCollisinHit(bullet[i]->bullet.pos, bullet[i]->bullet.radius, enemy->enemy.pos, enemy->enemy.radius) == true) {
			enemy->enemyIsAlive = false;
			bullet[i]->bulletIsShot = false;
			enemyDeadCount++;
		}

		enemy->Update();
		bullet[i]->Update();
	}
}

void Player::Draw() {
	if (playerIsAlive == true) {
		Novice::DrawEllipse((int)player.pos.x, (int)player.pos.y, (int)player.radius, (int)player.radius, 0.0f, BLUE, kFillModeSolid);
	}
	for (int i = 0; i < 32; i++) {
		bullet[i]->Draw();
	}
	enemy->Draw();
}