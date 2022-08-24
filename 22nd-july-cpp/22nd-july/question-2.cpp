#include<iostream>
#include<string>
using namespace std;

class student {
  string name;
  int roll;
  float marks[5];
  float totalMarks;
  float percentage;

 public:

  void setName(string name) {
	  this -> name = name;
	}

	void setRoll(int roll) {
		this -> roll = roll;
	}

	void setMarks(float *marks) {
		for(int i = 0 ; i < 5 ; i++) {
		  this -> marks[i] = marks[i];
		}
	}

	void setTotalMarks() {
      float total = 0;
      for(int i = 0 ; i < 5 ; i++) {
      	total += this -> marks[i];
      }
      this -> totalMarks = total;
	}

  void setPercentage() {
   	  float total = 0;
      for(int i = 0 ; i < 5 ; i++) {
      	total += this -> marks[i];
      }
      this -> percentage = total/5;
  }
  string getName() {
    return this -> name;
  }
  int getRoll() {
    return this -> roll;
  }
  float getTotalMarks() {
   	return this -> totalMarks;
  }

  float getPercentage() {
   	return this -> percentage;
  }
  void printMarks() {
    for(int i = 0 ; i < 5 ; i++) {
      cout << this -> marks[i] << "\t";
    }
  }
  void studentWithGivenRollNumber(int roll) {
   	    if(this -> roll == roll) {
   	      cout << "DETAILS OF ROLL NUMBER " << roll << " ARE AS FOLLOWS : " << endl << endl;
   	      cout << "NAME : " << this -> name << endl;
   	      cout << "MARKS : ";
   	      for(int i = 0 ; i < 5 ; i++) {
      	    cout << this -> marks[i] << "\t";
          }
          cout << endl;
          cout <<"TOTAL MARKS : " << this -> totalMarks << endl;
          cout << "PERCENTAGE : " << this -> percentage << "%" << endl;
          cout << endl;
   	    }
  }

  void studentInGivenRange(float lowerRange , float upperRange) {
   	    if(this -> percentage >= lowerRange && this -> percentage <= upperRange) {
          cout << "NAME : " << this -> name << endl;
          cout << "ROLL NUMBER : " << this -> roll << endl;
   	      cout << "MARKS : ";
   	      for(int i = 0 ; i < 5 ; i++) {
      	    cout << this -> marks[i] << "\t";
          }
          cout << endl;
          cout <<"TOTAL MARKS : " << this -> totalMarks << endl;
          cout <<"PERCENTAGE : " << this -> percentage << "%" << endl;
          cout << endl; 
   	    }
  }

};
void sortStudentArray(student *s,int n) {
  for(int i = 0 ; i < n ; i++) {
    student min = s[i];
    int minIndex = i;

    for(int j = i+1 ; j < n ; j++) {
      if(s[j].getTotalMarks() < min.getTotalMarks()) {
        min = s[j];
        minIndex = j;
      }
    }

    student temp = s[i];
    s[i] = s[minIndex];
    s[minIndex] = temp;
  }
}


int main() {
  int n;
  cout << "ENTER TOTAL NO. OF STUDENTS : ";
  cin >> n;
  student s[n];

  for(int i = 0 ; i < n ; i++) {
   string name;
   cout << "ENTER NAME OF STUDENT " << i+1 << " : ";
   cin >> name;
   s[i].setName(name);

   int roll;
   cout << "ENTER ROLL NUMBER OF THE STUDENT : " ;
   cin >> roll;
   s[i].setRoll(roll);

   float arr[5];
   cout << "ENTER MARKS IN 5 SUBJECTS OF THE STUDENT : " << endl ;
   for(int i = 0 ; i < 5 ; i++) {
      cin >> arr[i];
   }
   s[i].setMarks(arr);
   s[i].setTotalMarks();
   s[i].setPercentage();
 }
 
 cout <<endl<<"(A)"<<endl;
 //finding total marks & percentage of all students
 for(int i = 0 ; i < n ; i++) {
   cout << "TOTAL MARKS OF STUDENT " << i+1 << " : " << s[i].getTotalMarks() << endl;
   cout << "PERCENTAGE OF STUDENT " << i+1 << " : " << s[i].getPercentage() <<"%"<< endl; 
   cout << endl; 
 }

 cout << endl << "(B)" << endl;

 //display student information of a given roll number
 int num;
 cout << "ENTER THE DESIRED ROLL NUMBER : ";
 cin >> num;
 for(int i = 0 ; i < n ; i++) {
  s[i].studentWithGivenRollNumber(num);
 }
 cout << endl << "(C)" << endl;

 //display details for all the students having percentage in a given range
  float lowerLimit , upperLimit;
  cout << "ENTER LOWER RANGE & UPPER RANGE RESPECTIVELY : " << endl;
  cin >> lowerLimit >> upperLimit;
  cout << endl << "STUDENTS HAVING PERCENTAGE IN THE RANGE OF " << lowerLimit << "% - " << upperLimit <<"% : "<<endl << endl;
  for(int i = 0 ; i < n ; i++) {
  s[i].studentInGivenRange(lowerLimit,upperLimit);
 }

 // sorting the student array in ascending order of marks

  sortStudentArray(s,n);

  cout << endl << "(D)" << endl;

  cout <<"AFTER SORTING THE UPDATED ORDER OF STUDENT IS : " << endl << endl;
  
  for(int i = 0 ; i < n ; i++) {
    cout << "NAME : " << s[i].getName() << endl;
    cout << "ROLL NUMBER : " << s[i].getRoll() << endl;
   	cout << "MARKS : ";
    s[i].printMarks();
    cout << endl;
    cout <<"TOTAL MARKS : " << s[i].getTotalMarks() << endl;
    cout <<"PERCENTAGE : " << s[i].getPercentage() << "%" << endl;
    cout << endl; 
  }
 
}