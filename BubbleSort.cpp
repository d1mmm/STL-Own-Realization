#include<iostream>

using namespace std;

int main() {
	int a[6] = { 1,5,3,2,4,6 };
	int c[8];
	int k = 0;
	for (int i = 0; i < 6; ++i) {
		for (int j = i; j < 6; ++j)
		{
			if (a[i] >= a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	for (int i = 0; i < 6; i++) 
	{
		cout << a[i] << " ";
	}
	return 0;
}