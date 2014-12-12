#include "CollisionManager.h"

using namespace sf;

CollisionManager::CollisionManager(std::vector<bool> masque)
{
	masque.resize(1400);
}

bool CollisionManager::collisionTop(std::vector<bool> masque, int x, int y, int tailleTuile)
{
	if (masque[int(x / tailleTuile) + 50 * int((y / tailleTuile) - 1)] == true)
	{
		std::cout << "collision haut" << std::endl;
		return true;
	}
	return false;
}
bool CollisionManager::collisionDown(std::vector<bool> masque, int x, int y, int tailleTuile)
{
	if (masque[int(x / tailleTuile) + 50 * int((y / tailleTuile) + 1)] == true)
	{
		std::cout << "collision bas" << std::endl;
		return true;
	}
	return false;
}
bool CollisionManager::collisionRight(std::vector<bool> masque, int x, int y, int tailleTuile)
{
	if (masque[int((x / tailleTuile) + 1) + 50 * int(y / tailleTuile)] == true)
	{
		std::cout << "Collision droite" << std::endl;
		return true;
	}
	return false;
}
bool CollisionManager::collisionLeft(std::vector<bool> masque, int x, int y, int tailleTuile)
{
	if (masque[int((x / tailleTuile) - 1) + 50 * int(y / tailleTuile)] == true)
	{
		std::cout << "collision gauche" << std::endl;
		return true;
	}
	return false;
}