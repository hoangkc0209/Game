#pragma once
#include "GameStateBase.h"
#include "GameObject/MouseButton.h"
#include "Fighter.h"

class Sprite2D;
class SpriteAnimation;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(SDL_Event& e) override;
	void	HandleTouchEvents(SDL_Event& e, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw(SDL_Renderer* renderer) override;
	void	DrawBoundingBox(SDL_Renderer* renderer);
	int m_KeyPress = 0;

private:
	std::shared_ptr<SpriteAnimation>	m_background;
	std::shared_ptr<Sprite2D>   h1_object, attack1_object, obj1, hp1 ;
	std::shared_ptr<Sprite2D>	h2_object, attack2_object, obj2, hp2 ; 
	//std::shared_ptr<Text>		m_score;
	std::list<std::shared_ptr<MouseButton>>	m_listButton;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;
	std::shared_ptr<SpriteAnimation> obj;
	std::shared_ptr<MouseButton> button;
	float time = 0.0f;
	float m_Velocity = 10.0f;
	Fighter player1;
	Fighter player2;
	int m_hp1 = 100,m_hp2=100;
};

