#include "PieceInitialize.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
Piece PieceInitialize::createPiece(PieceType pieceType, PieceColor pieceColor)
{
    switch (pieceType)
    {
    case KING:
        return King(pieceColor);
        break;
    case QUEEN:
        return Queen(pieceColor);
        break;
    case KNIGHT:
        return Knight(pieceColor);
        break;
    case PAWN:
        return Pawn(pieceColor);
        break;
    case BISHOP:
        return Bishop(pieceColor);
        break;
    case ROOK:
        return Rook(pieceColor);
        break;
    case NONE:
        return Piece();
        break;
    default:
        throw std::invalid_argument("Unknown piece type!!");
    }
}
