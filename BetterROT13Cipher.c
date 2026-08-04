/**
 * This code is written by KP-100 (github) on 8/3/2026 and uploaded online 8/3/2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 1000
#define KEY 13

typedef struct {
    char *text; // Pointer to point to DMA user input
    char *encryptedText;// Pointer to point to DMA encrypted text
    char* decryptedText; // Pointer to point to DMA decrypted text
    int key;
}Data;

char* encryption(char *input, int len, int key){
    char* encryptionText = malloc(sizeof(char) * (len + 1));
    if(encryptionText == NULL){
        printf("\nMemory Allocation Failed");
        return NULL;
    }

    for(int i = 0; i < len; i++){
        if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')){
            char upperCase = toupper(input[i]);
            encryptionText[i] = ((upperCase - 'A' + key) %26 ) + 'A';
        }
        else{
            encryptionText[i] = input[i];
        }
    }

    encryptionText[len] = '\0';
    return encryptionText;
}

char* decryption(char *output, int len, int key){
    char* decryptionText = malloc(sizeof(char) * (len + 1));
    if(decryptionText == NULL){
        printf("\nMemory Allocation Failed.");
        return NULL;
    }

    for(int i = 0; i < len; i++){
        if((output[i] >= 'A' && output[i] <= 'Z') || (output[i] >= 'a' && output[i] <= 'z')){
            char upperCase = toupper(output[i]);
            decryptionText[i] = ((upperCase - 'A' - key + 26) % 26) + 'A';
        }
        else{
            decryptionText[i] = output[i];
        }
    }

    decryptionText[len] = '\0';
    return decryptionText;
}

int main(){

    int userInput;

    Data* data = malloc(sizeof(Data));
    if(data == NULL){
        printf("\nMemory Allocation failed.");
        return 1;
    }

    data->text = NULL;
    data->encryptedText = NULL;
    data->decryptedText = NULL;
    data->key = KEY;

    printf("\n\n\n***************************************");
    printf("\n*                                     *");
    printf("\n*       Message Portal (Online)       *");
    printf("\n*                                     *");
    printf ("\n***************************************");

    do{
        
        do{

            printf("\n What would you like to do? \n 1: Encrypt Text \n 2: Decrypt Text \n 3: Exit System");
            printf ("\nEnter: ");

            if(scanf("%d", &userInput) != 1 || userInput < 1 || userInput > 3){
                printf("\n Not a Valid Input.\n");
                while(getchar() != '\n');
                userInput = 0;
            }

        }while(userInput == 0);


        //user option 1
        if(userInput == 1){
            printf("\nEnter Text: ");
            char tempArr[MAXSIZE];
            scanf(" %999[^\n]", tempArr);
            int len = strlen(tempArr) + 1;

            free(data->text);
            data->text = NULL;
            free(data->encryptedText);
            data->encryptedText = NULL;

            data->text = malloc(sizeof(char) * len);

            if(data->text == NULL){
                printf("\nMemory Allocation Failed.");
                return 1;
            }

            strcpy(data->text, tempArr);
            len = strlen(data->text);

            data->encryptedText = encryption(data->text, len, data->key);
            if(data->encryptedText == NULL){
                printf("\nMemory Allocation Failed.");
                return 1;
            }
            printf("\nENCRYPTED TEXT: %s\n\n", data->encryptedText);

        }

        else if(userInput == 2){
            printf("Enter ENCRYPTED text: ");
            char tempArr[MAXSIZE];
           scanf(" %999[^\n]", tempArr);
            int len = strlen(tempArr) + 1;

            free(data->encryptedText);
            data->encryptedText = NULL;
            free(data->decryptedText);
            data->decryptedText = NULL;

            data->encryptedText = malloc(sizeof(char) * len);
            if(data->encryptedText == NULL){
                printf("Memory Allocation Failed.");
                return 1;
            }

            strcpy(data->encryptedText, tempArr);
            len = strlen(data->encryptedText);
            data->decryptedText = decryption(data->encryptedText, len, data->key);

            if(data->decryptedText == NULL){
                printf("\nMemory Allocation Failed.");
                return 1;
            }

            printf("DECRYPTED TEXT: %s\n\n", data->decryptedText);
        }


    }while(userInput != 3);

    printf ("\n\n\n***************************************");
    printf("\n*       Message Portal (Offline)      *");
    printf ("\n***************************************");
    printf("\nGoodbye!\n");

    //free the used memory:
    free(data->text);
    free(data->encryptedText);
    free(data->decryptedText);
    free(data);

    return 0;

}

