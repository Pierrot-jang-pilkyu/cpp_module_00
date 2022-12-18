#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

using	std::cout;
using	std::cin;
using	std::endl;
using	std::string;

class Zombie
{
private:
	string	name;
public:
	Zombie();
	Zombie(string name);
	void	announce(void);
	void	setZombieName(string name);
	string	getZombieName(void);
	~Zombie();
};	

#endif
