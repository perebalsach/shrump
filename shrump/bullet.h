#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"


class Bullet
{
public:
	const float START_SPEED = 15000;

	Bullet();
	
	sf::Sprite getSprite();
	sf::Vector2f getPosition();

	void setPosition(sf::Vector2f pos);
	void shoot();
	void stop();

	void update(Player &player, float elapsedTime);

	bool hasCollide();

private:
	sf::Vector2f m_Position;
	//float m_bulletSpeed = 1000;
	float m_xTarget;
	float m_yTarget;
	
	bool m_isFlyng;
	bool m_hit;

	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};

