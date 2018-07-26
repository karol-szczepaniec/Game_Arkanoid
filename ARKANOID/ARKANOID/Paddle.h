#pragma once

#include "Ball.h"

class Paddle : public sf::Drawable
{
public:
	Paddle(float t_X, float t_Y);

	Paddle() = delete; // domyœlny konstruktor usuwam

	~Paddle() = default; // konstruktor domyœlny

	void update(); // metoda update

	// sprawdzanie stycznych krawêdzi, bêd¹ zwracaæ wspó³rzêdne krawêdzi kszta³tu
	float left();
	float right();
	float top();
	float bottom();

	Vector2f getPosition();

private:

	// muszê nadpisaæ metodê DRAW:
	void draw(RenderTarget& target, RenderStates states) const override;

	// prostok¹tna paletka
	RectangleShape shape_p;

	// szerokoœæ i wysokoœæ paletki;
	const float paddleWidth{ 80.0f };
	const float paddleHeight{ 20.0f };
	const float paddleVelocity{ 6.0f }; // prêdkoœæ przesuwania paletki, velocity - prêdkoœæ

	// wektor prêdkoœci:
	Vector2f velocity{ paddleVelocity,0.0f }; // (x,y) x= paddelVelocity, y =0


};

