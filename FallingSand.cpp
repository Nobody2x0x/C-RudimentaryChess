#include "FallingSand.h"
#include <stdlib.h>

FallingSand::FallingSand()
{
	grid = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
	updateGrid = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			grid[i][j] = 0; // Initialize the grid with 0s (empty cells)
			updateGrid[i][j] = 0; // Initialize the update grid with 0s (empty cells)
		}
	}
}

FallingSand::~FallingSand()
{

}


void FallingSand::AddParticle(sf::Vector2i& mousePos)
{
	int x = mousePos.x / width; // Convert mouse position to grid coordinates
	int y = mousePos.y / width;
	if (x >= 0 && x < rows && y >= 0 && y < cols)
	{
		updateGrid[x][y] = 1; // Set the update grid to 1 (sand particle)
	}

}

void FallingSand::UpdateGrid()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (grid[i][j] == 1 && j < cols - 1 && j >= 0 && i > 0 && i < rows - 1)
			{
				if (grid[i][j + 1] == 0)
				{
					updateGrid[i][j] = 0; // Clear the current cell
					updateGrid[i][j + 1] = 1; // Move down to the next cell
				}

				else if (grid[i + 1][j + 1] == 0 && grid[i - 1][j + 1] == 0)
				{
					bool dir = rand() % 2; // Randomly choose a direction to move down diagonally

					if (dir)
					{
						updateGrid[i][j] = 0; // Clear the current cell
						updateGrid[i + 1][j + 1] = 1; // Move down to the next cell diagonally
					}
					else
					{
						updateGrid[i][j] = 0; // Clear the current cell
						updateGrid[i - 1][j + 1] = 1; // Move down to the next cell diagonally
					}
				}

				else if (grid[i + 1][j + 1] == 0)
				{
					updateGrid[i][j] = 0;
					updateGrid[i + 1][j + 1] = 1; // Move down to the next cell diagonally
				}
				else if (grid[i - 1][j + 1] == 0)
				{
					updateGrid[i][j] = 0;
					updateGrid[i - 1][j + 1] = 1; // Move down to the next cell diagonally
				}
			}
		}
	}
}

void FallingSand::Draw(sf::RenderWindow& window)
{
	int randomColor = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (grid[i][j] == 1)
			{
				rect.setSize(sf::Vector2f(width, width));

				if (randomColor == 0)
				{
					rect.setFillColor(sf::Color::White);
				}
				else if (randomColor == 1)
				{
					rect.setFillColor(sf::Color::Green);
				}
				else if (randomColor == 2)
				{
					rect.setFillColor(sf::Color::Cyan);
				}
				else if (randomColor == 3)
				{
					rect.setFillColor(sf::Color::Magenta);
				}
				else if (randomColor == 4)
				{
					rect.setFillColor(sf::Color::Yellow);
				}
				else if (randomColor == 5)
				{
					rect.setFillColor(sf::Color::Red);
				}

				rect.setPosition(sf::Vector2f({ i * width, j * width }));

				window.draw(rect); //Draw the particle
			}

			grid[i][j] = updateGrid[i][j]; // Update the grid with the new state
		}
	}
}