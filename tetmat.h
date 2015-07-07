#ifndef TETMAT_H
#define TETMAT_H

#include <iostream>
#include <vector>

class tetMat{
public:
	tetMat();

	tetMat(int width, int height);

	virtual ~tetMat();

	void create();
	void printMatrix() const;

	int getHeight() const;
	int getWidth() const;
private:

	int m_width;
	int m_height;
	std::vector< std::vector<char> > m_mat;
};

#endif