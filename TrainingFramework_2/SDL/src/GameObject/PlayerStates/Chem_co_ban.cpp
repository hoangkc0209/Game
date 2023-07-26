#include "Chem_co_ban.h"
#include "Define.h"
#include "PlayerStateMachine.h"

Chem_co_ban::Chem_co_ban(PlayerStateMachine& state_mech)
	:PlayerStateBase(state_mech)
{
	m_player_state = (int)PlayerState::CHEM_CO_BAN;
	SetAnimation("genjuro/chem co ban 2.png", 1, 8, 1,0.1f);
}

Chem_co_ban::~Chem_co_ban()
{
}

void Chem_co_ban::Init()
{
}

void Chem_co_ban::Exit()
{
}

void Chem_co_ban::Reset()
{
	m_animation.get()->Reset();
}

void Chem_co_ban::HandleEvents()
{
}

void Chem_co_ban::HandleKeyEvents(SDL_Scancode control[6], float deltaTime)
{
}

void Chem_co_ban::Update(float deltaTime, float& x, float& y)
{
	m_animation.get()->Update(deltaTime);
	y = SCREEN_HEIDHT - 150 - 8;
	if (m_animation.get()->GetFinished()) 
	{
		m_state_machine.ChangeState((int)PlayerState::IDLE);
		y = SCREEN_HEIDHT - 150;
	}
		
}

void Chem_co_ban::Draw(SDL_Renderer* renderer, float x, float y)
{
	m_animation.get()->Set2DPosition(x, y);
	m_animation.get()->SetFlip(m_is_flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
	m_animation.get()->Draw(renderer);
}
