#include <bits/stdc++.h>
using namespace std;

/*
    Author: Priyangshu Das
    Topic: Striver DSA Sheet - Pattern Problems

    Description:
    This file contains multiple pattern problems used to
    improve logic building using loops.

    Tip:
    Change function call in main() to test different patterns.
*/


// 🔹 Pattern 1: Square Pattern
void pattern1(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}


// 🔹 Pattern 2: Right Triangle (Stars)
void pattern2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}


// 🔹 Pattern 3: Number Triangle
void pattern3(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
}


// 🔹 Pattern 4: Same Number Triangle
void pattern4(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << "\n";
    }
}


// 🔹 Pattern 5: Inverted Star Triangle
void pattern5(int n) {
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}


// 🔹 Pattern 6: Inverted Number Triangle
void pattern6(int n) {
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
}


// 🔹 Pattern 7: Pyramid
void pattern7(int n) {
    for(int i = 0; i < n; i++) {

        // spaces
        for(int j = 0; j < n - i - 1; j++)
            cout << " ";

        // stars
        for(int j = 0; j < 2*i + 1; j++)
            cout << "*";

        cout << "\n";
    }
}


// 🔹 Pattern 8: Inverted Pyramid
void pattern8(int n) {
    for(int i = 0; i < n; i++) {

        // spaces
        for(int j = 0; j < i; j++)
            cout << " ";

        // stars
        for(int j = 0; j < 2*n - (2*i + 1); j++)
            cout << "*";

        cout << "\n";
    }
}


// 🔹 Pattern 9: Diamond
void pattern9(int n) {
    pattern7(n);
    pattern8(n);
}


// 🔹 Pattern 10: Half Diamond
void pattern10(int n) {
    for(int i = 1; i <= 2*n-1; i++) {
        int stars = (i > n) ? 2*n - i : i;

        for(int j = 1; j <= stars; j++)
            cout << "* ";

        cout << "\n";
    }
}


// 🔹 Pattern 11: Binary Triangle
void pattern11(int n) {
    for(int i = 0; i < n; i++) {
        int val = (i % 2 == 0) ? 1 : 0;

        for(int j = 0; j <= i; j++) {
            cout << val;
            val = 1 - val;  // toggle
        }
        cout << "\n";
    }
}


// 🔹 Pattern 12: Number Palindrome Pyramid
void pattern12(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 2*n; j++) {

            if (j <= i)
                cout << j;

            else if(j > 2*n - i)
                cout << 2*n - j + 1;

            else
                cout << " ";
        }
        cout << "\n";
    }
}


// 🔹 Pattern 13: Continuous Numbers
void pattern13(int n) {
    int k = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << k++ << " ";
        }
        cout << "\n";
    }
}


// 🔹 Pattern 14: Alphabet Triangle
void pattern14(int n) {
    for(int i = 0; i < n; i++) {
        for(char ch = 'A'; ch <= 'A' + i; ch++) {
            cout << ch << " ";
        }
        cout << "\n";
    }
}


// 🔹 Pattern 21: Hollow Square
void pattern21(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(i==0 || j==0 || i==n-1 || j==n-1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}


// 🔹 Pattern 22: Concentric Square
void pattern22(int n) {
    for(int i = 0; i < 2*n-1; i++) {
        for(int j = 0; j < 2*n-1; j++) {

            int top = i;
            int left = j;
            int bottom = 2*(n-1) - i;
            int right = 2*(n-1) - j;

            cout << (n - min(min(top, bottom), min(left, right)));
        }
        cout << "\n";
    }
}


// 🔹 MAIN FUNCTION
int main() {
    int n;
    cin >> n;

    pattern22(n);   // 👉 Change this to test other patterns

    return 0;
}