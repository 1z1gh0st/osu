#include <iostream>
#include <cstdlib>

using namespace std;

void print(int array[], int start, int size) {
   if(start == size)
      return;
   else {
      print(array, start+1,size);
      cout << array[start] << endl;
    }
}

int main() {
	int a[5];
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	print(a, 0, 5);
	return 0;
}
