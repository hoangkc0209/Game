#include "TrungChieu.h"

#include "Keystate.h"
#include "PlayerStateMachine.h"

Trung_chieu::Trung_chieu(PlayerStateMachine& state_mech)
	: PlayerStateBase(state_mech)
{
	m_player_state = (int)PlayerState::TRUNG_CHIEU;
	SetAnimation("genjuro/trung chieu.png", 1, 7, 1, 0.07f);
}

Trung_chieu::~Trung_chieu()
{
}

void Trung_chieu::Init()
{
}

void Trung_chieu::Exit()
{
}


void Trung_chieu::Reset()
{
	m_animation.get()->Reset();
}

void Trung_chieu::HandleEvents()
{
}

void Trung_chieu::HandleKeyEvents(SDL_Scancode control[6], float deltaTime)
{

}

void Trung_chieu::Update(float deltaTime, float& x, float& y)
{
	m_animation->Update(deltaTime);
	if (m_animation->GetFinished())
		m_state_machine.ChangeState((int)PlayerState::IDLE);
}

void Trung_chieu::Draw(SDL_Renderer* renderer, float x, float y)
{
	m_animation->Set2DPosition(x, y);
	m_animation->SetFlip(m_is_flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
	m_animation->Draw(renderer);
}
