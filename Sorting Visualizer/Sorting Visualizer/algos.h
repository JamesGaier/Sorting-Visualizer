#pragma once
#include<vector>
#include<thread>
#include<algorithm>
#include<chrono>
#include"rectangle.h"
void swap(int a, int b, std::vector<Rectangle>& rects) {
	float temp = rects[a].getX();
	rects[a].setX(rects[b].getX());
	rects[b].setX(temp);
}
void bubbleSort(std::vector<Rectangle>& rects, sf::RenderWindow& window) {
	bool sorted = false;
	bool swapped = false;
	if (not sorted) {
		for (int i = 0; i < rects.size(); i++) {
			for (int j = 0; j < rects.size() - 1; j++) {
				window.clear();
				for (auto& rect : rects) {
				
					rect.render(window);
				}
				if (rects[j] > rects[j+1]) {
					swap(j, j + 1, rects);
					swapped = true;
				}
				sf::sleep(sf::milliseconds(10));
				window.display();
			}
		}
	}
	else {
		for (auto& rect : rects) {
			rect.render(window);
		}
	}
	if (swapped) sorted = true;
}
void insertionSort(std::vector<Rectangle>& rects, sf::RenderWindow& window) {
	for (int i = 1; i < rects.size(); i++) {
		int j = i;
		while (j > 0 and rects[j - 1] > rects[j]) {
			window.clear();
			for (auto& rect : rects) {
				rect.render(window);
			}
			swap(j, j - 1, rects);
			j--;
			sf::sleep(sf::milliseconds(20));
			window.display();
		}
	}
}
void selectionSort(std::vector<Rectangle>& rects, sf::RenderWindow& window) {
	for (int i = 0; i < rects.size() - 1; i++){
		int min = i;
		for (int j = i + 1; j < rects.size(); j++) {
			
			if (rects[j] < rects[min]) {
				min = j;
			}
		}
		window.clear();
		for (auto& rect : rects) {
			rect.render(window);
		}
		swap(i, min, rects);
		sf::sleep(sf::milliseconds(100));
		window.display();
	}
}
void mergeSort(std::vector<Rectangle>& rects, sf::RenderWindow& window) {

}
