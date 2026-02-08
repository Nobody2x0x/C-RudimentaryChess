#pragma once
#include "PlayerStrategy.h"
#include "Game.h"
#include <memory>
#include <stdexcept>
#include <iostream>

class Game;

class HumanPlayerStrategy : public PlayerStrategy
{
public:
	HumanPlayerStrategy();
	std::shared_ptr<PlayerStrategy> clone() const override;
	Move getNextMove(Game& game, Position from, Position to) const override;
};