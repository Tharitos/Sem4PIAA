#include <iostream>
#include <string>
#include <vector>
#include "include/KMP.h"

using namespace std;
int main(int argc, char *argv[])
{
	string A;
	string B;
	cin >> B;
	cin >> A;
	vector<int> res = kmp(A, B, 2);
	int n = res.size();
	if (n > 0) {
		cout << res[0];
	}
	else
		cout << "-1";
	cout << endl;
	system("Pause");
	return 0;
}
//проверка только шифта в ручную
