#ifndef _HEADER_ARBRE_H
#define _HEADER_ARBRE_H
#include <iostream>
#include <cstring>
#include "queue.h" // Used for level order traversing
// using namespace queue;
#define size_s 64
typedef const char Object;

// we first define the node struct
struct Node {
    Object* reference;
    Node* left;
    Node* right;
    
    // Build this instance node
    void this_node(Object* object, Node* left, Node* right){
        this->reference = object;
        this->left = left;
        this->right = right;
    }

    // Build new node
    Node* new_node(Object* object, Node* left, Node* right){
        Node* node = new Node{object, left, right};
        return node;
    }

    // Print out a node reference
    char* to_string(Object* object)
    { 
        char* ref = (char*) object;
        char* output = (char*) malloc(size_s);
        snprintf(output, size_s, "%s", ref);
        return output;
    }

    // Compare to references for two nodes
    int compare(Object* object1, Object* object2)
    {
        char* ref1  = (char*) object1;
        char* ref2 = (char*) object2;
        return strcmp(ref1, ref2);
    }

};

// Define the tree struct
struct Tree {
    // The root node 
    Node* root = new Node{NULL, NULL, NULL};

    // Functions and methods
    // create new tree
    void new_tree(Node* root){
        this->root = root;
    }

    // Find a node
    Node* find(Node* root, Node* node){
        if(root == NULL || node == NULL)
            return NULL;
        if(this->root->compare(root->reference, node->reference) == 0)
            return root;
        Node* first_found = this->find(root->left, node);
        if(first_found != NULL)
            return first_found;
        return this->find(root->right, node);
    }

    // Append child node
    bool append_node(Node* parent,Node* child){

        Node* parent_node = new Node();
        parent_node = this->find(this->root, parent);
        if(parent_node == NULL){
            std::cout << "No matching found for " << this->root->to_string(parent_node->reference);
            return false;
        }
        if(parent_node->left != NULL && parent_node->right != NULL){
            std::cout << this->root->to_string(parent_node->reference) << " already has 2 childs.";
            return false;
        }
        if(parent_node->left == NULL)
            parent_node->left = child;
        else
            parent_node->right = child;
        return true;
    }

    // traversing tree
    void pre_order(Node* root){
        if(root != NULL)
        {
            std::cout << root->to_string(root->reference) << std::endl;
            this->pre_order(root->left);
            this->pre_order(root->right);
        } else 
            return;
    }

    void level_order(){
        queue::Queue* queue = new queue::Queue();
        queue->init();
        queue->push(this->root);
        while(queue->length != 0){
            Node* extracted = (Node*) queue->pop(); 
            std::cout << this->root->to_string(extracted->reference) << std::endl;
            if(extracted->left != NULL) queue->push(extracted->left);
            if(extracted->right != NULL) queue->push(extracted->right);
        }
        return;
    }
};

#endif