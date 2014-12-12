#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Tilemap : public sf::Drawable, public sf::Transformable
{
public:
	Tilemap();
	bool chargerMap(const std::string& tilePath, sf::Vector2u tileSize, std::vector<unsigned int> tiles, unsigned int width, unsigned int height);
	std::vector<unsigned int> chargerFichierLevel(const std::string& levelPath, sf::Vector2i dim);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vertex* getVertex();
	sf::VertexArray getVertices();
	int getTileNumber();

private:
	sf::Texture m_textureTile;
	sf::VertexArray m_vertices;
	sf::Vertex* quad;
	int tileNumber;
};