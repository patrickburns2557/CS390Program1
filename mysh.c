/*
Patrick Burns
September 26, 2022
Class: CS 390
Assignment: Program 1
Program: My Shell
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

/* Function Prototypes */
void echo(char userInput[1024]);
void ps1(char userInput[1024]);
void cat(char userInput[1024]);
void cp(char userInput[1024]);
void rm(char userInput[1024]);
void mkdir(char userInput[1024]);
void rmdir(char userInput[1024]);

int main()
{
	int x = 0;
	char ps1[] = "$";
	char userInput[1024];
	char command[128];
	
	printf("\n");


	do
	{
		printf("%s ", ps1);
		fgets(userInput, 1024, stdin);
		/*printf("%s\n", userInput);*/


		if (strncmp(userInput, "echo ", 5) == 0)
		{
			echo(userInput);
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
			/*USAGE MESSAGE*/
		}

	} while (1);

	return 0;
}


void echo(char userInput[1024])
{
	bool nArg = false; /* used to determine whether to apply -n */
	char* token; /* used during tokenization */
	int numTokens = 0;
	int i = 0; /* declared here since using -ansi disallows var declarations inside for loops */
	char tokens[128][256];
			
	/* tokenizes and stores input into tokens array */
	token = strtok(userInput, " ");
	while(token != NULL)
	{
		if((strcmp(token, "-n") == 0) && (numTokens == 1)) /* Checks if -n found immediately after "echo" in the command*/
		{
			nArg = true;
		}
		strcpy(tokens[numTokens++], token);
		token = strtok(NULL," ");
	}
	
	/* Replace the newline character in the last token with a 0 */
	for(i = 0;;i++)
	{
		if(tokens[numTokens-1][i] == '\n')
		{
			tokens[numTokens-1][i] = 0;
			break;
		}
	}

	/* Print out the message. If -n was found, skip printing it */
	if(nArg)
	{
		for(i = 2; i < numTokens; i++)
		{
			printf("%s ", tokens[i]);
		}
	}
	else
	{
		for(i = 1; i < numTokens; i++)
		{
			printf("%s ", tokens[i]);
		}
	}
	
	if(!nArg)
	{
		printf("\n");
	}	
}

void ps1(char userInput[1024])
{

}

void cat(char userInput[1024])
{

}

void cp(char userInput[1024])
{

}

void rm(char userInput[1024])
{

}

void mkdir(char userInput[1024])
{

}

void rmdir(char userInput[1024])
{

}