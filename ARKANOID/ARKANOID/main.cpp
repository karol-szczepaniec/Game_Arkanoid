// w C++ 11 zamiast nawiasów () mo¿na stosowaæ {}
// wygl¹da to tak:
// RenderWindow oknoAplikacji{VideoMode{800,600,32},"Arkanoid"};

// 1- stworzenie klasy kulki
// 2- rysowanie kulki na ekranie
// 3- kolizja kulki ze œcianami, poruszanie siê kulki vector2f
// 4- paletka

#include"Ball.h"
#include "Paddle.h"
#include "Block.h"
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>

//using namespace std;	// vector nale¿y do przestrzeni nazw standardowych

// funkcja szablonowa
template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
	// kolizja dwóch obiektów 
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

	// tworzê kulkê :

	Ball ball(400,300); // do konstruktora podrzucam œrodek ekranu

	// tworzê paletkê:

	Paddle paddle(400,570);

	// klocki
	unsigned blocksX{ 10 }, blocksY{ 4 }, blockWidth{ 60 }, blockHeight{20}; // iloœæ bloków w rzêdzie i w wierszu, szerokoœæ i wysokoœæ klocka

	// tablica klocków

	std::vector<Block> blocks; // wektor do przechowywania klocków typu Block o nazwie blocks, konieczne u¿ycie przestrzeni nazw std

	// iterowanie klocków
	for (int i = 0; i < blocksY; i++)
	{
		for (int j = 0; j < blocksX; j++)
		{
			blocks.emplace_back((j + 1) *(blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
		}
	}

	// g³ówna pêtla gry - nieskoñczona pêtla
	while (oknoAplikacji.isOpen())


	{
		// zmienna do przechowywania zdarzeñ
		Event zdarzenie;

		// czyszczê ekran do czarnego koloru
		oknoAplikacji.clear(Color::Black);

		// wewnêtrzna pêtla obs³uguj¹ca kolejkê zdarzeñ ( while do puki s¹ zdarzenia czyli pollEvent zwraca wartoœæ true.
		while (oknoAplikacji.pollEvent( zdarzenie ))
		{
			// jeœli klikniêto na krzy¿yk zamkniêaci aplikacji
			if (zdarzenie.type == Event::Closed)
			{
				// zamknij onko aplikacji
				oknoAplikacji.close();
			}

			// jeœli klikniêto ESC
			if (zdarzenie.type == Event::KeyPressed  && zdarzenie.key.code == Keyboard::Escape)
			{
				// zamknij okno aplikacji
				oknoAplikacji.close();
			}
		}

		// update wartoœci po³o¿enia:
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
		

		// wywo³ujê metodê draw:
		oknoAplikacji.draw(ball);
		oknoAplikacji.draw(paddle);

		// rysowanie bloczków:
		for(auto& block : blocks)
			{
				oknoAplikacji.draw(block);
			}
		// pokazuje okno aplikacji na ekranie
		oknoAplikacji.display();
	}

	return 0;
}