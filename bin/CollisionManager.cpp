#include "CollisionManager.h"

using namespace sf;

CollisionManager::CollisionManager()
{}

bool CollisionManager::collisionTop(bool masque[], int x, int y, int tailleTuile)
{
	if (masque[int(x / tailleTuile) + 50 * int((y / tailleTuile) - 1)] == 1)
	{
		std::cout << "collision haut" << std::endl;
		return true;
	}
	return false;
}
bool CollisionManager::collisionDown(bool masque[], int x, int y, int tailleTuile)
{
	if (masque[int(x / tailleTuile) + 50 * int((y / tailleTuile) + 1)] == 1)
	{
		std::cout << "collision bas" << std::endl;
		return true;
	}
	return false;
}
bool CollisionManager::collisionRight(bool masque[], int x, int y, int tailleTuile)
{
	if (masque[int((x / tailleTuile) + 1) + 50 * int(y / tailleTuile)] == 1)
	{
		std::cout << "Collision droite" << std::endl;
		return true;
	}
	return false;
}
bool CollisionManager::collisionLeft(bool masque[], int x, int y, int tailleTuile)
{
	if (masque[int((x / tailleTuile) - 1) + 50 * int(y / tailleTuile)] == 1)
	{
		std::cout << "collision gauche" << std::endl;
		return true;
	}
	return false;
}