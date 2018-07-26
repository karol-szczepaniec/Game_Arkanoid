// w C++ 11 zamiast nawias�w () mo�na stosowa� {}
// wygl�da to tak:
// RenderWindow oknoAplikacji{VideoMode{800,600,32},"Arkanoid"};

// 1- stworzenie klasy kulki
// 2- rysowanie kulki na ekranie
// 3- kolizja kulki ze �cianami, poruszanie si� kulki vector2f
// 4- paletka

#include"Ball.h"
#include "Paddle.h"
#include "Block.h"
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>

//using namespace std;	// vector nale�y do przestrzeni nazw standardowych

// funkcja szablonowa
template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
	// kolizja dw�ch obiekt�w 
	return A.right() >= B.left() && A.left() <= B.right()
		&& A.bottom() >= B.top() && A.top() <= B.bottom();
}

// test kolizji paletka kulka
bool colisionTest(Paddle& paddle, Ball& ball)
{
	if (!isIntersecting(paddle, ball)) return false;

	ball.moveUp();

	if (ball.getPosition().x < paddle.getPosition().x)
	{
		ball.moveLeft();
	}
	else if (ball.getPosition().x > paddle.getPosition().x)
	{
		ball.moveRight();
	}
}

// kolizja kulki z bloczkiem:
bool colisionTest(Block& block, Ball& ball)
{
	if (!isIntersecting(block, ball)) return false;

	block.destroy();

	float overlapLeft{ ball.right() - block.left() };
	float overlapRight{ block.right() - ball.left() };

	float overlapTop{ball.bottom() - block.top()};
	float overlapBottom{block.bottom() - ball.top()};

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverLapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverLapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverLapX) < abs(minOverLapY))
	{
		ballFromLeft ? ball.moveLeft() : ball.moveRight();
	}
	else
	{
		ballFromTop ? ball.moveUp() : ball.moveDown();
	}
}


int main()
{
	// tworze okno aplikacji
	RenderWindow oknoAplikacji(VideoMode(800, 600, 32), "Arkanoid");

	// ustawianie FPS - frame per second, model fix time step
	oknoAplikacji.setFramerateLimit(60);

	// tworz� kulk� :

	Ball ball(400,300); // do konstruktora podrzucam �rodek ekranu

	// tworz� paletk�:

	Paddle paddle(400,570);

	// klocki
	unsigned blocksX{ 10 }, blocksY{ 4 }, blockWidth{ 60 }, blockHeight{20}; // ilo�� blok�w w rz�dzie i w wierszu, szeroko�� i wysoko�� klocka

	// tablica klock�w

	std::vector<Block> blocks; // wektor do przechowywania klock�w typu Block o nazwie blocks, konieczne u�ycie przestrzeni nazw std

	// iterowanie klock�w
	for (int i = 0; i < blocksY; i++)
	{
		for (int j = 0; j < blocksX; j++)
		{
			blocks.emplace_back((j + 1) *(blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
		}
	}

	// g��wna p�tla gry - niesko�czona p�tla
	while (oknoAplikacji.isOpen())


	{
		// zmienna do przechowywania zdarze�
		Event zdarzenie;

		// czyszcz� ekran do czarnego koloru
		oknoAplikacji.clear(Color::Black);

		// wewn�trzna p�tla obs�uguj�ca kolejk� zdarze� ( while do puki s� zdarzenia czyli pollEvent zwraca warto�� true.
		while (oknoAplikacji.pollEvent( zdarzenie ))
		{
			// je�li klikni�to na krzy�yk zamkni�aci aplikacji
			if (zdarzenie.type == Event::Closed)
			{
				// zamknij onko aplikacji
				oknoAplikacji.close();
			}

			// je�li klikni�to ESC
			if (zdarzenie.type == Event::KeyPressed  && zdarzenie.key.code == Keyboard::Escape)
			{
				// zamknij okno aplikacji
				oknoAplikacji.close();
			}
		}

		// update warto�ci po�o�enia:
		ball.update();
		paddle.update();
		colisionTest(paddle, ball);

		// sprawdzanie trafieniabloczka:
		for (auto& block : blocks)
		{
			if (colisionTest(block, ball)) break;
		}

		auto iterator = remove_if(begin(blocks), end(blocks), [](Block& block) {return block.isDestroyed();  });
		blocks.erase(iterator, end(blocks));
		

		// wywo�uj� metod� draw:
		oknoAplikacji.draw(ball);
		oknoAplikacji.draw(paddle);

		// rysowanie bloczk�w:
		for(auto& block : blocks)
			{
				oknoAplikacji.draw(block);
			}
		// pokazuje okno aplikacji na ekranie
		oknoAplikacji.display();
	}

	return 0;
}