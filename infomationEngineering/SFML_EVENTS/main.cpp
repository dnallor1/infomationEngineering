#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

const static auto DEFAULT_COLOR = sf::Color(100, 250, 50);
class CustomRectangleShape : public sf::RectangleShape {
public:
    CustomRectangleShape(const sf::Vector2f &size, const sf::Vector2f &position) : sf::RectangleShape(size) {
        setPosition(position);
        setFillColor(DEFAULT_COLOR);
    }
    void setSpeed(const int &x_s, const int&y_s, const int &ro_s) {
        m_speed_x = x_s;
        m_speed_y = y_s;
        m_speed_ro = ro_s;
    }
    void setBounds(const float& left, const float& right, const float& up,const float& down){
        bound_left  = left;
        bound_right  = right;
        bound_up  = up;
        bound_down  = down;
    }
    void moveInDirection(float dt, const sf::Keyboard::Key &key) {
        if (not currently_selected_) {
            return;
        }
        sf::FloatRect bounds = getGlobalBounds();
        if (key == sf::Keyboard::Up and bounds.top > 0) {
            bouncce();
            move(0, -m_speed_y * dt);
        } else if (key == sf::Keyboard::Down and
                   bounds.top + bounds.height > window_size.y) {
            bouncce();
            move(0, m_speed_y * dt);
        } else if (key == sf::Keyboard::Left and bounds.left > 0) {
            bouncce();
            move(-m_speed_x * dt, 0);
        } else if (key == sf::Keyboard::Right and
                   bounds.left + bounds.width > window_size.x) {
            bouncce();
            move(m_speed_x * dt, 0);
        }
    }
    void moveInDirection2(float dt, sf::Vector2i mouse_pos) {
        if (not currently_selected_) {
            return;
        }
        bouncce();
        move(mouse_pos.x * dt, mouse_pos.y * dt);
    }
    bool isClicked(const sf::Vector2i &mouse_position) {
        sf::FloatRect bounds = getGlobalBounds();
        if(mouse_position.x >= bounds.left &&
           mouse_position.x <= bounds.left + bounds.width &&
           mouse_position.y >= bounds.top &&
           mouse_position.y <= bounds.top + bounds.height) {
            return true;
        }
        return false;
    }
    void select() {
        setFillColor(sf::Color(255, 0, 0));
        currently_selected_ = true;
    }
    void deselect() {
        setFillColor(DEFAULT_COLOR);
        currently_selected_ = false;
    }
private:
    int m_speed_x = 0 ;
    int m_speed_y = 0 ;
    int m_speed_ro = 0 ;
    float bound_left = 0;
    float bound_right = 0;
    float bound_up = 0;
    float bound_down = 0;
    bool currently_selected_ = false;
    sf::Vector2u window_size;

    void bouncce(){
        sf::FloatRect rectangle_bounds = getGlobalBounds();
        if(rectangle_bounds.top <= bound_up){
            m_speed_y = abs(m_speed_y);
        }
        if(rectangle_bounds.top + rectangle_bounds.height >= bound_down){
            m_speed_y = abs(m_speed_y) * -1;
        }
        if(rectangle_bounds.left <= bound_left ){
           m_speed_x = abs(m_speed_x);
        }
        if(rectangle_bounds.left + rectangle_bounds.width >= bound_right){
            m_speed_x = abs(m_speed_x) * -1;
        }
    }
};
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    std::srand(std::time(nullptr));
    std::vector<CustomRectangleShape> rectangles;
    for(int i=0; i<10; i++) {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangleShape(size, position));
    }
    for(auto &rec : rectangles) {
        rec.setFillColor(sf::Color(0, 255, 0));
        rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rec.setSpeed(3000, 3000, 1500);
    }
    sf::Clock clock;
    bool clicked = false;
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.type == sf::Event::MouseButtonPressed) {
                //                     if(event.mouseButton.button == sf::Mouse::Left)
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                for (auto &rec : rectangles) {

                    if (rec.isClicked(mouse_pos)) {
                        rec.select();
                    }
                    else {
                        rec.deselect();
                    }
                }
                clicked = true;
            }
            if(event.type == sf::Event::MouseButtonReleased) {
                clicked = false;
            }
            if(event.type == sf::Event::KeyPressed) {
                //                                if(event.key.code == sf::Keyboard::Space)
                for (auto &rec : rectangles) {
                    rec.moveInDirection(dt, event.key.code);
                }
            }
            if(clicked && event.type == sf::Event::MouseMoved) {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                for (auto &rec : rectangles) {
                    rec.moveInDirection2(dt, mouse_pos);
                }
            }
        }
        window.clear(sf::Color::Black);
        for(auto &rec : rectangles) {
            window.draw(rec);
        }
        window.display();
    }
    return 0;
}
