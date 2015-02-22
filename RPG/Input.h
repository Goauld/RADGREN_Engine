#ifndef _INPUT_H_
#define _INPUT_H_

#include <SFML/Graphics.hpp>

class Input
{
private:
	const int NUM_KEYCODES;
	const int NUM_MOUSEBUTTONS;

	bool* lastKeys;
	bool* lastMouse;

	//sf::Keyboard::Key int_to_key(int code);

public:
	Input(void);
	~Input(void);

	void Update();

	bool GetKey(sf::Keyboard::Key key);

	bool GetKeyDown(sf::Keyboard::Key keyCode);

	bool GetKeyUp(sf::Keyboard::Key keyCode);

	bool GetMouse(sf::Mouse::Button mouseButton);

	bool GetMouseDown(sf::Mouse::Button mouseButton);

	bool GetMouseUp(sf::Mouse::Button mouseButton);

	sf::Vector2f& GetMousePosition();

	sf::Vector2f& GetMousePosition(sf::RenderWindow& window);

	sf::Vector2i& GetMousePositionWithRotate(sf::RenderWindow& window, sf::View& view)
	{
	
	float AngleView = view.getRotation();

	sf::Vector2i Point_A;
	sf::Vector2i Point_B;
	sf::Vector2i Point_C;
	sf::Vector2i MousePosition;
	//view.setCenter(dx,dy);

	Point_C = sf::Mouse::getPosition(window);
	Point_A.x = Point_C.x;
	Point_A.y = 0;
	Point_B.x = 0;
	Point_B.y = 0;

	float AngleMouse = 0.0f;
	//AngleMouse = angle_point(Point_A,Point_B,Point_C);
	AngleMouse += AngleView;

	float Length = 0.0f;
	//Length = getlenght(Point_C,Point_B);

	MousePosition.x = cos(AngleMouse / 57.32) * (Length);
	MousePosition.y = sin(AngleMouse / 57.32) * (Length);


	return MousePosition;
	}

	void SetMousePosition(sf::Vector2f pos);

	//static void SetCursor(bool enabled);

};


#endif

