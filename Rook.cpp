#include "Rook.h"

namespace { //Basically a function to get the fookin compiler off my back (l-value bs)
	const RookMovementStrategy* getRookStrategy(PieceColor color)
	{
		static const RookMovementStrategy whiteStrategy(WHITE);
		static const RookMovementStrategy blackStrategy(BLACK);
		static const RookMovementStrategy blankStrategy(BLANK);

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

Rook::Rook() : Piece(ROOK, BLANK, getRookStrategy(BLANK))
{
}

Rook::Rook(PieceColor color) : Piece(ROOK, color, getRookStrategy(color))
{
}

Rook::~Rook()
{
}
