#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* head; // Front
    Node* tail; // Rear
    int size;
public:
    Queue() {
        head = tail = nullptr;
        size = 0;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            // List
            head = tail = newNode;
        } else {
            // Add to end
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        cout << "Enqueued: " << val << endl;
    }

    // Dequeue Remove from Head
    void dequeue() {
        if (head == nullptr) {
            cout << "Queue is Empty! Cannot dequeue." << endl;
            return;
        }

        Node* temp = head;
        int val = temp->data;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
        }

        delete temp;
        size--;
        cout << "Dequeued: " << val << endl;
    }

    int peek() {
        if (head == nullptr) {
            cout << "Queue is Empty!" << endl;
            return -1; 
        }
        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int getSize() {
        return size;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // Output: 10 20 30

    cout << "Front element: " << q.peek() << endl; // Output: 10

    q.dequeue(); // Removes 10
    q.display(); // Output: 20 30

    q.dequeue(); // Removes 20
    q.dequeue(); // Removes 30
    q.dequeue(); // Error: Empty

    return 0;
}