/*
 * game.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: Selth Afrinon
 */

#include "game.h"

// Constructors

game::game(int x, int y):board(x, y),user(0,0){

	max_x = x;
	max_y = y;
	turn_count = 1;
}

// Setters

void game::set_tile_mask(int x, int y){
	board.get_tile(x,y)->set_mask(true);
}

void game::set_tile_exit(int x, int y){
	board.get_tile(x,y)->make_exit();
}

void game::set_tile_user(int x, int y){
	user.set_x(x);
	user.set_y(y);
}

// manipulators

void game::fill_tile(int x, int y, int cond){
	board.get_tile(x, y)->apply_fp(cond);
}

void game::smoke_tile(int x, int y){
	board.get_tile(x,y)->apply_smoke();
	eval_tile(board.get_tile(x,y), true);

}

void game::smoke_all(){
	for(int i = 0; i < max_y; i++){
		for(int j = 0; j< max_x; j++){
			board.get_tile(j,i)->apply_smoke();
		}
	}
}

// uses "wasd" controls
int game::move_player(std::string in){
	int mov_x = user.get_x(), mov_y = user.get_y();
	int moved = 0;
	if(in == "w"){
		if(mov_y!= max_y - 1){
			int tile_cond = board.get_cond(mov_x, mov_y + 1);
			if((tile_cond == 4) || (tile_cond == 6) || (tile_cond == 7) || ((tile_cond == 0) & (user.get_mask()))){
				user.move_up();
				moved = 1;
			}else if(tile_cond == 3){
				board.get_tile(mov_x, mov_y + 1)->apply_fp(4);
				moved = 1;
			}
		}
	}else if(in == "s"){
		if(mov_y!= 0){
			int tile_cond = board.get_cond(mov_x, mov_y - 1);
			if((tile_cond == 4) || (tile_cond == 6) || (tile_cond == 7) || ((tile_cond == 0) & (user.get_mask()))){
				user.move_down();
				moved = 1;
			}else if(tile_cond == 3){
				board.get_tile(mov_x, mov_y - 1)->apply_fp(4);
				moved = 1;
			}
		}
	}else if (in == "a"){
		if(mov_x!= 0){
			int tile_cond = board.get_cond(mov_x - 1, mov_y);
			if((tile_cond == 4) || (tile_cond == 6) || (tile_cond == 7) || ((tile_cond == 0) & (user.get_mask()))){
				user.move_left();
				moved = 1;
			}else if(tile_cond == 3){
				board.get_tile(mov_x - 1, mov_y)->apply_fp(4);
				moved = 1;
			}
		}
	}else if (in == "d"){
		if(mov_x != max_x - 1){
			int tile_cond = board.get_cond(mov_x + 1, mov_y);
			if((tile_cond == 4) || (tile_cond == 6) || (tile_cond == 7) || ((tile_cond == 0) & (user.get_mask()))){
				user.move_right();
				moved = 1;
			}else if(tile_cond == 3){
				board.get_tile(mov_x + 1, mov_y)->apply_fp(4);
				moved = 1;
			}
		}
	}else if(in == "q"){
			moved = 3;
	}else{
		moved = 0;
	}

	if(moved & (board.get_tile(user.get_x(), user.get_y())->get_mask())){
		user.get_mask();
		board.get_tile(user.get_x(), user.get_y())->set_mask(false);
	}else if(moved & (board.get_tile(user.get_x(), user.get_y())->get_exit())){
		moved = 2;
	}
	return moved;
}

void game::inc_turn(){
	turn_count++;
}

std::string game::print_map(){
	std::string symbols = "SF#|/=_ X0DB";
	char buffer[50];
	sprintf(buffer, "%d\n", turn_count);
	std::string out = "Turn: ";
	out += buffer;
	if(user.get_mask()){
		out += "Player has a smoke mask.\n";
	}else{
		out += "Player does not have a smoke mask.\n";
	}
	for(int i = max_y; i >= -1; i--){
		for(int j = -1; j <= max_x; j++){
			if(i == max_y || i == -1){
				out += "II";
			}else if(j == -1 || j == max_x){
				out += "II";
			}else{
				if((user.get_x() == j) & (user.get_y() == i)){
					out += "P ";
				}else if(board.get_tile(j,i)->get_mask()){
					out += "MM";
				}else if(board.get_tile(j,i)->get_exit()){
					out += "EE";
				}else{
					out += symbols[board.get_tile(j,i)->get_cond()];
					out += symbols[board.get_tile(j,i)->get_cond()];
				}
				//out += " ";
			}
		}
		out += "\n";
	}
	out += "\n";
	return out;
}

