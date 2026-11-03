/**
 * This code is written by KP-100 (github) on 6/29/2026 and uploaded online 11/03/2026
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 1000

typedef struct {
    char *text;
    char *encryptedText;
    char *decryptedText;
    char *key;
} Data;


// Encrypts the input using XOR and converts it to hexadecimal.
char* encryption(char *input, int len, char *key) {

    int keyLength = strlen(key);

    if (keyLength == 0) {
        return NULL;
    }

    char *encryptionText = malloc((len * 2 + 1) * sizeof(char));

    if (encryptionText == NULL) {
        printf("\nMemory Allocation Failed.");
        return NULL;
    }

    for (int i = 0; i < len; i++) {

        unsigned char x =
            (unsigned char)input[i] ^
            (unsigned char)key[i % keyLength];

        sprintf(&encryptionText[i * 2], "%02X", x);
    }

    encryptionText[len * 2] = '\0';

    return encryptionText;
}


// Converts hexadecimal back to characters and decrypts using XOR.
char* decryption(char *output, int len, char *key) {

    int keyLength = strlen(key);

    if (keyLength == 0 || len % 2 != 0) {
        printf("\nInvalid encrypted text or key.");
        return NULL;
    }

    int textLength = len / 2;

    char *decryptionText = malloc((textLength + 1) * sizeof(char));

    if (decryptionText == NULL) {
        printf("\nMemory Allocation Failed.");
        return NULL;
    }

    for (int i = 0; i < textLength; i++) {

        unsigned int x;

        if (sscanf(&output[i * 2], "%2X", &x) != 1 ||
            !isxdigit((unsigned char)output[i * 2]) ||
            !isxdigit((unsigned char)output[i * 2 + 1])) {

            printf("\nInvalid hexadecimal input.");
            free(decryptionText);
            return NULL;
        }

        decryptionText[i] =
            (char)((unsigned char)x ^
            (unsigned char)key[i % keyLength]);
    }

    decryptionText[textLength] = '\0';

    return decryptionText;
}


int main() {

    int userInput;

    Data *data = malloc(sizeof(Data));

    if (data == NULL) {
        printf("\nMemory Allocation Failed.");
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


    do {

        do {

            printf("\n What would you like to do?");
            printf("\n 1: Encrypt Text");
            printf("\n 2: Decrypt Text");
            printf("\n 3: Exit System");
            printf("\nEnter: ");

            if (scanf("%d", &userInput) != 1 ||
                userInput < 1 || userInput > 3) {

                printf("\nNot a Valid Input.\n");

                int c;
                while ((c = getchar()) != '\n' && c != EOF);

                userInput = 0;
            }
            else {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }

        } while (userInput == 0);


        // User Option 1: Encryption
        if (userInput == 1) {

            printf("\nEnter Text: ");

            char tempArr[MAXSIZE];
            char tempKey[MAXSIZE];

            if (fgets(tempArr, sizeof(tempArr), stdin) == NULL) {
                continue;
            }

            tempArr[strcspn(tempArr, "\n")] = '\0';

            int len = strlen(tempArr);


            free(data->text);
            data->text = NULL;

            free(data->encryptedText);
            data->encryptedText = NULL;


            data->text = malloc((len + 1) * sizeof(char));

            if (data->text == NULL) {
                printf("\nMemory Allocation Failed.");
                break;
            }

            strcpy(data->text, tempArr);


            do {

                printf("\nEnter Key: ");

                if (fgets(tempKey, sizeof(tempKey), stdin) == NULL) {
                    tempKey[0] = '\0';
                    continue;
                }

                tempKey[strcspn(tempKey, "\n")] = '\0';

                if (strlen(tempKey) == 0) {
                    printf("\nKey cannot be empty.\n");
                }

            } while (strlen(tempKey) == 0);


            free(data->key);
            data->key = NULL;

            len = strlen(tempKey);

            data->key = malloc((len + 1) * sizeof(char));

            if (data->key == NULL) {
                printf("\nMemory Allocation Failed.");
                break;
            }

            strcpy(data->key, tempKey);


            len = strlen(data->text);

            data->encryptedText = encryption(
                data->text,
                len,
                data->key
            );

            if (data->encryptedText == NULL) {
                printf("\nEncryption Failed.");
                continue;
            }

            printf("\nENCRYPTED TEXT (HEX): %s\n\n", data->encryptedText);
        }


        // User Option 2: Decryption
        else if (userInput == 2) {

            printf("\nEnter Encrypted HEX Text: ");

            char tempArr[MAXSIZE * 2];
            char tempKey[MAXSIZE];

            if (fgets(tempArr, sizeof(tempArr), stdin) == NULL) {
                continue;
            }

            tempArr[strcspn(tempArr, "\n")] = '\0';

            int len = strlen(tempArr);


            free(data->encryptedText);
            data->encryptedText = NULL;

            free(data->decryptedText);
            data->decryptedText = NULL;


            data->encryptedText = malloc((len + 1) * sizeof(char));

            if (data->encryptedText == NULL) {
                printf("\nMemory Allocation Failed.");
                break;
            }

            strcpy(data->encryptedText, tempArr);


            do {

                printf("\nEnter Key: ");

                if (fgets(tempKey, sizeof(tempKey), stdin) == NULL) {
                    tempKey[0] = '\0';
                    continue;
                }

                tempKey[strcspn(tempKey, "\n")] = '\0';

                if (strlen(tempKey) == 0) {
                    printf("\nKey cannot be empty.\n");
                }

            } while (strlen(tempKey) == 0);


            free(data->key);
            data->key = NULL;

            len = strlen(tempKey);

            data->key = malloc((len + 1) * sizeof(char));

            if (data->key == NULL) {
                printf("\nMemory Allocation Failed.");
                break;
            }

            strcpy(data->key, tempKey);


            len = strlen(data->encryptedText);

            data->decryptedText = decryption(
                data->encryptedText,
                len,
                data->key
            );

            if (data->decryptedText == NULL) {
                printf("\nDecryption Failed.");
                continue;
            }

            printf("\nDECRYPTED TEXT: %s\n\n", data->decryptedText);
        }


    } while (userInput != 3);


    printf("\n\n\n***************************************");
    printf("\n*       Message Portal (Offline)      *");
    printf("\n***************************************");
    printf("\nGoodbye!\n");


    // Free all dynamically allocated memory.
    free(data->text);
    free(data->encryptedText);
    free(data->decryptedText);
    free(data->key);
    free(data);

    return 0;
}
