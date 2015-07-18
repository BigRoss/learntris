#ifndef TETMAT_H
#define TETMAT_H

#include <iostream>
#include <vector>
#include <ctype.h>

class tetMat{
public:
	tetMat();

	tetMat(int width, int height);

	virtual ~tetMat();

	void create();
	void setPoint(int x, int y, char newVal);
	void step(float& score, int& cleared);
	void clear();
	void clearActive();
	
	void printMatrix(int num) const;

	bool checkColumn(int num) const;
	bool checkRow(int num) const;
	char getVal(int x, int y);
	int getHeight() const;
	int getWidth() const;
private:

	int m_width;
	int m_height;
	std::vector< std::vector<char> > m_mat;
};

#endif