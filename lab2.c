#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct unicodeBlocks{
        char hexStr1[50];
        char hexStr2[50];
        char name[50];
        long double hex1;
        long double hex2;
    };
#define BUFFERSIZE 100
    struct unicodeBlocks saveToStruct(char *str){
        struct unicodeBlocks block;
        int count = 0;
        char* token = strtok(str, "..;");

        while(token != NULL)
        {
            if (count == 0){
                strcpy(block.hexStr1, token);
                }
            else if (count == 1){
                strcpy(block.hexStr2, token);
                }
            else{
                strcpy(block.name, token);
            }
            count++;
            token = strtok(NULL, "..;" );
        }
        return block;
    }
typedef enum { false = 0, true } bool;

bool isEmptyLine(const char *s) {
  static const char *emptyline_detector = " \t\n";

  return strspn(s, emptyline_detector) == strlen(s);
}

long convertToHex(char hexStr[]){
    return strtol(hexStr, NULL, 16);
}

long double readInUserHex(){
    char hex[8];
    printf("Please enter your hexcode: ");
     fgets(hex, 8, stdin);

    return strtol(hex, NULL, 16);
}

int main()
{
    struct unicodeBlocks blocks[300];
    FILE *fp = fopen("Blocks.txt", "r");
    if (fp == NULL){
        printf("Error opening file");
    }

    char str[BUFFERSIZE];
    int count = 0;
    while(fgets(str, BUFFERSIZE, fp)){
        if(str[0] != '#' && isEmptyLine(str) == false){
            blocks[count] = saveToStruct(str);
            blocks[count].hex1 = convertToHex(blocks[count].hexStr1);
            blocks[count].hex2 = convertToHex(blocks[count].hexStr2);
            count++;
        }
    }
    long double userInput = readInUserHex();
    count = 0;
    int found = 0;
    while(count < 300 && found == 0){
        if(userInput >= blocks[count].hex1 && userInput <= blocks[count].hex2){
            printf("The block name is %s", blocks[count].name);
            found = 1;
        }
        count++;
    }

    fclose(fp);
    return 0;
}
