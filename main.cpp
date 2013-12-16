#include <iostream>
#include <sstream>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

int main()
{
    using namespace sf;

    bool run = true;
    unsigned score = 0;
    RenderWindow w1;

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
                std::cout << scoreStream.str() << std::endl;
                w1.setTitle(scoreStream.str());
                break;
            }
            default:
                break;
            }
        }


        w1.clear();
        w1.display();
    }
}
