#include <iostream>
#include <vector>
#include <algorithm>

std::string previousPermutation(std::string permute)
{
	int n = permute.length() - 1;
	int i = n;
	while(i >= 0 && permute[i - 1] <= permute[i])
		i--;
	int j = i - 1;
	while(j + 1 <= n && permute[j + 1] <= permute[i - 1])
		j++;
	std::swap(permute[i - 1], permute[j]);
	std::reverse(permute.begin() + i, permute.end());
	return permute;
}

int main(void)
{
	std::string s = "1342";
	s = previousPermutation(s);
	std::cout << s << std::endl;
	return 0;
}

/*

if(inversion_point == t.rend())
	{
		return t;
	}
	else if(inversion_point == t.rbegin())
	{
		std::swap(*inversion_point, *t.rbegin());
	}
	std::reverse(t.rbegin(), inversion_point);

*/
