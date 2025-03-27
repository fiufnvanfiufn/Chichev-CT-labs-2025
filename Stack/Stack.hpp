#ifndef MyStack_hpp
#define MyStack_hpp

#include <iostream>

// Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode {
private:
    INF d;                  // информационная часть узла
    ListNode* next;         // указатель на следующий узел списка
    ListNode(void) { next = nullptr; } // Конструктор
    friend FRIEND;
};

// Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;
public:
    MyStack(void) : top(nullptr) {}           // Конструктор
    ~MyStack(void) {
        while (!empty()) pop();
    } // Деструктор

    bool empty(void) {
        return top == nullptr;
    } // Проверка на пустоту

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
};

#endif // MyStack_hpp
