#include "Input.h"
#include <stdlib.h>


	Input::Input(void):NUM_KEYCODES(109), NUM_MOUSEBUTTONS(2)
	{
		lastKeys = nullptr;
		lastMouse = nullptr;
		lastKeys = new bool[NUM_KEYCODES];
		lastMouse = new bool[NUM_KEYCODES];
	}


	Input::~Input(void)
	{
		if(lastKeys != nullptr)
			delete [] lastKeys;
		if(lastMouse != nullptr)
			delete [] lastMouse;
	}

	/*sf::Keyboard::Key Input::int_to_key(int code)
	{
		switch(code)
		{
			case 0:			return sf::Keyboard::A;				break;
			case 1:			return sf::Keyboard::B;				break;
			case 2:			return sf::Keyboard::C;				break;
			case 3:			return sf::Keyboard::D;				break;
			case 4:			return sf::Keyboard::E;				break;
			case 5:			return sf::Keyboard::F;				break;
			case 6:			return sf::Keyboard::G;				break;
			case 7:			return sf::Keyboard::H;				break;
			case 8:			return sf::Keyboard::I;				break;
			case 9:			return sf::Keyboard::J;				break;
			case 10:		return sf::Keyboard::K;				break;
			case 11:		return sf::Keyboard::L;				break;
			case 12:		return sf::Keyboard::M;				break;
			case 13:		return sf::Keyboard::N;				break;
			case 14:		return sf::Keyboard::O;				break;
			case 15:		return sf::Keyboard::P;				break;
			case 16:		return sf::Keyboard::Q;				break;
			case 17:		return sf::Keyboard::R;				break;
			case 18:		return sf::Keyboard::S;				break;
			case 19:		return sf::Keyboard::T;				break;
			case 20:		return sf::Keyboard::U;				break;
			case 21:		return sf::Keyboard::V;				break;
			case 22:		return sf::Keyboard::W;				break;
			case 23:		return sf::Keyboard::X;				break;
			case 24:		return sf::Keyboard::Y;				break;
			case 25:		return sf::Keyboard::Z;				break;
			case 26:		return sf::Keyboard::Num0;			break;
			case 27:		return sf::Keyboard::Num1;			break;
			case 28:		return sf::Keyboard::Num2;			break;
			case 29:		return sf::Keyboard::Num3;			break;
			case 30:		return sf::Keyboard::Num4;			break;
			case 31:		return sf::Keyboard::Num5;			break;
			case 32:		return sf::Keyboard::Num6;			break;
			case 33:		return sf::Keyboard::Num7;			break;
			case 34:		return sf::Keyboard::Num8;			break;
			case 35:		return sf::Keyboard::Num9;			break;
			case 36:		return sf::Keyboard::Escape;		break;

			default: return sf::Keyboard::Unknown;
		}
		
	}*/

	void Input::Update()
	{
		for(int i = 0; i < NUM_KEYCODES; i++)
			lastKeys[i] = GetKey((sf::Keyboard::Key)i);
		
		for(int i = 0; i < NUM_MOUSEBUTTONS; i++)
			lastKeys[i] = GetMouse((sf::Mouse::Button)i);
	}

	bool Input::GetKey(sf::Keyboard::Key key)
	{
		return sf::Keyboard::isKeyPressed(key);
	}

	bool Input::GetKeyDown(sf::Keyboard::Key keyCode)
	{
		if(GetKey(keyCode) && !lastKeys[keyCode])
			return true;

		return false;
	}

	bool Input::GetKeyUp(sf::Keyboard::Key keyCode)
	{
		if(!GetKey(keyCode) && lastKeys[keyCode])
			return true;

		return false;
	}

	bool Input::GetMouse(sf::Mouse::Button mouseButton)
	{
		//try{
			return sf::Mouse::isButtonPressed(mouseButton);
	/*	}catch(...)
		{
			printf("2");
		}*/
	}

	bool Input::GetMouseDown(sf::Mouse::Button mouseButton)
	{
		return GetMouse(mouseButton) && !lastMouse[mouseButton];
	}

	bool Input::GetMouseUp(sf::Mouse::Button mouseButton)
	{
		return !GetMouse(mouseButton) && lastMouse[mouseButton];
	}

	sf::Vector2f& Input::GetMousePosition()
	{
		return (sf::Vector2f)sf::Mouse::getPosition();
	}

	sf::Vector2f& Input::GetMousePosition(sf::RenderWindow& window)
	{
		return (sf::Vector2f)sf::Mouse::getPosition(window);
	}

	void Input::SetMousePosition(sf::Vector2f pos)
	{
		sf::Mouse::setPosition((sf::Vector2i)pos);
	}

	/*void Input::SetCursor(bool enabled)
	{
		Mouse.setGrabbed(!enabled);
		sf::Mouse::
	}*/