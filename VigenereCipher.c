#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
* Formula:
* Encrypt: Ciphertext = (Plaintext[i] + Key[i]) mod 26
* Decrypt: Plaintext = (Ciphertext[i] - Key[i] + 26) mod 26
*/

int main() {
    char text[1000], key[1000], encrypted_text[1000], decrypted_text[1000];
    int i, j = 0, textLength, keyLength, userChoice = 0;

    printf ("\n\n\n***************************************");
    printf("\n*       Message Portal (Online)       *");
    printf ("\n***************************************");

    // Main menu loop
    do {
        do {
            printf("\n What would you like to do? \n 1: Encrypt Text \n 2: Decrypt Text \n 3: Exit System");
            printf ("\nEnter: ");

            if (scanf("%d", &userChoice) != 1 || (userChoice < 1 || userChoice > 3)) {
                printf("\nNot a valid selection.\n");
                while (getchar() != '\n');  // clear buffer
                userChoice = 0;
            } else {
                while (getchar() != '\n');  // clear newline left in buffer
            }
        } while (userChoice == 0);

        // Encryption
        if (userChoice == 1) {
            j = 0;

            printf("\nEnter Text: ");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = '\0';

            int valid = 0;
            do {
                printf("Enter Key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0';

                if (strlen(key) == 0) {
                    printf("Key cannot be empty.\n");
                    continue;
                }

                valid = 1;
                for (i = 0; i < strlen(key); i++) {
                    if (!((key[i] >= 'A' && key[i] <= 'Z') || (key[i] >= 'a' && key[i] <= 'z'))) {
                        valid = 0;
                        printf("Invalid key. Use only alphabetic characters.\n");
                        break;
                    }
                }
            } while (!valid);

            textLength = strlen(text);
            keyLength = strlen(key);

            for (i = 0; i < textLength; i++) {
                if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
                    char upper_case_text = toupper(text[i]);
                    char upper_case_key = toupper(key[j]);

                    encrypted_text[i] = ((upper_case_text - 'A') + (upper_case_key - 'A')) % 26 + 'A';
                    j++;

                    if (j == keyLength){
                         j = 0;
                    }
                } else {
                    encrypted_text[i] = text[i]; 
                }
            }

            encrypted_text[textLength] = '\0';
            printf("Encrypted text: %s\n\n", encrypted_text);
        }

        // Decryption
        else if (userChoice == 2) {
            j = 0;

            printf("\nEnter Encrypted Text: ");
            fgets(encrypted_text, sizeof(encrypted_text), stdin);
            encrypted_text[strcspn(encrypted_text, "\n")] = '\0';

            int valid = 0;
            do {
                printf("Enter Key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0';

                if (strlen(key) == 0) {
                    printf("Key cannot be empty.\n");
                    continue;
                }

                valid = 1;
                for (i = 0; i < strlen(key); i++) {
                    if (!((key[i] >= 'A' && key[i] <= 'Z') || (key[i] >= 'a' && key[i] <= 'z'))) {
                        valid = 0;
                        printf("Invalid key. Use only alphabetic characters.\n");
                        break;
                    }
                }
            } while (!valid);

            textLength = strlen(encrypted_text);
            keyLength = strlen(key);

            for (i = 0; i < textLength; i++) {
                if ((encrypted_text[i] >= 'A' && encrypted_text[i] <= 'Z') || (encrypted_text[i] >= 'a' && encrypted_text[i] <= 'z')) {
                    char upper_cipher_text = toupper(encrypted_text[i]);
                    char upper_case_key = toupper(key[j]);

                    decrypted_text[i] = ((upper_cipher_text - 'A') - (upper_case_key - 'A') + 26) % 26 + 'A';
                    j++;

                    if (j == keyLength){
                         j = 0;
                    }
                } else {
                    decrypted_text[i] = encrypted_text[i];
                }
            }

            decrypted_text[textLength] = '\0';
            printf("Decrypted Text: %s\n\n", decrypted_text);
        }

    } while (userChoice != 3);

    printf ("\n\n\n***************************************");
    printf("\n*       Message Portal (Offline)      *");
    printf ("\n***************************************");
    printf("\nGoodbye!\n");

    return 0;
}
