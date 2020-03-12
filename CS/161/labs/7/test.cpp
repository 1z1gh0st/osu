#include <iostream>

using namespace std;

void edit_pointer(int *ptr)
{
    *ptr = 6;
}

int main()
{
    int num = 5;
    int *ptr = new int; 
    *ptr = num;
    cout << *ptr << endl;
    edit_pointer(ptr);
    cout << *ptr << endl;
    delete ptr;
}
