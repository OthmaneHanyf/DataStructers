// Example program for linked list usage

#include <iostream>
#include "linked_list.h"

int manu(){
    printf("\n\nList of names management\n\n");
    printf("0 - End program\n");
    printf("1 - Insert item\n");
    printf("2 - Delete item\n");
    printf("3 - Print out list items\n");
    printf("What is your choice ? : ");
    int code; 
    scanf("%d", &code);
    std::cout << std::endl;
    return code;
}

int main(){
    List* listPtr = new List();
    listPtr->init();
    bool end = false;
    while(!end){
        switch(manu()){
            case 0:
                end = true;
                break;
            case 1:{
                try{
                    char* name = (char*) malloc(16);
                    int position;
                    std::cout << "Enter a name : ";
                    std::cin >> name; std::cout << std::endl;
                    if(listPtr->length != 0){
                        std::cout << "Enter the insertion position : ";
                        std::cin >> position; std::cout << std::endl;
                        listPtr->addItem(name, position);
                    } else {
                        listPtr->addItem(name, 0);
                    }
                } catch(...){
                    std::cout << "Error in the insertion !";
                }
                }break;
            case 2:{
                try{
                    int position;
                    if(listPtr->length != 0){
                        if(listPtr->length != 1){
                            std::cout << "Enter the deletion position : ";
                            std::cin >> position; std::cout << std::endl;
                            listPtr->deleteItem(position);
                        } else {
                            listPtr->deleteItem(0);
                        }
                    } else {
                        std::cout << "The list is empty already !";
                    }
                } catch(...){
                    std::cout << "Error in the insertion !";
                }
                }break;
            case 3:{
                listPtr->show();
                }break;
            default:
                end = true;
                free(listPtr);
                free(name);
                break;
        }
    }
}