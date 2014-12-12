#include <SFML/Graphics.hpp>

#include "Tilemap.h"
#include "Character.h"
#include "CollisionManager.h"

float switchFps = 100;
int SPEED = 1.8;


int main()
{

	std::vector<bool> masque = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	enum Dir{ Down, Left, Right, Up };
	sf::Vector2i anim(1, Down);
	sf::RenderWindow window(sf::VideoMode(1600, 896), "Eroilor Online 2D");

	Character perso1("character.png", sf::Vector2f(0, 0));
	Tilemap tilemap, tileItems;
	CollisionManager colMgr(masque);

	std::vector<unsigned int>level = tilemap.chargerFichierLevel("level.txt", sf::Vector2i(50,28));
	std::vector<unsigned int>levelItems = tileItems.chargerFichierLevel("levelItems.txt",sf::Vector2i(50,28));

	if (!tilemap.chargerMap("tilesMap.png", sf::Vector2u(32, 32), level, 50, 28))
		return -1;
	if (!tileItems.chargerMap("tileb.png", sf::Vector2u(32, 32), levelItems, 50, 28))
		return -1;

	bool updateFps = true;
	bool isMoving = false;

	sf::Clock timer;

	float fpsCount = 0;
	float fpsSpeed = 500;

	window.setFramerateLimit(120);

	//GESTIONNAIRE DES INPUTS

	while (window.isOpen())
	{
		int indexPersoX = (perso1.getCharacter().getPosition().x + 32) / 32;
		int indexPersoY = (perso1.getCharacter().getPosition().y + 32) / 32;
		int distanceAParcourirX(32 * indexPersoX - (perso1.getCharacter().getPosition().x));
		int distanceAParcourirY(32 * indexPersoY - (perso1.getCharacter().getPosition().y));

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;

				default:
					break;
				}
			}
				break;
			default:
				break;
			}

		}

		//Gestion du clavier

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			SPEED = 2.3;
		else
			SPEED = 1.8;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && indexPersoY != 0 && !colMgr.collisionTop(masque, perso1.getCharacter().getPosition().x, perso1.getCharacter().getPosition().y, 32) && !isMoving)
		{
			std::cout << "index du personnage : " << indexPersoY - 1 << " distance a parcourir : " << distanceAParcourirY << std::endl;
			distanceAParcourirY = 32;
				anim.y = Up;
				perso1.moveTop(SPEED);
				perso1.moveText();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && indexPersoY != 28 && !colMgr.collisionDown(masque, perso1.getCharacter().getPosition().x, perso1.getCharacter().getPosition().y, 32) && !isMoving)
		{
			std::cout << "index du personnage : " << indexPersoY << " distance a parcourir : " << distanceAParcourirY << std::endl;
			distanceAParcourirY = 32;
				anim.y = Down;
				perso1.moveBottom(SPEED);
				perso1.moveText();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && indexPersoX != 50 && !colMgr.collisionRight(masque, perso1.getCharacter().getPosition().x, perso1.getCharacter().getPosition().y, 32) && !isMoving)
		{
			std::cout << "index du personnage : " << indexPersoX << " distance a parcourir : " << distanceAParcourirX << " position du personnage : " << perso1.getCharacter().getPosition().x * 2<< std::endl;
			distanceAParcourirX = 32;
				anim.y = Right;
				perso1.moveRight(SPEED);
				perso1.moveText();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && indexPersoX != 0 && !colMgr.collisionLeft(masque, perso1.getCharacter().getPosition().x, perso1.getCharacter().getPosition().y, 32) && !isMoving)
		{
			std::cout << "index du personnage : " << indexPersoX - 1 << " distance a parcourir : " << distanceAParcourirX << std::endl;
			distanceAParcourirX = 32;
				anim.y = Left;
				perso1.moveLeft(SPEED);
				perso1.moveText();
		}
		else if (distanceAParcourirX < 32 && anim.y == Right && indexPersoX != 50)
		{
			isMoving = true;
			anim.y = Right;
			perso1.moveRight(SPEED);
			perso1.moveText();
		}
		else if (distanceAParcourirX < 32 && anim.y == Left && indexPersoX != 0)
		{
			isMoving = true;
			anim.y = Left;
			perso1.moveLeft(SPEED);
			perso1.moveText();
		}
		else if (distanceAParcourirY < 32 && anim.y == Down && indexPersoY != 28)
		{
			isMoving = true;
			anim.y = Down;
			perso1.moveBottom(SPEED);
			perso1.moveText();
		}
		else if (distanceAParcourirY < 32 && anim.y == Up && indexPersoY != 0)
		{
			isMoving = true;
			anim.y = Up;
			perso1.moveTop(SPEED);
			perso1.moveText();
		}
		else
		{
			anim.x = 1;
			updateFps = false;
			isMoving = false;
		}

		// Ralentir l'animation
		if (updateFps)
		{
			fpsCount += fpsSpeed * timer.restart().asSeconds();
		}
		else
		{
			fpsCount = 0;
			updateFps = true;
		}
		if (fpsCount >= switchFps)
		{
			anim.x++;

			if (anim.x * 32 >= perso1.getTextureCharacter().getSize().x)
				anim.x = 0;
			updateFps = false;
		}


		perso1.setTexturePerso(sf::IntRect(anim.x * 32, anim.y * 32, 32, 32));

		window.clear();
		window.draw(tilemap);
		window.draw(tileItems);
		window.draw(perso1.getText());
		window.draw(perso1.getCharacter());
		window.display();
	}

	return 0;
}