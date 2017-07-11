#include <iostream>
#include <vector>

double medianof4(int a, int b, int c, int d)
{
    int max = std::max(a, std::max(b, std::max(c, d)));
    int min = std::min(a, std::min(b, std::min(c, d)));
    return (a + b + c + d - max - min) / 2.0;
}

double medianof3(int a, int b, int c)
{
	return a + b + c - std::max(a, std::max(b, c)) - std::min(a, std::min(b, c));
}

double medianof2(int a, int b) 
{
    return (a + b) / 2.0;
}

int findMedian(int arr1[], int N, int arr2[], int M)
{
	if(N == 0 && M == 0)
		return -1;
	else if(N == 1 && M == 0)
		return arr1[0];
	else if(N == 0 && M == 1)
		return arr2[0];
	else if(N == 1 && M == 1)
		return medianof2(arr1[0], arr2[0]);
	if(N == 1)
	{
		if(M & 1)
		{
			return medianof2(arr2[M / 2], medianof3(arr1[0], arr2[M / 2 - 1], arr2[M / 2 + 1]));
		}
		return medianof3(arr2[M / 2], arr2[M / 2 - 1], arr1[0]);
	}
	if(N == 2)
	{
		if (M == 2)
    		return medianof4(arr1[0], arr1[1], arr2[0], arr2[1]);

		if (M & 1)
		    return medianof3( arr2[M/2], std::max(arr1[0], arr2[M/2 - 1]), std::min(arr1[1], arr2[M/2 + 1]));
 
		return medianof4(arr2[M/2], arr2[M/2 - 1], std::max( arr1[0], arr2[M/2 - 2] ), std::min( arr1[1], arr2[M/2 + 1]));
	}
	
	int midA = (N - 1) / 2;
	int midB = (M - 1) / 2;
	if(arr1[midA] <= arr2[midB])
	{
		return findMedian(arr1 + midA, N / 2 + 1, arr2, M - midA);
	}
	return findMedian(arr1, N / 2 + 1, arr2 + midA, M - midA);
}

int main(void)
{
	int A[] = {900};
    int B[] = {5, 8, 10, 20};
 
    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);
 	
    std::cout << findMedian( A, N, B, M ) << std::endl;
	return 0;
}
