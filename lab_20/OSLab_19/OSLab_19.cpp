// OSLab_19.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <list>
using namespace std;

string ConvertToBin(int a)
{
	int  b;
	string str = "";
	b = a;
	while (b > 0)
	{
		a = b;
		if (a % 2 == 0) str += '0';
		else str += '1';
		b = a / 2;
	}
	if (str.length() != 4) str += string(4 - str.length(), '0');
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	int i = 0, size = 1;
	string ss = "", buffer;
	cin >> ss;
	cout << "\n" ;
	list<string> first, next, result;
	typedef list<string>::iterator Iterator;

	string temp = ss;
	while (ss.length() != 0)
	{
		buffer += ss[i];   
		Iterator iter = find(first.begin(), first.end(), buffer);

		if (iter != first.end()) i++;
		else
		{
			if (i + 1 <= ss.length())
			{
				first.insert(first.end(), buffer);
				next.insert(next.end(), string(1, ss[i + 1]));
				result.insert(result.end(), ConvertToBin(size++));
			}
			ss = ss.erase(0, i + 1);
			buffer = "";
			i = 0;
		}
	}

	for (Iterator iter = first.begin(), it = next.begin(), iterat = result.begin(); iter != first.end(); ++iter, ++it, ++iterat)
	{
		cout << *iter << "\t" << "\t" << *iterat << "\n";
		*it;
	}

	string resultStr = "";
	while (temp.length() != 0)
	{
		ss += temp[i];

		if (find(first.begin(), first.end(), ss) != first.end())	i++;
		else
		{
			i--;
			ss.erase(ss.end() - 1, ss.end());
			for (Iterator iter2 = first.begin(), iter3 = result.begin(); iter2 != first.end(); ++iter2, ++iter3)
			{
				if (*iter2 == ss)
				{
					resultStr += *iter3 + " ";
					ss = "";
					temp.erase(0, i + 1);
					i = 0;
					break;
				}
			}
		}
	}
	cout << "encoded\n" << resultStr << "\n";
	buffer = "";
	i = 0;
	temp = "";

	while (resultStr.length() != 0)
	{
		if (resultStr[i] != ' ')	buffer += resultStr[i++];
		else
		{
			resultStr.erase(0, i + 1);

			for (Iterator iter2 = first.begin(), iter3 = result.begin(); iter2 != first.end(); ++iter2, ++iter3)
			{
				if (*iter3 == buffer)
				{
					temp += *iter2;
					buffer = "";
					i = 0;
					break;
				}
			}
		}
	}
	cout << "\n" << temp << "\n\n";
}

