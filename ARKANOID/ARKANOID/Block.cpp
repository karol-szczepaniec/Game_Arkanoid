#include "Block.h"



Block::Block(float t_X, float t_Y, float t_Width, float t_Height)
{
	shape_b.setPosition(t_X, t_Y);
	shape_b.setSize({ t_Width, t_Height });
	shape_b.setFillColor(Color::Red);
	shape_b.setOrigin(t_Width / 2.f, t_Height / 2.f );

}

void Block::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(this->shape_b, states);
}

float Block::left()
{
	// pobieram aktualn¹ pozycjê paletki

	return this->shape_b.getPosition().x - shape_b.getSize().x / 2.f; // pozycja paletki minus rozmiar
}

float Block::right()
{
	return this->shape_b.getPosition().x + shape_b.getSize().x / 2.f; // poycja kulki plus promieñ
}

float Block::top()
{
	return this->shape_b.getPosition().y - shape_b.getSize().y / 2.f; // pozycja minus promieñ, y roœnie w dó³
}

float Block::bottom()
{
	return this->shape_b.getPosition().y + shape_b.getSize().y / 2.f; // pozycja plus promieñ
}

bool Block:: isDestroyed()
{
	return this->destroyed;
}

void Block::destroy()
{
	this->destroyed = true;
}

Vector2f Block::getSize()
{
	return shape_b.getSize();
}

void Block::update()
{

}