#include <iostream>
#include <math.h>

using namespace std;

int â()
{
	double x, y, s;
	s = 0;
	cout << "Vedite X: ";
	cin >> x;
	cout << "Vedite Y: ";
	cin >> y;
	if (x / y < 0){
		s = 2 / 3 + log(abs(sin(y)));
		cout << "Vetv2  " << endl;
		cout << "Otvet: s=  " << s << endl;
	}
	else if (x / y > 0){
		s = pow(x + log(abs(y)), 3);
		cout << "Vetv1  " << endl;
		cout << "Otvet: s=  " << s << endl;
	}
	else if (x ==0 && y==0){
		s = pow(x + log(abs(y)), 3);
		cout << "It is impossible to divide by 0" << endl;
	}
	else{
		s = (pow(pow(x, 2), 1 / 3) + y);
		cout << "Vetv3  " << endl;
		cout << "Otvet: s=  " << s << endl;
	}
	
	system("pause");
	return 0;
}