#include<iostream>
using namespace std;
int average(int[],int);
int average(int array[100],int size){
	int sum=0;
	for(int i=0;i<size;i++){
		sum=sum+array[i];
	}
int	avg=sum/size;
return avg;
}
int main(){
	int list[100],length;
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
	int total=average(list,length);
	cout<<"the avrage is="<<total;
}
