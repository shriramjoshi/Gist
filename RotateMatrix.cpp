#include <iostream>
#include <algorithm>
#include <vector>

void rotateMatrix90(std::vector<std::vector<int>>& matrix)
{
	int size = matrix.size() - 1;
	for(int i = 0; i < (matrix.size() / 2); ++i)
	{
		for(int j = i; j < size - i; ++j)
		{
			int temp1 = matrix[size - j][i];
			int temp2 = matrix[size - i][size - j];
			int temp3 = matrix[j][size - i];
			int temp4 = matrix[i][j];
			matrix[i][j] = temp1;
			matrix[size - j][i] = temp2;
			matrix[size - i][size - j] = temp3;
			matrix[j][size - i] = temp4;		
		}
	}
}

void rotateMatrix180(std::vector<std::vector<int>>& matrix)
{
	int size = matrix.size() - 1;
	for(int i = 0; i < (matrix.size() / 2); ++i)
	{
		for(int j = i; j < size - i; ++j)
		{
			int temp1 = matrix[size - j][i];
			int temp2 = matrix[size - i][size - j];
			int temp3 = matrix[j][size - i];
			int temp4 = matrix[i][j];
			matrix[i][j] = temp2;
			matrix[size - j][i] = temp3;
			matrix[size - i][size - j] = temp4;
			matrix[j][size - i] = temp1;		
		}
	}
}


int main(void)
{
	std::vector<std::vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	rotateMatrix90(matrix);
	for(auto row : matrix)
	{
		for(auto i : row)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
