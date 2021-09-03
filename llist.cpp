/*****************************************************************
// 
//    NAME:        Cole Amparo
//
//    HOMEWORK:    project2
//
//    CLASS:       ICS 212
//
//    INSTRUCTOR:  Ravi Narayan
//
//    DATE:  December 1st, 2020
//
//    FILE:  llist.cpp
//
//    Description:
//     The database functions, that you can use to print, add, find
//     or delete records in the database. readfile and writefile are
//     used to keep track of the records in the database, even after 
//     the space is released (by the function cleanup).
//
//
//
****************************************************************/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>

#include "record.h"
#include "llist.h"

using namespace std;


/*****************************************************************                     
//
//         Function name: llist
//                   
//           
//         DESCRIPTION:   Constructor called when a new linked list is 
//                        created. Makes start equal to NULL and reads  
//                        from the file "database.txt" to the linked list.            
//                                          
//                         
//         Parameters:    llist::llist() : N/A
//                        
//                     
//                                                     
//                         
//         Return values: N/A
//                                          
//                        
****************************************************************/

llist::llist()
{
    #ifdef DEBUG
        start = NULL;

    #else
        strcpy(filename, "database.txt");
        start = NULL;
        if (readfile() == -1)
        {
            cout << "\nDatabase is empty.\n" << endl;
        }

    #endif
}

/*****************************************************************                     
//        
//
//        Function name: llist
//                            
//                    
//        DESCRIPTION:   Constructor called when a new linked list is 
//                       created. Makes start equal to NULL and reads  
//                       from the given textfile to the linked list.            
//                                                   
//                                  
//        Parameters:    llist::llist(char[]): The textfile that 
//                                 is read from to the linked list.
//                              
//                                                              
//                                  
//        Return values: N/A
//                                                   
//                                 
****************************************************************/

llist::llist(char inputfile[])
{

    #ifdef DEBUG
        start = NULL;

    #else
        strcpy(filename, inputfile);
        start = NULL;
        readfile();

    #endif

}

/*****************************************************************                     
// 
//         Function name: ~llist
//                            
//                  
//         DESCRIPTION:   Destructor called when a linked list is 
//                        deleted. Writes the linked list to the textfile,
//                        then deallocates the space for the
//                        records in the linked list.
//                                   
//                                                   
//                                  
//         Parameters:    llist::~llist() : N/A
//                                 
//                                                                                            
//                                  
//         Return values: N/A
//                                                   
//                                
****************************************************************/



llist::~llist()
{
    #ifdef DEBUG
        cleanup();

    #else
        writefile();
        cleanup();

    #endif
}




/*****************************************************************
//  
//    Function name: addRecord
//  
//    DESCRIPTION:   Adds a new record to the database, if there are records
//                   already in the database, orders the records by size of   
//                   account number (bigger -> smaller), 
//                   
//  
//    Parameters:    int llist::addRecord (int, char[], char[]) :
//                             account number, name and
//                             address of a new record.
//                              
//  
//    Return values: 0: record was successfully added to linked list.   
//                   
//  
****************************************************************/

int llist::addRecord (int accNo, char name[], char address[])
{

    #ifdef DEBUG

        cout << "\n*** THIS IS IN DEBUG MODE ***\n" << endl;
        cout << "*** The function addRecord when called will add a new record with the ***" << endl;
        cout << "*** parameters: account number, name, address, and pointer of *struct record ***" << endl;
        cout << "*** This is the inputed information to create the record with***" << endl;
        cout << "*** Account Number: " << accNo << " ***" << endl;
        cout << "*** Name: " << name << "***" << endl;
        cout << "*** Address: " << address << "***" << endl;

    #else 
 
        int exit;
        int listAcc;
        int newAcc;
        int startAcc;

        struct record * listAdd;
        struct record * listPrev;
        struct record * newAdd;

        listAdd = NULL;
        listPrev = NULL;
        newAdd = NULL;
      
        newAdd = new struct record;
       
 
        (*newAdd).accountno = accNo;
        strcpy((*newAdd).name, name);
        strcpy((*newAdd).address, address);
        (*newAdd).next = NULL;

        listAdd = start;
        
        exit = 0;     

        if (start != NULL)
        {
            startAcc = (*start).accountno;
        }

        newAcc = (*newAdd).accountno;

        while (exit == 0)
        {
            if (start != NULL)
            {
                listAcc = (*listAdd).accountno;
            }
 
            if (start == NULL)
            {
                start = newAdd;
                exit++;
            }
            else 
            {
                if (newAcc >= startAcc)
                {
                    (*newAdd).next = start;
                    start = newAdd;
                    exit++;
                }
                else
                {
                    if (newAcc >= listAcc)
                    {
                        (*newAdd).next = listAdd;
                        (*listPrev).next = newAdd;
                        exit++;
                    }
                    else
                    {
                        if ((*listAdd).next == NULL)
                        {
                            (*listAdd).next = newAdd;
                            exit++;
                        }
                        else
                        {
                            listPrev = listAdd;
                            listAdd = (*listAdd).next;
                        }

                    }
                }

            }   
      
        }

    #endif

    return 0;
}


