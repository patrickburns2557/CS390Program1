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
void command_echo(char userInput[1024]);
void command_ps1(char userInput[1024]);
void command_cat(char userInput[1024]);
void command_cp(char userInput[1024]);
void command_rm(char userInput[1024]);
void command_mkdir(char userInput[1024]);
void command_rmdir(char userInput[1024]);

/* Global Variable */
char ps1[1024] = "$";


int main()
{
	int x = 0;
	char userInput[1024];
	char command[128];
	
	printf("\n");


	do
	{
		printf("%s ", ps1);
		fgets(userInput, 1024, stdin);
		


		if (strncmp(userInput, "echo ", 5) == 0)
		{
			command_echo(userInput);
		}
		else if ((strncmp(userInput, "ps1 ", 4) == 0) || (strncmp(userInput, "PS1 ", 4) == 0))
		{
			command_ps1(userInput);
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

/* Function handles the echo command */
void command_echo(char userInput[1024])
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

/* Function handles the PS1 command */
void command_ps1(char userInput[1024])
{
	char* token; /* used during tokenization */
	char tokens[128][256];
	char newPs1[1024] = "";
	int numTokens = 0;
	int i = 0;  /* declared here since using -ansi disallows var declarations inside for loops */

	token = strtok(userInput, " ");
	while(token != NULL)
	{
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

	/* concatenate each token to the newPs1 string */
	for(i = 1; i<numTokens;i++)
	{
		strcat(newPs1, tokens[i]);
		if(i < numTokens-1) /* don't add a space after the last string */
		{
			strcat(newPs1, " ");
		}
	}

	/* set the new PS1 variable */
	strcpy(ps1, newPs1);

}

/* Function handles the cat command */
void command_cat(char userInput[1024])
{
	char* token;
	char tokens[128][256];
	int numTokens;
	int i = 0;

	token = strtok(userInput, " ");
	while(token != NULL)
	{
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
}

/* Function handles the cp command */
void command_cp(char userInput[1024])
{
	char* token;
	char tokens[128][256];
	int numTokens;
	int i = 0;

	token = strtok(userInput, " ");
	while(token != NULL)
	{
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
}

/* Function handles the rm command */
void command_rm(char userInput[1024])
{
	char* token;
	char tokens[128][256];
	int numTokens;
	int i = 0;

	token = strtok(userInput, " ");
	while(token != NULL)
	{
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
}

/* Function handles the mkdir command */
void command_mkdir(char userInput[1024])
{
	char* token;
	char tokens[128][256];
	int numTokens;
	int i = 0;

	token = strtok(userInput, " ");
	while(token != NULL)
	{
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
}

/* Function handles the rmdir command */
void command_rmdir(char userInput[1024])
{
	char* token;
	char tokens[128][256];
	int numTokens;
	int i = 0;

	token = strtok(userInput, " ");
	while(token != NULL)
	{
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
}