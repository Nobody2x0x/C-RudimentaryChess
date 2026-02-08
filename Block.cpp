#include "Block.h"

Block::Block()
{
	blockShape = sf::RectangleShape({ width, height });
}

Block::Block(float b_width, float b_height)
{
	blockShape = sf::RectangleShape({ b_width, b_height });
}

Block::~Block()
{

}

void Block::SetVelocity(const sf::Vector2f& velocity)
{
	blockVelocity = velocity;
}

void Block::SetAcceleration(const sf::Vector2f& acceleration)
{
	blockAcceleration = acceleration;
}

void Block::SetPosition(const sf::Vector2f& position)
{
	blockPosition = position;
	blockShape.setPosition(blockPosition);
	
}

void Block::SetGravity()
{
	blockAcceleration.y = gravity;
}

void Block::GetPosition()
{
	std::cout << "Block Position: (" << blockPosition.x << ", " << blockPosition.y << ")" << std::endl;
}

void Block::GetAcceleration()
{
	std::cout << "Block Acceleration: (" << blockAcceleration.x << ", " << blockAcceleration.y << ")" << std::endl;
}

void Block::GetVelocity()
{
	std::cout << "Block Velocity: (" << blockVelocity.x << ", " << blockVelocity.y << ")" << std::endl;
}

bool Block::CheckOverlap(Block& block)
{
	if (blockPosition.x + width < block.blockPosition.x
		&& blockPosition.x < block.blockPosition.x + block.width
		&& blockPosition.y + height < block.blockPosition.y
		&& blockPosition.y < block.blockPosition.y + block.height)
		return true;
	else
		return false;
}

void Block::UpdatePosition(float deltaTime)
{
	// Update the position of the block based on deltaTime
	blockShape.setPosition(blockPosition);

	blockVelocity.x += blockAcceleration.x * deltaTime;
	blockVelocity.y += blockAcceleration.y * deltaTime;

	blockPosition.x += blockVelocity.x * deltaTime;
	blockPosition.y += blockVelocity.y * deltaTime;

	if (blockVelocity.x >= 200.0f)
		blockVelocity.x = 200.0f;

	if (blockVelocity.y >= 200.0f)
		blockVelocity.y = 200.0f;
	
	// Ensure the block does not go out of bounds
	if (blockPosition.x <= 0) //Left boundary
		blockPosition.x = 0;

	if (blockPosition.y <= 0) //Top boundary
		blockPosition.y = 0;

	if (blockPosition.x + blockShape.getGlobalBounds().size.x >= sf::VideoMode::getDesktopMode().size.x) //Right boundary
		blockPosition.x = sf::VideoMode::getDesktopMode().size.x - blockShape.getGlobalBounds().size.x;

	if (blockPosition.y + blockShape.getGlobalBounds().size.y >= sf::VideoMode::getDesktopMode().size.y) //Bottom boundary
		blockPosition.y = sf::VideoMode::getDesktopMode().size.y - blockShape.getGlobalBounds().size.y;

}

void Block::DrawBlock(sf::RenderWindow& RenderTarget)
{
	RenderTarget.draw(blockShape);
}
