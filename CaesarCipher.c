#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char text[1000], encrypted_text[1000], decrypted_text[1000];
    int i, key, userChoice, textLength;

    printf ("\n\n\n***************************************");
    printf("\n*       Message Portal (Online)       *");
    printf ("\n***************************************");


    do
    {
        do
        {
            printf("\n What would you like to do? \n 1: Encrypt Text \n 2: Decrypt Text \n 3: Exit System");
            printf ("\nEnter: ");

            if (scanf("%d", &userChoice) != 1 || userChoice < 1 || userChoice > 3){
                printf("\nNot a valid selection.\n");
                while (getchar() != '\n');  
                userChoice = 0;            
            } else {
                while (getchar() != '\n');  
            
            }
        } while (userChoice == 0);
        
        if (userChoice == 1){
            printf("\nEnter Text: ");
            scanf(" %[^\n]", text);

            do {
                printf("\nEnter Key: ");
                if (scanf("%d", &key) != 1 || key < 0 || key > 25) {
                    printf("\nInvalid key. Please enter a number between 0 and 25.\n");
                    while (getchar() != '\n'); 
                    key = -1; 
                }
            } while (key < 0);

           // key = key % 26;

            textLength = strlen(text);

            for (i = 0; i < textLength; i ++){
                if((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')){
                    char upper_case_text = toupper(text[i]);
                    encrypted_text[i] = ((upper_case_text - 'A' + key) % 26) + 'A';
                } else {
                    encrypted_text[i] = text[i];
                }

            }

            encrypted_text[textLength] = '\0';
            printf("Encrypted text: %s\n\n", encrypted_text);

        }

        else if (userChoice == 2){
            printf("\nEnter Encrypted Text: ");
            scanf(" %[^\n]", encrypted_text);

            do {
                printf("\nEnter Key: ");
                if (scanf("%d", &key) != 1 || key < 0 || key > 25) {
                    printf("\nInvalid key. Please enter a number between 0 and 25.\n");
                    while (getchar() != '\n'); // clear input
                    key = -1; // force loop
                }
            } while (key < 0);
            // key = key % 26;

            textLength = strlen(encrypted_text);

            for (i = 0; i < textLength; i++){
                if((encrypted_text[i] >= 'A' && encrypted_text[i] <= 'Z') || (encrypted_text[i] >= 'a' && encrypted_text[i] <= 'z')){
                    char upper_case_text = toupper(encrypted_text[i]);
                    decrypted_text[i] = ((upper_case_text - 'A' - key + 26) % 26) +'A';
                } else {
                    decrypted_text[i] = encrypted_text[i];
                }

            }

            decrypted_text[textLength] = '\0';
            printf("Decrypted text: %s\n\n", decrypted_text);

        }
        


    } while (userChoice != 3);

    
    printf ("\n\n\n***************************************");
    printf("\n*       Message Portal (Offline)      *");
    printf ("\n***************************************");
    printf("\nGoodbye!\n");

    return 0;
    
}
