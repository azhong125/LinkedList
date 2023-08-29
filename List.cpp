#include "List.h"
#include <stdexcept>
#include <iostream>
using namespace std;

List::List(){
    head = NULL;
}
List::List(const List& other){
    head = NULL;
    for (int i = 0; i < (int) other.count(); ++i) {
        this->insert(other.lookup(i));
    }
}

List::List(List&& other) {
    head = NULL;
    for (int i = 0; i < (int) other.count(); ++i) {
        this->insert(other.lookup(i));
    }
    other.~List();
}

List::~List() {
    Node* firstNode = head;
    while (firstNode != NULL) {
        Node* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
    head = NULL;
}

size_t List::count() const {
    Node* nextNode = head;
    size_t count = 0;
    while(nextNode != NULL) {
        count++;
        nextNode = nextNode->next;
    }
    return count;
}

void List::insert(const string& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* nextNode = head;
        Node* prevNode = head;
        if (head->data.compare(newNode->data) >= 0) {
            newNode->next = head;
            head = newNode;
        } else {
            int count = 0;
            while(nextNode->next != NULL) {
                int comparison = nextNode->data.compare(newNode->data);
                if (comparison >= 0) {
                    count = -1;
                    break;
                }
                else {
                    nextNode = nextNode->next;
                    if (count != 0) prevNode = prevNode->next;
                    count++;
                }
            }
            if (count == -1) {
                newNode->next = prevNode->next;
                prevNode->next = newNode;
            } else {
                if (nextNode->data.compare(newNode->data) > 0) {
                    newNode->next = prevNode->next;
                    prevNode->next = newNode;
                } else {
                    nextNode->next = newNode;
                }
            }
        }
    }
}

const string& List::lookup(size_t index) const {
    if (head == NULL) throw out_of_range("Index out of range");
    Node* nextNode = head;
    for (int i = 0; i < (int) index; ++i) {
        if (nextNode->next == NULL) throw out_of_range("Index out of range");
        nextNode = nextNode->next;
    }
    return nextNode->data;
}

void List::print(bool reverse) const{
    cout << "[";
    if (reverse) {
        for (int i = (int) count() - 1; i >= 0; --i) {
            if (lookup(i) < lookup(i - 1)){
                cout << lookup(i - 1) << ", ";
                cout << lookup(i);
                i--;
            } else {
                cout << lookup(i);
            }
            if (i != 0) cout << ", ";
        }
    } else {
        for (int i = 0; i < (int) count(); ++i) {
            cout << lookup(i);
            if (i != (int) count() - 1) cout << ", ";
        }
    }
    cout << "]" << endl;
}

string List::remove(size_t index) {
    if (head == NULL) throw out_of_range("Index out of range");
    Node* prev = head;
    Node* current = head;
    Node* next = current->next;
    if (index >= count()) throw out_of_range("Index out of range");
    if (index == 0) {
        head = head->next;
    } else {
        for (int i = 0; i < (int) index; ++i) {
            if (current->next == NULL) throw out_of_range("Index out of range");
            prev = current;
            current = next;
            next = current->next;
        }
        prev->next = next;
    }
    string answer = current->data;
    delete current;
    return answer;
}

size_t List::remove(const std::string& value) {
    int count = 0;
    while (head != NULL && head->data == value) {
        Node* next = head;
        head = head->next;
        delete next;
        count++;
    }
    if (head != NULL){
        Node* prev = head;
        Node* current = head;
        Node* next = current->next;

        while (current->next != NULL) {
            if (current->data == value) {
                count++;
                prev->next = next;
                delete current;
                current = prev;

            } else {
                prev = current;
                current = next;
                next = current->next;
            }

        }
        if (current->data == value) {
            count++;
            prev->next = next;
            delete current;
        }
    }


    return count;
}