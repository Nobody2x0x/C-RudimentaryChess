#include "Bishop.h"
namespace { //Basically a function to get the fookin compiler off my back (l-value bs)
	const BishopMovementStrategy* getBishopStrategy(PieceColor color)
	{
		static const BishopMovementStrategy whiteStrategy(WHITE);
		static const BishopMovementStrategy blackStrategy(BLACK);
		static const BishopMovementStrategy blankStrategy(BLANK);

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

Bishop::Bishop() : Piece(BISHOP, BLANK, getBishopStrategy(BLANK))
{
}

Bishop::Bishop(PieceColor color) : Piece(BISHOP, color, getBishopStrategy(color))
{
}

Bishop::~Bishop()
{
}
