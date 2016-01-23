#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// https://www.interviewbit.com/courses/programming/topics/strings/problems/zigzag/

string zigzag(string s, int n)
{
	if (s.size() <= 1 || n == 1)
		return s;
	string res = "";
	for (int i = 0; i<n; i++)
	{
		int j = (n - i - 1) * 2;
		int x = i * 2;
		int cur = i;
		if (0 == j || x == 0)
		{
			int k = 0 == j ? x : j;
			while (cur < s.size())
			{
				res += s[cur];
				cur += k;
			}
		}
		else
		{
			while (cur < s.size())
			{
				res += s[cur];
				cur += j;
				if (cur < s.size())
					res += s[cur];
				cur += x;
			}
		}
	}
	return res;
}



int main()
{
	zigzag("b",1);
}