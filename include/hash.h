#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct _Person{
  char *pName;
  int nAge;
  struct _Person * next;
} Person;

unsigned int hash(char *pName);

void initHashTable(Person *pTable[]);
void printHashTable(Person *pTable[]);
bool insertToTable(Person *pPerson, Person *pTable[]);
Person *removeFromTable(char *pName, Person *pTable[]);
Person *findInTable(char *pName, Person *pTable[]);

#endif // __HASH_H__