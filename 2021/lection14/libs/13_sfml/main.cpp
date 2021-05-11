#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    unsigned int sizeX = 800;
    unsigned int sizeY = 600;

    sf::RenderWindow window(sf::VideoMode(sizeX, sizeY), "SFML Window");

    sf::CircleShape shape(64.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture texture;
    if (!texture.loadFromFile("res/icon.png"))
    {
        std::cout << "Can not load texture!" << std::endl;
        return -1;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sprite.move(sf::Vector2f(0.1f, 0.1f));

        window.clear(sf::Color(255, 255, 255));
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
