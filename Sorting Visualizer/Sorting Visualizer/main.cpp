#include <SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include<random>
#include"algos.h"
#include"rectangle.h"
#include<thread>
constexpr int NUM_RECTS = 100;
constexpr std::pair<int, int> size{ std::make_pair(600,600) };
std::vector<Rectangle> genRects();

int main() {
    
    srand(time(NULL));
    std::vector<int> a{ 1,4,6,1,2,3,5,1,7 };
    sf::RenderWindow window(sf::VideoMode(size.first, size.second), "Sorting Visualizer");
    
    for (const auto& el : a) {
        std::cout << el << std::endl;
    }
    

    std::vector<Rectangle> rects = genRects();
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        selectionSort(rects, window);
        //rects = mergeSort(rects, window);
        for (auto& rect : rects) {
            rect.render(window);
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