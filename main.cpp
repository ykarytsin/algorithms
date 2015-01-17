#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

template <class Type>
void initArray(Type *array, int length);

template <class Type>
void showArray(Type *array, int length);

template <class Type>
void sortSelection(Type *array, int begin, int end);

int main()
{
    int array[20];

    initArray<int>(array, 20);
    showArray<int>(array, 20);

    cout << endl;

    sortSelection<int>(array, 0, 20);
    showArray<int>(array, 20);
    return 0;
}

template <class Type>
void initArray(Type *array, int length) {
    for(int index = 0; index < length; index++)
        array[index] = rand() % length;
}

template <class Type>
void showArray(Type *array, int length) {
    for(int index = 0; index < length; index++) {
        if(index % 10 == 0)
            cout << "\n";
        cout << setw(6) << array[index];
    }
}

template <class Type>
void sortSelection(Type *array, int begin, int end) {
    for(int i = begin; i < end - 1; i++) {
        int min = i;
        for(int j = i + 1; j < end; j++)
            if(array[j] < array[min])
                min = j;
        swap(array[i], array[min]);
    }
}
