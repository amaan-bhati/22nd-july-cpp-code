#include <iostream>
using namespace std;

struct student
{
  char name[30];
  int roll;
  int marks[5];
  void getdata()
  {
    cout<<"Enter name : ";
    cin>>name;
    cout<<"Enter roll number : ";
    cin>>roll;
    cout<<"Enter marks in 5 subject : ";
    for(int i=0;i<5;i++)
      cin>>marks[i];
  }
  void dispdata()
  {
    cout<<"Name = "<<name<<endl;
    cout<<"Roll = "<<roll<<"\n";
    cout<<"Marks = ";
    for(int i=0;i<5;i++)
    cout<<marks[i]<<"\t";
  }
};
int main()
{
  student s;// struct is not required to declare a structure variable
  s.getdata();
  cout<<"\n Student Information\n";
  s.dispdata();
  return 0;
}