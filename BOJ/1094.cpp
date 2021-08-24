#include <iostream>
#include <cstdio>

using namespace std;

int bit_count(int A){
    if (A == 0) return 0;
    return A % 2 + bit_count(A / 2);
}

int main() {
    int x;
    scanf("%d", &x);
    cout << bit_count(127 & x);
    return 0;
}