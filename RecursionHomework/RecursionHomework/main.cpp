#include <iostream>
#include <fstream>
using namespace std;

int ComputeSumOfDigits(int number)
{
	if (number == 0)
	{
		return 0;
	}

	return number%10 + ComputeSumOfDigits(number/10);
}

int CountWays(int steps)
{
	if (steps == 1)
	{
		return 1;
	}
	if (steps == 2)
	{
		return 2;
	}

	return CountWays(steps - 1) + CountWays(steps - 2);
}

int CountSubsets(int a[], int size, int target)
{
	if (size < 0)
	{
		return 0;
	}
	if (a[size] == target)
	{
		return 1 + CountSubsets(a, size - 1, target);
	}
	int count = 0;
	for (int i = 0; i <= size; i++)
	{
		if (a[size] + a[i] == target);
		count++;
	}

	return CountSubsets(a, size - 1, target);
}

bool IsSolvable(int start, int a[], int size)
{
	if (start < 0 || start > size - 1)
	{
		return false;
		cout << start << endl;
	}
	
	if (a[start] == 0){
		cout << a[start] << endl;
		return true;
		
	}
	//cout << "didnt fail didnt pass " << a[start] << start << endl;
	if (a[start - a[start]] == a[start] && start - a[start - a[start]] < a[start])
		return IsSolvable(start + a[start], a, size);
	if (a[start + a[start]] == a[start] && size - a[start]-1 < a[start])
		return IsSolvable(start - a[start], a, size);


	//cout << "DIDNT MEET ANY" << endl;
	return IsSolvable(start + a[start], a, size) || IsSolvable(start - a[start], a, size);
}

bool MazeSearch(char ** a, char ** b, int x, int y, int sizeX, int sizeY)
{
	if (x > sizeX - 1 || x < 0){
		//cout << "out size" << endl;
		return false;
	}
	if (y>sizeY - 1 || y < 0)
	{
		//cout << "outside y" << endl;
		return false;
	}
	if (b[x][y] == 't')
	{
		//cout << "visited" << endl;
		return false;
	}
	if (a[x][y] == 'X')
	{
		
		//cout << "On X" << endl;
		return false;
	}
	if (a[x][y] == 't')
	{
		cout << "found treasure" << endl;
		return true;
	}
	
	cout << "WE ARE HERE " << x << " , " << y << endl;
	//cout << "WHERE THE HECK ARE WE???" << endl;
	b[x][y] = 't';


	return MazeSearch(a, b, x + 1, y, sizeX, sizeY) || MazeSearch(a, b, x - 1, y, sizeX, sizeY) || MazeSearch(a, b, x, y + 1, sizeX, sizeY) || MazeSearch(a, b, x, y - 1, sizeX, sizeY);

}


int main()
{
	
	//cout << "THE SUM OF DIGITS: " << ComputeSumOfDigits(12345) << endl;
	//cout << "THE NUMBER OF WAYS: " << CountWays(10) << endl;
	//int a[] = { 2,2,2,3,3,3};
	//cout << "TOTAL SUBSETS: " << CountSubsets(a, 4, 6);
	//int a[] = { 3, 6, 4, 1,3,4,2,5,3,0};
		//if (IsSolvable(0, a, 10))
			//cout << "SOLVED!" << endl;
		//else cout << "NOT SOLVABLE!" << endl;
	
	ifstream fin;
	fin.open("maze1.txt");
	int sx, sy, lx, ly;
	fin >> sx >> sy >> lx >> ly;
	char ** maze;
	char ** visit;
	visit = new char *[lx];
	maze = new char *[lx];
	
	cout << sy << sx << endl;
	

	//for (int i = 0; i < sy; i++)
	//{
	//	*(maze + i) = new char[ly];

	//	*(visit + i) = new char[ly];

	//	for (int j = 0; j < sx; j++)
	//	{
	//		//fin >> maze[i][j];
	//		//visit[i][j] = ' ';
	//		//cout << maze[i][j];
	//	}

	//	cout << endl;

	//}
	

	cout << "THIS SHOULD FIND IT" << endl;
	
	/*if (MazeSearch(maze, visit, lx, ly, sx, sy))
		cout << "I FOUNT IT" << endl;
	else
		cout << "NOT FINDABLE" << endl;*/


	fin.close();

	fin.open("maze2.txt");
	
	fin >> sx >> sy >> lx >> ly;
	char ** maze2;
	char ** visit2;
	visit2 = new char *[lx];
	maze2 = new char *[lx];

	//cout << sy << endl;
	/*for (int i = 0; i < sy; i++)
	{
		maze[i] = new char[sy];
		visit[i] = new char[sy];
	}*/

	/*for (int i = 0; i < sy; i++)
	{
		for (int j = 0; j < sx; j++)
		{
			char a;
			fin >> a;
			maze2[i][j] = a;
			
			cout << maze2[i][j];
		}

		cout << endl;

	}*/
	cout << lx << ly << endl;
	cout << "THIS SHOULD NOT FIND IT" << endl;

	/*if (MazeSearch(maze2, visit2, lx, ly, sx, sy))
		cout << "I FOUNT IT" << endl;
	else
		cout << "NOT FINDABLE" << endl;*/

	fin.close();
	
	return 0;
}

