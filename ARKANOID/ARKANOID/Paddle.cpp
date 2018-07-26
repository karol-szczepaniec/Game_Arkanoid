#include "Paddle.h"



Paddle::Paddle(float t_X, float t_Y)
{
	shape_p.setPosition(t_X, t_Y);
	shape_p.setSize({ this->paddleWidth,this->paddleHeight });
	shape_p.setFillColor(Color::Green);
	shape_p.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
}

void Paddle::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(this->shape_p, states);
}

void Paddle::update()
{
	this->shape_p.move(this->velocity);

	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
	{
		velocity.x = -paddleVelocity;
	}

	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800)
	{
		velocity.x = paddleVelocity;
	}

	else
	{
		velocity.x = 0;
	}
}


// zachowania stycznych krawêdzi:

float Paddle::left()
{
	// pobieram aktualn¹ pozycjê paletki

	return this->shape_p.getPosition().x - shape_p.getSize().x / 2.f; // pozycja paletki minus rozmiar
}

float Paddle::right()
{
	return this->shape_p.getPosition().x + shape_p.getSize().x / 2.f; // poycja kulki plus promieñ
}

float Paddle::top()
{
	return this->shape_p.getPosition().y - shape_p.getSize().y / 2.f; // pozycja minus promieñ, y roœnie w dó³
}

float Paddle::bottom()
{
	return this->shape_p.getPosition().y + shape_p.getSize().y / 2.f; // pozycja plus promieñ
}


Vector2f Paddle::getPosition()
{
	return shape_p.getPosition();
}