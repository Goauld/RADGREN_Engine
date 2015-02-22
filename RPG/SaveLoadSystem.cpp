#include "SaveLoadSystem.h"


	SaveLoadSystem::SaveLoadSystem(void)
	{
	}


	SaveLoadSystem::~SaveLoadSystem(void)
	{
	}

	 
	bool SaveLoadSystem::loadMap(Map* map,int & w, std::string nameConfigFile)
	{
		fin.open(nameConfigFile);

		try
		{
			for(int i=0; i<w; i++)
				for(int j=0; j<w; j++)
					fin >> map->getValue(i, j);
		}
		catch(...)
		{
			fin.close();
			return false;
		}

		fin.close();
		return true;
	}
