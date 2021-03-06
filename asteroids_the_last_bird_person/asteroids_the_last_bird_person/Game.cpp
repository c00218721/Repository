//Name: Callum Lynch && Adam Kealy
//login: c00218721 && c00213914
//Date: Feb 27 -
//Time taken
//------------------------------------------------------
//Game of asteroids where we will defend the galaxy as the 
//last birdMan
//------------------------------------------------------
//known Bugs

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
#pragma comment(lib,"opengl32.lib") //
#pragma comment(lib,"glu32.lib") 

#include "SFML\Graphics.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.h"


int main()
{
	Game aGame;
	aGame.LoadContent();
	aGame.run();

	return 0;
}


void Game::LoadContent()
//loads the font file
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}
}

Game::Game()
{

	//menu screen message
	m_menuMessage.setFont(m_font);
	m_menuMessage.setCharacterSize(23);
	m_menuMessage.setColor(sf::Color::White);
	m_menuMessage.setPosition(100, 300);

	//hanger screen message
	m_hangerScreenMessage.setFont(m_font);
	m_hangerScreenMessage.setCharacterSize(23);
	m_hangerScreenMessage.setColor(sf::Color::White);
	m_hangerScreenMessage.setPosition(025, 300);//

	//upgrade screen message
	m_upgradeScreenMessage.setFont(m_font);
	m_upgradeScreenMessage.setCharacterSize(23);
	m_upgradeScreenMessage.setColor(sf::Color::White);
	m_upgradeScreenMessage.setPosition(025, 300);

	//buy screen message
	m_buyScreenMessage.setFont(m_font);
	m_buyScreenMessage.setCharacterSize(23);
	m_buyScreenMessage.setColor(sf::Color::White);
	m_buyScreenMessage.setPosition(025, 300);

	//navigation screen message
	m_navigationScreenMessage.setFont(m_font);
	m_navigationScreenMessage.setCharacterSize(23);
	m_navigationScreenMessage.setColor(sf::Color::White);
	m_navigationScreenMessage.setPosition(025, 300);
}


void Game::run()
{
	//create the window
	window.create(sf::VideoMode(600, 600), "ASTEROIDS: THELAST BIRD MAN");
	srand(time(nullptr));	//set the random speed
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	//clock object will keep the time
	sf::Clock clock;
	clock.restart();
	while (window.isOpen())
	{
		//check if the close buttin is pressed
		sf::Event event;
		while (window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since the last update and restart the clock
		timeSinceLastUpdate += clock.restart();


		//update every 60th of a second
		if (timeSinceLastUpdate > timePerFrame)
		{
			keyboardInput();
			updateVariables();

			display();

			//reset the timeSinceLastUpatde
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}//end while loop
}

void Game::keyboardInput()		//all these change the screens 
{
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))	//MENU TO HANGER
	{
		if (menuScreen == true)
		{
			menuScreen = false;
			hangerScreen = true;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))	//HANGER TO UPGRADE
	{
		if (hangerScreen == true)
		{
			hangerScreen = false;
			upgradeScreen = true;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))// HANGER TO NAVIGATION
	{
		if (hangerScreen == true)
		{
			hangerScreen = false;
			navigationScreen = true;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))//navigation to hanger
	{
		if (navigationScreen)
		{
			navigationScreen = false;
			hangerScreen = true;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))	// UPGRADE TO SHOP
	{
		if (upgradeScreen)
		{
			upgradeScreen = false;
			buyScreen = true;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))//upgrade to hanger
	{
		if (upgradeScreen)
		{
			upgradeScreen = false;
			hangerScreen = true;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))	//SHOP TO UPGRADE
	{
		if (buyScreen == true)
		{
			upgradeScreen = true;
			buyScreen = false;
		}
	}
	
}

void Game::updateVariables()
{

}
void Game::display()
{
	window.clear();																						// all these are to print the messages out to the screen

	m_licenseScreenMessage.setString("license screen man");

	m_hangerScreenMessage.setString("hanger screen man press 1 to go to upgrades and 2 to go to navigation");	
	
	m_menuMessage.setString("menu screen press Tab to go to  the hanger");

	m_upgradeScreenMessage.setString("upgrade screen press 3 to go to the shop and backspace to go back");

	m_buyScreenMessage.setString("shop screen press esc to go back");

	m_navigationScreenMessage.setString("navigation screen press esc to go back");


	if (licenseScreen)				//all these will print hte message to the screen 
	{
		window.draw(m_licenseScreenMessage);
	}

	if (menuScreen)
	{
		window.draw(m_menuMessage);
	}

	if (hangerScreen)
	{
		window.draw(m_hangerScreenMessage);
	}

	if (upgradeScreen)
	{
		window.draw(m_upgradeScreenMessage);
	}

	if (buyScreen)
	{
		window.draw(m_buyScreenMessage);
	}

	if (navigationScreen)
	{
		window.draw(m_navigationScreenMessage);
	}
	window.display();
}