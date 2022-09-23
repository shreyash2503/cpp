#include <iostream>
using namespace std;
class Dynamic{
int *data;
int index;
int capacity;
public:
Dynamic(){
  data = new int[5];
  index=0;
  capacity=5;
}
Dynamic(Dynamic const& d){
  this->index = d.index;
  this->capacity = d.capacity;
  this->data = new int[d.capacity];
  for(int i=0;i<d.index;i++){
    this->data[i]=d.data[i];
  }
}
Dynamic operator=(Dynamic const& d){
  this->index = d.index;
  this->capacity = d.capacity;
  this->data = new int[d.capacity];
  for(int i=0;i<d.index;i++){
    this->data[i]=d.data[i];
  }
}

void add(int element){
  if(index==capacity){
    int *newData = new int[capacity*2];
    for(int i=0;i<index;i++){
      newData[i]=data[i];
    }
    delete []data;
    capacity = capacity*2;
    data=newData;
  }
  data[index]=element;
  index++;
}
int add(int element,int index){
  if(index>=0 && index<this->index){
    data[index]=element;
  }
  else if(index==this->index){
    add(element);
  }
  else{
    return -1;
  }
}
void print()const{
  for(int i=0;i<index;i++){
    cout<<data[i]<<" ";
  }
  cout<<endl;
}
void getCapacity() const{
  cout<<capacity<<endl;
}
};

int main() {
  Dynamic d1;
  d1.add(5);
  d1.add(4);
  d1.add(6);
  d1.add(100);
  d1.add(45);
  d1.add(45);
  d1.add(56);
  d1.getCapacity();
  Dynamic d2;
  d2 = d1;
  d2.add(100,0);
  d2.print();
  d1.print();
}
