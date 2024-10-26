#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Date {
    int day, month, year;
};


struct Student{
	char RegNo[40];
	char name[40];
	Date Dob;
	int marks[5];

};

void input(Date &d) {
	cout<<endl;
	cout<<"Student date Of Birth"<<endl<<endl;
    cout << "Enter Day(1 to 31)=";
    cin >> d.day;
    while (d.day < 1 || d.day > 31) {
        cout << "You entered an invalid day\n";
        cout << "Enter Day(1 to 31)=";
        cin >> d.day;
    }

    cout << "Enter Month(1 to 12)=";
    cin >> d.month;
    while (d.month < 1 || d.month > 12) {
        cout << "You entered an invalid month\n";
        cout << "Enter Month(1 to 12)=";
        cin >> d.month;
    }

    cout << "Enter Year(1995 to 2007)=";
    cin >> d.year;
    while (d.year < 1995 || d.year > 2007) {
        cout << "You entered an invalid year\n";
        cout << "Enter Year(1995 to 2007)=";
        cin >> d.year;
    }
}


void output(Date &d) {
    cout << "Date of birth is =";
    cout << d.day << "/";
    cout << d.month << "/";
    cout << d.year << endl;
}


void Add(Student *,int ,int &);
void Delete(Student *,int &);
void Modify(Student *,int);
void Find(Student *,int);
void Sort(Student *,int);
void Print(Student *,int);

