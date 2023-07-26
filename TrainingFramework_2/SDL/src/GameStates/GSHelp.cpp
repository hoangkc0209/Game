#include "GSHelp.h"
#include "GameObject/TextureManager.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/MouseButton.h"
#include "GameObject/SpriteAnimation.h"
#include "GameObject/Camera.h"
#include <SDL_image.h>
#include <SDL_rect.h>

GSHelp::GSHelp()
{
}

GSHelp::~GSHelp()
{
}



void GSHelp::Init()
{
	auto texture = ResourceManagers::GetInstance()->GetTexture("button/backgr_menu.jpg");

	// background
	m_background = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	m_background->SetSize(SCREEN_WIDTH, SCREEN_HEIDHT);
	m_background->Set2DPosition(0, 0);
	//control player1
	texture = ResourceManagers::GetInstance()->GetTexture("button/button_control_1.png");
	control1_object = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	control1_object->SetSize(120, 140);
	control1_object->Set2DPosition(50, 100);

	texture = ResourceManagers::GetInstance()->GetTexture("button/button_j.png");
	attack1_object = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	attack1_object->SetSize(40, 60);
	attack1_object->Set2DPosition(200, 100);
	//control_player2
	texture = ResourceManagers::GetInstance()->GetTexture("button/button_control_2.png");
	control2_object = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	control2_object->SetSize(120, 140);
	control2_object->Set2DPosition(50, 300);

	texture = ResourceManagers::GetInstance()->GetTexture("button/button_4.png");
	attack2_object = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	attack2_object->SetSize(40, 60);
	attack2_object->Set2DPosition(200, 300);

	// exit button
	texture = ResourceManagers::GetInstance()->GetTexture("button/btn_exit.png");
	std::shared_ptr<MouseButton> btnClose = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	btnClose->SetSize(80,30);
	btnClose->Set2DPosition(SCREEN_WIDTH - btnClose->GetWidth(), 10);
	btnClose->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(btnClose);


	// game title


	///Set Font
	m_textColor = { 255, 255, 0 };
	m_textGameName = std::make_shared<Text>("Data/lazy.ttf", m_textColor);
	m_textGameName->SetSize(300, 50);
	m_textGameName->Set2DPosition((SCREEN_WIDTH - m_textGameName->GetWidth()) / 2, SCREEN_HEIDHT / 2 - 300);
	m_textGameName->LoadFromRenderText("Antagonistic Fight");
	m_Sound = std::make_shared<Sound>("Data/Sounds/thegoodthebad.wav");
	m_Sound->PlaySound();
}

void GSHelp::Exit()
{
	ResourceManagers::FreeInstance();
}

void GSHelp::Pause()
{
	m_Sound->StopSound();

}

void GSHelp::Resume()
{
	m_Sound->PlaySound();
}


void GSHelp::HandleEvents()
{
}

void GSHelp::HandleKeyEvents(SDL_Event& e)
{
}

void GSHelp::HandleTouchEvents(SDL_Event& e, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvent(&e))
		{
			break;
		}
	}
}

void GSHelp::HandleMouseMoveEvents(int x, int y)
{
}
//float time = 0.0f;
void GSHelp::Update(float deltaTime)
{
	time += deltaTime;
	//printf("DeltaTime = %f", deltaTime);
	if (time >= 1.5f)
	{
		time = 0.0f;
	}
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSHelp::Draw(SDL_Renderer* renderer)
{
	
	m_background->Draw(renderer);
	control1_object->Draw(renderer);
	control2_object->Draw(renderer);
	attack1_object->Draw(renderer);
	attack2_object->Draw(renderer);

	for (auto it : m_listButton)
	{
		it->Draw(renderer);
	}
	m_textGameName->Draw(renderer);
}
