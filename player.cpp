#include "player.h"
#include <iostream>

Player::Player()
{
	m_Speed = START_SPEED;
	m_Helth = START_HELTH;

	m_Texture.loadFromFile("graphics/spaceship.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(25, 25);
}

Sprite Player::getSprite()
{
	return m_Sprite;
}

Vector2f Player::getPos()
{
	//return m_Sprite.getGlobalBounds();
	return m_Sprite.getPosition();
}

void Player::setPosition(Vector2f position)
{
	m_Position = Vector2f(position.x, position.y);
	m_Sprite.setPosition(position);
}

void Player::update(float elapsedTime)
{
	if (m_DownPressed)
	{
		m_Speed -= ACCELERATION;
		m_Position.y -= m_Speed * elapsedTime * ACCELERATION;
		m_Speed = m_Position.y;
		std::cout << "y: " << m_Position.y << std::endl;
	}

	if (m_UpPressed)
	{
		m_Position.y += m_Speed * elapsedTime * ACCELERATION;
		m_Speed = m_Position.y;
		std::cout << "y: " << m_Position.y << std::endl;
	}

	if (m_RightPressed)
	{
		//m_Speed *= ACCELERATION;
		m_Position.x += m_Speed * elapsedTime * ACCELERATION;
		m_Speed = m_Position.x;
		std::cout << "x: " << m_Position.x << std::endl;
	}

	if (m_LeftPressed)
	{		
		m_Position.x -= m_Speed * elapsedTime * ACCELERATION;
		m_Speed = m_Position.x;
		std::cout << "x: " << m_Position.x << std::endl;
	}
	
	m_Sprite.setPosition(m_Position);
}

void Player::moveDown()
{
	m_DownPressed = true;
}

void Player::moveLeft()
{
	m_LeftPressed = true;
}

void Player::moveRight()
{
	m_RightPressed = true;
}

void Player::moveUp()
{
	m_UpPressed = true;	
}

void Player::stopDown()
{
	m_DownPressed = false;
}

void Player::stopUp()
{
	m_UpPressed = false;
}

void Player::stopLeft()
{
	m_LeftPressed = false;
}

void Player::stopRight()
{
	m_RightPressed = false;
}

float Player::getSpeed()
{
	return m_Speed;
}