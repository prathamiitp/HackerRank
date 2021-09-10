#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // the "size" is size of pointer array that is pointing to different arrays
    // "query" is the no of query for the given data
    int size, query;
    cin >> size >> query;

    int *arr[size]; // pointer type array. a array each element of which points to a different array
    for (int i=0; i<size; i++) {
        // the size of subarray, whoes pointer is contained in main array
        int subSize;
        cin >> subSize;

        // creating a dynamic in a loop whoes values are stored at specific memory location and are  
        // not deleted upon completion of corresponding loop (for which the "new" keyword is used)
        int *tempArr= new int[subSize];
        for(int j=0; j<subSize; j++){
            cin >> tempArr[j];
        }

        // the pointer to first element of the newly created array is placed in pointer array created earlier
        arr[i]=tempArr;
        // at this point the newly created array would have been deleted if "new" keyword was not used
    }

    // handling the query
    for (int i=1; i<=query; i++){
        int primaryIndex, secondaryIndex;
        cin >> primaryIndex >> secondaryIndex;

        // since arr has only the index of 0th element of the array hence adding the secondaryIndex
        // to reach the prescribed location. then getting the value using '*'
        cout << *(arr[primaryIndex]+secondaryIndex) << endl;
    }
    return 0;
}       
