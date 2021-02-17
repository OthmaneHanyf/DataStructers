#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_
#include <cstring>

typedef void Object;

typedef struct Item{
    Object* reference;
    Item* next;
} Item;

typedef struct {
    Item* first;
    Item* last;
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
        this->first = new Item{NULL, NULL};
        this->last = new Item{NULL, NULL};
        this->length = 0;
    }
    void push(Object* obj){
        Item* newItem = new Item{obj, NULL};
        if(this->first->reference == NULL){
            this->first = newItem;
            this->last = newItem;
        }
        else {
            if(this->first->next == NULL){
                this->last = newItem;
                this->first->next = this->last;
            } else {
                this->last->next = newItem;
                this->last = newItem;
            }
        } 
        this->length++;
    }
    Object* pop(){
        Item* extrait = this->first;
        if(this->length != 0) {
            this->first = this->first->next;
            if(this->first == NULL) {
                this->last = new Item{NULL, NULL};
                this->first = new Item{NULL, NULL};
            }
            this->length--;
        }
        return extrait != NULL ? extrait->reference : NULL;
    }
    void show(){
        if(this->first == NULL){
            std::cout << "The list is empty!" << std::endl;
        } else {
            int i = 0;
            Item* current = this->first;
            while(i < this->length){
                std::cout << this->toString(current->reference) << ", ";
                current = current->next;
                i++;
            }
        }
    }
} File;

#endif