#pragma once

#include <vector>
#include <random>		// Random
#include <stdlib.h>		
#include <math.h>		// fmod
#include <algorithm>	// sort

#include "Player.h"

class Game
{
	std::string	name;
	int maxA;
	int maxB;
	int maxC;
	int maxD;

	Game( void );
	
public:
	std::vector< Player > list;
	int maxGroup;
	int numOfPlayers;
	int minPlayers;
	int resPlayers;

	Game( std::string name );
	void setMaxPlayerPerCategory( std::vector< Player > list, int maxPlayer );
	void collectPlayer( std::vector< Player > &list,  int nr, int maxPlayer );
	static bool cmpCategory( Player p1, Player p2 );
	std::string getName( void );
};