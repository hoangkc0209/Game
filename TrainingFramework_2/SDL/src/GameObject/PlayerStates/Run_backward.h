#pragma once

#include "PlayerStateBase.h"

class Run_backward : public PlayerStateBase
{
public:
	Run_backward(PlayerStateMachine& state_mech);
	~Run_backward();

	void Init();
	void Exit();

	void Reset();

	void HandleEvents();
	void HandleKeyEvents(SDL_Scancode control[6], float deltaTime);
	void Update(float deltaTime, float& x, float& y);
	void Draw(SDL_Renderer* renderer, float x, float y);
private:
	static constexpr int m_dashspeed = 2000;
	static constexpr int m_deaccel_rate = m_dashspeed / 4;
	int m_current_speed = m_dashspeed;
};
