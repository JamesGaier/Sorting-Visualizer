#include <SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include<random>
#include"algos.h"
#include"rectangle.h"
#include<thread>
constexpr int NUM_RECTS = 30;
constexpr std::pair<int, int> size{ std::make_pair(600,600) };
std::vector<Rectangle> genRects();
bool isSorted(std::vector<Rectangle>& rects) {
    auto sorted = true;
    for (auto i = 0; i < rects.size() - 1; i++) {
        if (rects[i] > rects[i + 1]) {
            sorted = false;
        }
    }
    return sorted;
}
int main() {
    
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(size.first, size.second), "Sorting Visualizer");

    std::vector<Rectangle> rects = genRects();

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        if (not isSorted(rects)) {
            mergeSort(rects, 0, rects.size()-1, window);
        }
        else {
            for (auto& rect : rects) {
                rect.render(window);
            }
        }
        


        window.display();
    }
    return 0;
}

std::vector<Rectangle> genRects() {
    
    std::vector<Rectangle> to_ret;
    for (int i = 0; i < NUM_RECTS; i++) {
        to_ret.push_back(Rectangle(i, size.second, NUM_RECTS));
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, NUM_RECTS - 1);
    for (int i = 0; i < NUM_RECTS; i++) {
        int rand = dis(gen);
        float temp = to_ret[i].getX();
        to_ret[i].setX(to_ret[rand].getX());
        to_ret[rand].setX(temp);
    }

    return to_ret;
}