// Tile Evaluators

void game::eval_tile(tile* cur_tile, bool x_fix){
	int cond = cur_tile->get_cond(),
			x = cur_tile->get_x(),
			y = cur_tile->get_y();
	tile_set to_check = tile_set();
	tile* check_tile;

	if(x != 0){
		to_check.add_tile(board.get_tile(x - 1, y));
	}

	if((y != 0)){
		to_check.add_tile(board.get_tile(x, y - 1));
	}

	if((x != max_x - 1)){
		to_check.add_tile(board.get_tile(x + 1, y));
	}

	if((y != max_y - 1)){
		to_check.add_tile(board.get_tile(x, y + 1));
	}

	if(cond == 0){
		tile_set sur_check = tile_set();
		bool is_smoked = false;
		for(int i = 0; i < to_check.get_size(); i++){
			check_tile = to_check.get_tile(i);
			if((check_tile->get_cond() == 1) & !is_smoked){
				cur_tile->apply_smoke();
				is_smoked = true;
				for(int j = 0; j < to_check.get_size(); j++){
					check_tile = to_check.get_tile(j);
					if(check_tile->get_cond() == 0){
						sur_check.add_tile(check_tile);
					}
				}
			}else if(check_tile->get_cond() == 6){
				sur_check.add_tile(check_tile);
			}
			eval_set(&sur_check, false);
		}
	}else if(cond == 1){
		tile_set sur_check = tile_set();
		for(int i = 0; i < to_check.get_size(); i++){
			check_tile = to_check.get_tile(i);
			if(check_tile->get_cond() == 0 || check_tile->get_cond() == 6){
				sur_check.add_tile(check_tile);
			}
		}
		eval_set(&sur_check, false);
	}else if(cond == 6){
		for(int i = 0; i < to_check.get_size(); i++){
			check_tile = to_check.get_tile(i);
			if(check_tile->get_cond() == 1){
				tile_set sur_check = tile_set();
				for(int j = 0; j < to_check.get_size(); j++){
					check_tile = to_check.get_tile(j);
					if(check_tile->get_cond() == 0){
						check_tile->apply_smoke();
						sur_check.add_tile(check_tile);
					}
				}
				eval_set(&sur_check, false);
				break;
			}
		}
	}else if(cond == 8){
		tile_set sur_check = tile_set();
		for(int i = 0; i < to_check.get_size(); i++){
			check_tile = to_check.get_tile(i);
			if(check_tile->get_cond() == 1 || check_tile->get_cond() == 0){
				check_tile->apply_smoke();
				sur_check.add_tile(check_tile);
			}else if(check_tile->get_cond() == 2){
				check_tile->apply_fp(10);
			}else if(check_tile->get_cond() == 3 || check_tile->get_cond() == 4 || check_tile->get_cond() == 5){
				check_tile->apply_fp(11);
			}else if(check_tile->get_cond() == 6){
				check_tile->apply_fp(1);
				sur_check.add_tile(check_tile);
			}
		}
		eval_set(&sur_check, false);
		board.get_tile(x,y)->apply_fp(9);
		if(x_fix){
			eval_set(&to_check, true);
		}
	}else if((cond == 9) & x_fix){
		tile_set sur_check = tile_set();
		cur_tile->apply_fp(1);
		for(int i = 0; i < to_check.get_size(); i++){
			check_tile = to_check.get_tile(i);
			if(check_tile->get_cond() == 9){
				sur_check.add_tile(check_tile);
			}else if(check_tile->get_cond() == 10){
				check_tile->apply_fp(5);
			}else if(check_tile->get_cond() == 11){
				check_tile->apply_fp(6);
			}
		}
		eval_set(&sur_check, true);
	}
	delete check_tile;
}

void game::eval_set(tile_set* in, bool ex_fix){
	for(int i = 0; i < in->get_size(); i++){
		eval_tile(in->get_tile(i), ex_fix);
	}
}
