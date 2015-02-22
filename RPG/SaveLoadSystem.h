#ifndef _SAVE_LOAD_SYSTEM_H_
#define _SAVE_LOAD_SYSTEM_H_

#include <fstream>
#include <SFML/Graphics.hpp>
#include "Map.h"



class SaveLoadSystem
{
private:
	std::ifstream fin;
	std::ofstream fout;

public:
	SaveLoadSystem(void);
	~SaveLoadSystem(void);

	bool loadMap(Map* map,int & w, std::string nameConfigFile);

};


#endif

