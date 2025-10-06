#include <stdio.h>
#include <string.h>
#include <ctype.h>

int modInverse(int a, int m){
    a = a % m;
    for (int x = 1; x < m; x++){
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

void encryption(char *text, int keyMultiplier, int key, char *result){
    int textLength = strlen(text);

    for (int i = 0; i < textLength; i++){
        if((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')){
            char upper_case_text = toupper(text[i]);
            result[i] = ((keyMultiplier * (upper_case_text - 'A') + key) % 26) + 'A';
        } else {
            result[i] = text[i];
        }
    }
    result[textLength] = '\0';
}

void decryption(char *text, int keyMultiplier, int key, char *result){
    int inv = modInverse(keyMultiplier, 26);
    if(inv == -1){
        printf("Error: Key multiplier has no modular inverse. Decryption impossible.\n");
        result[0] = '\0';
        return;
    }

    int textLength = strlen(text);
    for (int i = 0; i < textLength; i++){
        if((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')){
            char upper_case_text = toupper(text[i]);
            result[i] = (inv * ((upper_case_text - 'A') - key + 26) % 26) + 'A';
        } else {
            result[i] = text[i];
        }
    }
    result[textLength] = '\0';
}

int main(){
    char text[1000], encrypted_text[1000], decrypted_text[1000];
    int keyMultiplier, userChoice, key;

    printf("\n\n\n***************************************");
    printf("\n*       Message Portal (Online)       *");
    printf("\n***************************************");

    do{
        do{
            printf("\n What would you like to do? \n 1: Encrypt Text \n 2: Decrypt Text \n 3: Exit System");
            printf("\nEnter: ");

            if(scanf("%d", &userChoice) != 1 || userChoice < 1 || userChoice > 3){
                printf("Invalid Selection.\n");
                while(getchar() != '\n');
                userChoice = 0;
            } else {
                while(getchar() != '\n');
            }
        } while(userChoice == 0);

        if(userChoice == 1){
            printf("Enter text: ");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = '\0';

            printf("Enter Key Multiplier: ");
            while(scanf("%d", &keyMultiplier) != 1){
                printf("Invalid Input, enter a number: ");
                while(getchar() != '\n');
            }

            printf("Enter Key: ");
            while(scanf("%d", &key) != 1){
                printf("Invalid Input, enter a number: ");
                while(getchar() != '\n');
            }
            while(getchar() != '\n');

            encryption(text, keyMultiplier, key, encrypted_text);
            printf("Encrypted Text: %s\n", encrypted_text);
        }

        if(userChoice == 2){
            printf("Enter text to decrypt: ");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = '\0';

            printf("Enter Key Multiplier: ");
            while(scanf("%d", &keyMultiplier) != 1){
                printf("Invalid Input, enter a number: ");
                while(getchar() != '\n');
            }

            printf("Enter Key: ");
            while(scanf("%d", &key) != 1){
                printf("Invalid Input, enter a number: ");
                while(getchar() != '\n');
            }
            while(getchar() != '\n');

            decryption(text, keyMultiplier, key, decrypted_text);
            if(decrypted_text[0] != '\0')
                printf("Decrypted Text: %s\n", decrypted_text);
        }

    } while(userChoice != 3);

    return 0;
}
