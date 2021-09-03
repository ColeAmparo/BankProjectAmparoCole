/***************************************************************** 
//   
//        NAME:        Cole Amparo
//    
//        HOMEWORK:    project 2
//    
//        CLASS:       ICS 212
//    
//        INSTRUCTOR:  Ravi Narayan
//    
//        DATE:  December 1st, 2020
//    
//        FILE:  user_interface.cpp
//    
//        Description:
//         Asks the user to pick a menu option, then
//         prompts them for info such as their Account Number
//         Name, and Address, and sends that info to the database
//         to complete the menu option the user picked.
//    
****************************************************************/

#include <string.h>
#include <iostream>
#include <iomanip>
#include <string>

#include "llist.h"
#include "record.h"

using namespace std;

void find(llist &);
void printall(llist &);
void getaddress(char[], int);


/*****************************************************************
//
//
//
//      Function name: main
//      
//  
//      DESCRIPTION:   Asks the user which one of the following options
//                     in the menu they want to use, and then leads
//                     them to the correct place.
//                   
//  
//      Parameters:    int main(int, char*[]) : command line arguements 
//                               
//  
//      Return values:  0 : Main needs a return value
//                     
//
//
//
****************************************************************/

int main(int argc, char *argv[])
{
   
    int quitCounter;

    string option;
    string trash;

    char optionArr[50]; 
 
    const char* addCheck;
    const char* AddCheck;
    const char* printCheck;
    const char* PrintCheck;
    const char* findCheck;
    const char* FindCheck;
    const char* deleteCheck;
    const char* DeleteCheck;
    const char* quitCheck;  
    const char* QuitCheck;  

    
    llist mylist; 

    quitCounter = 0;
 
 
    if(argc == 1)
    {

        cout << "\nPick one of the following options to add, print, find or delete bank Records." << endl;    

        while (quitCounter == 0)
        {
            cout << "\n\nTo pick an option, please type the option name.\n" << endl;
            cout << "Add: Add a new record in the database" << endl;
            cout << "Print: Print all records in the database" << endl;
            cout << "Find: Find record(s) with a specified account number" << endl;
            cout << "Delete: Delete existing records(s) from the database using the account number as a key" << endl;
            cout << "Quit: Quit the program\n" << endl;

            cout << "Enter the name of an option:" << endl;

            getline(cin, option);       
    
            strcpy(optionArr, option.c_str());     
  
           
            addCheck = strstr("add", optionArr);
            AddCheck = strstr("Add", optionArr);
            printCheck = strstr("print", optionArr);
            PrintCheck = strstr("Print", optionArr);
            findCheck = strstr( "find", optionArr);
            FindCheck = strstr( "Find", optionArr);
            deleteCheck = strstr("delete", optionArr);
            DeleteCheck = strstr("Delete", optionArr);
            quitCheck = strstr("quit", optionArr);
            QuitCheck = strstr("Quit", optionArr);


            if (addCheck || AddCheck)
            {
                 int accountno;
                 char name[25];
                 char address[80];
                    

                 cout << "To add a new record, please enter the account number:" << endl;
                 cin >> accountno;
                 getline(cin, trash);
    
                 while(accountno < 0)
                 {   
                     cout << "\nERROR: Access code can't be negative, please enter an acceptable code." << endl;
                     cin >> accountno;
                     getline(cin, trash);
                 }

    
                 cout << "\nNext please enter your Given name and last name:" << endl;
                 cin.getline(name, 25);
                 
    
                 cout << "\nLast, please enter your address, and type * then press enter to confirm" << endl;
                 cout << "WARNING: Please make sure address is less than 80 charecters" << endl;
                 cout << "if address is over 80, charecters over the limit will be left off the record" << endl;
    
                 getaddress(address, 80);
    
                 mylist.addRecord(accountno, name, address);
                 
                 #ifndef DEBUG

                 cout << "\n\nConfirming information added to database:\n" << endl;
                 cout << "Account Number: " << accountno << endl;
                 cout << "Name: " << name << endl;
                 cout << "Address: \n" << address << endl;

                 #endif
            }
            else
            {
                if (printCheck || PrintCheck)
                {
                    printall(mylist);
                }
                else
                {
                    if (findCheck || FindCheck)
                    {  
                        find(mylist);
                    }
                    else
                    {
                        if (deleteCheck || DeleteCheck)
                        {          
                            int accountNo;
                    
                            #ifndef DEBUG
                            int returnVal;
                            #endif

                            cout << "To delete your records please enter your account number:" << endl;

                            cin >> accountNo;
                            getline(cin, trash);

                            while(accountNo < 0)
                            {
                                cout << "\nERROR: Access code can't be negative, please enter an accetable code." << endl;
                                cin >> accountNo;
                                getline(cin, trash);
                            }
                           
                            #ifdef DEBUG 

                            mylist.deleteRecord(accountNo);

                            #else


                            returnVal = mylist.deleteRecord(accountNo);     

                            if (returnVal == -1)
                            {
                                cout << "\nA record with that account number does not exist in the database." << endl;
                            }

                            #endif

                        }
                        else 
                        {
                            if (quitCheck || QuitCheck)
                            {   
                                 quitCounter++;
                                   
                            }
                            else
                            {
                                cout << "ERROR: Enter one of the menu options" << endl;
                            }
                        }
                    }       
                }
            }     
        }
    }
    else
    {
        cout << "ERROR NOT IN DEBUG MODE" << endl;
    }

    return 0;

}


