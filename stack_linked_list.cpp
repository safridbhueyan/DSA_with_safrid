
#include<iostream>
using namespace std;
class Node{
  public:
      int data;
      Node* next;
      Node(int d){
        this->data=d;
        this->next = NULL;
      }
};

  class stack{
  Node* head;
  int capacity;
  int current_size;
  public:
  stack(int c){
  this ->capacity = c;
  this ->current_size = 0;
  head = NULL;
  }
  bool isEmpty(){
     return this->head == NULL;
                }
  bool isFull(){
  return this->capacity==current_size;
      }

 void push(int data){
     if(this->capacity==current_size){
        cout<<"overflow"<<endl;
        return;}
       Node* new_node = new Node(data);
        new_node->next=this->head;
        this->head =new_node;

        this->current_size++;
 }
 int pop(){
 if(this->head == NULL){
        cout<<"underflow"<<endl;
        return INT_MIN;}
      Node* new_head = this->head->next;
      this->head->next=NULL;
      Node*to_be_removed = this->head;
      int result=to_be_removed->data;
      delete to_be_removed;
      this->head = new_head;
      return result;
  }
  int getTop(){
  if(this->head == NULL){
        cout<<"underflow"<<endl;
        return INT_MIN;}

        return this->head->data;

  }
   int size(){
     return current_size;
     }
};

int main(){
   stack sd(5);

   sd.push(7);
   sd.push(5);
   sd.push(6);
  cout<<sd.getTop()<<endl;
   sd.push(9);
   sd.push(2);
   sd.push(3);
  cout<<sd.getTop()<<endl;
    sd.pop();
    sd.pop();
  cout<<sd.getTop()<<endl;

return 0;
}
