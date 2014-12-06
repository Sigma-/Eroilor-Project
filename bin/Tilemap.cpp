#include "Tilemap.h"

using namespace sf;

Tilemap::Tilemap()
{}
bool Tilemap::chargerMap(const std::string& tilePath, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)
{
	if (!m_textureTile.loadFromFile(tilePath))
	{
		return false;
	}

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{

		tileNumber = tiles[i + j * width];

		int tu = tileNumber % (m_textureTile.getSize().x / tileSize.x);
		int tv = tileNumber / (m_textureTile.getSize().x / tileSize.x);

		quad = &m_vertices[(i + j * width) * 4];

		quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
		quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
		quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
		quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

		quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
		quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
		quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
		quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

		}

	return true;
}
void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	states.texture = &m_textureTile;

	target.draw(m_vertices, states);
}
std::vector<int> Tilemap::chargerFichierLevel(const std::string& levelPath, sf::Vector2i dim)
{
	std::vector<int> conf;
	conf.resize(dim.x, dim.y);
	std::ifstream level(levelPath);
	level.open(levelPath.c_str());
	std::string line(""), index("");
	int count(0);

	while(!level.eof())
	{
		std::getline(level, line);
		for (int i(0); i < line.length(); i++)
		{
			if (line[i] == ' ' || line[i] == ',')
			{
				conf[count] = (atoi(index.c_str()));
				index = "";
				count++;
			}
			if (line[i] == ',')break;
			else index += line[i];
		}
		index = "";
	}
	level.close();

	return conf;

}

sf::Vertex* Tilemap::getVertex()
{
	return quad;
}
sf::VertexArray Tilemap::getVertices()
{
	return m_vertices;
}
int Tilemap::getTileNumber()
{
	return tileNumber;
}