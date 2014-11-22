#include <SFML/Graphics.hpp>

class Tilemap : public sf::Drawable, public sf::Transformable
{
public:
	Tilemap();
	bool chargerMap(const std::string& tilePath, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
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
