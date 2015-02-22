#include "TestGame.h"


		TestGame::TestGame(void)
		{
			window = nullptr;
		}

		TestGame::~TestGame(void)
		{

		}

		void TestGame::init(const int & w, const int & h, sf::RenderWindow * window)
		{
			this->window = window;
		}

		void TestGame::input(Input & input)
		{

		}

		void TestGame::start()
		{

		}

		void TestGame::update(const float & time)
		{

		}

		void TestGame::save()
		{
		
		}

		void TestGame::loading(Input & input)
		{
		
		}

		void TestGame::render()
		{
			if(window == nullptr)
				throw "!?";


			window->clear();
		}

		bool TestGame::isLoad()
		{
			return load;
		}

		void TestGame::close()
		{
		
		}