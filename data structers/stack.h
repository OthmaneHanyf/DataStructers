#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_
#include <cstring>

typedef void Object;

typedef struct Item{
    Object* reference;
    Item* next;
} Item;

typedef struct {
    Item* TOS; // Top Of Stack
    Item* BOS; // Bottom Of Stack
    int length;

    char* toString(Object* object){
        char* str = (char*) object;
        char* output = (char*) malloc(sizeof(str));

        snprintf(output, sizeof(str), "%s", str);
        return output;
    }
    bool areEqual(Object* object1, Object* object2){
        char* str1  = (char*) object1;
        char* str2  = (char*) object2;
        return strcmp(str1, str2) == 0 ? true : false;
    }

    void init(){
        this->TOS = new Item{NULL, NULL};
        this->BOS = new Item{NULL, NULL};
        this->length = 0;
    }
    void push(Object* obj){
        Item* newItem = new Item{obj, NULL};
        if(this->BOS->reference == NULL){
            this->BOS = newItem;
            this->TOS = newItem;
        }
        else {
            if(this->BOS->next == NULL){
                this->TOS = newItem;
                this->BOS->next = this->TOS;
            } else {
                this->TOS->next = newItem;
                this->TOS = newItem;
            }
        } 
        this->length++;
    }
    Object* pop(){
        Item* extrait = this->TOS;
        if(this->length != 0) {
            int i = 1;
            Item* current = this->BOS;
            while(i < this->length){
                current = current->next;
                i++;
            }
            free(current->next);
            this->TOS = current;

            if(this->BOS == this->TOS) {
                this->BOS = new Item{NULL, NULL};
                this->TOS = new Item{NULL, NULL};
            }
            this->length--;
        }
        return extrait != NULL ? extrait->reference : NULL;
    }
    void show(){
        if(this->BOS == NULL){
            std::cout << "The list is empty!" << std::endl;
        } else {
            int i = 0;
            Item* current = this->BOS;
            while(i < this->length){
                std::cout << this->toString(current->reference) << ", ";
                current = current->next;
                i++;
            }
        }
    }
} Stack;

#endif