#include"Search.h"
#include<iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5, 5, 5, 5, 5, 10, 11, 12};
    cout << (::lower_bound(a, a + 12, 12) - a) << endl;
    cout << (::upper_bound(a, a + 12, 12) - a) << endl;
}