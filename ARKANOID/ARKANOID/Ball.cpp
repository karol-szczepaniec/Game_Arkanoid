#include "Ball.h"



Ball::Ball(float t_X, float t_Y)
{

	shape.setPosition(t_X, t_Y); // ustawiam pozycjê kulki

	shape.setRadius(this->ballRadius); // ustawiam promieñ kulki

	shape.setFillColor(Color::Yellow); // ustawiam kolor

	// ustawiam Orgin - czyli punkt œrodka wzglêdem, którego s¹ przesuniêcia odbicia i inne transformacje
	shape.setOrigin(this->ballRadius, this->ballRadius);	// (x,y) przesuwam o wartoœæ promienia w prawo i w dó³, obie wartoœci dodatnie [tak, y te¿ dodatni]

}

// metoda wywo³ywana po przekazaniu obiektu do rysowania.
void Ball::draw(RenderTarget& target, RenderStates state) const	// renerTarget - przekazywane jest okno, renderStates- dodatkowe paramerty rysowanego obiektu
{
	target.draw(this->shape, state);
}

// metoda aktualizacji, po³o¿enia obiektu:

void Ball::update()
{
	// metoda move przesuwa o wartoœæ danego wektora, przkaujê wektor prêdkosci:
	shape.move(this->velocity);

	// dodajê do update'a sprawdzanie czy nie zas³a stycznoœæ z krawêdzi¹:
	if (this->left() < 0) // je¿eli lewa krawêdŸ jest mniejsza od 0
	{
		velocity.x = ballVelocity; // zmieniam na wartoœci dodatnie
	}
	else if (this->right() > 800) // jeœli prawa krawêdŸ jest wiêksza od 800, raczej powinno byæ przekazane przez wartoœæ to 800.
	{
		velocity.x = -ballVelocity;	// zmieniam na wartoœci ujemne
	}

	if (this->top() < 0) // je¿eli mniejsze ni¿ góra
	{
		velocity.y = ballVelocity;
	}
	else if (this->bottom() > 600) // je¿eli mniejsze ni¿ dó³
	{
		velocity.y = -ballVelocity;
	}

}


// zachowania stycznych krawêdzi:

float Ball::left()
{
	// pobieram aktualn¹ pozycjê kulki

	return this->shape.getPosition().x - shape.getRadius(); // pozycja klulki minus promieñ.
}

float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius(); // poycja kulki plus promieñ
}

float Ball::top()
{
	return this->shape.getPosition().y - shape.getRadius(); // pozycja minus promieñ, y roœnie w dó³
}

float Ball::bottom()
{
	return this->shape.getPosition().y + shape.getRadius(); // pozycja plus promieñ
}


// zachowanie metod move

void Ball::moveDown()
{
	this->velocity.y = ballVelocity;
}

void Ball::moveUp()
{
	this->velocity.y = -ballVelocity;
}

void Ball::moveRight()
{
	this->velocity.x = ballVelocity;
}

void Ball::moveLeft()
{
	this->velocity.x = -ballVelocity;
}

Vector2f Ball::getPosition()
{
	return shape.getPosition();
}