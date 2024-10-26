#include<iostream>
using namespace std;
void average(int[][100],int,int,int&);
void average(int array[100][100],int r,int c,int &avg){
	int sum=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
		sum=sum+array[i][j];
	}
}
	avg=sum/c;

}
int main(){
	int list[100][100],row,col,avg1;
	cout<<"enter row of array=";
	cin>>row;
	cout<<"enter col of array=";
	cin>>col;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
 	   cout<<"the value of array is=";
		cin>>list[i][j];
	}
}
		for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
		cout<<list[i][j]<<" ";
	}

	cout<<endl;
}
	average(list,row,col,avg1);
	cout<<"the array sum of average is="<<avg1;
	}
