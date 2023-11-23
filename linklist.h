#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
#include <stdexcept>
#include <string>
#include <exception>
#include <iostream>

template <typename ElemType>
class LinkList {
public:
    struct Node{
        ElemType elem {};
        Node *next {nullptr};

        Node() = default;
        Node(const Node &) = default;
        Node(Node &&) = default;
        const Node & operator=(const Node &node) {
            elem = node.elem;
            next = node.next;
        };
        Node &operator=(Node &&) = default;

        Node(const ElemType &elem_) :elem{elem_} {} 
        Node(ElemType &&elem_) : elem(elem_) {}
    };

    void Insert(const ElemType &elem) {
        Node *ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = new Node {elem};
    }

    void Insert(int position, const ElemType &elem) {
        Node *ptr = head;
        for (int i = 0; i < position; i++) {
            if (ptr == nullptr) {
                throw std::runtime_error {std::string{
                    "invalid position"
                }};
            }
            
            ptr = ptr->next;
        }

        if (position < 0 || ptr == nullptr) {
            throw std::runtime_error {std::string{
                "invalid position"
            }};
        }
        Node *tmp = ptr->next;
        ptr->next = new Node {elem};
        ptr->next->next = tmp;
    }

    void Delete(int position) {
        Node *prev = head;
        Node *ptr = head->next;
        for (int i = 0; i < position; i++) {
            if (ptr == nullptr) {
                throw std::runtime_error {std::string{
                    "invalid position"
                }};
            }
            
            ptr = ptr->next;
            prev = prev->next;
        }

        if (position < 0 || ptr == nullptr) {
            throw std::runtime_error {std::string{
                "invalid position"
            }};
        }

        Node *tmp = ptr->next;
        prev->next = tmp;
        delete ptr;
    }

    const Node* Find(const ElemType &elem) const {
        Node *ptr = head->next;
        while (ptr != nullptr) {
            if (ptr->elem == elem) {
                return ptr;
            }
            ptr = ptr->next;
        }
        
        return ptr;
    }

    Node *Find(const ElemType &elem) {
        Node *ptr = head->next;
        while (ptr != nullptr) {
            if (ptr->elem == elem) {
                return ptr;
            }
            ptr = ptr->next;
        }

        return ptr;
    }

    void print () {
        Node *ptr = head->next;
        while (ptr != nullptr) {
            std::cout << ptr->elem << ' ';
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }

    LinkList() {
        head = new Node {ElemType{}};
    }

    ~LinkList() {
        Node * ptr = head->next;
        while (ptr != nullptr) {
            Node *tmp = ptr->next;
            delete ptr;
            ptr = tmp;
        }
    }

private:
    Node *head;
};

#endif