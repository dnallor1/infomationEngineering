#include <iostream>
#include <vector>
#include "Invoice.h"

using namespace std;

int main(){

    Invoice inv("7770003699", "0123456789");
    inv.add_item(Item("M3 screw", 0.37, 'A', 100));
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));
    std::cout << inv << std::endl;
    return 0;
}

