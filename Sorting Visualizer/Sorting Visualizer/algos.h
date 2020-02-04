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

void merge(std::vector<Rectangle>& arr, int low, int mid, int high, sf::RenderWindow& window)
{
	
    int leftLen = mid - low + 1;
    int rightLen = high - mid;
	

	std::vector<Rectangle> L(leftLen);
	std::vector<Rectangle> R(rightLen);

	for (auto i = 0; i < leftLen; i++) {
        L[i] = arr[low + i];

	}
    for (auto j = 0; j < rightLen; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < leftLen && j < rightLen)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
			arr[k].setX(k * arr[k].getGridSize());
            i++;
        }
        else
        {
            arr[k] = R[j];
			arr[k].setX(k * arr[k].getGridSize());
            j++;
        }
        k++;
    }


    while (i < leftLen)
    {
        arr[k] = L[i];
		arr[k].setX(k * arr[k].getGridSize());
        i++;
        k++;
    }

    while (j < rightLen)
    {
        arr[k] = R[j];
		arr[k].setX(k * arr[k].getGridSize());
        j++;
        k++;
    }
	window.clear();
	for (auto& rect : arr) {
		rect.render(window);
	}
	sf::sleep(sf::milliseconds(200));
	window.display();
}


void mergeSort(std::vector<Rectangle>& rects, const int low, const int high, sf::RenderWindow& window)
{
	
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSort(rects, low, mid, window);
		
        mergeSort(rects, mid + 1, high, window);

        merge(rects, low, mid, high, window);
		
    }
}