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

//Print the matrix
void tetMat::printMatrix() const{
	for(int i = 0; i < m_height; i++){
		for(int j = 0; j < m_width; j++){
			std::cout << m_mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int tetMat::getHeight() const{
	return m_height;
}

int tetMat::getWidth() const{
	return m_width;
}