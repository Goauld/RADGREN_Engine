#include "CoreEngine.h"
#include "ErrorSystem.h"


	CoreEngine::CoreEngine(int width, int height, Game * game):LIMIT_TIME(2000.0f)
	{
		isRunning = false;
		this->game = game;
		this->width = width;
		this->height = height;
		window = nullptr;
		time = 0.0f;
		view.setCenter(width/2, height/2);
		view.setSize(width, height);
	}

	CoreEngine::~CoreEngine(void)
	{
		if(window != nullptr)
		{
			delete window;
			window = nullptr;
		}
	}

	void CoreEngine::createWindow(std::string name)
	{
		window = new sf::RenderWindow(sf::VideoMode(width, height), name);
	}

	void CoreEngine::start()
	{
		if(isRunning)
			return;

		run();
	}
	
	void CoreEngine::stop()
	{
		if(!isRunning)
			return;

		isRunning = false;
	}

	void CoreEngine::cleanUp()
	{
		window->close();
	}

	void CoreEngine::run()
	{
		isRunning = true;
		state = MAIN_MENU;

		try {
			game->init(width, height, window); 
		}
		catch(std::bad_alloc & ba){
			std::cerr << ba.what() << std::endl;
			state = CLOSE;
		}

		do
		{
			Sleep(1);
			try
			{
				if(event.type == sf::Event::Closed)
				{
					game->close();
					stop();
				}

				input.Update();
						
				switch(state)
				{
					case MAIN_MENU:
						{
							if(game->isLoad())
								game->close();

							view.setCenter(width/2, height/2);
							view.setSize(width, height);
							window->setView(view);

							state = menu.firstUpdate(*window, input);
							clock.restart();
						}
					break;

					case MENU:
						{
							view.setCenter(width/2, height/2);
							view.setSize(width, height);
							window->setView(view);

							state = menu.mainUpdate(*window, input);
							clock.restart();
						}
					break;

					case START:	
						{		
							game->start(); 
							state = GAME;
						}							
					break;

					case GAME:	
						{	
							game->input(input);
							state = menu.gameUpdate(*window, input);
							time = (float)clock.getElapsedTime().asMicroseconds() * 0.01f;

							if(time > LIMIT_TIME)
								throw ErrorSystem("too many time");
							else
								game->update(time);

							game->render();
							clock.restart();
						}	
					break;

					case LOAD:
						{
							game->loading(input);
							state = GAME;
							clock.restart();
						}
					break;

					case SAVE:
						{
							game->save();
							state = MAIN_MENU;
						}
					break;

					case PAUSE:
						{
							game->render();
							state = menu.psuseUpdate(*window,input);
						}
					break;

					case CLOSE:	
						{
							cleanUp(); 
							stop();	
						}					
					break;
				}
				window->display();
			}
			catch(ErrorSystem & a)
			{
				std::cerr << a.what() << std::endl;
				time = 0.0f;
				clock.restart();
			}
			catch(std::bad_alloc & ba)
			{
				std::cerr << ba.what() << std::endl;
				state = CLOSE;
			}
			catch(char * str)
			{
				std::cerr << str<< std::endl;
				state = CLOSE;
			}

		window->pollEvent(event);
		}while(isRunning && window->isOpen());
	}