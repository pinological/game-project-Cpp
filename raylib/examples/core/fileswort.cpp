#include <iostream>
#include <stdio.h>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;
void insert(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
}
void display() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
     
      
      int temp = ptr->data;
        printf("%d ",temp);
      ptr = ptr->next;
   }
}
int main(){
    insert(3);
    insert(7);
    insert(9);
    display();
   

    return 0; 
}