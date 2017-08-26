#ifndef UNIONFIND_H
#define UNIONFIND_H
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
struct Pair {
	int parentId;
	int size;
};

class UnionFind // with pair
{
public:
	void _union(Pair data[], int index1, int index2, int size){
		int root1 = _find(data, index1);
		int root2 = _find(data, index2);
		if (index1 == index2){ // union to itself, used to show that is has been unblocked
			data[index1].parentId = index1;
			data[index1].size += 1;
		}
		if (root1 == root2 && root1 != -1) return; // dont do anything if in the same group
		if (data[root1].size > data[root2].size){
			//union data 2 to data 1
			data[root2].parentId = root1;
			data[root1].size = 1 + data[root1].size + data[root2].size;
		}
		else {
			// union data 1 to data 2
			data[root1].parentId = root2;
			data[root2].size = 1 + data[root1].size + data[root2].size;
		}
	}

	int _find(Pair data[], int index){
		if (data[index].parentId == -1) return index;
		if (data[index].parentId == index) return index;
		return _find(data, data[index].parentId, index);
	}
	int _find(Pair data[], int parentIndex, int index){
		if (index == parentIndex) return index;
		if (data[parentIndex].parentId == parentIndex) return parentIndex;
		if (data[parentIndex].parentId == -1) return parentIndex;
		data[index].parentId = data[parentIndex].parentId;
		return _find(data, data[parentIndex].parentId, index);
	}

	void _initialize(Pair data[], int size){
		for (int i = 0; i < size; i++){
			Pair x;
			x.parentId = -1;
			x.size = 0;
			data[i] = x;
		}
	}

	void createDummyRows(Pair data[], int rowSize, int totalSize){
		for (int i = 0; i < rowSize; i++){
			data[i].parentId = 0;
		}
		data[0].size = rowSize;
		for (int i = totalSize - rowSize; i < totalSize; i++){
			data[i].parentId = totalSize - 1;
		}
		data[totalSize - 1].size = rowSize;
	}

	string print(Pair data[], int size, int limit){
		stringstream ss;
		for (int i = 0; i < size && i < limit; i++){
			ss << "INDEX: " << i << " Parent ID: " << data[i].parentId << " Size: " << data[i].size << endl;
		}
		return ss.str();
	}

	string printAsGrid(Pair data[], int size, int rowSize){
		stringstream ss;
		ss << "|";
		for (int i = 0; i < size; i++){
			if (i % rowSize == 0 && i != 0)	{
				ss << "|" << endl << "|";
			}
			if (data[i].parentId == -1) {
				ss << "X";
			}
			else {
				ss << " ";
			}
		}
		return ss.str();
	}

	bool _checkPercolation(Pair data[], int size){
		return _find(data, 0) == _find(data, size - 1);
	}
};

#endif // !UNIONFIND_H
