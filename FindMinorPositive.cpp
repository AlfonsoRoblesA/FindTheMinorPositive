#include <iostream>

using namespace std;

/**
This method is for find the minor positive that doesn't exist in the array,
the size is the size of the index and i represents the index for indentify the 
component
**/
int findMinor(int *array, int size, int i){
	// the last case, we reach here in case the array is full of negative numbers
	if(i==size){
		return 1;
	}
	// this is for discard all the negative numbers, because we only look for positive numbers
	if(array[i]<0){
		return findMinor(array, size, i+1);
	}
	// this one is for discard the current number in case the next number in the array is equal to this
	if(array[i]==array[i+1]){
		return findMinor(array,size,i+1);
	}
	// this case is for discard the current number when the next number is consecutive to this
	if(array[i]+1==array[i+1]){
		return findMinor(array,size,i+1);
	}
	// if the number passes all the cases, we can assume that the next number is the minor positive
	return array[i]+1;
}

//just a quicksort method
void divide(int list[], int start, int end) {
    int left = start;
    int right = end;
    int pivot = list[(start+end)/2];
        do {
            while (list[left] < pivot && left < end) {
                left++;
            }
            while (list[right] > pivot && right > start) {
                right--;
            }
            if (left <= right) {
                int temp = list[right];
                list[right] = list[left];
                list[left] = temp;
                left++;
                right--;
            }
        } while (left <= right);
        if (start < right) {
            divide(list, start, right);
        }
        if (left < end) {
            divide(list, left, end);
        }
    }

void quickSort(int list[], int size) {
    divide(list, 0, size-1);
}

int main(){
	//this is the array example
	int array[] = {-5,-1,-5,-2,-3,-4,0,-4,-5,-6,-7,-8,0,0,1,2,3,5,6,7,8,0,10,9};
	//we get the array's size
	int size = (sizeof(array)/sizeof(array[0]));
	//first we sort the numbers
	quickSort(array,size);
	//we find the minor positive value in the array
	cout << findMinor(array,size,0) << endl;
	
	return 0;
}


