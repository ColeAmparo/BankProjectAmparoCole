/***************************************************************** 
//      
//
//      NAME:        Cole Amparo
//        
//      HOMEWORK:    project 2
//      
//      CLASS:       ICS 212
//     
//      INSTRUCTOR:  Ravi Narayan
//      
//      DATE:        December 1st, 2020
//      
//      FILE:        llist.h
//        
//      DESCRIPTION:
//      Contains the private and public methods of the class 
//      llist and also has function prototypes for the public
//      methods.
//
****************************************************************/

#include "record.h"

class llist
{
private:
    record *    start;
    char        filename[16];
    int         readfile();
    int         writefile();
    void        cleanup();

public:
    llist();
    llist(char[]);
    ~llist();
    int addRecord(int, char [ ],char [ ]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
};
