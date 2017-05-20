//============================================================================
// Name        : Let it Burn Game.cpp
// Author      : Martin Rivera
// Version     : 1
// Date Started: 2017-04-22
// Date Finished:
// Description : Simulates propagation of fire or something like that.
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "tile.h"
#include "map.h"
#include "game.h"
#define fp "test_fp.txt"

using namespace std;

int main() {
	ifstream fp_file;
	fp_file.open("test_fp.txt");
	if(!fp_file.is_open()){
		cout << "No floorplan. Aborting.";
		return 0;
	}

	// Start setting up game board
	string fp_line;
	getline(fp_file,fp_line);
	int sp_2 = fp_line.find(" ", 3);
	int x_size = atoi(fp_line.substr(3,sp_2-3).c_str());
	int y_size = atoi(fp_line.substr(sp_2).c_str());
	game* cur_game = new game(x_size,y_size);			// need new player input stuff here

	while(!fp_file.eof()){
		getline(fp_file, fp_line);
		int cond = atoi(fp_line.substr(0,fp_line.find(" ")).c_str());
		getline(fp_file, fp_line);
		do{
			int x = atoi(fp_line.substr(0,fp_line.find(" ")).c_str());
			int y = atoi(fp_line.substr(fp_line.find(" ") + 1).c_str());
			if(cond == 100){
				cur_game->set_tile_exit(x,y);
			}else if(cond == 1000){
				cur_game->set_tile_mask(x,y);
			}else if(cond == 10000){
				cur_game->set_tile_user(x,y);
			}else{
				cur_game->fill_tile(x, y, cond);
			}
			getline(fp_file, fp_line);
		}while(fp_line != "END");
	}
	// Finish setting up game board

	// Start player turn
	string move;
	int has_moved = 1;

	do{
		cout << cur_game->print_map();
		do{
			if(has_moved == 0){
				cout << "Obstruction in the way!\nEnter another direction: ";
			}else{
				cout << "Enter your move: ";
			}
			cin >> move;
			cout << endl;
			has_moved = cur_game->move_player(move);
		}while(has_moved == 0);
		cur_game->inc_turn();
	}while((has_moved != 2) & (has_moved != 3));

	if(has_moved == 3){
		cout << "You quit.\nGame over.";
	}else{
		cout << "You escaped!\nGame over.";
	}

	return 0;
}




















