/*
includes all functions needed for Player class in Player.h
*/

# include <string>
using std::string;

# include "Player.h"

Player::Player() {
	name = "tbd";
}

void Player::setName(string nameIn) {
	name = nameIn;
}

string Player::getName() {
	return name;
}