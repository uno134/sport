#include "Game.h"

using namespace std;

int main()
{
	Game game( "Soccer" );

	// define players
	Player bene( "Bene", 'A' );
	Player billy( "Billy", 'B' );
	Player chienhui( "Chien Hui", 'D');
	Player chris( "Chris", 'A' );
	Player david( "David", 'A' );
	Player edo( "Edo", 'A' );
	Player hendry( "Hendry", 'C' );
	Player johan( "Johan", 'C' );
	Player jordy( "Jordy", 'B' );
	Player madison( "Madison", 'C' );
	Player marcel( "Marcel", 'D' );
	Player maria( "Maria", 'D' );
	Player mengkhun( "Meng Khun", 'B' );
	Player norman( "Norman", 'C' );
	Player ocep( "Ocep", 'B' );
	Player omJohn( "Om John", 'D' );
	Player randy( "Randy", 'D' );
	Player timmy( "Timmy", 'B' );
	Player timo( "Timotius", 'B' );
	Player waldorf( "Waldorf", 'C' );
	Player vincent( "Vincent", 'C');
	Player wiryadi( "Wiryadi", 'D' );
	Player yuchi( "Yuchi", 'D');
	
	// put players into list
	game.list.push_back( bene );
	game.list.push_back( billy );
	//game.list.push_back( chienhui );
	//game.list.push_back( chris );
	game.list.push_back( david );
	game.list.push_back( edo );
	game.list.push_back( hendry );
	game.list.push_back( johan );
	//game.list.push_back( jordy );
	//game.list.push_back( madison );
	game.list.push_back( marcel );
	//game.list.push_back( maria );
	game.list.push_back( mengkhun );
	game.list.push_back( norman );
	game.list.push_back( ocep );
	game.list.push_back( omJohn );
	game.list.push_back( randy );
	game.list.push_back( timmy );
	//game.list.push_back( timo );
	game.list.push_back( waldorf );
	game.list.push_back( vincent );
	game.list.push_back( wiryadi );
	game.list.push_back( yuchi );

	bool exit = false;
	int input = 0;
	char inputStr;
	
	while( !exit )
	{
		// refresh list of players
		vector< Player > playerList = game.list;
	
		// console output
		printf("=================================\n");
		printf("%20s\n", game.getName().c_str() );
		printf("=================================\n");
		printf("  Number of Players = %d\n", playerList.size() );
		printf("  Number of Group   = %d\n", game.maxGroup );
		printf("=================================\n");
		printf("SET (g)ROUP | (r)ANDOM | (q)UIT\n");
		printf("=================================\n");
		printf("Command : ");
		cin >> inputStr;

		if( inputStr == 'g' )
		{
			// Enter number of Group
			printf("Enter number of Group: ");
			while( !( cin >> game.maxGroup ) )
			{
				printf("!! Error, please enter a number !!\n");
				printf("Enter number of Group: ");
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		else if( inputStr == 'r' )
		{
			// randomise 
			if( game.maxGroup < 0 )
			{
				printf( "!! Cannot enter a negative number !!\n" );
			}
			else if( game.maxGroup == 0 )
			{
				printf( "!! Please enter a number of group first. Enter 'g' to setup a number of group !!\n" );
			}
			else if( game.maxGroup > game.list.size() )
			{
				printf( "!! Max number of group is %d !!\n", game.list.size() );
			}
			else 
			{
				game.numOfPlayers = playerList.size();
				game.minPlayers = game.numOfPlayers / game.maxGroup;
				game.resPlayers = (int)fmod((double)game.numOfPlayers, (double)game.maxGroup );

				game.setMaxPlayerPerCategory( playerList, game.minPlayers );
			
				for( int i = 1; i <= game.maxGroup; i++ )
				{	
					int numOfPlayersInGroup = game.minPlayers;
					if( game.resPlayers > 0 )
					{
						numOfPlayersInGroup++;
						game.resPlayers--;
					}
					game.collectPlayer( playerList, i, numOfPlayersInGroup );
				}
			}
		}
		else if( inputStr == 'q' )
		{
			// quit	
			exit = true;
		}
		else
		{
			printf( "!! Unknown Command !!\n" );
		}
		printf("\n");
	}
	
	printf( "!! Close Application !!" );
	return 0;
}