#include <stdio.h>
#include <string.h>

void xor_encrypt(char *text, char *key, char *result) {
    int textLength = strlen(text);
    int keyLength = strlen(key);

    for (int i = 0; i < textLength; i++) {
        unsigned char x = text[i] ^ key[i % keyLength];
        sprintf(&result[i * 2], "%02X", x);  
    }
    result[textLength * 2] = '\0';
}

void xor_decrypt(char *hexText, char *key, char *result) {
    int hexLength = strlen(hexText);
    int textLength = hexLength / 2;
    int keyLength = strlen(key);

    for (int i = 0; i < textLength; i++) {
        unsigned int x;
        sscanf(&hexText[i * 2], "%2X", &x);   
        result[i] = (char)(x ^ key[i % keyLength]);
    }
    result[textLength] = '\0';
}

int main() {
    char text[1000], key[1000], encrypted_text[2000], decrypted_text[1000];
    int userChoice;

    printf("\n\n\n***************************************");
    printf("\n*       Message Portal (Online)       *");
    printf("\n***************************************");

    do {
        printf("\n What would you like to do? \n 1: Encrypt Text \n 2: Decrypt Text \n 3: Exit System");
        printf("\nEnter: ");

        if (scanf("%d", &userChoice) != 1) {
            while (getchar() != '\n');
            userChoice = 0;
            continue;
        }
        while (getchar() != '\n'); 

        if (userChoice == 1) {
            printf("Enter text: ");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = '\0';

            printf("Enter key: ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = '\0';

            xor_encrypt(text, key, encrypted_text);
            printf("\nEncrypted Text (Hex): %s \n", encrypted_text);

        } else if (userChoice == 2) {
            printf("Enter encrypted HEX text: ");
            fgets(encrypted_text, sizeof(encrypted_text), stdin);
            encrypted_text[strcspn(encrypted_text, "\n")] = '\0';

            printf("Enter key: ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = '\0';

            xor_decrypt(encrypted_text, key, decrypted_text);
            printf("\nDecrypted Text: %s \n", decrypted_text);
        }

    } while (userChoice != 3);

    printf("\n\n\n***************************************");
    printf("\n*       Message Portal (Offline)      *");
    printf("\n***************************************");
    printf("\nGoodbye!\n");

    return 0;
}
