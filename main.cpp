<<<<<<< HEAD
#include <iostream>
#include <exception>
#include <iostream>
#include <stdexcept>
#include "linklist.h"

int main() {
    LinkList<int> link;
    link.Insert(1);
    link.print();
    link.Delete(0);
    link.print();
    link.Insert(0, 1);
    link.print();
    link.Insert(1, 1);
    link.print();

    try {
        link.Insert(3, 1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    LinkList<int>::Node *find_result = link.Find(1);
    std::cout << find_result << std::endl;
    std::cout << find_result->elem << std::endl;
    return 0;
}
