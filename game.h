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
	float m_score;
	int m_cleared;
	tetMat* m_mat;
};

#endif