#include <SFML/Graphics.hpp>
#include <iostream>

class Character
{
public:
	Character(const std::string& filePath, sf::Vector2f position);
	sf::Sprite getCharacter();
	sf::Texture getTextureCharacter();
	void setTexturePerso(sf::IntRect rect);
	void moveTop(float pos_y);
	void moveBottom(float pos_y);
	void moveRight(float pos_x);
	void moveLeft(float pos_x);
	void moveText();
	sf::Text getText();

private:
	int m_vie;
	std::string m_nom;
	sf::Text m_string;
	sf::Font font;
	sf::Image m_imgCharacter;
	sf::Texture m_textureCharacter;
	sf::Sprite m_character;
	int m_mana;
};
