/*
 NAME: Harish Palani
 CRN: 11467
 ASSIGNMENT: Lab 3
 SOURCES: stackoverflow.com
 */

#include <cctype>
#include <cmath>
#include <cstring>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Functions
int countSpaces(string &str);
long long decryptionCipher(long long base,
                           long long exponent,
                           long long divisor);

// Parameters
long long pq = 323;
long long e = 35;
long long d = 107;

int main() {
    // Accept input file path & load in string.
    string path;
    cout << "Enter input file path below." 
         << endl;
    cin >> path;
    
    ifstream t(path);
    stringstream buffer;
    buffer << t.rdbuf(); 
    string in = buffer.str(); // buffer.str() to get contents as string
    
    // Load input file contents into int array.
    int listSize = countSpaces(in) + 1;
    long long list[listSize];
    
    stringstream stream(in);
    int n;
    int index = 0;
    while (stream >> n) {
        list[index] = n;
        index++;
    }
    
    // Decrypt message and print translation.
    cout << "\nDecoded message:\n";
    for (int i = 0; i < listSize; i++) {
        // M = C^d mod pq (c: base, d: exponent, pq: divisor)
        long long c = list[i];
        long long m = decryptionCipher(c, d, pq);
        cout << m << " ";
    }
    cout << endl;
}

// Count number of spaces in string paramteter
int countSpaces(string &str) {
    int count = 0;
    int length = str.length();
    for (int i = 0; i < length; i++) {
        int c = str[i];
        if (isspace(c)) { count++; }
    }
    return count;
}

// Decipher input encryption characteristics
long long decryptionCipher(long long base,
                           long long exponent,
                           long long divisor) {
    long long product = 1;
    long long x = 1, y = base;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            x = (x * y) % divisor;
        }
        y = (y * y) % divisor;
        exponent /= 2;
    }
    
    return x % divisor;
}