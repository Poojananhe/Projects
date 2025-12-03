#include<stdio.h>
#include<string.h>

// Function to encrypt the plaintext
void encrypt(char plaintext[], char key[]) {
    int i, j;
    int key_len = strlen(key);

    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = 'a' + (plaintext[i] - 'a' + (key[j % key_len] - 'a')) % 26;
            j++;
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = 'A' + (plaintext[i] - 'A' + (key[j % key_len] - 'A')) % 26;
            j++;
        }
    }
}

// Function to decrypt the ciphertext
void decrypt(char ciphertext[], char key[]) {
    int i, j;
    int key_len = strlen(key);

    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            ciphertext[i] = 'a' + (ciphertext[i] - 'a' - (key[j % key_len] - 'a') + 26) % 26;
            j++;
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            ciphertext[i] = 'A' + (ciphertext[i] - 'A' - (key[j % key_len] - 'A') + 26) % 26;
            j++;
        }
    }
}

int main() {
    char text[100];
    char key[100];
    int choice;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character

    printf("1. Encrypt\n2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(text, key);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decrypt(text, key);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}

