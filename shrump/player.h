#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	const float START_SPEED = 8000;
	const float START_HELTH = 100;
	const float ACCELERATION = 1.7;

	Texture m_Texture;
	Sprite m_Sprite;
	Vector2f m_Position;
	float m_Speed;
	float m_Helth;

	// Which directions is the player currently moving in
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;

public:
	Player();
	
	// Getters
	Sprite getSprite();
	Vector2f getPos();
	
	// Setters
	void setPosition(Vector2f position);

	void update(float elapsedTime);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void stopUp();
	void stopDown();
	void stopLeft();
	void stopRight();

	float getSpeed();
};

