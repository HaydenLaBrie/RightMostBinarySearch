#include <stdio.h>
int RightMostBinarySearch(int *arr, int length, int find, int i, int j){
    int middle = (i + j) / 2; //This will be floor due to integer data type
    int x;
    int temp;
    while(i <= j){ //While the start does not exceed int size of last value in array
        if(arr[middle] < find){ //If middle element is less than what is being searched for
            i = middle + 1; //Obviously the element is not found and the element is greater than middle point => make i one element to the right
        }
        else if(arr[middle] == find){ //The middle position is where the element exists in the array
            int k = RightMostBinarySearch(arr, length, find, middle + 1, j);
            if(k < 0){
                return middle + 1; //Final return
            }
            else{
                return k;
            }
        }
        else{ //This condition will be when arr[midd] > find
            j = middle - 1; // make j 1 element left of middle because find is less than arr[middle]
        }
        middle = (i + j) / 2; //if not found i or j changes, thus middle must also change.
    }
    return -1;
}
int main(void){
    int arr[] = {1,2,4,4,4,4,4,8,8,9,9,12}; //Sorted int array of size n
    int find = 4;
    int length = sizeof(arr) / sizeof(*arr); // Determines the length by getting the full size of memory array uses and dividing by he size of first element memory size. Full memory / element memory = num elements = length
    int i = 0;
    int j = length - 1; // Length of array is n, last element is represented n - 1
    int location = RightMostBinarySearch(arr,length, find, i, j);
    printf("The location of the element is at position: %d\n", location);
    return 0;
}
