#ifndef _HEADER_QUEUE_H_
#define _HEADER_QUEUE_H_
#include <cstring>

namespace queue{
    typedef void Object;

    struct Item{
        Object* reference;
        Item* next;
    };

    typedef struct {
        Item* first;
        Item* last;
        int length;

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
    } Queue;
}

#endif