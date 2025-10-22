#include <iostream>
using namespace std;

template<typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}


template<typename T>
void selectionSort(T arr[], int len) {
    if (len < 2)
        return;
    for (int i = 0; i < len; i++) {
        int max = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[max] < arr[j])
                max = j;
        }
        if (max != i)
            mySwap(arr[max], arr[i]);
    }

}



template<typename T>
void printArray(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void test01()
{
    char ch[] = "abcdeeaabbccaabb";
    int num = sizeof(ch) / sizeof(char);
    selectionSort(ch, num);
    printArray(ch, num);
}

void test02()
{
    int num[] = { 1,2,3,4,5,6,7,8 };
    int len = sizeof(num) / sizeof(int);
    selectionSort(num, len);
    printArray(num, len);
}


int main()
{
    test01();
    test02();
    return 0;
}