#include "hash.h"

unsigned int hash(char *pName) {
  int nLength = strlen(pName);
  unsigned int nHashValue = 0;
  for (int i = 0; i < nLength; i++) {
    nHashValue += pName[i];
    nHashValue *= pName[i];
    nHashValue += i * i;
    nHashValue %= 10;
  }
  return nHashValue;
}

void initHashTable(Person *pTable[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    pTable[i] = NULL;
  }
}

void printHashTable(Person *pTable[]) {
  printf("#start\n");
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (pTable[i] == NULL) {
      printf("  %i  ---\n", i);
    } else {
      printf("  %i", i);
      for (Person *pPerson = pTable[i]; pPerson != NULL; pPerson = pPerson->next) {
        printf(" ~ %s", pPerson->pName);
      }
      printf("\n"); 
    }
  }
  printf("#end\n");
}

bool insertToTable(Person *pPerson, Person * pTable[]) {
  if (pPerson == NULL)
    return false;

  int index = hash(pPerson->pName);
  
  if (pTable[index] == NULL) {
    pTable[index] = pPerson;
    return true;
  } else {
    Person *lastPerson;
    for (lastPerson = pTable[index]; lastPerson->next != NULL; lastPerson = lastPerson->next);
    lastPerson->next = pPerson;
    return true;    
  }
}

Person *removeFromTable(char *pName, Person *pTable[]) {
  if (pName == NULL || pTable == NULL)
    return NULL;
  unsigned int index = hash(pName);
  Person *prevPerson;
  Person *wantedPerson;
  for (
    wantedPerson = pTable[index], prevPerson = NULL;
    wantedPerson != NULL && strcmp(wantedPerson->pName, pName) != 0;
    prevPerson = wantedPerson, wantedPerson = wantedPerson->next);
  
  if (wantedPerson == NULL)
    return NULL;
  if (prevPerson == NULL)
    pTable[index] = wantedPerson->next;
  else
    prevPerson->next = wantedPerson->next;
  
  return wantedPerson;
}

Person *findInTable(char *pName, Person *pTable[]) {
  if (pName == NULL || pTable == NULL)
    return NULL;
  unsigned int index = hash(pName);
  Person *wantedPerson;
  for (
    wantedPerson = pTable[index];
    wantedPerson != NULL && strcmp(wantedPerson->pName, pName) != 0;
    wantedPerson = wantedPerson->next);
  return wantedPerson;
}