#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isPalindrom(const string& str, int i, int j);

string longestPalindrome(string s) {
	if (s.size() < 2)
		return s;

	vector<vector<int>> ptrToMat(s.size());
	for (int i = 0; i < s.size(); ++i)
	{
		ptrToMat[i] = vector<int>(s.size());
	}

	int range = 1;
	
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = 0; j < s.size()-i; ++j)
		{
			ptrToMat[j][j + i];
			if (i == 0)
			{
				ptrToMat[j][j] = 1;
				continue;
			}
			if (isPalindrom(s, j, j+i))
			{
				ptrToMat[j][j + i] = std::max(ptrToMat[j][j + i - 1], ptrToMat[j + 1][j + i]) + 2;
			}
			else
			{
				ptrToMat[j][j + i] = std::max(ptrToMat[j][j + i - 1], ptrToMat[j + 1][j + i]);
			}
		}
		
	}
	string newStr = "";
	int i = 0;
	int j = s.size() - 1;
	int value = ptrToMat[i][j];
	while (j != 0)
	{
		int maxValue = std::max(ptrToMat[i][j - 1], ptrToMat[i + 1][j]);
		bool storeStr = false;
		int temps_i = 0;
		int temps_j = 0;
		if (value > maxValue || value == 1)
		{
			if (value == 1)
			{
				temps_i = 0;
				temps_j = 0;
			}
			else
			{
				temps_i = i;
				temps_j = j;
			}
			
			storeStr = true;
		}
		value = maxValue;
		if (value == ptrToMat[i][j - 1])
		{
			i = i;
			j = j - 1;
		}
		else if (value == ptrToMat[i + 1][j])
		{
			i = i + 1;
			j = j;
		}
		if (storeStr)
		{
			while (temps_i <= temps_j)
			{
				newStr += s[temps_i];
				temps_i++;
			}
			return newStr;
		}
	}
	return newStr;
}


bool isPalindrom(const string& str, int i, int j)
{
	if (i > j)
		return false;

	if (i == j)
		return true;

	while (i < j)
	{
		if (str[i] != str[j])
		{
			return false;
		}
		--j;
		++i;
	}
	return true;
}

int main()
{
    std::cout << "please input string\n";
	std::cin >> str;
	string ss = longestPalindrome(str);
	std::cout << "string is = " << ss;
    return 0;
}