/*******************************************************************            
//
//            Function name: printall
//        
//            DESCRIPTION: Tell the database to print all the records  
//                         it contains.
//                         
//        
//            Parameters: void printall (llist &) : an instance of a 
//                                                  linked list.
//        
//            Return values:  N/A
//           
//           
//        
***************************************************************/


void printall(llist & mylist)
{
    #ifndef DEBUG 

    cout << "\nThese are all the records current in the database:" << endl;
   
    #endif

    mylist.printAllRecords();
}



/******************************************************************
//      
//           Function name: find
//   
//           DESCRIPTION: Asks the user for their Account Number,
//                        then sends it to the database
//                        to find a record(s).
//                      
//      
//           Parameters:  void find (struct record*) : an instance of a 
//                                                    linked list. 
//                                                  
//       
//           Return values:  N/A
//                        
//    
//
//
**************************************************************/


void find(llist & mylist)
{
    int accountNo;

    #ifndef DEBUG
    int returnVal;
    #endif

    string trash;
    
    cout <<"\nTo find a record, please enter your account number:" << endl;

    cin >> accountNo;
    getline(cin, trash);

    while(accountNo < 0)
    {
        cout << "\nERROR: Access code can't be negative, please enter an accetable code." << endl;
        cin >> accountNo;
        getline(cin, trash);
    }

    #ifdef DEBUG

    mylist.findRecord(accountNo);

    #else

    returnVal = mylist.findRecord(accountNo);

    if (returnVal == -1)
    {
        cout << "\nA record(s) with the given account number is not in the database." << endl;
    }

    #endif
   
}


/*****************************************************************             
//
//            Function name: getaddress
//        
//            DESCRIPTION: Creates an input function that doesn't
//                         end on newline charecters, and instead   
//                         lands on a chosen delimiter. Then inputs
//                         the charecters into the given array
//        
//
//            Parameters:    void getaddress(char[], int) : char[] is the given array
//                                      and int is the size of the array
//                                                  .
//        
//            Return values:  N/A
//           
//           
//        
***************************************************************/


void getaddress(char inputArr[], int MAX)
{
    int i;
  
    string trash;

    for (i = 0; i < MAX; i++)
    {
        cin.get(inputArr[i]);        

        if (inputArr[i] == '*')
        {
            inputArr[i - 1] = '\0';
            i = MAX; 
            
        }
    }

    getline(cin, trash);
}
