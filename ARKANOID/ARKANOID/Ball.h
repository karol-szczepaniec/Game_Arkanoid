#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>

using namespace sf;

class Ball : public sf::Drawable	// Ball dziedziczy publicznie z klasy drawable
{
public:
	// tworze mój konstruktor:
	Ball(float t_X, float t_Y);  // koordynaty miejsca stworzenia obiektu, t-pod³oga

	Ball() = delete;	// usuwam konstruktor domyœlny
	~Ball() = default; // ustawiam konstruktor na domyœlny

	// aktualizacja obiektu co klatkê
	void update();

	// sprawdzanie stycznych krawêdzi, bêd¹ zwracaæ wspó³rzêdne krawêdzikszta³tu
	float left();
	float right();
	float top();
	float bottom();

	// metody do zmiany kierunku kulki
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	// pobieranie pozycji paletki oraz pi³ki

	Vector2f getPosition();

private:

	// tworzê obiekt kulki, za pomoc¹ prymitywu:
	CircleShape shape;	// primityw kulki

	const float ballRadius{ 10.0f }; // promieñ kulki, nowy sposób inicjalizowania {}

	const float ballVelocity{ 4.0f }; // nadanie ruchu kulce, wartoœæ prêdkoœci kulki  velocity - prêdkoœæ

	Vector2f velocity{ ballVelocity, ballVelocity }; // zmienna typu vector2f, (x,y) 

	// metoda rysuj¹ca - nadpisujê metodê z klasy Dravable, zawsze j¹ nadpisujê
	void draw(RenderTarget& target, RenderStates state) const override; // 1- render target z referencj¹, 2- render states | const podkreœla ze to metoda sta³a,
																		// override mówi ¿e jest nadpisana


};

