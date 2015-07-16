#ifndef TETRAMINO_H
#define TETRAMINO_H

#include "tetmat.h"
#include <ctype.h>

class Tetramino{
public:
	Tetramino(char tetName);
	~Tetramino();

	//get the width if width > height or vice versa
	int getMaxLength() const;
	void setChar(char tetName);
	void insertTet(tetMat* mat);
	void insertTetGame(tetMat* mat);
	void pushLeft(tetMat* mat);
	void pushRight(tetMat* mat);
	void showTetramino();
	void rotate(int direction);
private:
	tetMat* displayMatrix;
	bool m_active;
	char m_blockName;
	char m_char;
};

#endif