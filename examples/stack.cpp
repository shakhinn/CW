#include<iostream>
using namespace std;

class Stack{
	int *arr;
	int n;
	int capacity;

public:
	Stack(int c){
		std::cout<<"Stack"<<endl;
		capacity = c;
		arr = new int[capacity];
		n = -1;
	}

	bool pop(int &val){
		if(isEmpty()){
			return false;
		}
		val = arr[n];
		n--;
		return true;
	}
	
	bool push(int a){
		if(n==capacity-1)
			return false;
		n++;
		arr[n] = a;
		return true;
	}

	int top(){
		if(isEmpty()){
			cout<<"Stack is empty"<<endl;
			return 0 ;
		}
		return arr[n];
	}

	bool isEmpty(){
		return n == -1;
	}

	~Stack(){
		std::cout<<"~Stack"<<endl;
		delete[] arr;
	}
};




int main(){
	Stack s(10);
	s.top();
	printf("\n");
	s.push(10);
	cout<<s.top()<<endl;
	s.push(20);
	cout<<s.top()<<endl;
	int res;
	while(s.pop(res)){
		cout<<"res = "<<res<<endl;
		}
		
	
	
	return 0;
}
