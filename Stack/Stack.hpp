#ifndef MyStack_hpp
#define MyStack_hpp

#include <iostream>

template<class INF, class FRIEND>
class ListNode {
private:
    INF d;
    ListNode* next;
    ListNode(void) { next = nullptr; }
    friend FRIEND;
};


template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;
public:
    MyStack(void) : top(nullptr) {}
    ~MyStack(void) {
        while (!empty()) pop();
    }

    MyStack(const MyStack& ex) {
        if (ex.top != nullptr) {
            Node* currentNode = ex.top;
            Node* newNode = new Node;
            newNode->d = currentNode->d;
            newNode->next = currentNode->next;
            top = newNode;
            Node* lastNode = newNode;

            while (currentNode->next) {
                currentNode = currentNode->next;
                Node* newNode = new Node;
                newNode->d = currentNode->d;
                lastNode->next = newNode;
                lastNode = newNode;
            }
        }
    }

    MyStack& operator=(const MyStack& ex) {
        while (!empty()) {
            pop();
        }

        if (ex.top != nullptr) {
            Node* currentNode = ex.top;
            Node* newNode = new Node;
            newNode->d = currentNode->d;
            newNode->next = currentNode->next;
            top = newNode;
            Node* lastNode = newNode;

            while (currentNode->next) {
                currentNode = currentNode->next;
                Node* newNode = new Node;
                newNode->d = currentNode->d;
                lastNode->next = newNode;
                lastNode = newNode;
            }
        }
        return *this;
    }

    bool empty(void) {
        return top == nullptr;
    }

    bool push(INF n) {
        Node* newNode = new Node;
        if (!newNode) {
            return false;
        }
        newNode->d = n;
        newNode->next = top;
        top = newNode;
        return true;
    }

    bool pop(void) {
        if (empty()) {
            return false;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        return true;
    }



    INF top_inf(void) {
        if (empty()) {
            throw std::runtime_error("Стек пустой");
        }
        return top->d;
    }

    friend std::ostream& operator<<(std::ostream& in, const MyStack<INF>& Data) {
        Node* temp = Data.top;
        while (temp != nullptr) {
            in << temp->d << " ";
            temp = temp->next;
        }
        return in;
    }
};



#endif // MyStack_hpp
