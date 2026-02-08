#include <iostream>
#include "Block.h"
#include "FallingSand.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Board.h"
#include "Game.h"
#include "GameController.h"
#include "BoardInitialize.h"
#include "Move.h"
#include "Player.h"
#include "PlayerStrategy.h"
#include "HumanPlayerStrategy.h"
#include "PieceColor.h"
#include <vector>

int main()
{
	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({960, 960}), "SFML");
	
	float deltaTime = 1.0f/60.0f;
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	Player* whitePlayer = new Player("Alice", WHITE, new HumanPlayerStrategy());
	Player* blackPlayer = new Player("Tyrone", BLACK, new HumanPlayerStrategy());
	Game game(whitePlayer, blackPlayer, BoardInitialize().createStandardBoard());
	GameController gameController = GameController(&game);
	sf::Texture texture("ChessPiecesArray.png"); //This shit gives ballsy performance change later (Change done)

	std::vector<Position> positions;
	gameController.startGame();
	bool isDragging = false;
	sf::Vector2f offset;

	std::vector<Position>* possibleMoves = new std::vector<Position>(); //Possible move of a piece

	while (window.isOpen()) //Chess moveing scheme -> MousePosition / tileWidth( = 120 ) = Position();
	{

		while (const std::optional event = window.pollEvent())
		{

			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}


			if (event->is<sf::Event::MouseButtonPressed>())
			{
				mousePosition = sf::Mouse::getPosition(window);

				//Check for mouse position then return click position
				//Hmm, checck for chessTile position -> check if it's a valid chess piece -> select next position -> check for valid move -> if not delete both position to reset
				int row = mousePosition.y / 120;
				int col = mousePosition.x / 120;
				std::cout << row << std::endl;
				std::cout << col << std::endl;
				/*if (sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
				{
					offset = sf::Vector2f(mousePosition) - sprite.getPosition();
					isDragging = true;
				}*/
				positions.push_back(Position(row, col));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U))
			{
				gameController.undoGameMove();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
			{
				gameController.resignCurrentPlayer();
			}
		}
			
		if (positions.size() >= 1)
		{
			Game& activeGame = gameController.getGame();

			Piece piece = game.getBoard().getTile(positions[0]).getPiece();

			if (piece.getType() == NONE)
			{
				std::cout << "There's no piece here!";
				positions.clear();
			}
			else if (piece.getColor() != game.getCurrentPlayer().getPlayerColor())
			{
				std::cout << "That is not your piece! It is "
					<< (game.getCurrentPlayer().getPlayerColor() == WHITE ? "White's" : "Black's")
					<< " turn." << std::endl;
				positions.clear();
			}
			else
			{
				*possibleMoves = piece.getMovementStrategy()->getPossibleMoves(positions[0], activeGame.getBoard()); //Possible moves of the piece
				if (positions.size() >= 2)
				{
					Move move(positions[0], positions[1], &game.getCurrentPlayer());
					if (gameController.playMove(move))
					{
						std::cout << "Move played!";
					}
					else
					{
						std::cout << "Invalid move!!";
					}

					positions.clear();
				}
			}

		}
		/*if (event->is<sf::Event::MouseButtonReleased>())
		{
			isDragging = false;
		}*/

		//if (isDragging)
		//{
		//	sf::Vector2i mp = sf::Mouse::getPosition(window);
		//	sf::Vector2f mf(static_cast<float>(mp.x), static_cast<float>(mp.y));
		//	//sprite.setPosition(mf - offset);
		//}	

		window.clear();
		gameController.displayBoard(window, texture);

		if (positions.size() != 0) //If no piece is chosen, delete the old moves
		{
			for (Position pos : *possibleMoves)
			{
				sf::RectangleShape rect;
				rect.setSize(sf::Vector2f(120.0f, 120.0f));
				rect.setFillColor(sf::Color(226, 80, 80, 100));
				rect.setPosition(sf::Vector2f({ pos.getCol() * 120.0f, pos.getRow() * 120.0f })); //This row and col is inverted, I don't intend to fix it
				window.draw(rect);
			}
		}
		/*window.draw(sprite);*/
		window.display();
	}

	gameController.endGame();
	delete whitePlayer;
	delete blackPlayer;
	return 0;
}