#include <iostream>
#include <vector>
#include <stack>
#include "CStack.h"
#include "CVector.h"

using namespace std;

int main() {
   // std::cout << "Hello, World!" << std::endl;
    CVector<int> cVector(8);

    int value = 0;

    int i = 3;
    while (cin >> value && i--){
        cVector.push_back(value);
        cout << "Entered value: " << value << endl;
        cout << "Back is: " << cVector.back() << endl;
        cout << "Stack capacity: " << cVector.capacity() << endl;
        cout << "Stack size: " << cVector.size() << endl;

    }

    CStack<int> cStack1 = cVector;
    cStack1.show();

    return 0;
}