#include "Player.h"

Player::Player( std::string nm, char cat )
{
	name = nm;
	category = cat;
}

std::string Player::getName( void )
{
	return this->name;
}

char Player::getCategory( void )
{
	return this->category;
}