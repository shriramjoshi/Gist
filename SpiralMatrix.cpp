#include <iostream>
#include <vector>
#include <cmath>

// spiral order of square matrix
void spiralSquare(std::vector<std::vector<int>>& matrix)
{
	std::vector<std::vector<int>> directions = {{0, 1}, /* right */
									  		{1, 0}, /* down */
									  		{0, -1}, /* left */
									  		{-1, 0}, /*up*/ };
	int x = 0; int y = 0;
	int dir = 0;
	for(int i = 0; i < matrix.size() * matrix.size(); ++i)
	{
		matrix[x][y] = i + 1;
		int x_axis = x + directions[dir][0];
		int y_axis = y + directions[dir][1];
		//change directiions
		if(x_axis < 0 || x_axis >= matrix.size() ||
		   y_axis < 0 || y_axis >= matrix.size() ||
		   matrix[x_axis][y_axis] != -1)
		{
			dir = (dir + 1) % 4;
			x_axis = x + directions[dir][0];
			y_axis = y + directions[dir][1];
		}
		x = x_axis;
		y = y_axis;
	}
	return;
}

std::vector<int>* computeMatrix(std::vector<int> spiral)
{
	std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	std::vector<int>* matrix = new std::vector<int>[4];
	int x = 0;
	int y = 0;
	int dir = 0;
	for(int i = 0; i < spiral.size(); ++i)
	{
		matrix[x][y] = spiral[i];
		int x_axis = x + directions[dir][0];
		int y_axis = y + directions[dir][1];
		if(x < 0 || x >= std::sqrt(spiral.size()) ||
		y < 0 || y >= std::sqrt(spiral.size()))
		{
			dir = (dir + 1) % 4;
			x_axis = x + directions[dir][0];
			y_axis = y + directions[dir][1];
		}
		x = x_axis;
		y = y_axis;
	}
	return matrix;
}

//spiral order of m*n matrix
void computeSpiralMN(std::vector<std::vector<int>> matrix)
{
	std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int x = 0;
	int y = 0;
	int dir = 0;
	int rows = matrix.size();
	int cols = matrix[0].size();
	for(int i = 0; i < rows * cols; ++i)
	{
		std::cout << matrix[x][y] << " ";
		int x_axis = x + directions[dir][0];
		int y_axis = y + directions[dir][1];
		if((x_axis < 0 || x_axis >= rows) || (y_axis < 0 || y_axis >= cols))
		{
			dir = (dir + 1) % 4;
			x_axis = x + directions[dir][0];
			y_axis = y + directions[dir][1];
		}
		//std::cout << "X : " << x << " Y : " << y << std::endl;
		x = x_axis;
		y = y_axis;
	}
}

int main(void)
{
	std::vector<std::vector<int>> mat = {{1,2}, {3,4}, {5,6}, {7,8}};
	computeSpiralMN(mat);
	return 0;
}
