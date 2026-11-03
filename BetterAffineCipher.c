/**
 * This code is written by KP-100 (github) on 7/15/2026 and uploaded online 11/03/2026
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
    int keyMultiplier;
    int key;
} Data;


// Finds the modular inverse of the multiplier.
int modInverse(int a, int m) {
    a = ((a % m) + m) % m;

    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }

    return -1;
}


// Encrypts the input using the Affine Cipher.
char* encryption(char *input, int len, int a, int b) {

    char *encryptionText = malloc((len + 1) * sizeof(char));

    if (encryptionText == NULL) {
        printf("\nMemory Allocation Failed.");
        return NULL;
    }

    for (int i = 0; i < len; i++) {

        if ((input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= 'a' && input[i] <= 'z')) {

            char upperCase = toupper((unsigned char)input[i]);

            encryptionText[i] =
                ((a * (upperCase - 'A') + b) % 26) + 'A';
        }
        else {
            encryptionText[i] = input[i];
        }
    }

    encryptionText[len] = '\0';

    return encryptionText;
}


// Decrypts the input using the Affine Cipher.
char* decryption(char *output, int len, int a, int b) {

    int inverse = modInverse(a, 26);

    if (inverse == -1) {
        printf("\nInvalid multiplier. Decryption impossible.");
        return NULL;
    }

    char *decryptionText = malloc((len + 1) * sizeof(char));

    if (decryptionText == NULL) {
        printf("\nMemory Allocation Failed.");
        return NULL;
    }

    for (int i = 0; i < len; i++) {

        if ((output[i] >= 'A' && output[i] <= 'Z') ||
            (output[i] >= 'a' && output[i] <= 'z')) {

            char upperCase = toupper((unsigned char)output[i]);

            int value = upperCase - 'A' - b;

            value = ((value % 26) + 26) % 26;

            decryptionText[i] =
                ((inverse * value) % 26) + 'A';
        }
        else {
            decryptionText[i] = output[i];
        }
    }

    decryptionText[len] = '\0';

    return decryptionText;
}


// Validates whether the multiplier has a modular inverse.
int validMultiplier(int a) {
    return modInverse(a, 26) != -1;
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
    data->keyMultiplier = 0;
    data->key = 0;


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

                printf("\nEnter Key Multiplier (a): ");

                if (scanf("%d", &data->keyMultiplier) != 1 ||
                    !validMultiplier(data->keyMultiplier)) {

                    printf("\nInvalid multiplier. It must be relatively prime to 26.\n");

                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);

                    data->keyMultiplier = 0;
                }

            } while (!validMultiplier(data->keyMultiplier));


            do {

                printf("\nEnter Key (b): ");

                if (scanf("%d", &data->key) != 1 ||
                    data->key < 0 || data->key > 25) {

                    printf("\nInvalid key. Enter a number between 0 and 25.\n");

                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);

                    data->key = -1;
                }

            } while (data->key < 0);


            int c;
            while ((c = getchar()) != '\n' && c != EOF);


            len = strlen(data->text);

            data->encryptedText = encryption(
                data->text,
                len,
                data->keyMultiplier,
                data->key
            );

            if (data->encryptedText == NULL) {
                printf("\nEncryption Failed.");
                break;
            }

            printf("\nENCRYPTED TEXT: %s\n\n", data->encryptedText);
        }


        // User Option 2: Decryption
        else if (userInput == 2) {

            printf("\nEnter Encrypted Text: ");

            char tempArr[MAXSIZE];

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

                printf("\nEnter Key Multiplier (a): ");

                if (scanf("%d", &data->keyMultiplier) != 1 ||
                    !validMultiplier(data->keyMultiplier)) {

                    printf("\nInvalid multiplier. It must be relatively prime to 26.\n");

                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);

                    data->keyMultiplier = 0;
                }

            } while (!validMultiplier(data->keyMultiplier));


            do {

                printf("\nEnter Key (b): ");

                if (scanf("%d", &data->key) != 1 ||
                    data->key < 0 || data->key > 25) {

                    printf("\nInvalid key. Enter a number between 0 and 25.\n");

                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);

                    data->key = -1;
                }

            } while (data->key < 0);


            int c;
            while ((c = getchar()) != '\n' && c != EOF);


            len = strlen(data->encryptedText);

            data->decryptedText = decryption(
                data->encryptedText,
                len,
                data->keyMultiplier,
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
    free(data);

    return 0;
}
