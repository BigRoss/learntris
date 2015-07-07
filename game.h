#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "tetMat.h"

class Game{
public:
	Game();

	Game(int width, int height);
	virtual ~Game();
	void command(std::string input);
	
private:
	tetMat* m_mat;
};

#endif