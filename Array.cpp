#include<iostream>
using namespace std;

int main() {
	const int size = 6;
	int arr[size] = { 2,3,4,1,3,5 };
	int arr2[size] = {};
	int middle = 0;
	double s;
	for (int i = 0; i < size; ++i) {
		middle += arr[i];
		middle /= size;
		arr[i] = pow((arr[i] - middle), 2);
		s = (1 / size) * arr[i];
	}
	cout << middle << endl;
	
	/*for (int i = 0; i < size - 1; ++i) {
		arr2[i] = pow((arr[i] - middle), 2);
		s = (1 / size) * arr2[i];
	}*/
	
	cout << s << endl;
	
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << "\t";
	}
	return 0;
}