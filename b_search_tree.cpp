#include <utility> 
#include "b_search_tree.hpp"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace bst;

template<typename ElementType>
b_search_tree<ElementType>::b_search_tree() {
    root = nullptr;
}

template<typename ElementType>
void b_search_tree<ElementType>::insert(ElementType data) {
    root = insert_helper(root, data);
    size++;
}

template<typename ElementType>
Node<ElementType>* b_search_tree<ElementType>::insert_helper(Node<ElementType>* new_node, ElementType data) {
    if (new_node == nullptr) {
        return new Node<ElementType>(data, nullptr, nullptr);
    }
    if (data < new_node->data) {
        new_node->setLeft(insert_helper(new_node->getLeft(), data));  
        return new_node;
    } else {
        new_node->setRight(insert_helper(new_node->getRight(), data));
        return new_node;
    }
}

template<typename ElementType>
void b_search_tree<ElementType>::delete_element(ElementType data) {
    root = delete_helper(root, data);
    size--;
}

template<typename ElementType>
Node<ElementType>* b_search_tree<ElementType>::delete_helper(Node<ElementType>* n, ElementType data) {
    if (n == nullptr) {
        return nullptr;
    } 
    if (data == n->data) {
        if (n->left == nullptr && n->right == nullptr) {
            return nullptr;
        } else if (n->left == nullptr) {
            return n->right;
        } else if (n->right == nullptr) {
            return n->left;
        } 
        ElementType smallest_val = smallest(n);
        if (smallest_val != -1) {
            n->data = smallest_val;
        }
        n->right = delete_helper(n->right, smallest_val);
        return n;
    } else if (data < n->data) {
        n->setLeft(delete_helper(n->getLeft(), data));
        return n;
    } else {
        n->setRight(delete_helper(n->getRight(), data));
        return n;
    }
}

template<typename ElementType>
ElementType b_search_tree<ElementType>::smallest(Node<ElementType>* n) {
    if (n != nullptr) {
        ElementType smallest_val = 0;
        while (n) {
            if (n->data < smallest_val) {
                smallest_val = n->data;
            }
            n = n->left;
        }
        return smallest_val;
    }
    return -1;
}

template<typename ElementType>
bool b_search_tree<ElementType>::lookUp(ElementType data) {
    return lookUp_helper(root, data);
}

template<typename ElementType>
bool b_search_tree<ElementType>::lookUp_helper(Node<ElementType>* root_, ElementType data) {
   if (root_ == nullptr) {
       return false;
   } 
   if (root_->data == data) {
       return true;
   }
   if (root_->data < data) {
       return lookUp(root_->left, data);
   } else {
       return lookUp(root_->right, data);
   }
}

template<typename ElementType>
Node<ElementType>* b_search_tree<ElementType>::getRoot() {
    return this->root;
}

template<typename ElementType>
std::string b_search_tree<ElementType>::toString(Node<ElementType>* curr) {
    std::string nodes = "";
    if (curr == nullptr) {
        return "";
    }
    nodes += toString(curr->left);
    nodes += std::to_string(curr->data) + " ";
    nodes += toString(curr->right);
    return nodes;
}

template<typename ElementType>
int b_search_tree<ElementType>::getSize() {
    return this->size;
}
