#include <iostream>
#include <clocale>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void FindPairsWithSum(int Sum) {
        bool isFound = false;
        Node* current = head;
        cout << "Пары чисел с суммой " << Sum << " - " << endl;
        while (current != nullptr) {
            Node* runner = current->next;
            while (runner != nullptr) {
                if (current->data + runner->data == Sum) {
                    cout << current->data << " + " << runner->data << endl;
                    isFound = true;
                }
                runner = runner->next;
            }
            current = current->next;
        }

        if (isFound == false) {
            cout << "Пар с такой суммой не найдено" << endl;
        }
    }
}; 

int main() {
    setlocale(LC_ALL, "RU");
    DoublyLinkedList list;
    int size, value, Sum;
    cout << "Введите количество элементов в списке: ";
    cin >> size;
    cout << "Введите элементы списка: ";
    for (int i = 0; i < size; i++) {
        cin >> value;
        list.push_back(value);
    }

    cout << "Введите сумму для поиска пар: ";
    cin >> Sum;
    cout << "Двусвязный список: ";
    list.print();
    list.FindPairsWithSum(Sum);
}