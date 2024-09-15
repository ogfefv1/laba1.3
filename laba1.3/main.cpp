//
//  main.cpp
//  laba1.3
//
//  Created by Егор Джемлиханов on 13.09.2024.
//

//лаба1 3
#include <iostream>
using namespace std;

void fillArray(int** A, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            A[i][j] = rand() % 100;
        }
    }
}

void buildEvenArray(int** A, int m, int n, int** B, int* rowSizes)
{
    for (int i = 0; i < m; ++i)
    {
        int k = 0;
        for (int j = 0; j < n; ++j)
        {
            if (A[i][j] % 2 == 0)
            {
                B[i][k++] = A[i][j];
            }
        }
        rowSizes[i] = k;
    }
}

void printArray(int** B, int m, int* rowSizes)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < rowSizes[i]; ++j)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}

int countGreaterThanN(int** B, int m, int* rowSizes, int N)
{
    int count = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < rowSizes[i]; ++j)
        {
            if (B[i][j] > N)
            {
                ++count;
            }
        }
    }
    return count;
}

int main()
{
    int m = 5;
    int n = 5;
    int N;

    int** A = new int*[m];
    for (int i = 0; i < m; ++i)
    {
        A[i] = new int[n];
    }
    fillArray(A, m, n);

    int** B = new int*[m];
    for (int i = 0; i < m; ++i)
    {
        B[i] = new int[n];
    }
    int rowSizes[5] = {0};

    buildEvenArray(A, m, n, B, rowSizes);

    cout << "массив массив В:" << endl;
    printArray(B, m, rowSizes);

    cout << "напишите число N: ";
    cin >> N;

    int count = countGreaterThanN(B, m, rowSizes, N);
    cout << "количество элементов в массиве В, больше чем " << N << ": " << count << endl;

    for (int i = 0; i < m; ++i)
    {
        delete[] A[i];
        delete[] B[i];
    }
    delete[] A;
    delete[] B;

    return 0;
}










////лаба1 С1
//#include <iostream>
//using namespace std;
//
//int* createArray(int size, int minValue, int maxValue)
//{
//    int* array = new int[size];
//    for (int i = 0; i < size; ++i) 
//    {
//        array[i] = minValue + rand() % (maxValue - minValue + 1);
//    }
//    return array;
//}
//
//int findMaxElement(int* array, int size) 
//{
//    int maxElement = array[0];
//    for (int i = 1; i < size; ++i) 
//    {
//        if (array[i] > maxElement) 
//        {
//            maxElement = array[i];
//        }
//    }
//    return maxElement;
//}
//
//void printArray(int* array, int size)
//{
//    for (int i = 0; i < size; ++i)
//    {
//        cout << array[i] << " ";
//    }
//    cout << endl;
//}
//
//int main() 
//{
//    srand(time(0));
//
//    int size = 10;
//    int* array1 = createArray(size, 1, 100);
//    int* array2 = createArray(size, 1, 100);
//
//    cout << "массив 1: ";
//    printArray(array1, size);
//    cout << "массив 2: ";
//    printArray(array2, size);
//
//    int sumMaxElements = findMaxElement(array1, size) + findMaxElement(array2, size);
//    cout << "сумма макс элемента: " << sumMaxElements << endl;
//
//    delete[] array1;
//    delete[] array2;
//
//    return 0;
//}










