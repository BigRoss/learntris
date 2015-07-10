#include "tetramino.h"

Tetramino::Tetramino(char tetName){
	m_active = false;
	m_blockName = tetName;
	setChar(tetName);
}

Tetramino::~Tetramino(){

}

void Tetramino::setChar(char tetName){
	if(tetName == 'I'){
		m_char = 'c';
	}
	else if(tetName == 'O'){
		m_char = 'y';
	}
	else if(tetName == 'Z'){
		m_char = 'r';
	}
	else if(tetName == 'S'){
		m_char = 'g';
	}
	else if(tetName == 'J'){
		m_char = 'b';
	}
	else if(tetName == 'L'){
		m_char = 'o';
	}
	else if(tetName == 'T'){
		m_char = 'm';
	}
	else{
		//THIS MIGHT CAUSE PROBLEMS
		m_char = '.';
	}
}

void Tetramino::showTetramino(){
	//Make a matrix
	int matrixSize = getMaxLength();
	tetMat displayMatrix = tetMat(matrixSize, matrixSize);
	insertTet(displayMatrix);
	displayMatrix.printMatrix();
}

void Tetramino::insertTet(tetMat& mat){
	if(m_blockName == 'I'){
		for(int i = 0; i < 4; i++){
			mat.setPoint(i, 1, m_char);	
		}
	}
	else if(m_blockName == 'O'){
		mat.setPoint(0, 0, m_char);
		mat.setPoint(0, 1, m_char);
		mat.setPoint(1, 0, m_char);
		mat.setPoint(1, 1, m_char);
	}
	else if(m_blockName == 'Z'){
		mat.setPoint(0, 0, m_char);
		mat.setPoint(1, 0, m_char);
		mat.setPoint(1, 1, m_char);
		mat.setPoint(2, 1, m_char);
	}
	else if(m_blockName == 'S'){
		mat.setPoint(1, 0, m_char);
		mat.setPoint(2, 0, m_char);
		mat.setPoint(0, 1, m_char);
		mat.setPoint(1, 1, m_char);
	}
	else if(m_blockName == 'J'){
		mat.setPoint(0, 0, m_char);
		mat.setPoint(0, 1, m_char);
		mat.setPoint(1, 1, m_char);
		mat.setPoint(2, 1, m_char);
	}
	else if(m_blockName == 'L'){
		mat.setPoint(0, 1, m_char);
		mat.setPoint(1, 1, m_char);
		mat.setPoint(2, 1, m_char);
		mat.setPoint(2, 0, m_char);
	}
	else if(m_blockName == 'T'){
		mat.setPoint(1, 0, m_char);
		mat.setPoint(0, 1, m_char);
		mat.setPoint(1, 1, m_char);
		mat.setPoint(2, 1, m_char);
	}
}

int Tetramino::getMaxLength() const{
	if(m_blockName == 'I'){
		return 4;
	}
	else if(m_blockName == 'O'){
		return 2;
	}
	else if(m_blockName == 'Z'){
		return 3;
	}
	else if(m_blockName == 'S'){
		return 3;
	}
	else if(m_blockName == 'J'){
		return 3;
	}
	else if(m_blockName == 'L'){
		return 3;
	}
	else if(m_blockName == 'T'){
		return 3;
	}
}

