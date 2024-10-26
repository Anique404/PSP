#include<iostream>
using namespace std;
int factorial(int );
int  factorial(int a){
int fact=1;
for(int i=1;i<=a;i++)
	fact=fact*i;
return fact;

}
int main(){
	int n,f;
	cout<<"enter a number you want to factorial=";
	cin>>n;
	f=factorial(n);
	cout<<f;
	
}
