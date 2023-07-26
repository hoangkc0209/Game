#include "Fighter.h"

#include "GameManager/ResourceManagers.h"
#include "Define.h"
#include <assert.h>

Fighter::Fighter(int id, bool flip)
	:
	m_id(id),m_velocity(Vector2(0.0f, 0.0f))   
{
	m_score1 = 0;
	m_score2 = 0;
	m_isFlip = flip;
	m_state_machine.SetFlip(flip);
	
}

Fighter::~Fighter()
{
}

void Fighter::Init()
{
	m_position = Vector2(0.0f, 0.0f); // Đặt vị trí ban đầu của nhân vật
	m_velocity = Vector2(0.0f, 0.0f); // Đặt vận tốc ban đầu của nhân vật
	m_prevPosition = m_position; // Vị trí trước khi di chuyển ban đầu là vị trí ban đầu
}

void Fighter::SetControl(std::array<SDL_Scancode, 6> control)
{
	for (int i = 0; i < m_numControl; ++i)
		m_control[i] = control[i];
}

void Fighter::Draw(SDL_Renderer* renderer)
{
	m_state_machine.CurrentState().get()->Draw(renderer, m_position.x, m_position.y);
}

void Fighter::SetVelocity(float vx, float vy)
{
	m_velocity.x = vx;
	m_velocity.y = vy;
}
void Fighter::DrawBoundingBox(SDL_Renderer* renderer)
{
	// Xác định kích thước hộp xung quanh nhân vật
	int boxWidth = GetSpriteWidth();
	int boxHeight = GetSpriteHeight();

	// Vị trí góc trái trên của hộp xung quanh nhân vật
	int boxLeft = static_cast<int>(m_position.x);
	int boxTop = static_cast<int>(m_position.y);

	// Tạo một hình chữ nhật để vẽ hộp xung quanh nhân vật
	SDL_Rect boundingBox = { boxLeft, boxTop, boxWidth, boxHeight };

	// Đặt màu vẽ cho hộp xung quanh (màu trắng )
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	// Vẽ hộp xung quanh nhân vật lên màn hình
	SDL_RenderDrawRect(renderer, &boundingBox);
}


bool Fighter::checkCollision(Fighter p1, Fighter p2)
{
	float x1 = p1.m_position.x;
	float x2 = p2.m_position.x;
	int w1 = p1.GetSpriteWidth();
	int w2 = p2.GetSpriteWidth();

	bool collision = (x1 + w1 >= x2+65) && (x2 + w2 >= x1+65);

	return collision;
}