int main() {
    int maxsize;
    cout << "Enter the maximum number of students = ";
    cin >> maxsize;

    Student* students = new Student[maxsize];
    int currentsize = 0;

    char choice,ch;


do{
    
    cout<<endl;
    cout <<"\t"<<" ******************** What Do You Want *******************"<<endl<<endl;
    cout <<"\t"<< "Add a Student Record                                :"<<setw(7)<<"  A/a \n";
    cout <<"\t"<< "Delete a Student Record                             :"<<setw(7)<<"  D/d \n";
    cout <<"\t"<< "Modify a Student Record                             :"<<setw(7)<<"  M/m \n";
    cout <<"\t"<< "Find a Student Record                               :"<<setw(7)<<"  F/f  \n";
    cout <<"\t"<< "Sort a Student Record Acoording to Registration No  :"<<setw(7)<<"  S/s  \n";
	cout <<"\t"<< "Print all Record                                    :"<<setw(7)<<"  P/p  \n";
	cout <<"\t"<< "Quit                                                :"<<setw(7)<<"  X/x  \n";

    cout<<endl;
    cout<<endl;
    cout<<"Enter option=";
    cin >> choice;
    cout<<endl;
    switch (choice) {
    	
        case 'A':
        case 'a':
           
          Add(students,maxsize,currentsize);
           
            break;
            
        case 'D':
        case 'd':
           
          Delete(students,currentsize);
           
            break;
            
        case 'M':
        case 'm':
           
          Modify(students,currentsize);
          
           
            break;
            
        case 'F':
        case 'f':
           
         Find(students,currentsize);
           
            break;
            
        case 'S':
        case 's':
            Sort(students,currentsize);
          
            break;

       
        case 'P':
        case 'p':
           Print(students,currentsize);
          
           
            break;
            
            
        case 'X':
        case 'x':
        	
                delete[] students;
                students = NULL;
                
                return 0;
             
            break;
            
              
        default:
        	
            cout << "Invalid choice." << endl;
            break;
    }
    
    
    cout<<endl;
    cout<<"Do You Want to Perform Another Function(Y/N)=";
    cin>>ch;
    
    
    } while (ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n');
    
}



void Add(Student *s, int maxsize, int &currentsize) {
	
    if (currentsize < maxsize) {
        cout << "Enter Registration No=";
        cin >> s[currentsize].RegNo;

        int regNoLength = strlen(s[currentsize].RegNo);
        bool RegNo = true;

        for (int i = 0; i < regNoLength; i++) {
            if (!isdigit(s[currentsize].RegNo[i])) {
                RegNo = false;
                break;
            }
        }

        if (!RegNo) {
            cout << " RegistrationNo should contain only digits"<<endl;
            return;
        }
        
        for (int i = 0; i < currentsize; i++) {
            if (strcmp(s[currentsize].RegNo, s[i].RegNo) == 0) {
            	cout<<endl;
                cout << "You chould not enter Duplicate registration number."<<endl;
                return;
            }
        }
        
        
        cout << "Enter  Name=";
        cin >> s[currentsize].name;

        int NameLength = strlen(s[currentsize].name);
        bool Name = true;

        for (int i = 0; i < NameLength; ++i) {
            if (!isalpha(s[currentsize].name[i])) {
                Name = false;
                break;
            }
        }

        if (!Name) {
            cout << " Name should contain only Alphabets"<<endl;
            return;
        }
        
        input(s[currentsize].Dob);
        
         cout << "Enter Marks for 5 subjects (0 to 100)"<<endl;
        for (int i = 0; i < 5; ++i) {
        	cout<<"The Marks of Subject "<<i+1<<" =";
            cin >> s[currentsize].marks[i];
            
            while(s[currentsize].marks[i]<0 ||s[currentsize].marks[i]>100){
            	cout<<"You entered Invalid Marks"<<endl;
            	cout<<"The Marks of Subject" <<i+1<<" =";
                cin >> s[currentsize].marks[i];
			}
        }
        
        cout << "Student added successfully."<<endl;
        currentsize++;
        
    } 
	
	else {
        cout << "You should not add more Students" << endl;
    }
}



void Delete(Student* s, int &currentsize) {
    if (currentsize == 0) {
        cout << "Array is empty. No student to delete" << endl;
        return;
    }

    char regNo[40];
    cout << "Enter Registration No to Delete Student Record: ";
    cin >> regNo;

    int found = -1;

    for (int i = 0; i < currentsize; i++) {
        if (strcmp(s[i].RegNo, regNo) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (int i = found; i < currentsize - 1; i++) {
            s[i] = s[i + 1];
        }
        currentsize--;
        cout << "Student deleted successfully" << endl;
    } else {
        cout << "Student not found. No record deleted" << endl;
    }
}



void Modify(Student* s, int currentsize) {
    if (currentsize == 0) {
        cout << "Array is empty. No student to modify" << endl;
        return;
    }

    char regNo[40];
    cout << "Enter Registration No to Modify: ";
    cin >> regNo;

    int found = -1;

    for (int i = 0; i < currentsize; i++) {
        if (strcmp(s[i].RegNo, regNo) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        cout << "Current Information" << endl;
        cout << "Registration No= " << s[found].RegNo << endl;
        cout << "Name= " << s[found].name << endl;
        output(s[found].Dob);
        
        cout << "The Marks of Subject 5 " << endl;
        
        for (int j = 0; j < 5; ++j) {
            cout << "Subject " << j + 1 << " = " << s[found].marks[j] << endl;
        }
        cout << endl;

        cout << "Enter new Name: ";
        cin >> s[found].name;

        cout << "Enter new Date of Birth" << endl;
        input(s[found].Dob);

        cout << "Enter new Marks for 5 subjects" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "The Marks of Subject " << i + 1 << " = ";
            cin >> s[found].marks[i];
        }

        cout << "Student information modified successfully" << endl;
    } else {
        cout << "Student not found. No record modified" << endl;
    }
}



void Find(Student* s, int currentsize) {
    if (currentsize == 0) {
        cout << "Array is empty. No student to find" << endl;
        return;
    }

    char regNo[40];
    cout << "Enter Registration No to Find Student Record: ";
    cin >> regNo;

    int found = -1;

    for (int i = 0; i < currentsize; i++) {
        if (strcmp(s[i].RegNo, regNo) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
    	cout<<endl;
        cout << "Registration No= " << s[found].RegNo << endl;
        cout << "Name= " << s[found].name << endl;
        output(s[found].Dob);
        
        cout << "The Marks of Subject 5 " << endl;
        
        for (int j = 0; j < 5; ++j) {
            cout << "Subject " << j + 1 << " = " << s[found].marks[j] << endl;
        }
        cout << endl;
    } else {
        cout << "Student not found" << endl;
    }
}




void Sort(Student* s, int currentsize) {
    if (currentsize == 0) {
        cout << "No records to sort"<<endl;
        return;
    }


    for (int i = 0; i < currentsize-1; i++) {
        for (int j = i+1; j < currentsize; j++) {
            if (strcmp(s[i].RegNo, s[j].RegNo) > 0) {
             
                Student temp = s[i];
                s[i] = s[j ];
                s[j] = temp;
            }
        }
    }

    cout << "Student records sorted successfully by Registration No"<<endl;
}




void Print(Student* s, int currentsize) {
    if (currentsize > 0) {
        cout << endl;
        cout<<endl;
        cout <<"\t"<< "************  Student Records *************" << endl;
        for (int i = 0; i < currentsize; ++i) {
        	cout<<endl;
        	cout<<"\t"<<"The Record of Student "<<i+1<<endl;
        	cout<<endl;
            cout <<"\t"<< "Registration No= " << s[i].RegNo << endl;
            cout <<"\t"<< "Name= " << s[i].name << endl;
            cout<<"\t";
            output(s[i].Dob);
     

            cout <<"\t"<< "The Marks of Subject 5 "<<endl;
        
            for (int j = 0; j < 5; ++j) {
                cout <<"\t"<< "Subject " << j + 1 << " = " << s[i].marks[j]<<endl;
                
            }
            cout << endl;
        }
    } else {
        cout << "Array is empty. No records to print.\n";
    }
}



