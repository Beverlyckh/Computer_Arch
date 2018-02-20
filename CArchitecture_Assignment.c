/*
 ============================================================================
 Name        : CArchitecture_Assignment.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct date{
	int day;
	int month;
	int year;

};

struct contact{
	char name[15];
	char lastname[15];
	char bdi[10]; //bdi = birthday information
};

void loadContacts(){
	//char** tokens;
	char filename[100];

	struct contact c;

	FILE *file = fopen("/Users/beverlyackah/Desktop/Bev's_Workspace_DataStructure2017/CArchitecture_Assignment/contacts.txt", "r");

	char line[256];

	while(fgets(line, sizeof(line), file)){

		printf("%s", line);

		char *token = strtok(line, " ");
		int tokenCount = 0;
		char *fName[15];
		char *lName[15];
		char *dob[15];
		while (token != NULL)
		{
			//printf("The token is %s\n", token);



			tokenCount ++;


			//printf("The number of count is %d"
			//		"\n", tokenCount);

			if(tokenCount == 1){
				strcpy(fName,token);

			} else if(tokenCount == 2){
				strcpy(lName,token);

			} else if (tokenCount == 3){
				strcpy(dob,token);
			}
			else{

			}

			token = strtok(NULL, " ");
		}

		printf("The token is first : %s  last : %s bDay: %s\n", fName,lName,dob);

		//struct at the end of my for loop

		struct contact contactObject(fName, lName, dob);


	}



	fclose(file);



}


int main(void) {
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	struct date date_info[100];
	struct date *dates= date_info;

	struct contact contact_info[100];
	struct contact *contacts=contact_info;

	loadContacts();
	return 0;
}
