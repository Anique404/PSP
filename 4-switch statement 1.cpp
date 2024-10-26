#include <iostream>
using namespace std;
int main(){
	char ch;
	cout<<"enter a alphabet=";
	cin>>ch;
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
	
	switch(ch){
		case 'a':
		cout<<"vowel";	 break;
		case'e':
			cout<<"vowel";	break;
			case 'i':
			cout<<"vowel";break;
			case 'o':
			cout<<"vowel";break;
			case 'u':
			cout<<"vowel";break;
			default :
			cout<<"consonants";break;
	}
}
	else
	cout<<"\n you entered not a character";

}
