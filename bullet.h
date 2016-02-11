#ifndef _BULLET_H
#define _BULLET_H

#include <SFML/Graphics.hpp>
#include <math.h>

#define DEG2RAD 3.14159f / 180.0f

class Bullet : public sf::Drawable, public sf::Transformable {
    static const float lifetime;
    static const float speed;

public:
    Bullet(sf::Vector2f position, float angle);
    ~Bullet();

    bool isAlive();
    void kill();
    void update(float frametime);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    bool is_alive;
    float remaining_life;
    sf::Vector2f direction;
};

#endif