#include <iostream>
#include <vector>

void print(int arr[], int size) {
	for(int i = 0; i < size; ++i ) 
		std::cout << arr[i] << " ";
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

std::vector<int> bubbleSort(std::vector<int>& vec) {
	int sizeOfVec= vec.size(), temp = 0;
	bool flag = true;
	while(flag) {
		flag= false;
	    for(int i = 0; i < sizeOfVec - 1; ++i) {
	    	if(vec[i] > vec[i + 1]) {
	            temp = vec[i];
	            vec[i] = vec[i + 1];
	            vec[i + 1] = temp;
	            flag = true;
	    	}//if
	    }//for 
    }//while
    return vec;
}

void merge(int arr[], int l, int m, int r) {

	int subArrSize1 = m - l + 1, subArrSize2 = r - m;
	    
    int subArr1[subArrSize1], subArr2[subArrSize2];

    for(int i = 0; i < subArrSize1; ++i)
    	subArr1[i] = arr[i + l];

    for(int j = 0; j < subArrSize2; ++j)
    	subArr2[j] = arr[j + 1 + m];

    int indexArr1 = 0, indexArr2 = 0, index = l;

    while(indexArr1 < subArrSize1 && indexArr2 < subArrSize2) {
    	if(subArr1[indexArr1] <= subArr2[indexArr2]) {
    		arr[index] = subArr1[indexArr1++];
    	}
    	else {
    		arr[index] = subArr2[indexArr2++];
    	}
    	index++;
    }

    while(indexArr1 < subArrSize1) {
    	arr[index] = subArr1[indexArr1];
    	index++;
    	indexArr1++;
    }

    while(indexArr2 < subArrSize2) {
    	arr[index] = subArr2[indexArr2];
    	index++;
    	indexArr2++;
    }    
}

void mergeSort(int arr[], int l, int r) {
	
	if(l < r) {
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
	    merge(arr, l, m, r);
	}
}

int main(int argc, char* argv[]) {

	int arr[5] = { 1, 4, 2, 3, 7};
    mergeSort(arr, 0, 4);
    print(arr, 5);
	return 0;
}


