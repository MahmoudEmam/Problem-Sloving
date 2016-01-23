#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
	* 2. There are “n” ticket windows in the railway station. ith window has ai tickets available. Price of a ticket is equal to the number of tickets remaining in that window at that time. When “m” tickets have been sold, what’s the maximum amount of money the railway station can earn?
	* exa. n=2, m=4 in 2 window available tickets are : 2 , 5 from 2nd wicket sold 4 tickets so 5+4+3+2=14.

*/

int getMax(int M, vector<int> A)
{
	int N = A.size();
	sort(A.begin(), A.end());
	int current = A[N - 1];
	int maxSum = 0;
	int currCount = 1;
	int i = N - 1;
	while (i >= 0 && M > 0)
	{
		int prev = 0;
		prev = i - 1 >= 0 ? A[i - 1] : 0;
		int diff = current - prev;
		while (diff == 0 && i >= 0)
		{
			i--;
			currCount++;
			prev = i - 1 >= 0 ? A[i - 1] : 0;
			diff = current - prev;
		}
		while (diff > 0 && M > 0)
		{
			for (int j = 0; j<currCount && M > 0; j++)
			{
				maxSum += current;
				M--;
			}
			current--;
			diff--;
		}




	}
	return maxSum;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	getMax(13, v);
}