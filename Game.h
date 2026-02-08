#pragma once
#include <vector>
#include "Board.h"
#include "Move.h"
#include "Player.h"
#include "GameStatus.h"
#include "PieceColor.h"

class Player;
class Move;

class Game
{
private:
	std::vector<Move> moves;
	Player* whitePlayer;
	Player* blackPlayer;
	Board board;
	Player* currentPlayer;
	GameStatus gameStatus;
public:
	Game();
	Game(Player* whitePlayer, Player* blackPlayer, Board board);
	~Game();

	Board& getBoard();
	const Board& getBoard() const;
	Player& getCurrentPlayer();
	const Player& getCurrentPlayer() const;
	Player& getWhitePlayer();
	const Player& getWhitePlayer() const;
	Player& getBlackPlayer();
	const Player& getBlackPlayer() const;
	GameStatus& getGameStatus();
	const GameStatus& getGameStatus() const;

	std::vector<Move>& getMoves();
	const std::vector<Move>& getMoves() const;
	bool makeMove(Move& move);
	bool undoLastMove();
	void switchTurn();
	void resign(const Player& player);
	void forfeit(const Player& player);
	int getMoveCount();
	bool isPlayerTurn(const Player& player);
};