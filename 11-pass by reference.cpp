#include<iostream>
using namespace std;
void sum(int[],int,int &);
void sum(int a[100],int size,int &s){
	s=0;
	for(int i=0;i<=size;i++){
		s=s+a[i];
	}
}
int main(){
		int array[100],n,add;
	cout<<"enter a number=";
	cin>>n;
	for(int i=0;i<=n;i++){
		cout<<"enter value of array=";
		cin>>array[i];
	} 
		sum(array,n,add);
		cout<<add;

}
