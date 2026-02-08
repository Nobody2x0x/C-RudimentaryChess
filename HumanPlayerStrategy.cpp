#include "HumanPlayerStrategy.h"

HumanPlayerStrategy::HumanPlayerStrategy()
{

}

std::shared_ptr<PlayerStrategy> HumanPlayerStrategy::clone() const
{
	return std::make_shared<HumanPlayerStrategy>(*this);
}

Move HumanPlayerStrategy::getNextMove(Game& game, Position from, Position to) const
{
	try {
		//Add check for mouse position
		//Array to hold 2 position to move (from, to)
		if (game.getBoard().getTile(from).getPiece() == Piece())
		{
			throw std::invalid_argument("There's no piece in this tile");
		}

		return Move(from, to, &game.getCurrentPlayer());
	}
	catch (std::invalid_argument execption)
	{
		throw std::invalid_argument("Invalid move!");
	}
}
