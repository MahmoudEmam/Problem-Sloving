/*
problem link:
https://www.interviewbit.com/courses/programming/topics/strings/problems/prettyjson/
problem rules:
1-every { or [ will increase the spaceCount by one and enter new line with \t at the begining as the number in spaceCount
2-every , will push the current line and enter a new line with \t at the begining as the number in spaceCount
3- every } or ] will push the current line and enter new line with \t(spaccount -1) + { or [
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

string getSpaces(int n)
{
	string spaces = "";
	while (n > 0)
	{
		spaces += "\t";
		n--;
	}
	return spaces;
}
bool isEmpty(string line)
{
	while (line.size() > 0 && line[0] == '\t')
		line.erase(0, 1);
	return line.size() == 0;
}
vector<string>  prettyJSON(string A)
{
	string line = "";
	int spaceCount = 0;
	vector<string> res;
	for (int i = 0; i<A.size(); i++)
	{


		if ('[' == A[i] || '{' == A[i])
		{

			if (!isEmpty(line))
				res.push_back(line);
			line = getSpaces(spaceCount) + A[i];
			res.push_back(line);
			spaceCount++;
			line = getSpaces(spaceCount);

		}
		else if (',' == A[i])
		{
			line += A[i];
			res.push_back(line);
			line = getSpaces(spaceCount);
		}
		else if (A[i] == ']' || A[i] == '}')
		{
			res.push_back(line);
			spaceCount--;
			line = getSpaces(spaceCount);
			line += A[i];

		}
		else
			line += A[i];

	}
	if (line != "")
		res.push_back(line);
	return res;
}