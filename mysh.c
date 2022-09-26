/*
Patrick Burns
September 26, 2022
Class: CS 390
Assignment: Program 1
Program: My Shell
*/

#include "stdio.h"
#include "stdlib.h"

int main()
{
	int x = 0;
	char ps1[] = "$";
	char userInput[1024];
	char command[128];
	
	

	char str[80] = "This is - a - tokenizer - test";
	const char delim[2] = "-";
	char* token;

	token = strtok(str, delim);

	while (token != NULL)
	{
		printf(" %s\n", token);
		token = strtok(NULL, delim);
	}


	printf("\n\n\n");
	
	
	do
	{
		printf("%s ", ps1);
		fgets(userInput, 1024, stdin);
		//printf("%s\n", userInput);
		
		//either tokenize first, 

		if (strncmp(userInput, "echo ", 5) == 0)
		{
			printf("command echo entered\n");
		}
		else if (strncmp(userInput, "ps1 ", 4) == 0)
		{
			printf("command ps1 entered\n");
		}
		else if (strncmp(userInput, "cat ", 4) == 0)
		{
			printf("command cat entered\n");
		}
		else if (strncmp(userInput, "cp ", 3) == 0)
		{
			printf("command cp entered\n");
		}
		else if (strncmp(userInput, "rm ", 3) == 0)
		{
			printf("command rm entered\n");
		}
		else if (strncmp(userInput, "mkdir ", 6) == 0)
		{
			printf("command mkdir entered\n");
		}
		else if (strncmp(userInput, "rmdir ", 6) == 0)
		{
			printf("command rmdir entered\n");
		}
		else if ((strncmp(userInput, "exit", 4) == 0) || strncmp(userInput, "exit ", 5) == 0)
		{
			break;
		}
		else
		{
			printf("Invalid command.\n");
			//USAGE MESSAGE
		}
		
	} while (1);

	return 0;
}