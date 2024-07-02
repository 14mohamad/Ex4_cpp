// main.cpp
// Email: your_email@example.com

#include "Complex.hpp"
#include "Tree.hpp"
#include <iostream>

int main() {
    Tree<int> intTree;
    intTree.add_root(1);
    intTree.add_sub_node(1, 2);
    intTree.add_sub_node(1, 3);
    intTree.add_sub_node(2, 4);
    intTree.add_sub_node(2, 5);
    intTree.add_sub_node(3, 6);
    intTree.add_sub_node(3, 7);

    std::cout << "Integer Tree Pre-Order Traversal: ";
    Tree<int>::IteratorBase *i = intTree.begin_pre_order();
    while (i->hasNext()) {
        std::cout << i->next() << " ";
    }
    delete i;
    std::cout << std::endl;

    Tree<Complex> complexTree;
    complexTree.add_root(Complex(1.0, 1.0));
    complexTree.add_sub_node(Complex(1.0, 1.0), Complex(2.0, 2.0));
    complexTree.add_sub_node(Complex(1.0, 1.0), Complex(3.0, 3.0));
    complexTree.add_sub_node(Complex(2.0, 2.0), Complex(4.0, 4.0));
    complexTree.add_sub_node(Complex(2.0, 2.0), Complex(5.0, 5.0));
    complexTree.add_sub_node(Complex(3.0, 3.0), Complex(6.0, 6.0));
    complexTree.add_sub_node(Complex(3.0, 3.0), Complex(7.0, 7.0));

    Tree<Complex, 2>::IteratorBase *it;
    std::cout << "Complex Tree Pre-Order Traversal: ";
    it = complexTree.begin_pre_order();
    while (it->hasNext()) {
        std::cout << it->next() << " ";
    }
    delete it;
    std::cout << std::endl;

    std::cout << "Complex Tree Post-Order Traversal: ";
    it = complexTree.begin_post_order();
    while (it->hasNext()) {
        std::cout << it->next() << " ";
    }
    delete it;
    std::cout << std::endl;

    std::cout << "Complex Tree In-Order Traversal: ";
    it = complexTree.begin_in_order();
    while (it->hasNext()) {
        std::cout << it->next() << " ";
    }
    delete it;
    std::cout << std::endl;

    std::cout << "Complex Tree BFS Traversal: ";
    it = complexTree.begin_bfs_scan();
    while (it->hasNext()) {
        std::cout << it->next() << " ";
    }
    delete it;
    std::cout << std::endl;

    std::cout << "Complex Tree DFS Traversal: ";
    it = complexTree.begin_dfs_scan();
    while (it->hasNext()) {
        std::cout << it->next() << " ";
    }
    delete it;
    std::cout << std::endl;

    std::cout << "Tree structure: " << std::endl;
    complexTree.print();

    return 0;
}
