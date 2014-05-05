#include <cstdlib>
#include <iostream>
#include <string>
#include "player.hpp"
#include "gameboard.hpp"

Player player1, player2;
bool game_over = false;

void welcome_message() {
	std::cout << "=======================================================================" << std::endl;
	std::cout << "WELCOME TO T3: TOE-TIC-TAC!!!" << std::endl;
	std::cout << "Because if the classic game had a pirated version, this would be it" << std::endl;
	std::cout << "=======================================================================" << std::endl;
}


void player_select() {
	std::string name;
	int option = 0;

	std::cout << "Is PLAYER 1 a [1]human or [2]computer? ";
	std::cin >> option;

	while((option < 1) || (option > 2) || !std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input (only accept 1 or 2)" << std::endl << "Is PLAYER 1 a [1]human or [2]computer? ";
		std::cin >> option;
	}

	if(option == 2) {
		std::cout << "Well Too Bad!!! It's a human" << std::endl;
	}

	std::cout << "Enter PLAYER1's name: ";
	std::cin >> name;

	player1 = Player(name);
	
	std::cout << "Is PLAYER 2 a [1]human or [2]computer? ";
	std::cin >> option;

	while((option < 1) || (option > 2) || !std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input (only accept 1 or 2)" << std::endl << "Is PLAYER 2 a [1]human or [2]computer? ";
		std::cin >> option;
	}

	if(option == 2) {
		std::cout << "Well Too Bad!!! It's a human" << std::endl;
	}
	std::cout << "Enter PLAYER2's name: ";
	std::cin >> name;
	
	player2 = Player(name);
}

int main() {
	welcome_message();
	player_select();
	GameBoard game = GameBoard(player1, player2);
	while(1) {
		game.display();
		game.next_turn();
	}
}

