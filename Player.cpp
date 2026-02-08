#include "Player.h"

Player::Player()
{
	this->name = "";
	this->color = BLANK;
	this->playerStrategy = nullptr;
}

Player::Player(std::string name, PieceColor color)
{
	this->name = name;
	this->color = color;
	this->playerStrategy = nullptr;
}

Player::Player(std::string name, PieceColor color, const PlayerStrategy* playerStrategy)
{
	this->name = name;
	this->color = color;
	if (playerStrategy)
		this->playerStrategy = playerStrategy->clone();
	else
		this->playerStrategy = nullptr;
}

Player::~Player()
{
}

std::string& Player::getName()
{
	return name;
}

const std::string& Player::getName() const
{
	return name;
}

PieceColor& Player::getPlayerColor()
{
	return color;
}

const PieceColor& Player::getPlayerColor() const
{
	return color;
}

PlayerStrategy* Player::getPlayerStrategy()
{
	return playerStrategy.get();
}

bool Player::operator==(const Player& left) const
{
	return (this->name == left.name &&
			this->color == left.color);
}

bool Player::operator!=(const Player& left) const
{
	return !(*this == left);
}

Player& Player::operator=(const Player& left)
{
	this->name = left.name;
	this->color = left.color;

	return *this;
}
