#ifndef TETRAMINO_H
#define TETRAMINO_H

class Tetramino{
public:
	Tetramino(char tetName);
	~Tetramino();

	//get the width if width > height or vice versa
	int getMaxLength() const;
	void setChar(char tetName);
private:
	bool m_active;
	char m_blockName;
	char m_char;
};

#endif