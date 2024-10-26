#include<iostream>
using namespace std;
void even(int);
void even(int *n){
for(int i=1;i<=*n;i++){

if(i%2==0){
	cout<<"even number"<<endl;
}	else
cout<<"odd number"<<endl;
}
}
int main(){
	int number;
	cout<<"eneter a number=";
	cin>>number;
	even(&number);
	
}
