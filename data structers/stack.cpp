#include <iostream>
#include "stack.h"

int manu(){
    printf ("\n\n Stack of names managment\n\n");
    printf (" 0 - End the program\n");
    printf ("\n");
    printf (" 1 - Push item to the stack \n");
    printf (" 2 - Pop item from the stack\n");
    printf (" 3 - Print out the file\n");
    printf ("\n");
    printf ("What's your choice ? : ");
    int cod;
    std::cin >> cod;
    std::cout << std::endl;
    return cod;
}

int main(){
    Stack* stack = new Stack();
    stack->init();
    bool fini = false;
    while(!fini){
        switch(manu()){
            case 0:
                fini = true;
                break;
            case 1:{
                try{
                    char* name = (char*) malloc(16);
                    std::cout << "Enter the element to be pushed : ";
                    std::cin >> name; std::cout << std::endl;
                    stack->push(name);
                    std::cout << "The item was pushed successfully !";
                } catch(...){
                    std::cout << "Error was detected while pushing !";
                }
                }break;
            case 2:{
                try{
                    char* name = (char*) malloc(16);
                    name = (char*) stack->pop();
                    std::cout << "The item " << name << " was poped successfully !";
                } catch(...){
                    std::cout << "Error was detected while poping !";
                }
                }break;
            case 3:{
                stack->show();
                }break;
            default:
                fini = true;
                break;
        }
    }
}