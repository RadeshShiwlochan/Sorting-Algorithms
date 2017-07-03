#include <iostream>
#include <vector>

void print(std::vector<int>& vec) {
	for(int value : vec ) 
		std::cout << value << " ";
	std::cout << std::endl;
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

int main(int argc, char* argv[]) {

	std::vector<int> vec = { 1, 4, 3, 5, 6, 2 };
	auto v = insertionSort(vec);
	print(v);
	return 0;
}