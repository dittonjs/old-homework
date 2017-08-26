#include <iostream>

using namespace std;

int CalcSum(int a){

	if (a == 0) return 0;
	return a + CalcSum(a - 1);
}

int FindMin(int a[], int size){
	if (size == 1){
		return a[0];
	}
	if (a[0] > a[size - 1]){
		
		a[0] = a[size - 1];
		
	}

	return FindMin(a, size - 1);
}

int FindSum(int a[], int size){
	if (size == 1)
	return a[0];

	return a[size - 1] + FindSum(a, size - 1);
}

bool IsPalindrome(char a[], int size){
	if (a[0] != a[size - 1]) return false;
	if (size <= 1) return true;
	for (int i = 0; i < size; i++){
		if (i < size - 1)a[i] = a[i + 1];
		// cout << a[i];
	}
	return IsPalindrome(a, size - 2);
}

void PrintBinary(int a){
	if (a / 2 == 0) {
		cout << a % 2;
		return;
	}
	
	PrintBinary(a / 2);
	cout << a % 2;
	
}


int main(){

	int a[] = { 5, 4, 3, 2, 1 };
	
	cout << CalcSum(6);
	// should be 21;
	
	cout << FindMin(a, 5) << endl;
	// should be 1
	char b[] = { 'r', 'a', 'c', 'e', 'c', 'a', 'r' };
	cout << FindSum(a, 5) << endl;
	// should say 15
	
	if (IsPalindrome(b, 7)){
		cout << "You win" << endl;
	}
	// should say you win
	
	PrintBinary(13);
	// should say 1101
}