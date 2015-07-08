#include "game.h"

Game::Game(){
	m_mat = new tetMat();
	m_score = 0;
	m_cleared = 0;
}

Game::Game(int width, int height){
	m_mat = new tetMat(width, height);
	m_score = 0;
	m_cleared = 0;
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
	else if(input == "g"){
		//Parse and set new values
		std::string input = "";
		for(int i = 0; i < 22; i++){
			getline(std::cin, input);
			// std::cout << "input: [" << input << "] end input." << std::endl;
			int posCounter = 0;
			for(int j = 0; j < input.length(); j++){
				if(input.at(j) != ' '){
					m_mat->setPoint(posCounter, i, input.at(j));
					posCounter++;	
				}
			}
		}
	}
	else if(input == "c"){
		m_mat->clear();
	}
	else if(input == "?s"){
		std::stringstream ss;
		ss << m_score;
		std::cout << ss.str() << std::endl; 
	}
	else if(input == "?n"){
		std::stringstream ss;
		ss << m_cleared;
		std::cout << ss.str() << std::endl; 
	}
	else if(input == "s"){
		// m_mat->step();
	}
	else{

	}
}