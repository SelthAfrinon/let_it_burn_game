/*
 * game.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: Selth Afrinon
 */

#include "game.h"

game::game(int x, int y):board(x, y),user(0,0){

	max_x = x;
	max_y = y;
	turn_count = 0;
}

game::game(int x, int y, int play_start_x, int play_start_y):board(x, y),user(play_start_x, play_start_y){
	max_x = x;
	max_y = y;
	turn_count = 0;
}

void game::fill_tile(int x, int y, int cond){
	board.get_tile(x, y)->apply_fp(cond);
}

void game::smoke_tile(int x, int y){
	board.get_tile(x,y)->apply_smoke();
	turn_count++;
	eval_tile(x,y, new coord(x,y), true);

}

void game::smoke_all(){
	for(int i = 0; i < max_y; i++){
		for(int j = 0; j< max_x; j++){
			board.get_tile(j,i)->apply_smoke();
		}
	}
}

void game::eval_tile(int x, int y, coord* origin, bool x_fix){
	tile* cur_tile = board.get_tile(x,y);
	int cond = board.get_tile(x, y)->get_cond();
	coord_set* to_check = new coord_set();

	if((x != 0) & (x - 1 != origin->get_x())){
		to_check->add_coord(new coord(x - 1, y));
	}

	if((y != 0)){
		to_check->add_coord(new coord(x, y - 1));
	}

	if((x != max_x - 1)){
		to_check->add_coord(new coord(x + 1, y));
	}

	if((y != max_y - 1)){
		to_check->add_coord(new coord(x, y + 1));
	}

	if(cond == 0){
		tile* check_tile;
		coord_set* sur_check = new coord_set();
		bool is_smoked = false;
		for(int i = 0; i < to_check->get_size(); i++){
			check_tile = board.get_tile(to_check->get_coord(i));
			if((check_tile->get_cond() == 1) & !is_smoked){
				cur_tile->apply_smoke();
				is_smoked = true;
				for(int j = 0; j < to_check->get_size(); j++){
					check_tile = board.get_tile(to_check->get_coord(j));
					if(check_tile->get_cond() == 0){
						sur_check->add_coord(check_tile->get_coord());
					}
				}
			}else if(check_tile->get_cond() == 6){
				sur_check ->add_coord(check_tile->get_coord());
			}
			eval_set(sur_check);
		}
	}else if(cond == 1){
		tile* check_tile;
		coord_set* sur_check = new coord_set();
		for(int i = 0; i < to_check->get_size(); i++){
			check_tile = board.get_tile(to_check->get_coord(i));
			if(check_tile->get_cond() == 0 || check_tile->get_cond() == 6){
				sur_check->add_coord(check_tile->get_coord());
			}
		}
		eval_set(sur_check);
	}else if(cond == 6){
		tile* check_tile;
		for(int i = 0; i < to_check->get_size(); i++){
			check_tile = board.get_tile(to_check->get_coord(i));
			if(check_tile->get_cond() == 1){
				coord_set* sur_check = new coord_set();
				for(int j = 0; j < to_check->get_size(); j++){
					check_tile = board.get_tile(to_check->get_coord(j));
					if(check_tile->get_cond() == 0){
						check_tile->apply_smoke();
						sur_check->add_coord(check_tile->get_coord());
					}
				}
				eval_set(sur_check);
				break;
			}
		}
	}else if(cond == 8){
		tile* check_tile;
		coord_set* sur_check = new coord_set();
		for(int i = 0; i < to_check->get_size(); i++){
			check_tile = board.get_tile(to_check->get_coord(i));
			if(check_tile->get_cond() == 1 || check_tile->get_cond() == 0){
				check_tile->apply_smoke();
				sur_check->add_coord(check_tile->get_coord());
			}else if(check_tile->get_cond() == 2){
				check_tile->apply_fp(10);
			}else if(check_tile->get_cond() == 3 || check_tile->get_cond() == 4 || check_tile->get_cond() == 5){
				check_tile->apply_fp(11);
			}else if(check_tile->get_cond() == 6){
				check_tile->apply_fp(1);
				sur_check->add_coord(check_tile->get_coord());
			}
		}
		eval_set(sur_check);
		board.get_tile(x,y)->apply_fp(9);
		if(x_fix){
			eval_set(to_check, true);
		}
	}else if((cond == 9) & x_fix){
		tile* check_tile;
		coord_set* sur_check = new coord_set();
		cur_tile->apply_fp(1);
		for(int i = 0; i < to_check->get_size(); i++){
			check_tile = board.get_tile(to_check->get_coord(i));
			if(check_tile->get_cond() == 9){
				sur_check->add_coord(check_tile->get_coord());
			}else if(check_tile->get_cond() == 10){
				check_tile->apply_fp(5);
			}else if(check_tile->get_cond() == 11){
				check_tile->apply_fp(6);
			}
		}
		eval_set(sur_check, true);
	}
}

