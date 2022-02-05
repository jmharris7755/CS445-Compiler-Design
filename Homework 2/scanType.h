//Justin Harris 
//CS445
//Last Updated: 1-29-22

//scantype.h
//This file contains the declaration
//of a struct or class that is used to pass
//token information back from the scanner
//Must be included in flex/bison files

//example declaration of the struct

#ifndef SCANTYPE_H
#define SCANTYPE_H

struct TokenData{
    int tokenclass; //token class
    int linenum; //line where found
    char *tokenStrInput; //what string was actually read
    char cvalue; //any character value
    int nvalue; // any numeric or boolean value
    char *svalue; //any string value e.g. an id
    char *tokenID;
    int strLength; // Length of a string
};

#endif