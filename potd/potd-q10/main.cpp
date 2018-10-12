#include <iostream>
#include "Base.h"
#include "Derived.h"

using namespace std;

int main() {
    Base *x1 = new Base();
    Base *x2 = new Derived();
    Derived *y1 = new Derived();

    cout << x1->foo() << endl;  //Sam I Am
    cout << x2->foo() << endl;  //Sam I Am
    cout << y1->foo() << endl;  //I will not eat them.
    
    cout << x1->bar() << endl;  //Green Eggs
    cout << x2->bar() << endl;  //And Ham
    cout << y1->bar() << endl;  //And Ham


    delete x1;
    delete x2;
    delete y1;
}
