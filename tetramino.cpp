#include "tetramino.h"

Tetramino::Tetramino(char tetName){
	m_active = false;
	m_blockName = tetName;
	setChar(tetName);
}

Tetramino::~Tetramino(){

}

Tetramino::setChar(char tetName){
	if(tetName == 'I'){
		m_char = 'c';
	}
	else if(tetname == 'O'){
		m_char = 'y';
	}
	else if(tetname == 'Z'){
		m_char = 'r';
	}
	else if(tetname == 'S'){
		m_char = 'g';
	}
	else if(tetname == 'J'){
		m_char = 'b';
	}
	else if(tetname == 'T'){
		m_char = 'm';
	}
	else{
		//THIS MIGHT CAUSE PROBLEMS
		m_char = '.';
	}
}

Tetramino::getMaxLength(){

}

