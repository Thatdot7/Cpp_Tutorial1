#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"

class GameBoard {
	private:
		volatile bool player_turn;
		volatile bool game_over;
		char board_state[9];
		Player _player1, _player2;
	public:
		GameBoard(Player& player1, Player& player2);
		void display();
		void next_turn();
		char check_game();
};

#endif