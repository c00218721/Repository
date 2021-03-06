#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML\Graphics.hpp"	//include ssfml commands
#include <iostream>				//adds iostram library

class Game
{
	//private game members


public:
	//player stuff goes here

	sf::RenderWindow window;

	sf::Font m_font;	//font for writing text

	sf::Text m_splashScreenMessage;
	sf::Text m_licenseScreenMessage;
	sf::Text m_menuMessage;
	sf::Text m_upgradeScreenMessage;
	sf::Text m_buyScreenMessage;
	sf::Text m_hangerScreenMessage;
	sf::Text m_navigationScreenMessage;
	//----------------------------------------------------------------------------
	bool licenseScreen = false;
	bool menuScreen = true;
	bool upgradeScreen = false;
	bool buyScreen = false;
	bool hangerScreen = false;
	bool navigationScreen = false;

public:
	Game();
	void LoadContent();
	void run();
	void keyboardInput();
	void updateVariables();
	void display();


};