////лаба1 С2
//#include <iostream>
//using namespace std;
//
//int** create2DArray(int rows, int cols, int minValue, int maxValue)
//{
//    int** array = new int*[rows];
//    for (int i = 0; i < rows; ++i)
//    {
//        array[i] = new int[cols];
//        for (int j = 0; j < cols; ++j)
//        {
//            array[i][j] = minValue + rand() % (maxValue - minValue + 1);
//        }
//    }
//    return array;
//}
//
//int findMinElement(int** array, int rows, int cols) 
//{
//    int minElement = array[0][0];
//    for (int i = 0; i < rows; ++i) 
//    {
//        for (int j = 0; j < cols; ++j)
//        {
//            if (array[i][j] < minElement) 
//            {
//                minElement = array[i][j];
//            }
//        }
//    }
//    return minElement;
//}
//
//void print2DArray(int** array, int rows, int cols) 
//{
//    for (int i = 0; i < rows; ++i) 
//    {
//        for (int j = 0; j < cols; ++j)
//        {
//            cout << array[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main()
//{
//    srand(time(0));
//
//    int rows = 3, cols = 3;
//    int** array1 = create2DArray(rows, cols, 1, 100);
//    int** array2 = create2DArray(rows, cols, 1, 100);
//
//    cout << "массив 1:" << endl;
//    print2DArray(array1, rows, cols);
//    cout << "массив 2:" << endl;
//    print2DArray(array2, rows, cols);
//
//    int sumMinElements = findMinElement(array1, rows, cols) + findMinElement(array2, rows, cols);
//    cout << "сумма мин элемента: " << sumMinElements << endl;
//
//    for (int i = 0; i < rows; ++i)
//    {
//        delete[] array1[i];
//        delete[] array2[i];
//    }
//    delete[] array1;
//    delete[] array2;
//
//    return 0;
//}










////лаба2 3.1
//#include <iostream>
//using namespace std;
//
//int main() 
//{
//    double numbers[] = {1.5, 2.3, 3.7, 4.2, 5.0};
//    int size = sizeof(numbers) / sizeof(numbers[0]);
//    double sum = 0.0;
//
//    for (int i = 0; i < size; ++i) 
//    {
//        sum += numbers[i];
//    }
//
//    double average = sum / size;
//    cout << "Среднее арифметическое: " << average << endl;
//
//    return 0;
//}










////лаба2 3.2
//#include <iostream>
//using namespace std;
//
//int main() 
//{
//    int numbers[] = {10, 15, 20, 25, 30, 35, 40};
//    int size = sizeof(numbers) / sizeof(numbers[0]);
//    int A = 5;
//    int multiples[7];
//    int nonMultiples[7];
//    int multiplesCount = 0;
//    int nonMultiplesCount = 0;
//
//    for (int i = 0; i < size; ++i)
//    {
//        if (numbers[i] % A == 0) 
//        {
//            multiples[multiplesCount++] = numbers[i];
//        } 
//        else
//        {
//            nonMultiples[nonMultiplesCount++] = numbers[i];
//        }
//    }
//
//    cout << "Числа кратные " << A << ": ";
//    for (int i = 0; i < multiplesCount; ++i)
//    {
//        cout << multiples[i] << " ";
//    }
//    cout << endl;
//
//    cout << "Числа некратные " << A << ": ";
//    for (int i = 0; i < nonMultiplesCount; ++i)
//    {
//        cout << nonMultiples[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}










////лаба2 3.3
//#include <iostream>
//using namespace std;
//
//int main() 
//{
//    int temp[] = {3, 1, 4, 1, 5, 9, 2};
//    int size = sizeof(temp) / sizeof(temp[0]);
//    int stack[7];
//    int top = -1;
//
//    for (int i = 0; i < size; ++i) 
//    {
//        stack[++top] = temp[i];
//    }
//
//    int stackElements[7];
//    int stackElementsSize = 0;
//
//    while (top >= 0) 
//    {
//        stackElements[stackElementsSize++] = stack[top--];
//    }
//
//    int minElement = stackElements[0];
//    for (int i = 1; i < stackElementsSize; ++i) 
//    {
//        if (stackElements[i] < minElement)
//        {
//            minElement = stackElements[i];
//        }
//    }
//
//    int result[14];
//    int resultSize = 0;
//
//    for (int i = 0; i < stackElementsSize; ++i) 
//    {
//        result[resultSize++] = stackElements[i];
//        if (stackElements[i] == minElement)
//        {
//            result[resultSize++] = 0;
//        }
//    }
//
//    for (int i = resultSize - 1; i >= 0; --i) 
//    {
//        stack[++top] = result[i];
//    }
//
//    cout << "Стек после вставки 0: ";
//    while (top >= 0)
//    {
//        cout << stack[top--] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
