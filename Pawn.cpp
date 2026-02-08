#include "Pawn.h"

namespace { //Basically a function to get the fookin compiler off my back (l-value bs)
	const PawnMovementStrategy* getPawnStrategy(PieceColor color)
	{
		static const PawnMovementStrategy whiteStrategy(WHITE);
		static const PawnMovementStrategy blackStrategy(BLACK);
		static const PawnMovementStrategy blankStrategy(BLANK);

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

Pawn::Pawn() : Piece(PAWN, BLANK, getPawnStrategy(BLANK))
{
}

Pawn::Pawn(PieceColor color) : Piece(PAWN, color, getPawnStrategy(color))
{
}

Pawn::~Pawn()
{
}
