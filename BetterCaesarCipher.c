/**
 * This code is written by KP-100 (github) on 6/22/2026 and uploaded online 6/26/2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 1000

// Data structure for this Cipher.
typedef struct {
    char *text; // Pointer to point to DMA user input
    char *encryptedText;// Pointer to point to DMA encrypted text
    char* decryptedText; // Pointer to point to DMA decrypted text
    int key;
}Data;

/**
 *  This function takes in a array, then encrypts it, and then returns it back to the main function
 *  NOTE: Since this is a Cipher, everything is converted to UPPER case to preserve secrecy. Could be done in all lower case too.
 *  Idea here is that, even if its all upper case or all lower case, normal text is readble.
*/

char* encryption(char* input, int len, int key){
    char* encryptionText = malloc((len + 1) * sizeof(char)); // Exact amount of memory allocated
    if (encryptionText == NULL) {
        return NULL;
    }
    for(int i = 0; i < len ; i++){
        if((input[i] >= 'A' && input[i] <= 'Z') || input[i] >= 'a' && input[i] <= 'z'){ 
            char upperCase = toupper(input[i]);
            encryptionText[i] = ((upperCase - 'A' + key) % 26) + 'A';
        } 
        else{
            encryptionText[i] = input[i];
        }
    }

    encryptionText[len] = '\0';
    return encryptionText;
}

// This function takes in an (encrypted) array, then decrypts it, and then returns it back to the main function.
// NOTE: This also returns normal text in all UPPER case.
char* decryption(char* output, int len, int key){
    char* decryptionText = malloc((len + 1) * sizeof(char));
        for(int i = 0; i < len ; i++){
            if((output[i] >= 'A' && output[i] <= 'Z') || output[i] >= 'a' && output[i] <= 'z'){
                char upperCase = toupper(output[i]);
                decryptionText[i] = ((upperCase - 'A' - key + 26) % 26 + 'A');
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

    printf("\n\n\n***************************************");
    printf("\n*                                     *");
    printf("\n*       Message Portal (Online)       *");
    printf("\n*                                     *");
    printf ("\n***************************************");



    do
    { // do while loop until userinput is not "Exit"

        do
        {// do while user Input is 0, we set this to zero if userInput !=1, <1, or >3

            printf("\n What would you like to do? \n 1: Encrypt Text \n 2: Decrypt Text \n 3: Exit System");
            printf ("\nEnter: ");

            if(scanf("%d", &userInput) != 1 || userInput < 1 || userInput > 3){
                printf("\n Not a Valid Input.\n");
                while(getchar() != '\n');
                userInput = 0;
            }

        } while(userInput == 0);

        // User Option 1
        if(userInput == 1){
            printf("\nEnter Text: ");
            char tempArr[MAXSIZE];
            scanf(" %[^\n]", tempArr);
            int len = strlen(tempArr) + 1;
            data->text = malloc(sizeof(char) * len);
            if(data->text == NULL){
                printf("\nMemory Allocation Failed.\n");
                return 1;
            }
            strcpy(data->text, tempArr);

            do
            {
                printf("\nEnter key: ");
                if(scanf("%d", &data->key) != 1 || data->key < 1 || data->key > 25){
                    printf("\nInvalid key selection. Enter a number between 0 and 25.\n");
                    while(getchar()!= '\n');
                    data->key = -1;
                }

            } while (data->key < 0);

            len = strlen(data->text);

            data->encryptedText = encryption(data->text, len, data->key);
            if(data->encryptedText == NULL){
                printf("\nMemory Allocation Failed.");
                return 1;
            }
            printf("\nENCRYPTED TEXT: %s\n\n", data->encryptedText);
            
        }

        // User Option 2
        else if(userInput == 2){
            printf("\nEnter Encrypted Text: ");
            char tempArr[MAXSIZE];
            scanf(" %[^\n]", tempArr);
            int len = strlen(tempArr) + 1;

            data->encryptedText = malloc(len * sizeof(char));
            if(data->encryptedText == NULL){
                printf("\nMemory Allocation Failed");
            }
            strcpy(data->encryptedText, tempArr);

            do{
                printf("\nEnter Key: ");
                if(scanf("%d", &data->key) != 1 || data->key < 0 || data->key > 25){
                    printf("\n Invalid key. Enter a number between 0 and 25.\n");
                    while(getchar() != '\n');
                    data->key = -1;
                }

            }while(data->key < 0);

            len = strlen(data->encryptedText);
            data->decryptedText = decryption(data->encryptedText, len, data->key);
            printf("DECYPTED TEXT: %s\n\n", data->decryptedText);

        }

        
    
    } while(userInput != 3);


    printf ("\n\n\n***************************************");
    printf("\n*       Message Portal (Offline)      *");
    printf ("\n***************************************");
    printf("\nGoodbye!\n");

    // free the used memory
    free(data->text);
    free(data->encryptedText);
    free(data->decryptedText);
    free(data);
    return 0;

    
}
