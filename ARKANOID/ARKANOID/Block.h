#pragma once
#include<SFML\Graphics.hpp>

using namespace sf;

class Block : public sf::Drawable
{
public:
	Block(float t_X,float t_Y, float t_Width, float t_Height);
	Block() = delete;
	~Block() = default;

	void update();

	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

	bool isDestroyed(); // sprawdzanie czy bloczek jeszcz istnieje

	void destroy(); // metoda niszcz¹ca bloczek

	Vector2f getSize(); // pobieranie wielkoœci bloczka

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override; // odziedziczona metoda wypisuj¹ca

	RectangleShape shape_b;

	bool destroyed{ false };

}; 

