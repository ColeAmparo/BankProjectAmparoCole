/*****************************************************************
//     
//
//            NAME:        Cole Amparo
//        
//            HOMEWORK:    project2
//        
//            CLASS:       ICS 212
//       
//            INSTRUCTOR:  Ravi Narayan
//        
//            DATE:        December 1st, 2020
//        
//            FILE:        record.h
//        
//            DESCRIPTION:
//            A struct called records that holds 
//            an int, two char arrays, and a
//            pointer to a struct record.
//            
//      
//
****************************************************************/


#ifndef RECORD_H

struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
};

#define RECORD_H
#endif
