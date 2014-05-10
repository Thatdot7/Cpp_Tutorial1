#include <string>
#include <iostream>
#include "player.hpp"

Player::Player () {
	_name = "";
}

Player::Player (std::string name) {
	_name = name;
}



std::string Player::getName() {
	return _name;
}

int Player::getPlayerMove() {

	int option = 0;

	std::cout << "Enter the number in which to take: " << std::endl;
	std::cin >> option;

	while(option < 1 || option > 9 || !std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout <<"Invalid number" << std::endl << "Enter the number in which to take: " << std::endl;
		std::cin >> option;
	}

	return option-1;
}
