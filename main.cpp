#include <sstream>
#include <random>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

sf::Vector2i randPos();
sf::Color randCol();

std::mt19937_64 rEngine;
sf::RenderWindow w1;

int main()
{
    using namespace sf;

    Color bg = randCol();
    bool run = true;
    unsigned score = 0;

    VideoMode v = VideoMode::getDesktopMode();
    v.width = 1;
    v.height = 1;

    w1.create(v, "Score: 0", Style::None);

    while (run)
    {
        Event event;
        while (w1.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                run = false;
                break;
            case Event::MouseButtonReleased:
            {
                std::stringstream scoreStream;
                scoreStream << "Score: " << ++score;
                w1.setTitle(scoreStream.str());
                w1.setPosition(randPos());
                bg = randCol();
                break;
            }
            default:
                break;
            }
        }

        w1.clear(bg);
        w1.display();
    }

    w1.close();
}

sf::Vector2i randPos()
{
    std::uniform_int_distribution<int> x(0,sf::VideoMode::getDesktopMode().width);
    std::uniform_int_distribution<int> y(0,sf::VideoMode::getDesktopMode().height);

    return {x(rEngine),y(rEngine)};
}

sf::Color randCol()
{
    std::uniform_int_distribution<int> dist(0,255);

    return sf::Color(dist(rEngine), dist(rEngine), dist(rEngine));

}
