#include<iostream>
using namespace std;
void average(int,int,int&);
void average(int array[100],int size,int& avg){
	int sum=0;
	for(int i=0;i<size;i++){
		sum=sum+array[i];
	}
	avg=sum/size;

}
int main(){
	int list[100],length,avrg;
	cout<<"enter size of array=";
	cin>>length;
	for(int i=0;i<length;i++){
	   cout<<"the value of array is=";
		cin>>list[i];
	}
		for(int i=0;i<length;i++){
		cout<<list[i]<<" ";
	}
	cout<<endl;
	average(list,length,avrg);
	cout<<"the avrage is="<<avrg;
}
