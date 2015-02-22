#include "ButtonManager.h"


	ButtonManager::ButtonManager(void)
	{
		button = nullptr;
		numberButton = 0;
	}


	ButtonManager::~ButtonManager(void)
	{
		ListButton.clear();

		if(button != nullptr)
			delete button;
	}


	void ButtonManager::addButton(std::string name, const sf::Vector2f& position, const float& width, const float& height)
	{
		button = new Button(position,width,height);

		if(button == nullptr)
			return;

		ListButton.insert(std::pair<std::string,Button>(name,*button));
		numberButton++;

		if(button != nullptr)
		{
			delete button;
			button = nullptr;
		}
	}

	void ButtonManager::addButton(std::string name, float Xpos, float Ypos, const float& width, const float& height)
	{
		button = new Button(Xpos,Ypos,width,height);

		if(button == nullptr)
			return;

		ListButton.insert(std::pair<std::string,Button>(name,*button));
		numberButton++;

		if(button != nullptr)
		{
			delete button;
			button = nullptr;
		}
	}

	void ButtonManager::setTetureButton(std::string nameButton, sf::Texture& textureUp, sf::Texture& textureDown)
	{
		ListButton.find(nameButton)->second.setTextureUp(textureUp);
		ListButton.find(nameButton)->second.setTextureDown(textureDown);
	}

	void ButtonManager::setPressed(std::string nameButton, bool a)
	{
		ListButton.find(nameButton)->second.setIsPressed(a);
	}

	void ButtonManager::addTextures(std::string nameConfigFile, std::string nameTextureFile)
	{
		sf::Image image;
		if(!image.loadFromFile(nameTextureFile))
			return;

		int x = 0;
		int y = 0;

		fin.open(nameConfigFile);

		for(it=ListButton.begin(); it!=ListButton.end(); it++)
		{
			for(int i=0; i<2; i++)
			{
				fin >> x;
				fin >> y;

				sf::IntRect intRect;
				intRect.height = (int)(it->second.getHeight());
				intRect.left = x;
				intRect.width = (int)(it->second.getWidth());
				intRect.top = y;

				if(!i)
					it->second.setTextureUp(image, intRect);
				else
					it->second.setTextureDown(image, intRect);
			}

		}

		fin.close();
	}

	bool ButtonManager::isPressed(std::string nameButton, sf::Vector2f mousePosition)
	{
		if(ListButton.find(nameButton)->second.isCollision(mousePosition))
			return true;

		return false;
	}

	void ButtonManager::draw(sf::RenderWindow& window)
	{
		for(it=ListButton.begin(); it!=ListButton.end(); it++)
			it->second.draw(window);
	}

	void ButtonManager::clear()
	{
		if(button != nullptr)
		{
			delete button;
			button = nullptr;
		}

		numberButton = 0;
		ListButton.clear();
	}
