#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int angle;
	cout<<"the value of angle is=";
	cin>>angle;
	if(angle<90)
		cout<<"acute angle"<<endl;
	
	else if(angle>90)
		cout<<"abtuse angle"<<endl;
	
	else if (angle==90)
		cout<<"right angle";
		  
    else
	    cout<<"not a angle";
	
}
