#include<iostream>
using namespace std;

class stack{
int capacity;
int* arr;
int top;
public:
    stack(int c){
    this->capacity = c;
    arr = new int[c];
    this-> top= -1;

    }
    void push(int data){
    if(this->top == this->capacity-1){
        cout<<"overflow"<<endl;
        return;
          }
          this->top++;
          this->arr[this->top]=data;
          }

     int pop(){
      if(this->top==-1){
        cout<<"Underflow"<<endl;
        return INT_MIN;
                       }
      this->top--;
     }
     int getTop(){
     if(this->top==-1){
        cout<<"Underflow"<<endl;
        return INT_MIN;
     }
     return this->arr[this->top];}

     bool isEmpty(){
     return this->top==-1;
     }
     int size(){
     return this->top+1;
     }
     bool isFull(){
     return this->top == this->capacity-1;
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
