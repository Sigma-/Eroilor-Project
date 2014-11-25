#include <SFML\Graphics.hpp>
#include <iostream>

class CollisionManager
{
public:
	CollisionManager();
	bool collisionTop(bool masque[], int x, int y, int tailleTuile);
	bool collisionDown(bool masque[], int x, int y, int tailleTuile);
	bool collisionRight(bool masque[], int x, int y, int tailleTuile);
	bool collisionLeft(bool masque[], int x, int y, int tailleTuile);
private:

};