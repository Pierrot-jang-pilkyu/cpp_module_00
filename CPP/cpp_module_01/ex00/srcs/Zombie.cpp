#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	cout << "<name> " << this->name << endl;
}

void	Zombie::setZombieName(string name)
{
	this->name = name;
}

string

Zombie::~Zombie()
{
	cout << this->name << "is dead." << endl;
}