/*****************************************************************  
//        
//        Function name: printAllRecords
//      
//        DESCRIPTION:   Prints all the records in the database  
//                       
//                       
//      
//        Parameters:    void llist::printAllRecords () : N/A
//                                 
//                                  
//      
//        Return values: N/A
//                       
//      
****************************************************************/

void llist::printAllRecords()
{
    
    #ifdef DEBUG
    
        cout << "\n*** THIS IS IN DEBUG MODE ***\n" << endl;
        cout << "*** When called printAllRecords prints all records in database ***" << endl;
        cout << "*** Parameters: pointer to start of linked list of records ***" << endl;
    
    
    #else
 

        struct record * temp;
        temp = NULL;
   
        temp = start;
        
        if (start == NULL)
        {
            cout << "\nDatabase is empty." << endl;
        }
        else
        {     
            cout << "\n\nALL RECORDS IN DATABASE\n" << endl;

            while (temp != NULL)
            {
                cout <<"\nAccount Number: " << (*temp).accountno << endl;
                cout <<"Name: " << (*temp).name << endl;
                cout <<"Address: \n" << (*temp).address << endl;

                temp = (*temp).next;
            }       
        }    
    
    #endif  
}



/*****************************************************************  
//    
//        Function name: findRecord
//      
//        DESCRIPTION:  Finds the record(s) with the given accountnumber 
//                       
//                       
//      
//        Parameters:    int llist::findRecord (int) :
//                                  the account number.
//                               
//                                   
//        Return values:  -1: if record(s) was not found in database
//                         0: if record(s) was found in database
//                      
//      
****************************************************************/

int llist::findRecord (int uaccountno)
{
    int returnVal;

    returnVal = -1;

    #ifdef DEBUG
    
        cout << "\n*** THIS IS DEBUG MODE *** " << endl;
        cout << "*** findRecords was called, which looks for a record with the inputed Account Number***" << endl;
        cout << "*** The parameters are: the Account Number, and the pointer of the inputed record***" << endl;
        cout << "*** Account Number: " << uaccountno << "***" << endl;
        

    #else

        int accNo;

        struct record * temp = NULL; 

   
        if (start == NULL)
        {
            cout << "\nDatabase is empty." << endl;
            returnVal = 0;
        }
        else
        {
            temp = start;
            
            while(temp != NULL)
            {
                accNo = (*temp).accountno;
  
                if (accNo == uaccountno)
                {
                    cout << "Record(s) in the database with account number " << uaccountno << ":" << endl;
                    cout << "\nAccount Number: " << (*temp).accountno << endl;
                    cout << "Name: " << (*temp).name << endl;
                    cout << "Address: \n" << (*temp).address << endl;                               

                    returnVal = 0;
                }

                temp = (*temp).next;

            }
                        

        } 

    #endif

    return returnVal;
  
}




/*****************************************************************  
//    
//        Function name: deleteRecord
//      
//        DESCRIPTION:   Deletes record(s) with the given account  
//                      number
//                       
//      
//        Parameters:    int llist::deleteRecord (int) :
//                                 the account number.
//                                  
//      
//        Return values: Returns -1 if nothing was deleted
//                       
//      
****************************************************************/

