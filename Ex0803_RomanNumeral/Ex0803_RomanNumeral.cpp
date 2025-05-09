﻿#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// LeetCode: Roman to Integer
// https://leetcode.com/problems/roman-to-integer/description/

int RomanToInt(string s)
{
	unordered_map<char, int> m;

	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;

	int ans = 0;

	for (int i = 0; i < s.length(); i++)
	{
		// TODO:
		if(m[s[i]] < m[s[i+1]]){
			ans += m[s[i+1]] - m[s[i]];
			cout << i << " " << s[i] << " " << ans << " " << s[i] << " " << s[i+1] << endl;
			i += 1;
			continue;
		}
		else ans += m[s[i]];

		cout << i << " " << s[i] << " " << ans << " " << s[i] << " " << s[i+1] << endl;
	}

	cout << s << " = " << ans << endl;

	return ans;
}

int main()
{
	RomanToInt("II");

	RomanToInt("III");

	RomanToInt("XII");

	RomanToInt("XXVII");

	RomanToInt("IV");

	RomanToInt("IX");

	RomanToInt("XL");

	RomanToInt("XC");

	RomanToInt("CD");

	RomanToInt("CM");

	RomanToInt("LVIII");

	RomanToInt("MCMXCIV");

	return 0;
}