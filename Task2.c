#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Flag { False = 0, True = 1 };

struct User {
    char username[20];
    char password[20];
    enum Flag flag;
};

struct User users[100];
int userCount = 0;

void registerUser() {
    if (userCount < 100) {
        struct User newUser;

        printf("Enter a username: ");
        scanf("%s", newUser.username);

        printf("Enter a password: ");
        scanf("%s", newUser.password);

        printf("Enter a flag (True/1 or False/0): ");
        char flagInput[6]; // "True" or "False"
        scanf("%s", flagInput);

        for (int i = 0; flagInput[i]; i++) {
            flagInput[i] = tolower(flagInput[i]);
        }

        if (strcmp(flagInput, "true") == 0) {
            newUser.flag = True;
        } else {
            newUser.flag = False;
        }

        users[userCount++] = newUser;
        printf("Registration successful!\n");
    } else {
        printf("Registration Failed!\n");
    }
}


int loginUser(const char *username, const char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if (users[i].flag == True) {
                return 1; // User found and active
            } else {
                return 0; // User found but not active
            }
        }
    }
    return -1; // User not found
}

int main() {
    int choice;
    char username[20];
    char password[20];

    while (1) {
        printf("\n1. Register\n2. Login\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                printf("Enter your username: ");
                scanf("%s", username);

                printf("Enter your password: ");
                scanf("%s", password);

                int loginResult = loginUser(username, password);
                if (loginResult == 1) {
                    printf("Login successful!\n");
                } else if (loginResult == 0) {
                    printf("Login failed. User not active.\n");
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
