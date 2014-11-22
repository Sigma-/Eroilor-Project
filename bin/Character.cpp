#include "Character.h"

using namespace sf;

Character::Character(const std::string& filePath, Vector2f position) : m_vie(100), m_mana(100), m_nom("Sigma")
{
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "erreur chargement police" << std::endl;


		m_string.setFont(font);
		m_string.setString(m_nom);
		m_string.setColor(Color::White);
		m_string.setCharacterSize(12);

	if (!m_imgCharacter.loadFromFile(filePath))
	{
		std::cout << "Erreur durant le chargement de l'image" << std::endl;
	}
	else
	{
		std::cout << "L'image a bien etee chargee" << std::endl;
		m_imgCharacter.createMaskFromColor(Color::White);
	}
	if (!m_textureCharacter.loadFromImage(m_imgCharacter))
	{
		std::cout << "Erreur durant le chargement de la texture" << std::endl;
	}
	else
	{
		std::cout << "texture chargee" << std::endl;
		m_character.setTexture(m_textureCharacter);
		m_character.setPosition(position);
	}
}
void Character::setTexturePerso(sf::IntRect rect)
{
	m_character.setTextureRect(rect);
}
void Character::moveText()
{
	m_string.setPosition(m_character.getPosition().x,m_character.getPosition().y - 15);
}
Sprite Character::getCharacter()
{
	return m_character;
}
Texture Character::getTextureCharacter()
{
	return m_textureCharacter;
}
void Character::moveTop(float pos_y)
{
	m_character.move(0, (-pos_y - 32));
}
void Character::moveBottom(float pos_y)
{
	m_character.move(0, pos_y += 32);
}
void Character::moveRight(float pos_x)
{
	m_character.move(pos_x += 32, 0);
}
void Character::moveLeft(float pos_x)
{
	m_character.move((-pos_x - 32) , 0);
}
sf::Text Character::getText()
{
	return m_string;
}
