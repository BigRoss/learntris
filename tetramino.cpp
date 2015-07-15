#include "tetramino.h"

Tetramino::Tetramino(char tetName){
	m_active = false;
	m_blockName = tetName;
	setChar(tetName);

	int matrixSize = getMaxLength();
	displayMatrix = new tetMat(matrixSize, matrixSize);
	insertTet(displayMatrix);
}

Tetramino::~Tetramino(){

}

void Tetramino::showTetramino(){
	displayMatrix->printMatrix();
}

//To rotate a matrix 90/-90 degrees first transpose the matrix then reverse the rows, direction = 1 for 90 degree rotation, vice versa
void Tetramino::rotate(int direction){
	int matWidth = displayMatrix->getWidth();
	int matHeight = displayMatrix->getHeight();
	tetMat copy(matHeight, matHeight);
	//Make a copy of the display matrix:
	for(int i = 0; i < matHeight; i++){
		for(int j = 0; j < matWidth; j++){
			copy.setPoint(i, j, displayMatrix->getVal(i,j));
		}
	}

	//Rotate just for the display matrix:
	for(int i = 0; i < matHeight; i++){
		for(int j = 0; j < matWidth; j++){
			//Transpose the matrix:
			displayMatrix->setPoint(i, j, copy.getVal(j, i));
		}
	}

	//Rotate 90 degrees
	if(direction == 1){
		for(int i = 0; i < matHeight; i++){
			for(int j = 0; j < matWidth / 2; j++){
				//Reverse the rows:
				char temp = displayMatrix->getVal(j, i);
				displayMatrix->setPoint(j, i, displayMatrix->getVal(matWidth - j - 1, i));
				displayMatrix->setPoint(matWidth - j - 1, i, temp);
			}
		}
	}
	else{
		for(int i = 0; i < matWidth; i++){
			for(int j = 0; j < matHeight / 2; j++){
				//Reverse the columns:
				char temp = displayMatrix->getVal(i, j);
				displayMatrix->setPoint(i, j, displayMatrix->getVal(i, matHeight - j - 1));
				displayMatrix->setPoint(i, matHeight - j - 1, temp);
			}
		}
	}
		
}

void Tetramino::insertTet(tetMat* mat){
	if(m_blockName == 'I'){
		for(int i = 0; i < 4; i++){
			mat->setPoint(i, 1, m_char);	
		}
	}
	else if(m_blockName == 'O'){
		mat->setPoint(0, 0, m_char);
		mat->setPoint(0, 1, m_char);
		mat->setPoint(1, 0, m_char);
		mat->setPoint(1, 1, m_char);
	}
	else if(m_blockName == 'Z'){
		mat->setPoint(0, 0, m_char);
		mat->setPoint(1, 0, m_char);
		mat->setPoint(1, 1, m_char);
		mat->setPoint(2, 1, m_char);
	}
	else if(m_blockName == 'S'){
		mat->setPoint(1, 0, m_char);
		mat->setPoint(2, 0, m_char);
		mat->setPoint(0, 1, m_char);
		mat->setPoint(1, 1, m_char);
	}
	else if(m_blockName == 'J'){
		mat->setPoint(0, 0, m_char);
		mat->setPoint(0, 1, m_char);
		mat->setPoint(1, 1, m_char);
		mat->setPoint(2, 1, m_char);
	}
	else if(m_blockName == 'L'){
		mat->setPoint(0, 1, m_char);
		mat->setPoint(1, 1, m_char);
		mat->setPoint(2, 1, m_char);
		mat->setPoint(2, 0, m_char);
	}
	else if(m_blockName == 'T'){
		mat->setPoint(1, 0, m_char);
		mat->setPoint(0, 1, m_char);
		mat->setPoint(1, 1, m_char);
		mat->setPoint(2, 1, m_char);
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
