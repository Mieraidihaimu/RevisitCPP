#include <iostream>

using namespace std;

void basicAbstractions() {
    // enum class
    enum class color { red, green, blue };
    color c1 = color::blue;
    cout << "Enum class: " << &c1 << endl;
    cout << "Enum class value: " << (int)c1 << endl;

    // struct
    struct student {
        int rollNo;
        string name;
    };

    student s1;
    s1.rollNo = 1;
    s1.name = "John Doe";
    cout << "Struct: " << s1.rollNo << endl;
    cout << "Struct address " << &s1.name << endl;

    // union
    union marks {
        int internal;
        int external;
    };

    marks m1;
    cout << "Union without it: " << m1.internal  << m1.external << endl;

    cout << "Union address it: " << &m1 << endl;
    m1.internal = 10;
    cout << "Union: " << m1.internal << endl;
    m1.external = 20;
    cout << "Union: " << m1.external << endl;

    // class
    class student2 {
        public:
            int rollNo;
            string name;
    };

    student2 s2;
    s2.rollNo = 1;
    s2.name = "John Doe";
    cout << "Class: " << s2.rollNo << endl;
    cout << "Class address " << &s2.name << endl;

    // class with constructor and destructor
    class student3 {
        public:
            int rollNo;
            string name;

            student3() {
                cout << "Constructor" << endl;
            }

            ~student3() {
                cout << "Destructor" << endl;
            }
    };

    student3 s3;
    s3.rollNo = 1;
    s3.name = "John Doe";
    cout << "Class with constructor and destructor: " << s3.rollNo << endl;
    cout << "Class with constructor and destructor address " << &s3.name << endl;

    // memory allocation
    int *ptr = new int;
    *ptr = 10;
    cout << "Memory allocation: " << *ptr << endl;
    delete ptr;

    // memory allocation with array
    int *ptr2 = new int[5];
    ptr2[0] = 1;
    ptr2[1] = 2;
    ptr2[2] = 3;

    delete [] ptr2;

    cout << "Memory deleted? with array: " << ptr2[0] << endl; // will not throw an error?
    cout << "Memory deleted? with int: " << ptr << endl; // will not throw an error?

    // memory allocation with class
    student3 *ptr3 = new student3;
    ptr3->rollNo = 1;
    ptr3->name = "John Doe";
    cout << "Memory allocation with class: " << ptr3->rollNo << endl;
    cout << "Memory allocation with class address " << &ptr3->name << endl;
    delete ptr3;
    cout << "Memory deleted? with class: " << ptr3->rollNo << endl;

    // implement stack
    class stack {
        private:
            int top;
            int arr[5];

        public:
            stack() {
                top = -1;
                for (int i = 0; i < 5; i++) {
                    arr[i] = 0;
                }
            }

            bool isEmpty() {
                if (top == -1) {
                    return true;
                } else {
                    return false;
                }
            }

            bool isFull() {
                if (top == 4) {
                    return true;
                } else {
                    return false;
                }
            }

            void push(int val) {
                if (isFull()) {
                    cout << "Stack overflow" << endl;
                } else {
                    top++;
                    arr[top] = val;
                }
            }

            int pop() {
                if (isEmpty()) {
                    cout << "Stack underflow" << endl;
                    return 0;
                } else {
                    int popValue = arr[top];
                    arr[top] = 0;
                    top--;
                    return popValue;
                }
            }

            int count() {
                return (top + 1);
            }

            int peek(int pos) {
                if (isEmpty()) {
                    cout << "Stack underflow" << endl;
                    return 0;
                } else {
                    return arr[pos];
                }
            }

            void change(int pos, int val) {
                arr[pos] = val;
                cout << "Value changed at location " << pos << endl;
            }

            void display() {
                cout << "All values in the stack are: " << endl;
                for (int i = 4; i >= 0; i--) {
                    cout << arr[i] << endl;
                }
            }
    };

    stack s;
    cout << "Stack is empty? " << s.isEmpty() << endl;
    cout << "Stack is full? " << s.isFull() << endl;
    for (int i = 0; i < 7; i++) {
        s.push(i);
        cout << "Stack is full? " << s.isFull() << endl;
    }
    s.display();

    // implement queue
    class queue {
        private:
            int front;
            int rear;
            int arr[5];

        public:
            queue() {
                front = -1;
                rear = -1;
                for (int i = 0; i < 5; i++) {
                    arr[i] = 0;
                }
            }

            bool isEmpty() {
                if (front == -1 && rear == -1) {
                    return true;
                } else {
                    return false;
                }
            }

            bool isFull() {
                if (rear == 4) {
                    return true;
                } else {
                    return false;
                }
            }

            void enqueue(int val) {
                if (isFull()) {
                    cout << "Queue overflow" << endl;
                } else if (isEmpty()) {
                    rear = 0;
                    front = 0;
                    arr[rear] = val;
                } else {
                    rear++;
                    arr[rear] = val;
                }
            }

            int dequeue() {
                if (isEmpty()) {
                    cout << "Queue underflow" << endl;
                    return 0;
                } else if (front == rear) {
                    int popValue = arr[front];
                    arr[front] = 0;
                    rear = -1;
                    front = -1;
                    return popValue;
                } else {
                    int popValue = arr[front];
                    arr[front] = 0;
                    front++;
                    return popValue;
                }
            }

            int count() {
                return (rear + 1);
            }

            int peek(int pos) {
                if (isEmpty()) {
                    cout << "Queue underflow" << endl;
                    return 0;
                } else {
                    return arr[pos];
                }
            }

            void change(int pos, int val) {
                arr[pos] = val;
                cout << "Value changed at location " << pos << endl;
            }

            void display() {
                cout << "All values in the queue are: " << endl;
                for (int i = 0; i < 5; i++) {
                    cout << arr[i] << endl;
                }
            }
    };

    queue q;
    cout << "Queue is empty? " << q.isEmpty() << endl;
    cout << "Queue is full? " << q.isFull() << endl;
    for (int i = 0; i < 7; i++) {
        q.enqueue(i);
        cout << "Queue is full? " << q.isFull() << endl;
    }
    q.display();

    // implement linked list
    class node {
        public:
            int data;
            node *next;
    };

    node *head = new node();
    node *second = new node();
    head->data = 2;
    head->next = second;
    second->data = 3;

    cout << "Linked list: " << head->data << endl;
}