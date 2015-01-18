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

template <class Type>
void sortInsertion(Type *array, int begin, int end);

template <class Type>
void sortBubble(Type *array, int begin, int end);

template <class Type>
void sortShell(Type *array, int begin, int end);

template <class Type>
void sortQuick(Type *array, int begin, int end);

template <class Type>
void partition(Type *array, int begin, int end);

int main()
{
    int array[20];

    initArray<int>(array, 20);
    showArray<int>(array, 20);

    cout << endl;

    sortShell<int>(array, 0, 20);
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
    cout << endl;
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

template <class Type>
void sortInsertion(Type *array, int begin, int end) {
    for(int i = end - 1; i > begin; --i)
        if(array[i] < array[i-1])
            swap(array[i], array[i-1]);
    for(int i = begin + 2; i < end; ++i) {
        int j;
        Type var = array[i];
        for(j = i; var < array[j - 1]; --j) {
            array[j] = array[j-1];
        }
        array[j] = var;
    }
}

template <class Type>
void sortBubble(Type *array, int begin, int end) {
    for(int i = begin; i < end - 1; ++i)
        for(int j = end - 1; j > i; --j)
            if(array[j] < array[j - 1])
                swap(array[j], array[j - 1]);
}

template <class Type>
void sortShell(Type *array, int begin, int end) {
    int h;
    for(h = 1; h < (end - 1)/9; h = 3 * h + 1);
    for( ; h > 0; h /= 3) {
        for(int i = begin + h; i < end; ++i) {
            int j;
            Type var = array[i];
            for(j = i; var < array[j - h] && j >= begin + h; j -= h)
                array[j] = array[j - h];
            array[j] = var;
        }
    }
}
