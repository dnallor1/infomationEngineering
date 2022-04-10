#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::CircleShape circle(30.0);
    circle.setPosition(200.0, 100.0);
    circle.setFillColor(sf::Color(100, 50, 250));

    sf::CircleShape circle1(50.0);
    circle1.setPosition(600.0, 400.0);
    circle1.setFillColor(sf::Color(100, 250, 50));


    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::RectangleShape rectangle1(sf::Vector2f(90.0, 45.0));
    rectangle1.setPosition(600.0, 100.0);
    rectangle1.setFillColor(sf::Color::Yellow);


    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(2);
    triangle.setPosition(300.0, 300.0);

    sf::ConvexShape triangle1;
    triangle1.setPointCount(3);
    triangle1.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle1.setPoint(1, sf::Vector2f(0.0, 60.0));
    triangle1.setPoint(2, sf::Vector2f(100.0, 20.0));
    triangle1.setOutlineColor(sf::Color::Green);
    triangle1.setOutlineThickness(2);
    triangle1.setPosition(100.0, 450.0);


    sf::Clock clock;
    int rect_velocity_x = 150;
    int rect_velocity_y = 450;
    int rect_ang_velocity = 10;

    int circ_velocity_x = 50;
    int circ_velocity_y = 150;
    int circ_ang_velocity = 5;

    int conv_velocity_x = 100;
    int conv_velocity_y = 300;
    int conv_ang_velocity = 15;

    bool flag_y = false;
    bool flag_x = false;

    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        rectangle.move(rect_velocity_x*dt,rect_velocity_y*dt);
        rectangle.rotate(rect_ang_velocity*dt);

        circle1.move(circ_velocity_x*dt,circ_velocity_y*dt);
        circle1.rotate(circ_ang_velocity*dt);

        triangle.move(conv_velocity_x*dt,conv_velocity_y*dt);
        triangle.rotate(conv_ang_velocity*dt);

        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
        std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
        std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;

        if(rectangle_bounds.top <= 0 || rectangle_bounds.top + rectangle_bounds.height >= window.getSize().y)
        {
            if(flag_y != true)
            {
                rect_velocity_y *= -1;
                rectangle.setFillColor(sf::Color(rand() % 256,
                                                 rand() % 256,
                                                 rand() % 256));
            }
            flag_y = true;
        }
        else
            flag_y = false;

        if(rectangle_bounds.left <= 0 || rectangle_bounds.left + rectangle_bounds.width >= window.getSize().x)
        {
            if(flag_x!=true)
            {
                rect_velocity_x *= -1;
                rectangle.setFillColor(sf::Color(rand() % 256,
                                                 rand() % 256,
                                                 rand() % 256));
            }
            flag_x = true;
        }
        else
            flag_x = false;

        sf::FloatRect circle1_bounds = circle1.getGlobalBounds();
        std::cout << circle1_bounds.top << " " << circle1_bounds.left << " " ;
        std::cout << circle1_bounds.width << " " << circle1_bounds.height << std::endl;

        if(circle1_bounds.top <= 0 ||circle1_bounds.top + circle1_bounds.height >= window.getSize().y)
        {
            if(flag_y != true)
            {
                circ_velocity_y *= -1;
                circle1.setFillColor(sf::Color(rand() % 256,
                                               rand() % 256,
                                               rand() % 256));
            }
            flag_y = true;
        }
        else
            flag_y = false;

        if(circle1_bounds.left <= 0 || circle1_bounds.left + circle1_bounds.width >= window.getSize().x)
        {
            if(flag_x!=true)
            {
                circ_velocity_x *= -1;
                circle1.setFillColor(sf::Color(rand() % 256,
                                               rand() % 256,
                                               rand() % 256));
            }
            flag_x = true;
        }
        else
            flag_x = false;

        sf::FloatRect triangle_bounds = triangle.getGlobalBounds();
        std::cout << triangle_bounds.top << " " << triangle_bounds.left << " " ;
        std::cout << triangle_bounds.width << " " << triangle_bounds.height << std::endl;

        if(triangle_bounds.top <= 0 || triangle_bounds.top + triangle_bounds.height >= window.getSize().y)
        {
            if(flag_y != true)
            {
                conv_velocity_y *= -1;
                triangle.setFillColor(sf::Color(rand() % 256,
                                                rand() % 256,
                                                rand() % 256));
            }
            flag_y = true;
        }
        else
            flag_y = false;

        if(triangle_bounds.left <= 0 || triangle_bounds.left + triangle_bounds.width >= window.getSize().x)
        {
            if(flag_x!=true)
            {
                conv_velocity_x *= -1;
                triangle.setFillColor(sf::Color(rand() % 256,
                                                rand() % 256,
                                                rand() % 256));
            }
            flag_x = true;
        }
        else
            flag_x = false;


        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(circle);
        window.draw(circle1);
        window.draw(rectangle);
        window.draw(rectangle1);
        window.draw(triangle);
        window.draw(triangle1);

        window.display();
    }
    return 0;
}
