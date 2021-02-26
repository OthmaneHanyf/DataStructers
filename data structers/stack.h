#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_
#include <cstring>

namespace stack {
    typedef void Object;

    typedef struct Item{
        Object* reference;
        Item* next;
    } Item;

    typedef struct {
        Item* TOS; // Top Of Stack
        Item* BOS; // Bottom Of Stack
        int length;

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
    } Stack;
}

#endif