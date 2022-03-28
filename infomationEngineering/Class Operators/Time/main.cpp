#include <iostream>
#include <iomanip>
#include "timee.h"
using namespace std;
int main()
{
    Timee t1(200);
    cout << t1 << endl; // displays 03m:20s

    Timee t2;
    cin >> t2; // user enters 10h:12m:01s
    cout << t2 << endl;

    Timee t3 = t2 - t1; // 10h:8m:41s
    cout << t3 << endl; // displays 03m:20s
    return 0;
}
