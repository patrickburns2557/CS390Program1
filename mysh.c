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
#include "sys/stat.h"
#define MAX_TOKENS 32
#define MAX_TOKEN_LENGTH 256

/* Function Prototypes */
void command_echo(char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int numTokens);
void command_ps1(char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int numTokens);
void command_cat(char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int numTokens);
void command_cp(char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int numTokens);
void command_rm(char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int numTokens);
void command_mkdir(char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int numTokens);
void command_rmdir(char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int numTokens);



/* Global Variable */
char ps1[1024] = "$";


int main()
{
	char userInput[1024];
	char* token;
	char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
	int numTokens = 0;
	int i = 0;

	
	printf("\n");


	do
	{
		/* reset tokens back to zero for next input */
		numTokens = 0;
		
		/* print out the ps1 variable and get user input */
		printf("%s ", ps1);
		fgets(userInput, 1024, stdin);


		/* tokenize and store input into tokens array */
		token = strtok(userInput, " ");
		while(token != NULL)
		{
			strcpy(tokens[numTokens++], token);
			token = strtok(NULL, " ");
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


		if (strcmp(tokens[0], "echo") == 0)
		{
			command_echo(tokens, numTokens);
		}
		else if ((strcmp(tokens[0], "ps1") == 0) || (strcmp(tokens[0], "PS1") == 0)) /* allow user to use "ps1" or "PS1" */
		{
			command_ps1(tokens, numTokens);
		}
		else if (strcmp(tokens[0], "cat") == 0)
		{
			command_cat(tokens, numTokens);
		}
		else if (strcmp(tokens[0], "cp") == 0)
		{
			command_cp(tokens, numTokens);
		}
		else if (strcmp(tokens[0], "rm") == 0)
		{
			command_rm(tokens, numTokens);
		}
		else if (strcmp(tokens[0], "mkdir") == 0)
		{
			command_mkdir(tokens, numTokens);
		}
		else if (strcmp(tokens[0], "rmdir") == 0)
		{
			command_rmdir(tokens, numTokens);
		}
		else if (strcmp(tokens[0], "exit") == 0)
		{
			break;
		}
		else
		{
			printf("Invalid command.\n");
			printf("Valid commands: echo, PS1, cat, cp, rm, mkdir, rmdir, exit\n");
		}

	} while (1);

	return 0;
}

/* Function handles the echo command */
void command_echo(char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int numTokens)
{
	bool nArg = false; /* used to determine whether to apply -n */
	int i = 0; /* declared here since using -ansi disallows var declarations inside for loops */
	
	/* test for -n flag right after the "echo" token */
	if(strcmp(tokens[1], "-n") == 0)
	{
		nArg = true;
	}

	/* Print out the message. If "-n" was found as the token immediately after "echo", skip printing it in the output */
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
	
	/* only print a new line if the -n flag wasn't found */
	if(!nArg)
	{
		printf("\n");
	}	
}

/* Function handles the PS1 command */
void command_ps1(char tokens[128][256], int numTokens)
{
	char newPs1[1024] = "";
	
	int i = 0;  /* declared here since using -ansi disallows var declarations inside for loops */

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
void command_cat(char tokens[128][256], int numTokens)
{
	FILE *inputFile;
	int i = 0;
	char c = '0';

	/* Open file. If file not found, exit function */
	if ((inputFile = fopen(tokens[1], "r")) == NULL)
	{
		printf("File '%s' not found\n", tokens[1]);
		return;
	}

	/* iterate through entire file and print out its contents character by character */
	c = fgetc(inputFile);
	while(!feof(inputFile))
	{
		printf("%c", c);
		c = fgetc(inputFile);
	}


	fclose(inputFile);
}

/* Function handles the cp command */
void command_cp(char tokens[128][256], int numTokens)
{
	FILE *source;
	FILE *destination;
	char c;

	/* open source file. Exit function if failed */
	source = fopen(tokens[1], "rb");
	if(source == NULL)
	{
		printf("Failed to open source file '%s'\n", tokens[1]);
		return;
	}

	/* open destination file. Close source file and exit function if failed */
	destination = fopen(tokens[2], "wb");
	if(destination == NULL)
	{
		printf("Failed to open destination file '%s'\n", tokens[2]);
		fclose(source);
		return;
	}
	
	/* write to destination file character by character until the end of source is reached */
	c = fgetc(source);
	while(!feof(source))
	{
		fputc(c, destination);
		c = fgetc(source);
	}

	printf("Successfully copied '%s' to '%s'\n", tokens[1], tokens[2]);

	fclose(source);
	fclose(destination);
}

/* Function handles the rm command */
void command_rm(char tokens[128][256], int numTokens)
{
	/* remove file and print results of operation */
	if(remove(tokens[1]) == 0)
	{
		printf("Deleted '%s'\n", tokens[1]);
	}
	else
	{
		printf("Cannot remove '%s' : No such file or directory\n", tokens[1]);
	}
}

/* Function handles the mkdir command */
void command_mkdir(char tokens[128][256], int numTokens)
{
	/* uses stat call to see if the directory exists or not. If it doesn't, it creates the directory */
	struct stat st = {0};
	if (stat(tokens[1], &st) == -1)
	{
		mkdir(tokens[1], 0777);
		printf("Directory created\n");
	}
	else
	{
		printf("Cannot create directory. Directory already exists\n");
	}
	
}

/* Function handles the rmdir command */
void command_rmdir(char tokens[128][256], int numTokens)
{
	/* remove folder and print results of operation */
	if(remove(tokens[1]) == 0)
	{
		printf("Deleted '%s'\n", tokens[1]);
	}
	else
	{
		printf("Cannot remove '%s' : Either no such directory, or directory is not empty\n", tokens[1]);
	}
}