int llist::deleteRecord (int uaccountno)
{
    int returnVal;
    
    returnVal = -1;

    #ifdef DEBUG
   
        cout << "\n*** THIS IS DEBUG MODE ***" << endl;
        cout << "*** deleteRecords was called, deletes the record with the inputed Account Number ***" << endl;
        cout << "*** the parameters are the Account Number, and the record ***" << endl;
        cout << "*** Account Number: " << uaccountno << "***" << endl;
      
    
    #else 

        int startNo;
        int accNo;

        struct record * current = NULL;
        struct record * prev = NULL;
        struct record * temp = NULL;    
        
        if (start == NULL)
        {
            cout << "\nDatabase is Empty" << endl;
            returnVal = 0;
        }
        else
        {
            current = start;
       
            while(current != NULL && start != NULL)
            {
                startNo = (*start).accountno;
                accNo = (*current).accountno;

                if (startNo == uaccountno)
                {
                    temp = start;
                    start = (*start).next;  

                    cout << "\nThe following data has been deleted:" << endl;
                    cout << "\nAccount Number: " << (*temp).accountno << endl;
                    cout << "Name: " << (*temp).name << endl;
                    cout << "Address: \n" << (*temp).address << endl;

                    delete temp;

                    current = start;
                    returnVal = 0;

                }
                else
                {
                    if (accNo == uaccountno)
                    {
                        temp = (*current).next;
                        (*prev).next = temp;

                        cout << "\nThe following data has been deleted:" << endl;
                        cout << "\nAccount Number: " << (*current).accountno << endl;
                        cout << "Name: " << (*current).name << endl;
                        cout << "Address: \n" << (*current).address << endl;

                        delete current;
 
                        current = prev;
                        returnVal = 0;

                    }
                    else
                    {
                        prev = current;
                        current = (*current).next;
                    }

                }

            }   
        }

    #endif

    return returnVal;
  
}


/*****************************************************************     
//       
//           Function name: readfile
//        
//
//           DESCRIPTION:   Puts the information from the textfile  
//                          into the linked list.
//                               
//              
//           Parameters:    int llist::readfile () : N/A
//                                          
//              
//           Return values: Returns -1 if textfile is unable to be read
//                               
//              
****************************************************************/

int llist::readfile()
{
    int i;
    int accNo;
    char name[25];
    char address[80]; 
    char trash;
    int returnVal = 0;

    ifstream infile;
    
    infile.open(filename);

    if (infile.is_open())
    { 
 

        while(infile >> accNo)
        {   
     
            

            infile.get(trash);            

            infile.getline(name, 25);
            
                      
            for (i = 0; i < 80; i++)
            {
               
                infile.get(address[i]);
               
                if (address[i] == '*')
                {
                    
                    address[i - 1] = '\0';
                    i = 80;

                }

              
            }        

            llist::addRecord(accNo, name, address);
            
                   
        }
        
            infile.close();
       
    }
    else
    {
        returnVal = -1;
    }

    return returnVal;
}




/*****************************************************************     
// 
//          Function name: writefile
//                   
//           
//          DESCRIPTION:   writes the information from the linked list  
//                         onto the textfile
//                                          
//                       
//          Parameters:    int llist::writefile () : N/A
//                                                    
//                         
//           Return values: Returns -1 if textfile is unable to be written to
//                                          
//                         
****************************************************************/

int llist::writefile()
{
    int returnVal = 0;
    struct record * temp = NULL;

    ofstream outfile;

    outfile.open(filename);
 
    temp = start;

    if (outfile.is_open()) 
    {
        while(temp != NULL)
        {
            outfile << (*temp).accountno << endl;
            outfile << (*temp).name << endl;
            outfile << (*temp).address << endl;
            outfile << "*" << endl;             

            temp = (*temp).next;
            
        }

        outfile.close();
    }
    else
    {
        cout << "\nUnable to open file" << endl;
    }

    return returnVal;

}



/*****************************************************************            
//         
//
//         Function name: cleanup
//                   
//           
//         DESCRIPTION:   Deallocates the space of all records in the 
//                        linked list 
//                                     
//                                          
//                         
//         Parameters:    void llist::cleanup(): N/A                     
//                                                     
//                         
//         Return values: N/A
//                                          
//                        
****************************************************************/

void llist::cleanup()
{
    struct record * temp = NULL;

    while(start != NULL)
    {
        temp = start;
       
        start = (*start).next;

        delete temp;
       
    }


}
 
