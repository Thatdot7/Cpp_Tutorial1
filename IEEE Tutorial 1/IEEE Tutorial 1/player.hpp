#ifndef TUTORIAL_HPP
#define TUTORIAL_HPP

#include <string>

class Player {
	private:
		std::string _name;
	public:
		Player();
		Player(std::string name);
		std::string getName();
		int getPlayerMove();
};

#endif