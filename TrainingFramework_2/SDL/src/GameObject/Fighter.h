#pragma once

#include <string>
#include <array>

#include "CMath.h"
#include "PlayerStates/PlayerStateMachine.h"
#include "SpriteAnimation.h"

class Fighter
{
public:
	Fighter(int id, bool flip);
	~Fighter();

	void Init();
	//control [right, up, left, down, attack]
	void SetControl(std::array<SDL_Scancode, 6> control);
	void Draw(SDL_Renderer* renderer);
	void Update(float deltatime,Fighter p1,Fighter p2);
	void SetPosition(float x, float y);
	void HandleKeyEvents(float deltaTime);
	void DrawBoundingBox(SDL_Renderer* renderer);
	void SetVelocity(float vx, float vy);
	int CheckCollisionP1HitP2(Fighter p1, Fighter p2);
	int CheckCollisionP2HitP1(Fighter p1, Fighter p2);
	bool checkCollision(Fighter p1, Fighter p2);
	int GetSpriteWidth();
	int GetSpriteHeight();

private:
<<<<<<< HEAD
=======
	bool isPlayer2Dead = false,isPlayer1Dead=false;
	bool isHit1 = false, isHit2 = false;
>>>>>>> e10b1e015d4932730a54bb95e812f627bc9f598c
	//Basic attribute
	int m_id;
	float m_score1,m_score2;
	Vector2 m_position;
	Vector2 m_prevPosition;
	Vector2 m_velocity;
	
	//Flip false facing right, true facing left
	bool m_isFlip;
	//Input
	int m_KeyState = 0;
	static constexpr int m_numControl = 6;
	//control [right, up, left, down, attack]
	SDL_Scancode m_control[m_numControl];
	//State machine
	PlayerStateMachine m_state_machine;
};