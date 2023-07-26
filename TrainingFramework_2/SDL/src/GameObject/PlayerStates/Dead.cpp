#include "Dead.h"
#include "Define.h"
#include "Keystate.h"
#include "PlayerStateMachine.h"

Dead::Dead(PlayerStateMachine& state_mech)
	: PlayerStateBase(state_mech)
{
	m_player_state = (int)PlayerState::DEAD;
<<<<<<< HEAD
	SetAnimation("genjuro/bi ha.png", 1, 4, 1, 0.1f);
=======
	SetAnimation("genjuro/bi hat.png", 1, 6, 1, 0.5f);
>>>>>>> e10b1e015d4932730a54bb95e812f627bc9f598c
}

Dead::~Dead()
{
}

void Dead::Init()
{
}

void Dead::Exit()
{
}


void Dead::Reset()
{
	m_animation.get()->Reset();
}

void Dead::HandleEvents()
{
}

void Dead::HandleKeyEvents(SDL_Scancode control[6], float deltaTime)
{

}

void Dead::Update(float deltaTime, float& x, float& y)
{
	y = SCREEN_HEIDHT - 150 + 5;
	m_animation.get()->Update(deltaTime);
}

void Dead::Draw(SDL_Renderer* renderer, float x, float y)
{
	m_animation.get()->Set2DPosition(x, y);
	m_animation.get()->SetFlip(m_is_flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
	m_animation.get()->Draw(renderer);
}
