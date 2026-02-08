#include "Knight.h"
namespace { //Basically a function to get the fookin compiler off my back (l-value bs)
	const KnightMovementStrategy* getKnightStrategy(PieceColor color)
	{
		static const KnightMovementStrategy whiteStrategy(WHITE);
		static const KnightMovementStrategy blackStrategy(BLACK);
		static const KnightMovementStrategy blankStrategy(BLANK);

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
Knight::Knight() : Piece(KNIGHT, BLANK, getKnightStrategy(BLANK))
{
}

Knight::Knight(PieceColor color) : Piece(KNIGHT, color, getKnightStrategy(color))
{
}

Knight::~Knight()
{
}
