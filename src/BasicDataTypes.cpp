// This file will contain all the basic data types in C++.
#include <iostream>
#include <vector>

using namespace std;

// typedef
typedef int marks;

void basicDataTypes() {
    int a = 10;
    cout << "Integer: " << a << endl;

    float b = 10.5;
    cout << "Float: " << b << endl;

    double c = 10.5;
    cout << "Double: " << c << endl;

    char d = 'A';
    cout << "Character: " << d << endl;

    bool e = true;
    cout << "Boolean: " << e << endl;

    string str = "Hello World";
    cout << "String: " << str << endl;

    // Size of operator
    cout << "Size of int: " << sizeof(a) << endl;

    // Short hand operators
    int x = 10, y = 20;

    x += y;
    cout << "x += y: " << x << endl;

    enum color { red, green, blue };
    color c1 = blue;
    cout << "Enum: " << c1 << endl;

    marks m1 = 10;
    cout << "Marks: " << m1 << endl;

    // Reference variables
    int p = 10;
    int &r = p;
    cout << "Reference variable: " << r << endl;
    // reference to a reference variable
    int &r1 = r;
    cout << "Reference to a reference variable: " << r1 << endl;
    cout << "Reference variable r address: " << &r << endl;
    cout << "Reference variable r1 address: " << &r1 << endl;

    // Typecasting
    int i = 10;
    float f = 10.5;
    cout << "Typecasting: " << (float)i << endl;

    // Constant variables
    const int j = 10;
    // j = 20; // This will throw an error

    // Arrays
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array: " << arr[0] << endl;

    // Dictionary
    int dict[2][2] = {{1, 2}, {3, 4}};
    cout << "Dictionary: " << dict[0][0] << endl;

    // Set
    int set[5] = {1, 2, 3, 4, 5};
    cout << "Set: " << set[0] << endl;

    // vector
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Vector: " << vec[0] << endl;

    // auto types
    auto a1 = 10;
    auto a4 = true;
    auto a5 = "Hello World";
    auto a6 = {1, 2, 3, 4, 5};
    cout << "Auto: " << &a1 << endl;
}