void Fighter::Update(float deltatime,Fighter p1, Fighter p2)
{
	m_state_machine.CurrentState().get()->Update(deltatime, m_position.x, m_position.y);  
	
	// Ve Bound cho nhan vat
	int screenWidth = SCREEN_WIDTH;
	int screenHeight = SCREEN_HEIDHT;

	int spriteWidth = GetSpriteWidth();
	int spriteHeight = GetSpriteHeight();

	int leftBoundary = 0;
	int rightBoundary = screenWidth - spriteWidth;

	int m_topBoundary = 0;
	int m_bottomBoundary = screenHeight - spriteHeight;


	// Kiểm tra và giới hạn vị trí của nhân vật theo trục X
	if (m_position.x < leftBoundary)
	{
		m_position.x = leftBoundary;
	}
	else if (m_position.x > rightBoundary)
	{
		m_position.x = rightBoundary;
	}

	// Kiểm tra và giới hạn vị trí của nhân vật theo trục Y 
	if (m_position.y < m_topBoundary)
	{
		m_position.y = m_topBoundary;
	}
	else if (m_position.y > m_bottomBoundary)
	{
		m_position.y = m_bottomBoundary;
	}
	
	//////////////////////////////
	int collisionResult = checkCollision(p1, p2);
	// xử lý va chạm
	if (collisionResult == 1) 
	{
		//// Xác định hướng di chuyển của mỗi nhân vật
		int p1Direction = (m_position.x < p2.m_position.x) ? 1 : -1;
		int p2Direction = (p2.m_position.x < m_position.x) ? 1 : -1;

		float pushAmount = 50.0f;

		//// Đảo ngược hướng di chuyển cho cả hai nhân vật
		m_position.x -= pushAmount * p1Direction  ;
		p2.m_position.x -= pushAmount * p2Direction * deltatime;

		//// Cập nhật trạng thái và hoạt hình theo cách cần thiết
		m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::JUMP;
		////p2.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::DEAD;
		
		
		
	}
	//int x1Pos = p1.m_position.x;
	//int y1Pos = p1.m_position.y;
	//int x2Pos = p2.m_position.x;
	//int y2Pos = p2.m_position.y;
	//
	//int spriteWidthP1 = GetSpriteWidth();
	//int spriteHeightP2 = GetSpriteHeight();

	///*int leftBoundary = 0;
	//int rightBoundary = screenWidth - spriteWidth;

	//int m_topBoundary = 0;
	//int m_bottomBoundary = screenHeight - spriteHeight;*/
	//
	//if (x1Pos >= x2Pos)
	//{
	//	p1.m_position.x = x1Pos-10;
	//	p2.m_position.x = x2Pos -10;

	//}
	//else if (x2Pos <= x1Pos)
	//{
	//	x1Pos = x2Pos + 10;

	//}

	
	//////////////////////////////
	//check collision o day
	//play1 hit play2
	switch (CheckCollisionP1HitP2(p1,p2))
	{
	case 1:printf("p1 danh thuong p2\n");
<<<<<<< HEAD
		printf("%f\n", m_score1);
		m_score1 += 1;
		/*if () {
			m_score1 += 1;
		}*/
		break;
	case 2: printf("p1 chem cao p2\n");
=======
		p2.m_current_hp -= 100;
		isHit2 = true;
		if (isHit2)
			p2.m_state_machine.ChangeState((int)PlayerState::TRUNG_CHIEU);
		printf("%d,%d\n", p2.m_current_hp, p1.m_current_hp);
		break;
	case 2: printf("p1 chem cao p2\n");
		p2.m_current_hp -= 20;
		isHit2 = true;
		printf("%d,%d\n", p2.m_current_hp, p1.m_current_hp);
>>>>>>> e10b1e015d4932730a54bb95e812f627bc9f598c
		break;
	case 3: printf("p1 chem thap p2\n");
		break;
	case 4: printf("p1 da cao p2\n");
		break;
	case 5: printf("p1 da thap p2\n");
		break;
	default:
		break;
	}
<<<<<<< HEAD
	if (m_score1 >= 40.0f) {
=======

	//mat mau cua p1
	if (p2.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::IDLE) {
		p1.m_previos_hp = p1.m_current_hp;
	}
	if (p1.m_previos_hp > p1.m_current_hp) {
		return;
	}
	switch (CheckCollisionP2HitP1(p1, p2))
	{
	case 1:printf("p2 danh thuong p1\n");
		p1.m_current_hp -= 10;
		printf("%d,%d\n",p1.m_current_hp,p2.m_current_hp);
		/*if () {
			m_score1 += 1;
		}*/
		break;
	case 2: printf("p2 chem cao p1\n");
		break;
	case 3: printf("p2 chem thap p1\n");
		break;
	case 4: printf("p2 da cao p1\n");
		break;
	case 5: printf("p2 da thap p1\n");
		break;
	default:
		break;
	}
	//neu p2 het mau
	if (p2.m_current_hp <= 0 && !isPlayer2Dead) {
		isPlayer2Dead = true;
		p2.m_state_machine.ChangeState((int)PlayerState::DEAD);
		isHit2 = false;
	}

	//neu p1 het mau
	if (p1.m_current_hp <= 0 && !isPlayer1Dead) {
		p1.m_state_machine.ChangeState((int)PlayerState::DEAD);
		isPlayer1Dead = true;
	}
	/*if (m_score1 >= 40.0f) {
>>>>>>> e10b1e015d4932730a54bb95e812f627bc9f598c
		p2.m_state_machine.ChangeState((int)PlayerState::DEAD);
	}
	if (m_score2 >= 15.0f) {
		p1.m_state_machine.ChangeState((int)PlayerState::DEAD);
	}
}

void Fighter::SetPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}




//function check tai day, check dc 2 doi tuong p1 p2
int Fighter::CheckCollisionP1HitP2(Fighter p1, Fighter p2) {
	float x1 = p1.m_position.x;
	float y1 = p1.m_position.y;
	float x2 = p2.m_position.x;
	float y2 = p2.m_position.y;
	int w1 = p1.GetSpriteWidth();
	int h1 = p1.GetSpriteHeight();
	int w2 = p2.GetSpriteWidth();
	int h2 = p2.GetSpriteHeight();
	bool check_defend_or_dead = false;
	if (p2.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::DEFEND || p2.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::DEAD) {
		check_defend_or_dead = true;
	}
	if (x1<=x2 + w2 && x1 + w1>=x2 && p1.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::CHEM_CO_BAN && check_defend_or_dead==false)
		return 1;
	if (x1<x2 + w2/1.5 && x1 + w1/1.5>x2 && p1.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::CHEM_CAO && check_defend_or_dead==false)
		return 2;
	if (x1<x2 + w2/1.5 && x1 + w1/1.5>x2 && p1.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::CHEM_THAP && check_defend_or_dead==false)
		return 3;
	if (x1<=x2 + w2 && x1 + w1>=x2 && p1.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::DA_CAO && check_defend_or_dead==false)
		return 4;
	if (x1<x2 + w2/1.5 && x1 + w1/1.5>x2 && p1.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::DA_THAP && check_defend_or_dead==false)
		return 5;
}

int Fighter::CheckCollisionP2HitP1(Fighter p1, Fighter p2) {
	float x1 = p1.m_position.x;
	float y1 = p1.m_position.y;
	float x2 = p2.m_position.x;
	float y2 = p2.m_position.y;
	int w1 = p1.GetSpriteWidth();
	int h1 = p1.GetSpriteHeight();
	int w2 = p2.GetSpriteWidth();
	int h2 = p2.GetSpriteHeight();
	if (x1<x2 + w2 && x1 + w1>x2 && p2.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::CHEM_CO_BAN)
		return 1;
	if (x1<x2 + w2 && x1 + w1>x2 && p2.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::CHEM_CAO)
		return 2;
	if (x1<x2 + w2 && x1 + w1>x2 && p2.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::CHEM_THAP)
		return 3;
	if (x1<x2 + w2 && x1 + w1>x2 && p2.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::DA_CAO)
		return 4;
	if (x1<x2 + w2 && x1 + w1>x2 && p2.m_state_machine.CurrentState()->GetPlayerState() == (int)PlayerState::DA_THAP)
		return 5;
}

void Fighter::HandleKeyEvents(float deltaTime)
{
	m_state_machine.CurrentState().get()->HandleKeyEvents(m_control, deltaTime);
}

int Fighter::GetSpriteWidth()
{
	return m_state_machine.CurrentState().get()->GetSpriteWidth();
}
int Fighter::GetSpriteHeight() {
	return m_state_machine.CurrentState().get()->GetSpireHeigth();
}
