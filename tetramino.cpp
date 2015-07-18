#include "tetramino.h"

Tetramino::Tetramino(char tetName){
	m_active = true;
	m_blockName = tetName;
	setChar(tetName);

	int matrixSize = getMaxLength();
	displayMatrix = new tetMat(matrixSize, matrixSize);
	m_displayX = 3;
	m_displayY = 0;
	if(displayMatrix->getHeight() == 2){
		m_displayX = 4;
	}

	insertTet(displayMatrix);
}

Tetramino::~Tetramino(){
	delete displayMatrix;
}

void Tetramino::showTetramino(){
	displayMatrix->printMatrix(0);
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

void Tetramino::insertTetGame(tetMat* mat){
	for(int i = 0; i < displayMatrix->getHeight(); i++){
		//TODO: Check if any blocks under the 2 block free zone at the top!
		for(int j = 0; j < displayMatrix->getWidth(); j++){
			if(displayMatrix->getVal(j, i) != '.'){
				char newChar = toupper(displayMatrix->getVal(j, i));
				mat->setPoint(m_displayX + j, m_displayY + i, newChar);	
			}
		}
	}
}

void Tetramino::hardDrop(tetMat* mat){
	int i = 0;
	while(i < 22){
		pushDown(mat);
		i++;
	}
	m_active = false;
}

void Tetramino::pushDown(tetMat* mat){
	char blockChar = toupper(m_char);
	for(int j = 0; j < mat->getWidth(); j++){
		for(int i = mat->getHeight() - 1; i >= 0; i--){
			if(mat->getVal(j, i) == blockChar && (mat->getVal(j, i + 1) != '.' ||  i + 1 >= mat->getHeight() ) ) {
				return;
			}
			else{
				break;
			}
		}
	}
	//Shift block down
	for(int j = 0; j < mat->getWidth(); j++){
		for(int i = mat->getHeight(); i >= 0; i--){
			if(mat->getVal(j, i) == blockChar){
				mat->setPoint(j, i + 1, blockChar);
				mat->setPoint(j, i, '.');
			}
		}
	}
	m_displayY++;
}

void Tetramino::pushLeft(tetMat* mat){
	char blockChar = toupper(m_char);
	for(int i = 0; i < mat->getHeight(); i++){
		//Check to see if there is anything to the left of the block, if there is then we can't move and return
		for(int j = 0; j < mat->getWidth(); j++){
			if(mat->getVal(j, i) == blockChar && (mat->getVal(j - 1, i) != '.' || j == 0)){
				return;
			}
			else{
				//Break as we only check the first block for each row
				break;
			}
		}
	}

	//Shift the block to the left:
	for(int i = 0; i < mat->getHeight(); i++){
		for(int j = 1; j < mat->getWidth(); j++){
			if(mat->getVal(j, i) == blockChar){
				mat->setPoint(j - 1, i, blockChar);
				mat->setPoint(j, i, '.');
			}
		}
	}
	m_displayX++;
}

void Tetramino::pushRight(tetMat* mat){
	char blockChar = toupper(m_char);
	for(int i = 0; i < mat->getHeight(); i++){
		//Check to see if there is anything to the right of the block, if there is then we can't move and return
		for(int j = mat->getWidth() - 1; j > 0; j--){
			if(mat->getVal(j, i) == blockChar && (mat->getVal(j - 1, i) != '.' || j == 0)){
				return;
			}
			else{
				//Possible to shift, check next column
				break;
			}
		}
	}

	//Shift the block to the right
	for(int i = 0; i < mat->getHeight(); i++){
		for(int j = mat->getWidth() - 1; j >= 0; j--){
			if(mat->getVal(j, i) == blockChar){
				mat->setPoint(j + 1, i, blockChar);
				mat->setPoint(j, i, '.');
			}
		}
	}
	m_displayX++;
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
