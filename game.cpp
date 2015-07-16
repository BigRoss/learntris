#include "game.h"

Game::Game(){
	m_mat = new tetMat();
	m_score = 0;
	m_cleared = 0;
	m_currTet = NULL;
}

Game::Game(int width, int height){
	m_mat = new tetMat(width, height);	
	m_score = 0;
	m_cleared = 0;
	m_currTet = NULL;
}

Game::~Game(){
	delete m_mat;
}

void Game::command(std::string input){
	//Parse the input of spaces then execute commands
	int inputCounter = 0;
	char inputChar;
	while(inputCounter < input.length()){
		inputChar = input.at(inputCounter);
		if(inputChar == ' '){
			inputCounter++;
			continue;
		}
		else if(inputChar == '?'){
			inputCounter++;
			inputChar = input.at(inputCounter);
			if(inputChar == 's'){
				std::stringstream ss;
				ss << m_score;
				std::cout << ss.str() << std::endl; 
			}
			else if(inputChar == 'n'){
				std::stringstream ss;
				ss << m_cleared;
				std::cout << ss.str() << std::endl; 
			}
		}
		else if(inputChar == 'q'){
			//Quit game
			exit(0);
		}
		else if(inputChar == 'p'){
			//Print the state of the matrix
			m_mat->printMatrix();
		}
		else if(inputChar == 'g'){
			//Parse and set new values
			std::string newInput = "";
			for(int i = 0; i < 22; i++){
				getline(std::cin, newInput);
				// std::cout << "input: [" << input << "] end input." << std::endl;
				int posCounter = 0;
				for(int j = 0; j < newInput.length(); j++){
					if(newInput.at(j) != ' '){
						m_mat->setPoint(posCounter, i, newInput.at(j));
						posCounter++;	
					}
				}
			}
		}
		else if(inputChar == 'c'){
			m_mat->clear();
			delete m_currTet;
		}
		else if(inputChar == 's'){
			m_mat->step(m_score, m_cleared);
		}
		else if(inputChar == 'I' || inputChar == 'O' || inputChar == 'Z' || inputChar == 'S' || inputChar == 'J' || inputChar == 'L' || inputChar == 'T'){
			m_currTet = new Tetramino(inputChar);
		}
		else if(inputChar == 't'){
			//Diplay the tetramino in a matrix
			if(m_currTet != NULL){
				m_currTet->showTetramino();	
			}
		}
		else if(inputChar == ')'){
			if(m_currTet != NULL){
				m_currTet->rotate(1);	
			}
		}
		else if(inputChar == '('){
			if(m_currTet != NULL){
				m_currTet->rotate(0);	
			}
		}
		else if(inputChar == ';'){
			std::cout << std::endl;
		}
		else if(inputChar == 'P'){
			m_currTet->insertTetGame(m_mat);
			m_mat->printMatrix();
		}
		else if(inputChar == '<'){

		}
		else if(inputChar == '>'){
			
		}
		else{

		}
		
		inputCounter++;
	}
	
}