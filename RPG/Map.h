#ifndef _MAP_H_
#define _MAP_H_

#include <new> 


class Map
{
private:
	char* array;
	int size;
	int Width, Height;
	char null;

public:
	Map(int width, int height);
	~Map(void);

	char & getValue(int i, int j);

	inline int getSize()   {	return size;		}
	inline int getWidth()  {	return Width;		}
	inline int getHeight() {	return Height;		}

};


#endif
