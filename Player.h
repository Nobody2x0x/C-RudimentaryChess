#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "PieceColor.h"
#include "PlayerStrategy.h"
#include <memory>

class PlayerStrategy;

class Player
{
private:
	std::string name;
	PieceColor color;
	std::shared_ptr<PlayerStrategy> playerStrategy;
public:
	Player();
	Player(std::string name, PieceColor color);
	Player(std::string name, PieceColor color, const PlayerStrategy* playerStrategy);
	~Player();

	std::string& getName();
	const std::string& getName() const;
	PieceColor& getPlayerColor();
	const PieceColor& getPlayerColor() const;
	PlayerStrategy* getPlayerStrategy();
	bool operator==(const Player& left) const;
	bool operator!=(const Player& left) const;
	Player& operator=(const Player& left);
};

#endif // !PLAYER_H