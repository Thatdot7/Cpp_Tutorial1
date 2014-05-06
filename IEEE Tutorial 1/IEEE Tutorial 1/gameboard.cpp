#include <iostream>
#include "gameboard.hpp"

GameBoard::GameBoard (Player& player1, Player& player2) {

	_player1 = player1;
	_player2 = player2;

	board_state[0] = '1';
	board_state[1] = '2';
	board_state[2] = '3';
	board_state[3] = '4';
	board_state[4] = '5';
	board_state[5] = '6';
	board_state[6] = '7';
	board_state[7] = '8';
	board_state[8] = '9';

	player_turn = false;
}

void GameBoard::display () {
	std::cout << std::endl << " " << board_state[0] << " | " << board_state[1] << " | " << board_state[2] << std::endl;
	std::cout << "---|---|---" << std::endl;
	std::cout << " " << board_state[3] << " | " << board_state[4] << " | " << board_state[5] << std::endl;
	std::cout << "---|---|---" << std::endl;
	std::cout << " " << board_state[6] << " | " << board_state[7] << " | " << board_state[8] << std::endl << std:: endl;
}

void GameBoard::next_turn() {

	int position;

	if(!player_turn) {
		std::cout << "It is " << _player1.getName() << "'s move" << std::endl;
		
		while(1) {
			position = _player1.getPlayerMove();

			if(board_state[position] != 'X' && board_state[position] != 'O') {
				board_state[position] = 'X';
				break;
			} else {
				std::cout << "That position has been already taken, try again" << std::endl;
			}
		}

	} else {
		std::cout << "It is " << _player2.getName() << "'s move" << std::endl;

		while(1) {
			position = _player2.getPlayerMove();

			if(board_state[position] != 'X' && board_state[position] != 'O') {
				board_state[position] = 'O';
				break;
			} else {
				std::cout << "That position has been already taken, try again" << std::endl;
			}
		}
	}
	player_turn = !player_turn;
}

char GameBoard::check_game() {

	if(board_state[0] == board_state[1] && board_state[1] == board_state[2]) { return board_state[0];
	} else if((board_state[3] == board_state[4]) && (board_state[4] == board_state[5])){ return board_state[3];
	} else if((board_state[6] == board_state[7]) && (board_state[7] == board_state[8])){ return board_state[6];
	} else if((board_state[0] == board_state[3]) && (board_state[3] == board_state[6])){ return board_state[0];
	} else if((board_state[1] == board_state[4]) && (board_state[4] == board_state[7])){ return board_state[1];
	} else if((board_state[2] == board_state[5]) && (board_state[5] == board_state[8])){ return board_state[2];
	} else if((board_state[0] == board_state[4]) && (board_state[4] == board_state[8])){ return board_state[0];
	} else if((board_state[2] == board_state[4]) && (board_state[4] == board_state[6])){ return board_state[2];
	} else { return NULL; }

}