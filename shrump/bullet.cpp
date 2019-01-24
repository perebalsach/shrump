#include "bullet.h"
#include <SFML/Graphics.hpp>
#include "player.h"


Bullet::Bullet()
{
	m_hit = false;
	m_isFlyng = false;

	m_Texture.loadFromFile("graphics/bullet.png");
	m_Sprite.setTexture(m_Texture);

	m_Sprite.setOrigin(m_Sprite.getGlobalBounds().width / 2, m_Sprite.getGlobalBounds().height / 2);
}

sf::Sprite Bullet::getSprite()
{
	return m_Sprite;
}

sf::Vector2f Bullet::getPosition()
{
	return m_Position;
}

void Bullet::setPosition(sf::Vector2f pos)
{
	m_Sprite.setPosition(pos);
}

void Bullet::shoot()
{
	m_isFlyng = true;
	m_hit = false;
}

void Bullet::stop()
{
	m_isFlyng = false;
}

void Bullet::update(Player &player, float elapsedTime)
{
	sf::Vector2f playerPos = player.getPos();

	if (m_isFlyng)
	{
		// Move the bullet in the x axis
		m_Position.x += START_SPEED * elapsedTime;
		m_Position.y = playerPos.y;

		if (m_Position.x > 1700.0)
		{
			hasCollide();
		}
	}
	else
	{
		// Reset bullet position to the player position
		//std::cout << playerPos.y << std::endl;
		m_Position.x = playerPos.x;
		m_Position.y = playerPos.y;
	}

	m_Sprite.setPosition(m_Position);
}

bool Bullet::hasCollide()
{
	// Stops the bullet if has reached the max witdh screen size 1700 by now
	// TODO: get the screen size!
	if (m_Position.x > 1700)
	{
		m_hit = true;
		m_isFlyng = false;
		return true;
	}
	
	return false;
}



