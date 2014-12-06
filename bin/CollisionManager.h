#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>

class CollisionManager
{
public:
	CollisionManager();
	bool collisionTop(std::vector<bool> masque, int x, int y, int tailleTuile);
	bool collisionDown(std::vector<bool> masque, int x, int y, int tailleTuile);
	bool collisionRight(std::vector<bool> masque, int x, int y, int tailleTuile);
	bool collisionLeft(std::vector<bool> masque, int x, int y, int tailleTuile);
private:

};