#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

const static auto DEFAULT_COLOR = sf::Color(100, 250, 50);
class CustomRectangleShape : public sf::RectangleShape {
public:
    CustomRectangleShape(const sf::Vector2f &size, const sf::Vector2f &position) : sf::RectangleShape(size)
    {
        setPosition(position);
        setFillColor(DEFAULT_COLOR);
    }
    void setSpeed(const int &x_s, const int&y_s, const int &ro_s) {
        m_speed_x = x_s;
        m_speed_y = y_s;
        m_speed_ro = ro_s;
    }

    void animate(const sf::Time &elapsed){
        float dt = elapsed.asSeconds();
        move(m_speed_x * dt, m_speed_y * dt);
        rotate(m_speed_ro * dt);
        bounce();
    }
    void setBounds(const float& left, const float& right, const float& up,const float& down){
        bound_left  = left  ;
        bound_right  = right  ;
        bound_up  = up  ;
        bound_down  = down  ;
    }
    void change_color(sf::RectangleShape &rectangle)
    {
        rectangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    }
    void moveInDirection(float elapsed, const sf::Keyboard::Key &key) {
        if (not is_currently_selected_) {
            return;
        }
        sf::FloatRect bounding_box = getGlobalBounds();
        if (key == sf::Keyboard::Up and bounding_box.top > 0) {
            move(0, -m_speed_y * elapsed);
        } else if (key == sf::Keyboard::Down and
                   bounding_box.top + bounding_box.height < window_size.y) {
            move(0, m_speed_y * elapsed);
        } else if (key == sf::Keyboard::Left and bounding_box.left > 0) {
            move(-m_speed_x * elapsed, 0);
        } else if (key == sf::Keyboard::Right and
                   bounding_box.left + bounding_box.width < window_size.x) {
            move(m_speed_x * elapsed, 0);
        }
    }
    bool isClicked(const sf::Vector2i &mouse_position)
    {
        sf::FloatRect bounds = getGlobalBounds();
        if(mouse_position.x >= bounds.left && mouse_position.x <= bounds.left + bounds.width
                && mouse_position.y >= bounds.top && mouse_position.y <= bounds.top + bounds.height)
        {
            return true;
        }
        return false;
    }
    void select() {
        setFillColor(sf::Color(255, 0, 0));
        is_currently_selected_ = true;
    }
    void deselect() {
        setFillColor(DEFAULT_COLOR);
        is_currently_selected_ = false;
    }
private:
    int m_speed_x = 0 ;
    int m_speed_y = 0 ;
    int m_speed_ro = 0 ;
    float bound_left = 0;
    float bound_right = 0;
    float bound_up = 0;
    float bound_down = 0;
    bool is_currently_selected_ = false;
    sf::Vector2u window_size;
    void bounce(){
        sf::FloatRect rectangle_bounds = getGlobalBounds();

        if(rectangle_bounds.top <= bound_up){
            m_speed_y = abs(m_speed_y);
        }
        if(rectangle_bounds.top + rectangle_bounds.height >= bound_down){
            m_speed_y = abs(m_speed_y) * -1;
            setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }
        if(rectangle_bounds.left <= bound_left ){
            m_speed_x = abs(m_speed_x);
            setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }
        if(rectangle_bounds.left + rectangle_bounds.width >= bound_right){
            m_speed_x = abs(m_speed_x) * -1;
            setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }
    }
};
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    std::srand(std::time(nullptr));
    std::vector<CustomRectangleShape> rectangles;
    for(int i=0; i<10; i++)
    {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangleShape(size, position));
    }
    for(auto &rec : rectangles)
    {
        rec.setFillColor(sf::Color(0, 255, 0));
        rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rec.setSpeed(100, 200, 10);
    }
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(event.type == sf::Event::KeyReleased)
            {
                //                if(event.key.code == sf::Keyboard::Space)
                for (auto &rec : rectangles) {
                    rec.moveInDirection(dt, event.key.code);
                }
            }
            if(event.type == sf::Event::MouseButtonPressed)
            {
//                     if(event.mouseButton.button == sf::Mouse::Left)

                     sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                for (auto &rec : rectangles) {
                    if (rec.isClicked(mouse_pos))
                    {
                        rec.select();
                    }
                    else
                    {
                        rec.deselect();
                    }
                }
            }
        }
        window.clear(sf::Color::Black);

        for(auto &rec : rectangles)
        {
            window.draw(rec);
        }
        window.display();
    }
    return 0;
}
