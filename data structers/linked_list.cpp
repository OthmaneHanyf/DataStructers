// Example program for linked list usage

#include <iostream>
#include "linked_list.h"

#define size_s 64

// Application specific Object type
typedef struct {
    char* name = (char*) malloc(size_s);
} Person;

// Application specific functions
char* to_string(linked_list::Object* object){
    Person* person = (Person*) object;
    char* output = (char*) malloc(size_s);

    snprintf(output, size_s, "%s", person->name);
    return output;
}
bool are_equal(linked_list::Object* object1, linked_list::Object* object2){
    Person* person1  = (Person*) object1;
    Person* person2  = (Person*) object2;
    return strcmp(person1->name, person2->name) == 0 ? true : false;
}
void show(linked_list::List* list){
    if(list->first == NULL){
        std::cout << "The list is empty!" << std::endl;
    } else {
        int i = 0;
        linked_list::Item* current = list->first;
        while(i < list->length){
            std::cout << to_string(current->reference) << ", ";
            current = current->next;
            i++;
        }
    }
}

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
    linked_list::List* listPtr = new linked_list::List();
    listPtr->init();
    bool end = false;
    while(!end){
        switch(manu()){
            case 0:
                end = true;
                break;
            case 1:{
                try{
                    char* name = (char*) malloc(size_s);
                    int position;

                    // Get the person name
                    std::cout << "Enter a name : ";
                    std::cin >> name; std::cout << std::endl;
                    Person* person = new Person{name};
                    
                    if(listPtr->length != 0){
                        std::cout << "Enter the insertion position : ";
                        std::cin >> position; std::cout << std::endl;
                        listPtr->addItem(person, position);
                    } else {
                        listPtr->addItem(person, 0);
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
                show(listPtr);
                }break;
            default:
                end = true;
                free(listPtr);
                break;
        }
    }
}