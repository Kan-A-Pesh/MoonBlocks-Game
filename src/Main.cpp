#include "Platform/Platform.hpp"

int main()
{
	util::Platform platform;
	sf::RenderWindow window;

	window.create(sf::VideoMode(800, 600), "BlueMoon Game");
	platform.setIcon(window.getSystemHandle());

	sf::CircleShape shape(window.getSize().x / 2);
	shape.setFillColor(sf::Color::White);

	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("assets/sfml.png");
	shape.setTexture(&shapeTexture);

	sf::Event event;

	// Run the program as long as the window is open
	while (window.isOpen())
	{
		// Check every events
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}

void func()
{
	// this function is started when thread.launch() is called

	for (int i = 0; i < 10; ++i)
		std::cout << "I'm thread number one" << std::endl;
}