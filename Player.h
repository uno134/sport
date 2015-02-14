#pragma once

#include<iostream>

class Player
{
private:
	std::string name;
	char category;
	Player( void );

public:
	Player( std::string nm, char cat );

	char getCategory( void );
	std::string getName( void );
};