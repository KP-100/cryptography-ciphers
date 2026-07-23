/**
 * This code is written by KP-100 (github) on 6/19/2026 and uploaded online 6/26/2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 1000

typedef struct {
    char *text;          // Pointer to point to DMA user input
    char *encryptedText; // Pointer to point to DMA encrypted text
    char *decryptedText; // Pointer to point to DMA decrypted text
    char *key;
}Data;

// This function takes in the input array, and then encrypts it via the formula
char* encryption(char* input, int len, char* key){
    char* encryptionText = malloc((len + 1) * sizeof(char));
    if(encryptionText == NULL){
        return NULL;
    }
    int keyLength = strlen(key);
    int j = 0;
    for(int i = 0; i < len; i++){
        if((input[i] >= 'A' && input[i] <= 'Z') || input[i] >= 'a' && input[i] <= 'z'){
            char upperCaseInput = toupper(input[i]);
            char upperCaseKey = toupper(key[j]);
            encryptionText[i] = ((upperCaseInput - 'A') + (upperCaseKey - 'A')) % 26 + 'A';
            j++;
            if(j == keyLength){
                j = 0;
            }
        }
        else{
            encryptionText[i] = input[i];
        }
    }
    encryptionText[len] = '\0';
    return encryptionText;
}

// This function takes in an input array that is already encrypted, then takes in the key
// and  performs calculation via the formula and returns plaintext
char* decryption(char* output, int len, char* key){
    char* decryptionText = malloc((len + 1) * sizeof(char));
        int keyLength = strlen(key);
        int j = 0;
        for(int i = 0; i < len; i++){
            if((output[i] >= 'A' && output[i] <= 'Z') || output[i] >= 'a' && output[i] <= 'z'){
                char upperCaseOutput = toupper(output[i]);
                char upperCaseKey = toupper(key[j]);
                decryptionText[i] = ((upperCaseOutput - 'A') - (upperCaseKey - 'A') + 26) % 26 + 'A';
                j++;
                if(j == keyLength){
                    j = 0;
                }
        }
        else{
            decryptionText[i] = output[i];
        }
    }
    decryptionText[len] = '\0';
    return decryptionText;
}

// This is the main function, here we have a menu system, and option selection process.
/**
 * 1: Encrypt
 * 2: Decrypt
 * 3: Exit
 */
int main(){

    int userInput;
    Data* data = malloc(sizeof(Data));
    if(data == NULL){
        printf("\nMemory Allocation Failed.\n");
        return 1;
    }

    data->text = NULL;
    data->encryptedText = NULL;
    data->decryptedText = NULL;
    data->key = NULL;

    printf("\n\n\n***************************************");
    printf("\n*                                     *");
    printf("\n*       Message Portal (Online)       *");
    printf("\n*                                     *");
    printf("\n***************************************");



    do
    { // do while loop until userinput is not "Exit"

        do
        {// do while user Input is 0, we set this to zero if userInput !=1, <1, or >3

            printf("\n What would you like to do? \n 1: Encrypt Text \n 2: Decrypt Text \n 3: Exit System");
            printf("\nEnter: ");

            if(scanf("%d", &userInput) != 1 || userInput < 1 || userInput > 3){
                printf("\n Not a Valid Input.\n");
                while(getchar() != '\n');
                userInput = 0;
            }

        } while(userInput == 0);

        //User Input 1 (Encryption)
        if(userInput == 1){
            printf("\nEnter Text: ");
            char tempArr[MAXSIZE];
            char tempKey[MAXSIZE];
            scanf(" %[^\n]", tempArr);
            int len = strlen(tempArr) + 1;
            free(data->text);
            data->text = malloc(sizeof(char) * len);
            if(data->text == NULL){
                printf("\nMemory Allocation Failed.\n");
                return 1;
            }
            strcpy(data->text, tempArr);

            int valid = 0;
            do
            {
                printf("\nEnter Key: ");
                scanf(" %999[^\n]", tempKey);

                if(strlen(tempKey) == 0){
                    printf("\nKey cannot be empty.\n");
                    continue;
                }

                valid = 1;
                for(int i = 0; i < strlen(tempKey); i++){
                    if(!isalpha(tempKey[i])){
                        valid = 0;
                        printf("\nInvalid key. Use alphabetic characters only.\n");
                        break;
                    }
                }

            } while(!valid);

            free(data->key);
            len = strlen(tempKey) + 1;
            data->key = malloc(len * sizeof(char));
            if(data->key == NULL){
                printf("\nMemory Allocation Failed.\n");
                return 1;
            }
            strcpy(data->key, tempKey);

            len = strlen(data->text);
            free(data->encryptedText);
            data->encryptedText = encryption(data->text, len, data->key);
            if(data->encryptedText == NULL){
                printf("\nMemory Allocation Failed.");
                return 1;
            }
            printf("\nENCRYPTED TEXT: %s\n\n", data->encryptedText);

        }

        //User Input 2 (Decryption)
        else if(userInput == 2){
            printf("\nEnter Encrypted Text: ");
            char tempArr[MAXSIZE];
            char tempKey[MAXSIZE];
            scanf(" %[^\n]", tempArr);
            int len = strlen(tempArr) + 1;

            free(data->encryptedText);
            data->encryptedText = malloc(len * sizeof(char));
            if(data->encryptedText == NULL){
                printf("\nMemory Allocation Failed");
            }
            strcpy(data->encryptedText, tempArr);

            int valid = 0;
            do{
                printf("\nEnter Key: ");
                scanf(" %999[^\n]", tempKey);

                if(strlen(tempKey) == 0){
                    printf("\nKey cannot be empty.\n");
                    continue;
                }

                valid = 1;
                for(int i = 0; i < strlen(tempKey); i++){
                    if(!isalpha(tempKey[i])){
                        valid = 0;
                        printf("\nInvalid key. Use alphabetic characters only.\n");
                        break;
                    }
                }

            }while(!valid);

            free(data->key);
            len = strlen(tempKey) + 1;
            data->key = malloc(len * sizeof(char));
            if(data->key == NULL){
                printf("\nMemory Allocation Failed.\n");
                return 1;
            }
            strcpy(data->key, tempKey);

            len = strlen(data->encryptedText);
            free(data->decryptedText);
            data->decryptedText = decryption(data->encryptedText, len, data->key);
            printf("DECRYPTED TEXT: %s\n\n", data->decryptedText);

        }


    } while(userInput != 3);


    printf("\n\n\n***************************************");
    printf("\n*       Message Portal (Offline)      *");
    printf("\n***************************************");
    printf("\nGoodbye!\n");

    // free the used memory
    free(data->text);
    free(data->encryptedText);
    free(data->decryptedText);
    free(data->key);
    free(data);
    return 0;
}
