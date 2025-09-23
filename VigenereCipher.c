#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
*
* Formula:
* Encrypt: Ciphertext = (Plaintext[i] + Key letter[i]) mod 26
* Decrypt: Plaintext = (Ciphertext[i] - Key letter[i] + 26) mod 26
*
*/


int main (){
    // Define the variables be require based on formula and logic in C programming
    char text[500], key[500], encrypted_text[500], decrypted_text[500]; 
    int i, j = 0, textLength, keyLength, userChoice = 0;                   

    printf ("\n\n\n***************************************");
    printf("\n*       Message Portal (Online)       *");
    printf ("\n***************************************");

    // Main menu loop
    do {
        // Input validation loop for menu selection
        do {
            printf("\n What would you like to do? \n 1: Encrypt Text \n 2: Decrypt Text \n 3: Exit System");
            printf ("\nEnter: ");

            if (scanf("%d", &userChoice) != 1 || (userChoice < 1 || userChoice > 3)) {
                printf("\nNot a valid selection.\n");
                while (getchar() != '\n');  
                userChoice = 0;            
            } else {
                while (getchar() != '\n');  
            }
        } while (userChoice == 0);

        // Encryption
        if (userChoice == 1){
            j = 0;
            printf("\nEnter Text: ");
            scanf(" %[^\n]", text);  // allow spaces

            printf("Enter Key: ");
            scanf("%s", key);

            textLength = strlen(text);
            keyLength = strlen(key);

            for (i = 0; i < textLength; i++){
                if((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')){
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
        else if (userChoice == 2){
            j = 0;
            printf("\nEnter Encrypted Text: ");
            scanf(" %[^\n]", encrypted_text);  // allow spaces

            printf("Enter Key: ");
            scanf("%s", key);

            textLength = strlen(encrypted_text);
            keyLength = strlen(key);

            for (i = 0; i < textLength; i++){
                if((encrypted_text[i] >= 'A' && encrypted_text[i] <= 'Z') || (encrypted_text[i] >= 'a' && encrypted_text[i] <= 'z')){
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
