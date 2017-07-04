#include <iostream>
#include <vector>

void print(std::vector<int>& vec) {
	for(int value : vec ) 
		std::cout << value << " ";
	std::cout << std::endl;
}

int getMinElemIndx(std::vector<int>& vec, int startIndx) {
	int min = 0, sizeOfVec = vec.size();
	for(int index = startIndx; index < sizeOfVec; ++index) {
		if(min > vec[index]) min = index;
	}
	return min;
}

void swapElems(std::vector<int>& vec, int index1, int index2) {
	int temp = vec[index1];
	vec[index1] = vec[index2];
	vec[index2] = temp;
}


std::vector<int> insertionSort(std::vector<int>& vec) {
	int sizeOfVec = vec.size(), elemToInsert = 0, j = 0;
    for(int i = 1; i < sizeOfVec; ++i) {
        elemToInsert = vec[i];
        j = i;
        while(j - 1 >= 0) {
        	if(vec[j - 1] > elemToInsert) {
        		vec[j] = vec[j - 1];
        		j--;
        	}//if
        	else break;
        }//while
        vec[j] = elemToInsert;
    }//for
    return vec;
}

std::vector<int> selectionSort(std::vector<int>& vec) {
	int sizeOfVec = vec.size(), minNumIndx = 0, temp = 0;
	for(int i = 0; i < sizeOfVec - 1; ++i) {
		//find the index of min number
		minNumIndx = i;
		for(int j = i + 1; j < sizeOfVec; ++j) {
			if(vec[j] < vec[minNumIndx]) minNumIndx = j;
		}
		//swap the value at minNumIndx and i
		if(minNumIndx != i) {
		    temp = vec[i];
		    vec[i] = vec[minNumIndx];
		    vec[minNumIndx] = temp;
	    }
	}
	return vec;
}

int main(int argc, char* argv[]) {

	std::vector<int> vec = { 1, 4, 3, 5, 6, 2 };
	auto v = selectionSort(vec);
	print(v);
	return 0;
}