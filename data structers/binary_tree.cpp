#include <iostream>
#include "binary_tree.h"

#define size_s 64

int manu(){
    printf ("\n\n BINARY TREE MANAGMENT \n");
    printf (" 0 - End the program\n");
    printf ("\n");
    printf (" 1 - create a genealogic tree\n");
    printf (" 2 - Create an arithmetic expression tree\n");
    printf ("\n");
    printf (" 3 - Pre-order traversal\n");
    printf (" 4 - Level order traversal\n");
    printf (" 5 - Append node\n");
    printf ("\n");
    printf ("Votre choix ? ");
    int code;
    scanf ("%d", &code);
    getchar();
    printf ("\n");
    return code;
}

int main(){
    Tree* tree = new Tree();
    bool end = false;
    while(!end){
        switch(manu()){
            case 0:{
                end = true;
                }break;
            case 1:{
                Node* node = new Node();
                node->this_node("Samir", node->new_node("Kamal", node->new_node("Yassine", NULL, node->new_node("Hind", NULL, node->new_node("Yasmine", NULL, NULL))), node->new_node("Sarah", node->new_node("Kamal", NULL, NULL), NULL)), NULL);
                tree->new_tree(node);
                std::cout << "The genealogic tree was created successfully !";
                }break;
            case 2:{
                Node* node = new Node{"-", node->new_node("*", node->new_node("+", node->new_node("a", NULL, NULL), node->new_node("b", NULL, NULL)), node->new_node("-", node->new_node("c", NULL, NULL), node->new_node("d", NULL, NULL))), node->new_node("e", NULL, NULL)};
                tree->new_tree(node);
                std::cout << "The arithmetic expression tree was created successfully !";
                }break;
            case 3:{
                try{
                    tree->pre_order(tree->root);
                } catch (...){
                    std::cout << "Aucun arbre cree !";
                } 
                }break;
            case 4:{
                try{
                    tree->level_order();
                } catch (...){
                    std::cout << "Aucun arbre cree !";
                } 
                }break;
            case 5:{
                char* parent = new char[size_s];
                char* child = new char[size_s];

                std::cout << "The parent name : "; std::cin >> parent;
                std::cout << "The child name : "; std::cin >> child;

                Node* parent_node = new Node{parent, NULL, NULL};
                Node* child_node = new Node{child, NULL, NULL};
                tree->append_node(parent_node, child_node);
                // std::cout << "Appending end with success !";
                }break;
            default:
                end = true;
                break;
        }
    }
}