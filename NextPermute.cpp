#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<typename T>
T nextPermute(T& t)
{
	//return iterator to that position where ascending order doesn't follow
	auto inverse_point = std::is_sorted_until(t.rbegin(), t.rend());
	if(inverse_point == t.rend())
	{
		return t;
	}
	
	//upper_bound returns position of a first value which greater than value which is *inverse_point
	auto least_upper_bound = std::upper_bound(t.rbegin(), inverse_point, *inverse_point);
	std::iter_swap(inverse_point, least_upper_bound);
	std::reverse(t.rbegin(), inverse_point);
	return t;
}

int main(void)
{
	std::vector<int> vec = {1,3,4,2};
	vec = nextPermute(vec);
	for(auto i : vec)
		std::cout << i << " ";
	
	std::string str = "adbec";
	std::cout << nextPermute(str) << std::endl;
	
	return 0;
}

