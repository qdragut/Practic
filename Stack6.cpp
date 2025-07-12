#include <iostream>
#include <ctime>      
#include <random>
#include <clocale>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}  
};

class Stack {
private:
    Node* top;  

public:
    Stack() : top(nullptr) {}

    ~Stack() {  
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cerr << "Стек пустой" << endl;
            return -1;  
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void display() const {
        Node* current = top;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Реверс стека через рекурсию
    void reverse() {
        if (!isEmpty()) {
            int val = pop();
            reverse();
            insertAtBottom(val);
        }
    }

private:
    // вставляем элемент вниз
    void insertAtBottom(int val) {
        if (isEmpty()) {
            push(val);
        }
        else {
            int temp = pop();
            insertAtBottom(val);
            push(temp);
        }
    }
};

int main() {
    Stack stack;
    setlocale(LC_ALL, "RU");
    int n, val;
    cout << "Введите количество элементов: ";
    cin >> n;

    mt19937 gen(time(0));  // Генератор случайных чисел
    uniform_int_distribution<> dist(1, 100);  // Диапазон
    for (int i = 0; i < n; ++i) {
        stack.push(dist(gen));
    }

    cout << "Исходный стек: ";
    stack.display();

    stack.reverse();
    cout << "После реверса: ";
    stack.display();
}
