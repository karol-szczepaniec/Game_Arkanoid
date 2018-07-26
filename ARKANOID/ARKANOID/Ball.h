#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>

using namespace sf;

class Ball : public sf::Drawable	// Ball dziedziczy publicznie z klasy drawable
{
public:
	// tworze m�j konstruktor:
	Ball(float t_X, float t_Y);  // koordynaty miejsca stworzenia obiektu, t-pod�oga

	Ball() = delete;	// usuwam konstruktor domy�lny
	~Ball() = default; // ustawiam konstruktor na domy�lny

	// aktualizacja obiektu co klatk�
	void update();

	// sprawdzanie stycznych kraw�dzi, b�d� zwraca� wsp�rz�dne kraw�dzikszta�tu
	float left();
	float right();
	float top();
	float bottom();

	// metody do zmiany kierunku kulki
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	// pobieranie pozycji paletki oraz pi�ki

	Vector2f getPosition();

private:

	// tworz� obiekt kulki, za pomoc� prymitywu:
	CircleShape shape;	// primityw kulki

	const float ballRadius{ 10.0f }; // promie� kulki, nowy spos�b inicjalizowania {}

	const float ballVelocity{ 4.0f }; // nadanie ruchu kulce, warto�� pr�dko�ci kulki  velocity - pr�dko��

	Vector2f velocity{ ballVelocity, ballVelocity }; // zmienna typu vector2f, (x,y) 

	// metoda rysuj�ca - nadpisuj� metod� z klasy Dravable, zawsze j� nadpisuj�
	void draw(RenderTarget& target, RenderStates state) const override; // 1- render target z referencj�, 2- render states | const podkre�la ze to metoda sta�a,
																		// override m�wi �e jest nadpisana


};

