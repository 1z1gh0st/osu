#include "event.h"

using std::cout;
using std::endl;

void Event::show() {
    cout << symbol;
}

void Event::precept() {
    cout << precept_message << endl;
}