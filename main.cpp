#include <iostream>
#include "vector.hpp"

using namespace std;

void vec();
int main(int argc, const char * argv[]) {
    try {
        vec();
    } catch (char* mas) {
        cout << mas << endl;
    }
    return 0;
}

void vec(){
    Vector<int> v(4);
    while (1) {
        int c;
        cout << ": "; cin >> c;
        if (c < 0){
            break;
        }
        v.pushBack(c);
    }
    v.show();
    v.sort('<');
    v.show();
}
