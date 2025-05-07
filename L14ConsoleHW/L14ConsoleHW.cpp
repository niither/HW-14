#include <iostream>
using namespace std;

void show_array(int* ar, int size);
void delete_last_element(int*& ar, int& size);
void add_first_element(int*& ar, int& size, int userInt);

int main()
{
    int size = 10;
    int userInt;
    int* ar = new int[size] {14, 67, 83, 41, 99, 87, 34, 27, 22, 50};

    cout << "Array:\n";
    show_array(ar, size);

    delete_last_element(ar, size);
    cout << "\n\nArray after delete:\n";
    show_array(ar, size);

    cout << "\nEnter an int: ";
    cin >> userInt;
    add_first_element(ar, size, userInt);
    cout << "\nArray after add:\n";
    show_array(ar, size);

    delete[] ar; // Звільнення пам’яті перед завершенням
    return 0;
}

void show_array(int* ar, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << " ";
    }
    cout << "\n";
}

void delete_last_element(int*& ar, int& size)
{
    int* temp = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
        temp[i] = ar[i];
    delete[] ar;
    ar = temp;
    size--;
}

void add_first_element(int*& ar, int& size, int userInt)
{
    int* temp = new int[size + 1];
    temp[0] = userInt;
    for (int i = 0; i < size; i++)
    {
        temp[i + 1] = ar[i];
    }
    delete[] ar;
    ar = temp;
    size++;
}