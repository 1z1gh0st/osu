#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    for (auto element : mySet) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
