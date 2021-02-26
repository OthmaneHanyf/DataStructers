#include <iostream>
#include "queue.h"

#define size_s 64

// Application specific Object type
typedef struct {
    char* name;
} Person;

// Application specific functions
char* to_string(queue::Object* object){
    Person* person = (Person*) object;
    char* output = (char*) malloc(size_s);

    snprintf(output, size_s, "%s", person->name);
    return output;
}
bool are_equal(queue::Object* object1, queue::Object* object2){
    Person* person1  = (Person*) object1;
    Person* person2  = (Person*) object2;
    return strcmp(person1->name, person2->name) == 0 ? true : false;
}
void show(queue::Queue* queue){
    if(queue->first == NULL){
        std::cout << "The list is empty!" << std::endl;
    } else {
        int i = 0;
        queue::Item* current = queue->first;
        while(i < queue->length){
            std::cout << to_string(current->reference) << ", ";
            current = current->next;
            i++;
        }
    }
}

int manu(){
    printf ("\n\n QUEUE MANAGEMENT\n\n");
    printf (" 0 - End the program\n");
    printf ("\n");
    printf (" 1 - Push item to the queue \n");
    printf (" 2 - Pop item from the queue\n");
    printf (" 3 - Print out the queue\n");
    printf ("\n");
    printf ("What's your choice ? : ");
    int cod;
    std::cin >> cod;
    std::cout << std::endl;
    return cod;
}

int main(){
    queue::Queue* queue = new queue::Queue();
    queue->init();
    bool end = false;
    while(!end){
        switch(manu()){
            case 0:
                end = true;
                break;
            case 1:{
                try{
                    char* name = (char*) malloc(size_s);
            
                    std::cout << "Enter the element to be pushed : ";
                    std::cin >> name; std::cout << std::endl;
                    Person* person = new Person{name};
                    queue->push(person);
                    std::cout << "The item was pushed successfully !";
                } catch(...){
                    std::cout << "Error was detected while pushing !";
                }
                }break;
            case 2:{
                try{
                    std::cout << "The item " << to_string(queue->pop()) << " was poped successfully !";
                } catch(...){
                    std::cout << "Error was detected while poping !";
                }
                }break;
            case 3:{
                show(queue);
                }break;
            default:
                end = true;
                break;
        }
    }
}