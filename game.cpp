#include "game.h"

Game::Game(){
	m_mat = new tetMat();
}

Game::Game(int width, int height){
	m_mat = new tetMat(width, height);
}

Game::~Game(){
	delete m_mat;
}

void Game::command(std::string input){
	if(input == "q"){
		//Quit game
		exit(0);
	}
	else if(input == "p"){
		//Print the state of the matrix
		m_mat->printMatrix();
	}
	else{

	}
}