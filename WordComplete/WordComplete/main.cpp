
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "heap.h"
using namespace std;
const int SIZE = 4351;

bool contains(string x, string y, int count){
	if (x.length() < count) return false;
	for (int i = 0; i < count; i++){
		if (x[i] != y[i]) return false;
	}
	return true;
}

bool isLessThan(string target, string original, int count){
	if (original.length() < count) return false;
	for (int i = 0; i < count; i++){
		if (target[i] < original[i]) return true;
		if (target[i] > original[i]) return false;
	}
	return false;
}

int firstIndexOf(vector<Term> a, string target, int r){
	int first = 0;
	int last = a.size();
	int current = a.size() / 2;
	bool found = false;
	while (true){
		if (contains(a[current].word, target, r)){
			int i = current;
			while (i!=-1 && contains(a[i].word, target, r)){
				i--;
			}
			if (i == 0) return 0;
			return i + 1;
		}
		if (first > last) return -1;
		if (!isLessThan(target, a[current].word, r)){
			first = current + 1;
			current = (first + last) / 2;
		}
		else {
			last = current - 1;
			current = (first + last) / 2;
		}
	}

	return -1;
}
int lastIndexOf(vector<Term> a, string target, int r){
	int first = 0;
	int last = a.size() - 1;
	int current = a.size() / 2;
	bool found = false;
	while (true){
		if (contains(a[current].word, target, r)){
			int i = current;
			while (contains(a[i].word, target, r)){
				i++;
			}
			return i -1;
		}
		if (first > last) return -1;
		if (!isLessThan(target, a[current].word, r)){
			first = current + 1;
			current = (first + last) / 2;
		}
		else {
			last = current - 1;
			current = (first + last) / 2;
		}
	}

	return -1;
}
int main(){
	
	ifstream myfile;
	myfile.open("sortedText.txt");
	string temp = "";
	getline(myfile, temp);
	vector<Term> terms;
	LeftistHeap *heap = new LeftistHeap();
	LeftistHeap *otherHeap = new LeftistHeap();
	while (getline(myfile, temp)){
		stringstream ss(temp);
		string word;
		string number;
		int num;
		ss >> word;
		ss >> number;
		num = stoi(number);
		Term a(word, num);
		terms.push_back(a);
		//cout << temp << endl;
	}
	cout << lastIndexOf(terms, "abo", 3) << endl;
	heap->insert(terms[0]);
	heap->insert(terms[1]);
	heap->insert(terms[2]);
	heap->insert(terms[3]);
	heap->insert(terms[4]);
	heap->insert(terms[5]);
	cout << "HEAP 1 AFTER INSERTING THE FIRST 5 TERMS" << endl;
	cout << heap->toString() << endl;
	cout << "======================" << endl;
	heap->removeMax();
	cout << "AFTER REMOVE MAX" << endl;
	cout << heap->toString() << endl;
	cout << "======================" << endl;
	otherHeap->insert(terms[6]);
	otherHeap->insert(terms[7]);
	otherHeap->insert(terms[8]);
	otherHeap->insert(terms[9]);
	otherHeap->insert(terms[10]);
	otherHeap->insert(terms[11]);
	cout << "HEAP 2 AFTER INSERTING THE FIRST 5 TERMS" << endl;
	cout << otherHeap->toString() << endl;
	cout << "======================" << endl;
	otherHeap->removeMax();
	cout << "AFTER REMOVE MAX" << endl;
	cout << otherHeap->toString() << endl;
	cout << "======================" << endl;
	cout << "AFTER MERGING HEAP 2 INTO HEAP 1" << endl;
	heap->merge(otherHeap);
	cout << heap->toString() << endl;
	cout << "======================" << endl;
	cout << "AFTER REMOVE MAX" << endl;
	heap->removeMax();
	cout << heap->toString() << endl;
	cout << "======================" << endl;
	char x = 'y';
	while (x != 'n') {
		string userWord;
		cout << "Type the start of the word you want to autocomplete." << endl;
		cout << "You can include two queries by putting space in between the words," << endl;
		cout << "eg... 'acc dom' or by putting an &, eg... 'acc & dom'" << endl;
		LeftistHeap *heap = new LeftistHeap();
		LeftistHeap *otherHeap = new LeftistHeap();
		getline(cin, userWord);
		string temp;
		stringstream ss(userWord);
		ss >> temp;
		int start = firstIndexOf(terms, temp, temp.length());
		int finish = lastIndexOf(terms, temp, temp.length());
		if (start == -1 || finish == -1){
			cout << "NO MATCHES" << endl;
			cout << "Would yo like to try again?[y,n]" << endl;
			cin >> x;
			cin.ignore();
			cin.clear();
			continue;
		}
		for (int i = start; i <= finish; i++){
			heap->insert(terms[i]);
		}
		if (ss >> temp){
			if (temp == "&"){

				if (ss >> temp){
					int start = firstIndexOf(terms, temp, temp.length());
					int finish = lastIndexOf(terms, temp, temp.length());
					if (start != -1 && finish != -1){
						for (int i = start; i <= finish; i++){
							otherHeap->insert(terms[i]);
						}
					}
				}
			}
			else {
				int start = firstIndexOf(terms, temp, temp.length());
				int finish = lastIndexOf(terms, temp, temp.length());
				if (start != -1 && finish != -1){
					for (int i = start; i <= finish; i++){
						otherHeap->insert(terms[i]);
					}
				}
			}
			heap->merge(otherHeap);
		}
		int a;
		cout << "How many results would you like to display?" << endl;
		cin >> a;
		//cout << heap->toString() << endl; //for debugging
		cout << "QUERY: " << ss.str() << " COUNT: " << a << endl;
		heap->printInOrder(a);
		cout << endl;
		cout << "Would you like to go again> [y,n]" << endl;
		cin >> x;
		cin.ignore();
		cin.clear();

	}
	cout << "HAVE A GREAT DAY!" << endl;
	myfile.close();
	
	return 0;
}