#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

Person *pHashTable[TABLE_SIZE];

int main(int argc, char * argv[])
{
	initHashTable(pHashTable);
	
	Person rza = {"Rza", 19, NULL};
	Person cebi = {"Cebi", 31, NULL};
	Person nici = {"Nici", 20, NULL};
	Person mika = {"Mika", 69, NULL};
	Person tima = {"Tima", 20, NULL};
	Person qisi = {"Qisi", 20, NULL};
	Person arif = {"Arif", 20, NULL};
	Person murad = {"Murad", 20, NULL};



	insertToTable(&rza, pHashTable);
	insertToTable(&cebi, pHashTable);
	insertToTable(&nici, pHashTable);
	insertToTable(&mika, pHashTable);
	insertToTable(&tima, pHashTable);
	insertToTable(&qisi, pHashTable);
	insertToTable(&arif, pHashTable);
	insertToTable(&murad, pHashTable);


	printf("\n");

	// Person *removedPerson = removeFromTable("Cebi", pHashTable);
	// 	printf("Removed:\n  Name: %s, Age: %d\n", removedPerson ? removedPerson->pName : "NULL", removedPerson ? removedPerson->nAge : -1);
	// Person *wantedPerson = findInTable("Rza", pHashTable);
	// printf("Found:\n  Name: %s, Age: %d\n", wantedPerson ? wantedPerson->pName : "NULL", wantedPerson ? wantedPerson->nAge : -1);

	printHashTable(pHashTable);

	return 0;
}