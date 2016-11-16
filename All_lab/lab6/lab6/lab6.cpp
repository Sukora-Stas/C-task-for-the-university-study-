#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "asdfasdgfds dsgads gdas ghadfs hads";
	int k = 0;
	cout << "Vvedite K= " << endl;
	cin >> k;

	int pos = k;
	if (k < str.length() && str[k - 1] != ' ')
	{
		for (int i = k - 1; i >= 0; i--)
		{
			if (str[i] == ' ')
			{
				break;
			}
			else
			{
				pos--;
			}
		}
	}

	string sub1;
	string sub2;
	if (pos < str.length())
	{
		sub1 = str.substr(0, pos);
		sub2 = str.substr(pos, str.length());
	}
	else
	{
		sub1 = str;
	}
	cout << string(sub1) << endl;
	cout << sub2 << endl;

	system("pause");

}
