#include <iostream>
#include <tuple>

using namespace std;

#include <string>
#include <cstddef>
#include <concepts>

// Declaration of the concept "Hashable", which is satisfied by any type 'T'
// such that for values 'a' of type 'T', the expression std::hash<T>{}(a)
// compiles and its result is convertible to std::size_t
template<typename T>
concept Hashable = requires(T a)
{
    { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
};

struct meow {};

// Constrained C++20 function template:
template<Hashable T>
void f(T) { }
//
// Alternative ways to apply the same constraint:
// template<typename T>
//     requires Hashable<T>
// void f(T) {}
//
// template<typename T>
// void f(T) requires Hashable<T> {}
//
// void f(Hashable auto /*parameterName*/) {}

void basicControlFlows() {
    // if-else
    int a = 10;
    if (a > 10) {
        cout << "a is greater than 10" << endl;
    } else if (a < 10) {
        cout << "a is less than 10" << endl;
    } else {
        cout << "a is equal to 10" << endl;
    }

    // switch
    int b = 10;
    switch (b) {
        case 10:
            cout << "b is equal to 10" << endl;
            break;
        case 20:
            cout << "b is equal to 20" << endl;
            break;
        default:
            cout << "b is not equal to 10 or 20" << endl;
    }

    // switch case with enum
    enum color { red, green, blue };
    color c1 = blue;
    switch (c1) {
        case red:
            cout << "red" << endl;
            break;
        case green:
            cout << "green" << endl;
            break;
        case blue:
            cout << "blue" << endl;
            break;
        default:
            cout << "no color" << endl;
    }

    // while
    int c = 0;
    while (c < 10) {
        cout << "c: " << c << endl;
        c++;
    }

    // do-while
    int d = 0;
    do {
        cout << "d: " << d << endl;
        d++;
    } while (d < 10);

    // for
    for (int e = 0; e < 10; e++) {
        cout << "e: " << e << endl;
    }

    // break
    for (int f = 0; f < 10; f++) {
        if (f == 5) {
            break;
        } else if (f == 7) {
            continue;
        }
        cout << "f: " << f << endl;
    }

    // goto
    int g = 0;
    label:
    cout << "g: " << g << endl;
    g++;
    cout << "g+++: " << ++g << endl;
    if (g < 10) {
        goto label;
    }

    // ternary operator
    int h = 10;
    int i = 20;
    int j = (h > i) ? h : i;
    cout << "j: " << j << endl;

    // nested ternary operator
    int k = 10;
    int l = 20;
    int m = 30;
    int n = (k > l) ? ((k > m) ? k : m) : ((l > m) ? l : m);

    // switch case with enum class
    enum class color2 { red2, green2, blue2 };
    color2 c3 = color2::blue2;
    switch (c3) {
        case color2::red2:
            cout << "red2" << endl;
            break;
        case color2::green2:
            cout << "green2" << endl;
            break;
        case color2::blue2:
            cout << "blue2" << endl;
            break;
        default:
            cout << "no color2" << endl;
    }

    // closure capture by reference
    int o = 10;
    auto func = [&o]() {
        cout << "o: " << o << endl;
    };

    func();
    o++;
    func();

    // closure capture by value
    int p = 10;
    auto func2 = [p]() {
        cout << "clsoure capture p: " << p << endl;
    };

    p = 11;
    func2();

    // closure capture by value with mutable
    int q = 10;
    auto func3 = [q]() mutable {
        q++;
        cout << "clsoure capture q: " << q << endl;
    };

    func3();

    using std::operator""s;

    f("abc"s);    // OK, std::string satisfies Hashable
    // f(meow{}); // Error: meow does not satisfy Hashable
}