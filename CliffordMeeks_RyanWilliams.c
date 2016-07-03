/*
 * Project 4 CIS 308
 *  Created on: Mar 21, 2016
 *  	Author: Ryan Williams(Monday 10:30)/Clifford Meeks(Monday 1:30)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>


typedef struct stoptree{
    	char *word;
	char langs[30][30];
	int index;
    	struct stoptree *leftchild;
    	struct stoptree *rightchild;
}STOP_T;

void SearchTree(struct stoptree *root, char *stopword)
{
	if(root == NULL)
	{
		printf("WORD NOT FOUND!\n");
    		return;
	}
	else{
		if(strcmp(stopword, root->word) == 0)
		{
			int count = root->index;
	    		int i;
			printf("Word: %s\n", root->word);
			for(i = 0; i<count; i++){
				printf("Languages: %s\n", root->langs[i]);
			}
		}
		else if(strcmp(stopword, root->word) < 0)
		{
	    		 SearchTree(root->leftchild, stopword);
		}
		else
		{
	    		 SearchTree(root->rightchild, stopword);
		}
	}
	return;
}	
void AddToTree(char *new, struct stoptree **root, char *lang)
{
	
	if(NULL == *root){
	    	 *root = (struct stoptree *)malloc(sizeof(struct stoptree));
		(*root)->word = strdup(new);
		lang = strtok(lang, ".");
		memset((*root)->langs,0, sizeof((*root)->langs));
		strcpy((*root)->langs[0], lang);
		(*root)->index = 1;
		(*root)->leftchild = NULL;
		(*root)->rightchild = NULL;
	}
	else if(strcmp(new, (*root)->word) < 0)
	{
        	AddToTree(new, &(*root)->leftchild, lang);
	}
	else if(strcmp(new, (*root)->word) > 0)
	{
    		AddToTree(new, &(*root)->rightchild, lang);
	}
	else
	{
    		strcpy((*root)->langs[(*root)->index], lang);
		(*root)->index += 1;
	}
	return;
}


int ReadDirectoryFiles(struct stoptree **root)
{
	char nameDir[20];
	char *filename;
	printf("Enter the name of the directory\n");
	scanf("%s", nameDir);
	DIR *directory = opendir(nameDir);
	struct dirent *dirFile;
	if( directory== NULL){
		perror("couldnt open directory");
	}
	else{
		FILE *ptr;
		int count;
		count = 0;
	   	while(((dirFile=readdir(directory))!=NULL) && count<17)
	     	{
			char line[300];
			if (!strcmp (dirFile->d_name, ".")){
				continue;
			    }

			if (!strcmp (dirFile->d_name, "..")){
				continue;
			    }	
			if((filename = malloc(strlen(dirFile->d_name)+strlen(nameDir)+2)) != NULL){
			    filename[0] = '\0';   
			    strcat(filename, nameDir);
			    strcat(filename, "/");
			    strcat(filename,dirFile->d_name);
			}	
			ptr=fopen(filename ,"r");
			if(ptr == NULL){
				printf("file not opened\n");
				continue;
			}
			else{
				while(fgets(line, 30, ptr) != NULL)
				{
					int len = strlen(line);
					while(isspace(line[len-1]) && len){
						len--;
					}
					if(len){
						line[len] = '\0';
					}
				    	AddToTree(line, root, dirFile->d_name);
				}
			}
			count++:
			fclose(ptr);
    		}

       		closedir(directory);
	}
	
	return 0;
}

int main()
{
	char response[30];
	struct stoptree *ROOT = NULL;
	ReadDirectoryFiles(&ROOT);
	printf("Enter a word to search: \n");
	scanf("%s", response);
	SearchTree(ROOT, response);
	return 0;
}













