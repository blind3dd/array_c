// 
// pawelBek
// blind3dd@gmail.com
//

#include <stdio.h>
#include <stdlib.h>

#define SIZEOF(a) sizeof(*a) / sizeof(a[0]);

int getArrayInputCount(void);
int allocateArrayMemory(int count);
void getArrayInputValues(int count, int* array);
void printArray(int* array, int count);
void printSizeOfArrayParameter(int array[]);
void printLengthOfArrayParameter(size_t arraySize);

int main(int argc, char* argv[])
{
    int count = getArrayInputCount();
    int* array = allocateArrayMemory(count);
    int arraySize = (sizeof(*array)) * count; // intsize * count

    getArrayInputValues(count, array);
    printArray(array, count);

    printf("sizeof of array: %d\n", arraySize);
    printf("length of array: %d\n", count);	// arraySize / intsize
    printSizeOfArrayParameter(array);
    printLengthOfArrayParameter(arraySize);
    printf("first element of array: %d\n", array[0]);
    printf("last lement of array: %d\n", array[count - 1]);

    free(array);

    return 0;
}

int getArrayInputCount(void)
{
    int count;
    printf("Enter length of array:\n");
    scanf_s("%d", &count);

    return count;
}

int allocateArrayMemory(int count)
{
    // allocate enough memory to fit count of integers size elements,
    int* array = malloc(count * sizeof(*array));
    if (!array || count < 1)
    {
        printf("could not allocate the memory for given input");
        exit(EXIT_FAILURE);
    }

    return array;
}

void getArrayInputValues(int count, int* array)
{
    printf("Enter elements of array:\n");
    for (int i = 0; i < count; i++)
    {
        scanf_s("%d", &array[i]);
    }
}

void printArray(int* array, int count)
{
    printf("[");
    for (int i = 0; i < count - 1; i++)
    {
        printf("%d, ", array[i]);
    }

    if (count >= 1)
        printf("%d", array[count - 1]);	// last element
    printf("]\n");
}

void printSizeOfArrayParameter(int array[])
{
    printf("sizeof of a single array element: %d\n", (int)sizeof(array));
}

void printLengthOfArrayParameter(size_t arraySize)
{
    printf("number of array elements: %d\n", arraySize / sizeof(int));	// size / size int
}
