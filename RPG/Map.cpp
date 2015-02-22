#include "Map.h"


	Map::Map(int width, int height)
	{
		null = ' ';
		Width = width;
		Height = height;
		this->size = Width * Height;
		array = nullptr;

		if(size > 0)
			this->array = new char[size];
		else
		{
			this->array = nullptr;
			throw "size must be > 0!";
		}

		if(this->array == nullptr)
			throw std::bad_alloc();
	}


	Map::~Map(void)
	{
		if(array != nullptr)
		{
			delete [] array;
			array = nullptr;
		}
	}



	char & Map::getValue(int i, int j)
	{
		null = ' ';

		if(i < 0 || j < 0 || i >= Width || j >= Height)
			return null;

		return array[i*Width + j];
	}