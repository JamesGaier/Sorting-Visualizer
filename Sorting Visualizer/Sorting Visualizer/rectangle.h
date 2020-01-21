#pragma once
#include<SFML/Graphics.hpp>

class Rectangle {
private:
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::RectangleShape rect;
	sf::Color rect_color{ sf::Color::White };
public:
	Rectangle(const int i, const int w_height, const int num_rects) {
		const int GRID_SIZE = w_height/num_rects;
		size.x = GRID_SIZE;
		size.y = GRID_SIZE * i + GRID_SIZE;

		pos.x = i * GRID_SIZE;
		pos.y = w_height - size.y;
		
		rect.setPosition(pos);
		rect.setSize(size);
		rect.setFillColor(rect_color);
		rect.setOutlineThickness(1);
		rect.setOutlineColor(sf::Color(0,0,0));
	}
	void render(sf::RenderWindow& window) {
		window.draw(rect);
	}
	Rectangle() {}
	void setX(const float x) {
		pos.x = x;
		rect.setPosition(pos.x, pos.y);
	}
	void setY(const float y) {
		pos.y = y;
		rect.setPosition(pos.x, pos.y);
	}
	int getX() const {
		return pos.x;
	}
	int getY() const {
		return pos.y;
	}
	sf::Vector2f getSize() const {
		return size;
	}

	bool operator<(const Rectangle& rhs) {
		return (size.y > rhs.size.y and getX() < rhs.getX()) ? true : false;
	}
	bool operator<=(const Rectangle& rhs) {
		return (size.y >= rhs.size.y and getX() <= rhs.getX()) ? true : false;
	}
	bool operator>(const Rectangle& rhs) {
		return (size.y < rhs.size.y and getX() > rhs.getX()) ? true : false;
	}
	bool operator>=(const Rectangle& rhs) {
		return (size.y <= rhs.size.y and getX() >= rhs.getX()) ? true : false;
	}
};
