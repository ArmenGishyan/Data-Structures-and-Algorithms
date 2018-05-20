#include <iostream>
#include <list> 
#include <string>
#include <vector>
#include <iterator>
#include "queue.h"
#include <map>

using namespace std;
typedef pair<int,string> command_type;
typedef map<int,string>::iterator it_type;


int main()
{
  map<int,string> commands;
  commands.insert(command_type(1,"quit"));
  commands.insert(command_type(2,"enqueue"));
  commands.insert(command_type(3,"frontvalue"));
  commands.insert(command_type(4,"dequeue"));
  commands.insert(command_type(5,"length"));
  commands.insert(command_type(6,"clear"));
  commands.insert(command_type(7,"isfull"));

  int queueSize;
  cout<<"Please enter queue size: ";
  cin>>queueSize;
  Queue<int> q_array(queueSize);
  cout<<"----------------------------"<<"MENU"<<"----------------------------------\n";


  it_type i_toCommands=commands.begin();
  while(i_toCommands!=commands.end())
  {
    cout<<i_toCommands->first<<": "<<i_toCommands->second<<":\n";
    i_toCommands++;
  }
  
  
  int userInputCommand;
  while(cin>>userInputCommand)
  {
    bool flag=false;
    switch(userInputCommand)
    {
      case 1:
              {
                flag=true;
                break;
              }
      case 2:
              {
                int insertValue;
                cout<<"Please enter insertable value: \n";
                cin>>insertValue;
                q_array.enqueue(insertValue);
                break;
              }
      case 3:
              {
                cout<<"Front value is :"<<q_array.frontValue()<<"\n";
                break;
              }
      case 4:
              {
                q_array.dequeue();
                cout<<"First element was successfully delated: \n";
                break;
              }
      case 5:
              {
                cout<<"Length is :"<<q_array.length()<<"\n";
                break;
              }
      case 6:
              {
                cout<<"Array was successfully cleared: \n";
                q_array.clear();
                break;
              }
      case 7:
              {
                if(q_array.isFull())
                {
                  cout<<"Array is full: \n";
                }
                else
                {
                  cout<<"Array  isn't full: \n";
                }
                break;
              }
      default:
              {
                cout<<"Invalid input: \n";
                break;
              }
    }
    cout<<"Waiting for command _ "<<endl;
    if(flag) break;
   
  }
  
       


          


            


          



  return 0;
}

