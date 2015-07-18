#include "tetMat.h"

tetMat::tetMat() : m_width(10), m_height(22){
	create();
}

tetMat::tetMat(int width, int height) : m_width(width), m_height(height){
	create();
}

tetMat::~tetMat(){

}

//Set a point in the matrix to another character
void tetMat::setPoint(int x, int y, char newVal){
	m_mat[y][x] = newVal;
}

//Reset the matrix
void tetMat::clear(){
	for(int i = 0; i < m_height; i++){
		for(int j = 0; j < m_width; j++){
			m_mat[i][j] = '.';
		}
	}
}

void tetMat::clearActive(){
	for(int i = 0; i < m_height; i++){
		for(int j = 0; j < m_width; j++){
			if(isupper(m_mat[i][j])){
				m_mat[i][j] = '.';
			}
		}
	}
}


void tetMat::step(float& score, int& cleared){
	for(int i = 0; i < m_height; i++){
		bool line = true;
		for(int j = 0; j < m_width; j++){
			if(m_mat[i][j] == '.'){
				line = false;
				break;
			}
		}
		//If we clear a line then increment score and lines cleared, also reset the cleared line
		if(line){
			for(int j = 0; j < m_width; j++){
				m_mat[i][j] = '.';
			}
			cleared++;
			score += 100.0;
		}
	}
}

//Create a blank matrix
void tetMat::create(){
	for(int i = 0; i < m_height; i++){
		std::vector<char> row;
		for(int j = 0; j < m_width; j++){
			row.push_back('.');
		}
		m_mat.push_back(row);
	}
}

//Check if there is anything in the row #num
bool tetMat::checkRow(int num) const{
	for(int i = 0; i < m_width; i++){
		if(m_mat[num][i] != '.'){
			return false;
		}
	}
	return true;
}

//Check if there is anything in the column #num
bool tetMat::checkColumn(int num) const{
	for(int i = 0; i < m_height; i++){
		if(m_mat[i][num] != '.'){
			return false;
		}
	}
	return true;
}

//Print the matrix, if i = 0 then print everything including the active block, if it is 1 then only print inactive blocks etc
void tetMat::printMatrix(int num) const{
	for(int i = 0; i < m_height; i++){
		for(int j = 0; j < m_width; j++){
			if(isupper(m_mat[i][j]) && num == 1){
				std::cout << ". ";
			}
			else{
				std::cout << m_mat[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
}

char tetMat::getVal(int x, int y){
	if(x > m_width - 1 || x < 0 || y > m_height - 1 || y < 0){
		return '.';
	}
	return m_mat[y][x];
}

int tetMat::getHeight() const{
	return m_height;
}

int tetMat::getWidth() const{
	return m_width;
}