#include "tetMat.h"

tetMat::tetMat() : m_width(10), m_height(22){
	create();
}

tetMat::tetMat(int width, int height) : m_width(width), m_height(height){
	create();
}

tetMat::~tetMat(){

}

void tetMat::create(){
	for(int i = 0; i < m_height; i++){
		std::vector<char> row;
		for(int j = 0; j < m_width; j++){
			row.push_back('.');
		}
		m_mat.push_back(row);
	}
}

void tetMat::printMatrix() const{
	for(int i = 0; i < m_height; i++){
		for(int j = 0; j < m_width; j++){
			if(m_mat[i][j] == '.'){
				std::cout << ". ";
			}
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