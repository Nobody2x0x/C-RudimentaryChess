#pragma once
#include "Game.h"
#include "Move.h"
#include "Position.h"

class Game;
class Move;

class PlayerStrategy
{
public:
	virtual Move getNextMove(Game& game, Position from, Position to) const = 0;
	virtual std::shared_ptr<PlayerStrategy> clone() const = 0;
	virtual ~PlayerStrategy() = default;
};