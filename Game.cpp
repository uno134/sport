#include "Game.h"

Game::Game( std::string nm )
{
	name = nm;
	
	maxGroup = 0;
	numOfPlayers = 0;
	minPlayers = 0;
	resPlayers = 0;
}

bool Game::cmpCategory( Player p1, Player p2 )
{
	// sort category ASC
	return ( p1.getCategory() < p2.getCategory() );
}

void Game::setMaxPlayerPerCategory( std::vector< Player > list, int maxPlayer )
{
	int countA = 0;
	int countB = 0;
	int countC = 0;
	int countD = 0;
	
	// count player category
	for( unsigned int i = 0; i < list.size(); i++ )
	{
		if( list[ i ].getCategory() == 'A' )
		{
			countA++;
		}
		else if( list[ i ].getCategory() == 'B' )
		{
			countB++;
		}
		else if( list[ i ].getCategory() == 'C' )
		{
			countC++;
		}
		else if( list[ i ].getCategory() == 'D' )
		{
			countD++;
		}
		else
		{
			printf("!! Unknown category: %s !!\n", list[ i ].getCategory() );
		}
	}

	int totalPlayer = list.size();

	// determine max player per category in a group
	maxA = (int)ceil( (double)( countA * maxPlayer ) / totalPlayer );
	maxB = (int)ceil( (double)( countB * maxPlayer ) / totalPlayer );
	maxC = (int)ceil( (double)( countC * maxPlayer ) / totalPlayer );
	maxD = (int)ceil( (double)( countD * maxPlayer ) / totalPlayer );
}

void Game::collectPlayer( std::vector< Player > &list,  int nr, int maxPlayer )
{
	std::vector< Player > group;

	// create random number as index
	std::random_device rd;
	std::mt19937 gen( rd() );

	// collect player
	int numOfPlayer = 0;

	int countA = maxA;
	int countB = maxB;
	int countC = maxC;
	int countD = maxD;
	
	int iter = 0;

	while( numOfPlayer != maxPlayer )
	{
		// pick random
		std::uniform_int_distribution< int > dist( 0, list.size() - 1 );
		int index = dist( gen );
		bool takePlayer = false;
		
		// pick player based on its category
		if( list[ index ].getCategory() == 'A' && countA > 0 )
		{
	    	countA--;
	    	takePlayer = true;
		}
		else if( list[ index ].getCategory() == 'B' && countB > 0 )
		{
	    	countB--;
	    	takePlayer = true;
		}
		else if( list[ index ].getCategory() == 'C' && countC > 0 )
		{
	    	countC--;
	    	takePlayer = true;
		}
		else if( list[ index ].getCategory() == 'D' && countD > 0 )
		{
	    	countD--;
	    	takePlayer = true;
		}
		else
		{
			iter++;
			// if no more player within category is available, pick any available player
			if( iter >= list.size() )
			{
				takePlayer = true;
			}
		}
	    	
		if( takePlayer )
		{
			// put player into group
	    	group.push_back( list[ index ] );
			list.erase( list.begin() + index );
	    	numOfPlayer++;
	    	iter = 0;
		} 
	}
	
	// print player list in group
	printf("===================\n");
	printf("      Group %d\n", nr );
	printf("===================\n");

	sort( group.begin(), group.end(), &Game::cmpCategory );
	
	for ( unsigned int i = 0; i < group.size(); i++ )
	{
		printf( "%*d. %c >> %s\n", 3, i + 1, group[ i ].getCategory(), group[ i ].getName().c_str() );
	}
	printf("\n");
}

std::string Game::getName( void )
{
	return this->name;
}