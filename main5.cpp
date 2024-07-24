#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow x1(sf::VideoMode(1280, 720), "Pong");
    x1.setFramerateLimit(60);

    sf::RectangleShape Raqueta1(sf::Vector2f(25.0f, 100.0f));
    Raqueta1.setFillColor(sf::Color::Yellow);
    Raqueta1.setPosition(10, 320);

    sf::RectangleShape Raqueta2(sf::Vector2f(25.0f, 100.0f));
    Raqueta2.setFillColor(sf::Color::Yellow);
    Raqueta2.setPosition(1245, 320);

    sf::CircleShape pelota(10.0f);
    pelota.setFillColor(sf::Color::Cyan);
    pelota.setPosition(630, 350);

    sf::RectangleShape Puntos(sf::Vector2f(10.0f, 100.0f));
    Puntos.setFillColor(sf::Color::White);
    Puntos.setPosition(640, 0);

    sf::RectangleShape Puntos1(sf::Vector2f(10.0f, 100.0f));
    Puntos1.setFillColor(sf::Color::White);
    Puntos1.setPosition(640, 120);

    sf::RectangleShape Puntos2(sf::Vector2f(10.0f, 100.0f));
    Puntos2.setFillColor(sf::Color::White);
    Puntos2.setPosition(640, 240);

    sf::RectangleShape Puntos3(sf::Vector2f(10.0f, 100.0f));
    Puntos3.setFillColor(sf::Color::White);
    Puntos3.setPosition(640, 360);

    sf::RectangleShape Puntos4(sf::Vector2f(10.0f, 100.0f));
    Puntos4.setFillColor(sf::Color::White);
    Puntos4.setPosition(640, 480);

    sf::RectangleShape Puntos5(sf::Vector2f(10.0f, 100.0f));
    Puntos5.setFillColor(sf::Color::White);
    Puntos5.setPosition(640, 600);

    sf::RectangleShape Puntos6(sf::Vector2f(10.0f, 100.0f));
    Puntos6.setFillColor(sf::Color::White);
    Puntos6.setPosition(640, 620);

    sf::Font fuente;
    if(!fuente.loadFromFile("../arial.ttf")){
        std::cerr<<"Error"<<std::endl;
        return -1;
    }
    sf::Text Score;
    Score.setFont(fuente);
    Score.setCharacterSize(30);
    Score.setFillColor(sf::Color::White);
    Score.setPosition(460,10);

    int puntosizq=0;
    int puntosder=0;

    sf::Vector2f velocidad(5.0f, 5.0f);
    float aumento = 1.1f;

    while (x1.isOpen()) {
        sf::Event event;
        while (x1.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                x1.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Raqueta1.getPosition().y > 0) {
            Raqueta1.move(0, -5.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Raqueta1.getPosition().y + 100 < 720) {
            Raqueta1.move(0, 5.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Raqueta2.getPosition().y > 0) {
            Raqueta2.move(0, -5.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && Raqueta2.getPosition().y + 100 < 720) {
            Raqueta2.move(0, 5.0f);
        }

        pelota.move(velocidad);

        if (pelota.getPosition().y <= 0 || pelota.getPosition().y + 20 >= 720) {
            velocidad.y = -velocidad.y;
        }

        if (pelota.getPosition().x <= 0) {
            puntosder++;
            pelota.setPosition(630, 350);
            velocidad = sf::Vector2f(5.0f, 5.0f);
        } else if (pelota.getPosition().x + 20 >= 1280) {
            puntosizq++;
            pelota.setPosition(630, 350);
            velocidad = sf::Vector2f(-5.0f, 5.0f);
        }

        if (pelota.getPosition().x <= Raqueta1.getPosition().x + Raqueta1.getSize().x &&
            pelota.getPosition().x + pelota.getRadius() * 2 >= Raqueta1.getPosition().x &&
            pelota.getPosition().y <= Raqueta1.getPosition().y + Raqueta1.getSize().y &&
            pelota.getPosition().y + pelota.getRadius() * 2 >= Raqueta1.getPosition().y) {
            velocidad.x = -velocidad.x * aumento;
            velocidad.y *= aumento;
            pelota.setPosition(Raqueta1.getPosition().x + Raqueta1.getSize().x, pelota.getPosition().y);
        }

        if (pelota.getPosition().x + pelota.getRadius() * 2 >= Raqueta2.getPosition().x &&
            pelota.getPosition().x <= Raqueta2.getPosition().x + Raqueta2.getSize().x &&
            pelota.getPosition().y <= Raqueta2.getPosition().y + Raqueta2.getSize().y &&
            pelota.getPosition().y + pelota.getRadius() * 2 >= Raqueta2.getPosition().y) {
            velocidad.x = -velocidad.x * aumento;
            velocidad.y *= aumento;
            pelota.setPosition(Raqueta2.getPosition().x - pelota.getRadius() * 2, pelota.getPosition().y);
        }

        Score.setString(std::to_string(puntosizq)+"                                 "+std::to_string(puntosder));
        x1.clear();
        x1.draw(Raqueta1);
        x1.draw(Raqueta2);
        x1.draw(Puntos);
        x1.draw(Puntos1);
        x1.draw(Puntos2);
        x1.draw(Puntos3);
        x1.draw(Puntos4);
        x1.draw(Puntos5);
        x1.draw(Puntos6);
        x1.draw(pelota);
        x1.draw(Score);
        x1.display();
    }

    return 0;
}
