#include <iostream>
#include <cmath>

bool isPalndromic(int x)
{
	if(x < 0)
		return false;
	int num_digits = static_cast<int>(floor(log10(x))) + 1;
	int msd_mask = static_cast<int>(pow(10, num_digits - 1));
	for(int i = 0; i < (num_digits / 2); ++i)
	{
		if(x / msd_mask != x % 10)
		{
			return false;
		}
		x %= msd_mask;
		x /= 10;
		
		0msd_mask /= 100;
	}
	return true;
}

int main()
{
	int number = 0;
	std::cout << "Enter number : " << std::endl;
	std::cin >> number;
	if(isPalndromic(number))
		std::cout << "Palndrom" << std::endl;
	else
		std::cout << "Not Palndrom" << std::endl;
	return 0;
}
