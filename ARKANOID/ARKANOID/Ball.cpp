#include "Ball.h"



Ball::Ball(float t_X, float t_Y)
{

	shape.setPosition(t_X, t_Y); // ustawiam pozycj� kulki

	shape.setRadius(this->ballRadius); // ustawiam promie� kulki

	shape.setFillColor(Color::Yellow); // ustawiam kolor

	// ustawiam Orgin - czyli punkt �rodka wzgl�dem, kt�rego s� przesuni�cia odbicia i inne transformacje
	shape.setOrigin(this->ballRadius, this->ballRadius);	// (x,y) przesuwam o warto�� promienia w prawo i w d�, obie warto�ci dodatnie [tak, y te� dodatni]

}

// metoda wywo�ywana po przekazaniu obiektu do rysowania.
void Ball::draw(RenderTarget& target, RenderStates state) const	// renerTarget - przekazywane jest okno, renderStates- dodatkowe paramerty rysowanego obiektu
{
	target.draw(this->shape, state);
}

// metoda aktualizacji, po�o�enia obiektu:

void Ball::update()
{
	// metoda move przesuwa o warto�� danego wektora, przkauj� wektor pr�dkosci:
	shape.move(this->velocity);

	// dodaj� do update'a sprawdzanie czy nie zas�a styczno�� z kraw�dzi�:
	if (this->left() < 0) // je�eli lewa kraw�d� jest mniejsza od 0
	{
		velocity.x = ballVelocity; // zmieniam na warto�ci dodatnie
	}
	else if (this->right() > 800) // je�li prawa kraw�d� jest wi�ksza od 800, raczej powinno by� przekazane przez warto�� to 800.
	{
		velocity.x = -ballVelocity;	// zmieniam na warto�ci ujemne
	}

	if (this->top() < 0) // je�eli mniejsze ni� g�ra
	{
		velocity.y = ballVelocity;
	}
	else if (this->bottom() > 600) // je�eli mniejsze ni� d�
	{
		velocity.y = -ballVelocity;
	}

}


// zachowania stycznych kraw�dzi:

float Ball::left()
{
	// pobieram aktualn� pozycj� kulki

	return this->shape.getPosition().x - shape.getRadius(); // pozycja klulki minus promie�.
}

float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius(); // poycja kulki plus promie�
}

float Ball::top()
{
	return this->shape.getPosition().y - shape.getRadius(); // pozycja minus promie�, y ro�nie w d�
}

float Ball::bottom()
{
	return this->shape.getPosition().y + shape.getRadius(); // pozycja plus promie�
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