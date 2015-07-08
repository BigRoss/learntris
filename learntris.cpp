//Demo tetris game:
#include "game.h"
int main(){
	Game game;
	// Get input:
	std::string input = "";
	while(true){
		getline(std::cin, input);
		game.command(input);	
	}
	return 0;
}