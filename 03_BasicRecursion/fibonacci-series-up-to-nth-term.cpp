#include <bits/stdc++.h>
using namespace std;

// Recursive function to compute Nth Fibonacci number
int fibonacci(int N) {
    if (N <= 1) {
        return N;
    }
    return fibonacci(N - 1) + fibonacci(N - 2);
}

int main() {
    int N;
    cout <<"Enter upto which you want fibonacci series: ";
    cin >> N;
    cout << "Fibonacci Series up to " << N << " terms:\n";
    for (int i = 0; i < N; i++) {
        cout << fibonacci(i) << " ";
    }
    return 0;
}