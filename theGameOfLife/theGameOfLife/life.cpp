#include "life.h"
#include <iostream>

bool hasNeighbors(const bool cell[ROWS][COLS], int i, int j)
{
	int n = 0;
	if (i == 0)
	{
		if (j == 0)
		{
			if (cell[i][j + 1]) n++;
			if (cell[i + 1][j] && cell[i + 1][j] != NULL) n++;
			if (cell[i + 1][j + 1] && cell[i + 1][j + 1] != NULL) n++;
		}
		else if (j == COLS-1)
		{
			if (cell[i][j - 1] && cell[i][j - 1] != NULL) n++;
			if (cell[i + 1][j - 1] && cell[i + 1][j - 1] != NULL) n++;
			if (cell[i + 1][j] && cell[i + 1][j] != NULL) n++;
		}
		else
		{
			if (cell[i][j - 1] && cell[i][j - 1] != NULL) n++;
			if (cell[i][j + 1] && cell[i][j + 1] != NULL) n++;
			if (cell[i + 1][j - 1] && cell[i + 1][j - 1] != NULL) n++;
			if (cell[i + 1][j] && cell[i + 1][j] != NULL) n++;
			if (cell[i + 1][j + 1] && cell[i + 1][j + 1] != NULL) n++;
		}
	}
	else if (i == ROWS-1)
	{
		if (j == 0)
		{
			if (cell[i][j + 1]) n++;
			if (cell[i - 1][j] && cell[i + 1][j] != NULL) n++;
			if (cell[i - 1][j + 1] && cell[i + 1][j + 1] != NULL) n++;
		}
		else if (j == COLS-1)
		{
			if (cell[i][j - 1] && cell[i][j - 1] != NULL) n++;
			if (cell[i - 1][j - 1] && cell[i + 1][j - 1] != NULL) n++;
			if (cell[i - 1][j] && cell[i + 1][j] != NULL) n++;
		}
		else
		{
			if (cell[i][j - 1] && cell[i][j - 1] != NULL) n++;
			if (cell[i][j + 1] && cell[i][j + 1] != NULL) n++;
			if (cell[i - 1][j - 1] && cell[i + 1][j - 1] != NULL) n++;
			if (cell[i - 1][j] && cell[i + 1][j] != NULL) n++;
			if (cell[i - 1][j + 1] && cell[i + 1][j + 1] != NULL) n++;
		}
	}
	else
	{
		if (cell[i][j - 1] && cell[i][j - 1] != NULL) n++;
		if (cell[i][j + 1] && cell[i][j + 1] != NULL) n++;
		if (cell[i - 1][j - 1] && cell[i - 1][j - 1] != NULL) n++;
		if (cell[i - 1][j] && cell[i - 1][j] != NULL) n++;
		if (cell[i - 1][j + 1] && cell[i - 1][j + 1] != NULL) n++;
		if (cell[i + 1][j - 1] && cell[i + 1][j - 1] != NULL) n++;
		if (cell[i + 1][j] && cell[i + 1][j] != NULL) n++;
		if (cell[i + 1][j + 1] && cell[i + 1][j + 1] != NULL) n++;
	}
	// is the cell dead or alive?
	if (!cell[i][j])
	{
		switch (n)
		{
		case 3: 
			return true;
			break;
		default: 
			return false;
		}
	}  
	else
	{
		switch (n)
		{
		case 1:
			return false;
			break;
		case 2: 
			return true;
			break;
		case 3:
			return true;
			break;
		case 4:
			return false;
		default:
			return false;
			break;
		}
	}

	
}

void life(const bool current[ROWS][COLS], bool next[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			next[i][j] = hasNeighbors(current, i, j);
		}
	}
}