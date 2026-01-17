#pragma once
#include<iostream>
using namespace std;
class Screen
{
private:
	int height;
	int width;
	char* buffer;
public:
	Screen(int w, int h)
	{
		height = h;
		width = w;
		buffer = new char[height * width];
	}
	~Screen()
	{
		delete[] buffer;
	}
	void clear()
	{
		for (int i = 0; i < width * height; i++)
		{
			buffer[i] = ' ';
		}
	}

	void drawchar(int x, int y, char symbol)
	{
		if (x >= 0 && x < width && y >= 0 && y < height)
		{
			buffer[y * width + x] = symbol;
		}
	}

	void display()
	{
		cout << "\033[H";
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				cout << buffer[y * width + x];
			}
			cout << endl;
		}
	}
};