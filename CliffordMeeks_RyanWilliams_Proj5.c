/*
 * Project 5 CIS 308
 * Created on: April 9, 2016
 * Author: Ryan Williams(Monday 10:30)/Clifford Meeks(Monday 1:30)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#define DARRAY 30
#define LINESIZE 1000

/// <summary>
/// The structure for the stop tree node
/// </summary>
typedef struct stoptree{
    	char *word;
	char langs[DARRAY][DARRAY];
	int index;
    	struct stoptree *leftchild;
    	struct stoptree *rightchild;
}STOP_T;

typedef struct lang{
	int czech;
	int danish;
	int dutch;
	int english;
	int finnish;
	int french;
	int german;
	int hungarian;
	int icelandic;
	int italian;
	int norwegian;
	int polish;
	int portuguese;
	int romanian;
	int spanish;
	int swedish;
	int turkish;
}LANG_T;

/// <summary>
/// Search through the tree for the word
/// </summary>
/// <param name = "root"> The root of the stop tree </param>
/// <param name = "stopword"> The word being searched </param> 
void SearchTree(struct stoptree *root, char *stopword, struct stoptree **cur)
{
	//printf("%s\n", stopword);
	if(root == NULL)
	{
		//printf("WORD NOT FOUND!\n");
    		return;
	}
	else{
		if(strcmp(stopword, root->word) == 0)
		{
			*cur = root;
			//printf("cur = %s\n", (*cur)->word);
			return;
		}
		else if(strcmp(stopword, root->word) < 0)
		{
	    		 SearchTree(root->leftchild, stopword, cur);
		}
		else
		{
	    		 SearchTree(root->rightchild, stopword, cur);
		}
	}
	return;
}	

/// <summary>
/// Add the stopword to the tree of stop words
/// </summary> 
/// <param name = "new"> the word being added </param>
/// <param name = root> double pointer to the root </param>
/// <param name = lang> the language </param>
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

/// <summary> 
/// Read in the specified directory and each text file inside
/// </summary>
/// <param name = "root"> double pointer to the root of the tree </param>
int ReadDirectoryFiles(struct stoptree **root, char* directoryName)
{
	//printf("%s",directoryName);
	char *filename;
	DIR *directory = opendir(directoryName);
	struct dirent *dirFile;
	if(directory== NULL){
		perror("couldnt open directory");
	}
	else{
		FILE *ptr;
		int count;
		count = 0;
	   	while(((dirFile=readdir(directory))!=NULL) && count< 17)
	     	{
			char line[300];
			if (!strcmp (dirFile->d_name, ".")){
				continue;
			    }

			if (!strcmp (dirFile->d_name, "..")){
				continue;
			    }	
			if((filename = malloc(strlen(dirFile->d_name)+strlen(directoryName)+2)) != NULL){
			    filename[0] = '\0';   
			    strcat(filename, directoryName);
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
					//	printf("reads stopwords1");
				}		
			}
			//printf("blahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n");
			//printf("%d\n", count);
			count++;
			fclose(ptr);
    		}
		
       		
	}
	closedir(directory);
	return 0;
}

//Adds to the language count in the language structure to get a count of how much each language is in the text file
int AddLangs(struct lang **Langs, struct stoptree **node){
	int i;
	if((*node) != NULL){
	for(i = 0; i < DARRAY; i++){

		if(strcmp((*node)->langs[i], "czech") == 0){
			(*Langs)->czech+=1;
		}
		else if(strcmp((*node)->langs[i], "danish") == 0){
			(*Langs)->danish++;
		} 
		else if(strcmp((*node)->langs[i], "dutch") == 0){
			(*Langs)->dutch++;
		}
		else if(strcmp((*node)->langs[i], "english") == 0){
			(*Langs)->english+=1;
		}
		else if(strcmp((*node)->langs[i], "finnish") == 0){
			(*Langs)->finnish++;
		}
		else if(strcmp((*node)->langs[i], "french") == 0){
			(*Langs)->french++;
		}
		else if(strcmp((*node)->langs[i], "german") == 0){
			(*Langs)->german++;
		}
		else if(strcmp((*node)->langs[i], "hungarian") == 0){
			(*Langs)->hungarian++;
		}
		else if(strcmp((*node)->langs[i], "icelandic") == 0){
			(*Langs)->icelandic++;
		}
		else if(strcmp((*node)->langs[i], "italian") == 0){
			(*Langs)->italian++;
		}
		else if(strcmp((*node)->langs[i], "norwegian") == 0){
			(*Langs)->norwegian++;
		}
		else if(strcmp((*node)->langs[i], "polish") == 0){
			(*Langs)->polish++;
		}
		else if(strcmp((*node)->langs[i], "portuguese") == 0){
			(*Langs)->portuguese++;
		}
		else if(strcmp((*node)->langs[i], "romanian") == 0){
			(*Langs)->romanian++;
		}
		else if(strcmp((*node)->langs[i], "spanish") == 0){
			(*Langs)->spanish++;
		}
		else if(strcmp((*node)->langs[i], "swedish") == 0){
			(*Langs)->swedish++;
		}
		else if(strcmp((*node)->langs[i], "turkish") == 0){
			(*Langs)->turkish++;
		}
	}
}

	return 0;
}

//Reads in the text file and with each words checks it against the stop words
int Read_Text(struct lang *Langs,struct stoptree *root, char *filename)
{
	char *line;
	char* tokens[256];
	char *delims = " ,:;.";
	
	FILE *ptr;
	ptr=fopen(filename ,"r");
	
	printf("File opened\n");
	if(ptr != NULL){
		while(fgets(line, LINESIZE, ptr) != NULL){		
			int i = 0;
			//printf("gets line\n");
			tokens[i]=strtok(line,delims);    
			while(tokens[i]!=NULL)                    
			{
			      //printf("token: %s\n", tokens[i]);	
			      struct stoptree *curtree;
			      SearchTree(root, tokens[i], &curtree);
				
			      if(curtree != NULL){
					//printf("%s\n", curtree->word);
					AddLangs(&Langs, &curtree);
				}
				//printf("%d\n", Langs->english);	
			      
			      i++;
			      tokens[i]=strtok(NULL,delims);
			}
		}
		fclose(ptr);
	}
	else{
		printf("TEXT FILE NOT OPENED");
	}
return 0;
	
}


//Finds the language with the maximum count and returns that language
char* FindMaxLanguage(struct lang **Langs)
{
	char* max;
	int maxInt = 0;
	int i;

	for(i = 0; i < DARRAY; i++){

		if((*Langs)->czech > maxInt){
			max = "Czech";
			maxInt = (*Langs)->czech;
		}
		else if((*Langs)->danish > maxInt){
			max = "Danish";
			maxInt = (*Langs)->danish;
		} 
		else if((*Langs)->dutch > maxInt){
			max = "Dutch";
			maxInt = (*Langs)->dutch;
		}
		else if((*Langs)->english > maxInt){
			max = "English";
			maxInt = (*Langs)->english;
		}
		else if((*Langs)->finnish > maxInt){
			max = "Finnish";
			maxInt = (*Langs)->finnish;
		}
		else if((*Langs)->french > maxInt){
			max = "French";
			maxInt = (*Langs)->french;
		}
		else if((*Langs)->german > maxInt){
			max = "German";
			maxInt = (*Langs)->german;
		}
		else if((*Langs)->hungarian > maxInt){
			max = "Hungarian";
			maxInt = (*Langs)->hungarian;
		}
		else if((*Langs)->icelandic > maxInt){
			max = "Icelandic";
			maxInt = (*Langs)->icelandic;
		}
		else if((*Langs)->italian > maxInt){
			max = "Italian";
			maxInt = (*Langs)->italian;
		}
		else if((*Langs)->norwegian > maxInt){
			max = "Norwegian";
			maxInt = (*Langs)->norwegian;
		}
		else if((*Langs)->polish > maxInt){
			max = "Polish";
			maxInt = (*Langs)->polish;
		}
		else if((*Langs)->portuguese > maxInt){
			max = "Portuguese";
			maxInt = (*Langs)->portuguese;
		}
		else if((*Langs)->romanian > maxInt){
			max = "Romanian";
			maxInt = (*Langs)->romanian;
		}
		else if((*Langs)->spanish > maxInt){
			max = "Spanish";
			maxInt = (*Langs)->spanish;
		}
		else if((*Langs)->swedish > maxInt){
			max = "Swedish";
			maxInt = (*Langs)->swedish;
		}
		else if((*Langs)->turkish > maxInt){
			max = "Turkish";
			maxInt = (*Langs)->turkish;
		}
	}
	return max;
}

//this is the main function
int main(int argc, char *argv[])
{
	struct stoptree *ROOT = NULL;
	struct lang LANGS = {0 , 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	struct lang *LANGptr = &LANGS;
	char *Language;
	if(argc < 2)
	{
		printf("Usage: testprog <dirname>\n");
		return 1;
	}
	printf("%s\n", argv[1]);
	ReadDirectoryFiles(&ROOT, argv[1]);
	
	printf("%s\n", argv[2]);
	Read_Text(&LANGS, ROOT, argv[2]);
	Language = FindMaxLanguage(&LANGptr);
	printf("The Language is: %s\n", Language);
	return 0;
}
















