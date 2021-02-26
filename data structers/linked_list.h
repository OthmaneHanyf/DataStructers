#ifndef _HEADER_LINKED_LIST_H
#define _HEADER_LINKED_LIST_H
#include <iostream>
#include <cstring>

namespace linked_list{
    typedef const void Object;

    struct Item {
        Object* reference;
        Item* next;
    };

    typedef struct{
        Item* first;
        Item* last;
        int length;

        void init(){
            this->first = NULL; 
            this->last = NULL; 
            this->length = 0; 
        }
        void addItem(Object* object, int position){
            Item* newItem = new Item{object, NULL};

            if(position == 0 || this->first == NULL){
                newItem->next = this->first;
                this->first = newItem;
                // Set up list for the first insertion
                if(this->first == NULL) {
                    this->first->next = NULL;
                }
                this->length++;
                std::cout << "The item was inserted successfully !";
            } else {
                // The second insertion
                if(this->last == NULL){
                    this->last = newItem;
                    this->first->next = this->last;
                    this->length++;
                    std::cout << "The item was inserted successfully !";
                } else {
                    if(position <= this->length){
                        int i = 1;
                        Item* current = this->first;
                        while(i < position){
                            current = current->next;
                            i++;
                        }
                        newItem->next = current->next;
                        current->next = newItem;
                        this->length++;
                        std::cout << "The item was inserted successfully !";
                    } else {
                        std::cout << "Index out of range\n";
                    }
                }
            }
        }

        void deleteItem(int position){
            if(position < this->length){
                if(position == 0){
                    // free(this->first->reference);
                    this->first = this->first->next;
                    this->length--;
                    std::cout << "Item was deleted successfully !";
                } else {
                    int i = 1;
                    Item* current = this->first;
                    while(i <= position){
                        current = current->next;
                        i++;
                    }
                    current = current->next;
                    this->length--;
                    std::cout << "Item was deleted successfully !";
                }
            } else {
                std::cout << "Index out of range !";
            }
        }
    } List;
}

#endif