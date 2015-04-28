#include<bits/stdc++.h>
using namespace std;
const string s = "abcdefghijklmnopqrstuvwxyz";
int palindrome(string str)
{
	string revstr = str;
	reverse(revstr.begin(), revstr.end());
	return str == revstr;
}
int main()
{
	string str;
	while(cin >> str)
	{
		int len = str.size(), ok = false;
		for(int i = 0; i < len + 1 && !ok; i++)
		{
			for(int j = 0; j < 26; j++)
			{
				string newstr = str;
				newstr.insert(i, s, j, 1);
				if(palindrome(newstr))
				{
					cout << newstr << endl;
					ok = true;
				}
			}
		}
		if(!ok)
			puts("NA");
	}
	return 0;
}
