#include <iostream>

using namespace std;

int main()
{
    int array[10];
    cout << "Please enter ten integer numbers." << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < (sizeof(array)/sizeof(*array)); i++)
    {
        cout << " " << array[i];
    }
    return 0;
}