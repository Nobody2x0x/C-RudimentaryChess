#include "Queen.h"

namespace { //Basically a function to get the fookin compiler off my back (l-value bs)
	const QueenMovementStrategy* getQueenStrategy(PieceColor color)
	{
		static const QueenMovementStrategy whiteStrategy(WHITE);
		static const QueenMovementStrategy blackStrategy(BLACK);
		static const QueenMovementStrategy blankStrategy(BLANK);

		switch (color)
		{
		case WHITE:
			return &whiteStrategy;
			break;
		case BLACK:
			return &blackStrategy;
			break;
		default:
			return &blankStrategy;
			break;
		}
	}
}

Queen::Queen() : Piece(QUEEN, BLANK, getQueenStrategy(BLANK))
{

}

Queen::Queen(PieceColor color) : Piece(QUEEN, color, getQueenStrategy(color))
{

}

Queen::~Queen()
{

}
