#pragma once

#include "Ball.h"

class Paddle : public sf::Drawable
{
public:
	Paddle(float t_X, float t_Y);

	Paddle() = delete; // domy�lny konstruktor usuwam

	~Paddle() = default; // konstruktor domy�lny

	void update(); // metoda update

	// sprawdzanie stycznych kraw�dzi, b�d� zwraca� wsp�rz�dne kraw�dzi kszta�tu
	float left();
	float right();
	float top();
	float bottom();

	Vector2f getPosition();

private:

	// musz� nadpisa� metod� DRAW:
	void draw(RenderTarget& target, RenderStates states) const override;

	// prostok�tna paletka
	RectangleShape shape_p;

	// szeroko�� i wysoko�� paletki;
	const float paddleWidth{ 80.0f };
	const float paddleHeight{ 20.0f };
	const float paddleVelocity{ 6.0f }; // pr�dko�� przesuwania paletki, velocity - pr�dko��

	// wektor pr�dko�ci:
	Vector2f velocity{ paddleVelocity,0.0f }; // (x,y) x= paddelVelocity, y =0


};