void game::eval_set(coord_set* in){
	for(int i = 0; i < in->get_size(); i++){
		eval_tile(in->get_coord(i)->get_x(), in->get_coord(i)->get_y(), in->get_coord(i), false);
	}
}

void game::eval_set(coord_set* in, bool x_fix){
	for(int i = 0; i < in->get_size(); i++){
		eval_tile(in->get_coord(i)->get_x(), in->get_coord(i)->get_y(), in->get_coord(i), x_fix);
	}
}

// uses "wasd" controls
bool game::move_player(std::string in){
	int mov_x = user.get_x(), mov_y = user.get_y();
	bool moved = false;
	if(in == "w"){
		if(mov_y!= max_y - 1){
			int tile_cond = board.get_cond(mov_x, mov_y + 1);
			if((tile_cond == 4) || (tile_cond == 6) || (tile_cond == 7) || ((tile_cond == 0) & (user.has_mask()))){
				user.move_up();
				moved = true;
			}else if(tile_cond == 3){
				board.get_tile(mov_x, mov_y + 1)->apply_fp(4);
				moved = true;
			}
		}
	}else if(in == "s"){
		if(mov_y!= 0){
			int tile_cond = board.get_cond(mov_x, mov_y - 1);
			if((tile_cond == 4) || (tile_cond == 6) || (tile_cond == 7) || ((tile_cond == 0) & (user.has_mask()))){
				user.move_down();
				moved = true;
			}else if(tile_cond == 3){
				board.get_tile(mov_x, mov_y - 1)->apply_fp(4);
				moved = true;
			}
		}
	}else if (in == "a"){
		if(mov_x!= 0){
			int tile_cond = board.get_cond(mov_x - 1, mov_y);
			if((tile_cond == 4) || (tile_cond == 6) || (tile_cond == 7) || ((tile_cond == 0) & (user.has_mask()))){
				user.move_left();
				moved = true;
			}else if(tile_cond == 3){
				board.get_tile(mov_x - 1, mov_y)->apply_fp(4);
				moved = true;
			}
		}
	}else if (in == "d"){
		if(mov_x != max_x - 1){
			int tile_cond = board.get_cond(mov_x + 1, mov_y);
			if((tile_cond == 4) || (tile_cond == 6) || (tile_cond == 7) || ((tile_cond == 0) & (user.has_mask()))){
				user.move_right();
				moved = true;
			}else if(tile_cond == 3){
				board.get_tile(mov_x + 1, mov_y)->apply_fp(4);
				moved = true;
			}
		}
	}else{
		moved = false;
	}

	if(moved & (board.get_tile(user.get_x(), user.get_y())->has_mask())){
		user.get_mask();
		board.get_tile(user.get_x(), user.get_y())->rem_mask();
	}
	return moved;
}


void game::print_map(){
	std::string symbols = "SF#|/=_ X0DB";
	std::cout << "Turn: " << turn_count << std::endl;
	for(int i = max_y; i >= -1; i--){
		for(int j = -1; j <= max_x; j++){
			if(i == max_y || i == -1){
				std::cout << "II";
			}else if(j == -1 || j == max_x){
				std::cout << "II";
			}else{
				if((user.get_x() == j) & (user.get_y() == i)){
					std::cout << "P ";
				}else if(board.get_tile(j,i)->has_mask()){
					std::cout << "MM";
				}else if(board.get_tile(j,i)->is_exit()){
					std::cout << "EE";
				}else{
					std::cout << symbols[board.get_tile(j,i)->get_cond()];
					std::cout << symbols[board.get_tile(j,i)->get_cond()];
				}
				//std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
