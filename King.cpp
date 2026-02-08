#include "King.h"
namespace { //Basically a function to get the fookin compiler off my back (l-value bs)
	const KingMovementStrategy* getKingStrategy(PieceColor color)
	{
		static const KingMovementStrategy whiteStrategy(WHITE);
		static const KingMovementStrategy blackStrategy(BLACK);
		static const KingMovementStrategy blankStrategy(BLANK);

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

King::King() : Piece(KING, BLANK, getKingStrategy(BLANK))
{
}

King::King(PieceColor color) : Piece(KING, color, getKingStrategy(color))
{
}

King::~King()
{
}
