/*
 ============================================================================
 Name        : CArchitecture_Assignment.c
 Author      : Beverly ACKAH
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct date{
	char *day[2];
	char *month[2];
	int year;

};
struct contact{
	char name[15];
	char lastname[15];
	int bdi[10]; //bdi = birthday information
};
//global variable that can be accessed by main
struct contact c[6];

//load contact function to read all records of contacts.txt
void loadContacts(){
	char filename[100];
	struct contact *array;
	struct date *date1;

	FILE *file = fopen("/Users/beverlyackah/Desktop/Bev's_Workspace_DataStructure2017/CArchitecture_Assignment/contacts.txt", "r");

	char line[256];
	int count = 0;

	while(fgets(line, sizeof(line), file)){

		char *token = strtok(line, " ");
		int tokenCount = 0;
		char *fName[16];
		char *lName[16];
		int *dob[10];
		struct contact myContact;
		while (token != NULL)
		{
			tokenCount ++;
			if(tokenCount == 1){

				strcpy(myContact.name, token);
			} else if(tokenCount == 2){

				strcpy(myContact.lastname, token);

			} else if (tokenCount == 3){

				strcpy(myContact.bdi,token);
				break;
			}
			else{
			}
			token = strtok(NULL, " ");

		}

		c[count]=myContact;

		count++;
	}
	fclose(file);
}

int main(void) {
	struct date myDate;
	loadContacts();
	int i;
	for(i=0; i<6; i++){
		//to split the birthday information we got in token
		char *token1 = strtok(c[i].bdi, "-"); //returns first token (token = birtday info we get from for loop)
		int tokenCount = 0;
		int *bDay;
		int *bMonth;
		int *bYear;
		strcpy(myDate.day, token1);
		while (token1!= NULL) //while we split, we also store data in our struct
		{

			tokenCount++;

			if(tokenCount == 3){
				myDate.year = atoi(token1);
				int yearVar = myDate.year;
				int age = 2018 - yearVar;
				if( yearVar <= 2000 && yearVar>=1993){


					printf("%c.%s %d \n", c[i].name[0],  c[i].lastname,  age);

				}
			}
			token1=strtok(NULL,"-");
		}
	}
	return 0;
}
