#include<iostream>
using namespace std;
void sum(int [][10],int,int,int,int *);
void sum(int a[10][10],int row,int col,int add,int *avg){
	 add=0;
		for(int i=0;i<=row;i++){
		add=0;
		for(int j=0;j<=col;j++){	
		add=add+a[i][j];	
}
cout<<"the sum is=";
cout<<add<<endl;
*avg=add/col;
cout<<"the value of avrage is="<<*avg<<endl;
}
}
int main(){
	int b[10][10],r,c,plus,ag;
	cout<<"enter a number of rows=";
	cin>>r;
	cout<<"enter a number of col=";
	cin>>c;
	for(int i=0;i<=r;i++){
	for(int j=0;j<=c;j++){
	cout<<"enter value of array=";
	cin>>b[i][j];
}
}
	for(int i=0;i<=r;i++){
	for(int j=0;j<=c;j++){
	cout<<b[i][j]<<" ";
}
cout<<endl;
}
sum(b,r,c,plus,&ag);
}
