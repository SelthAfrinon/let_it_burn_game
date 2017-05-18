/*
 * player.h
 *
 *  Created on: May 9, 2017
 *      Author: Selth Afrinon
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class player{
private:
	int x, y;
	bool mask;

public:
	// constructors
	player(int, int);

	// setters
	void set_x(int);
	void set_y(int);

	// manipulators
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void give_mask();

	// getters
	int get_x();
	int get_y();
	bool get_mask();

	// deconstructors
	~player() {}

};



#endif /* PLAYER_H_ */
