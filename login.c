#include <stdio.h>
#include <conio.h> // Required for getch()
#include <stdlib.h> // Required for atoi()

int main() 
{
    char pin_str[20]; // Array to store the PIN as characters
    int i = 0;
    char ch;

    int correct_pin = 12345678;
    int entered_pin;

    printf("Enter your PIN: ");

    // Loop to read characters until Enter is pressed
    while (1) {
        ch = getch(); // Read a character without displaying it

        if (ch == 13) { // 13 is the ASCII code for the Enter key
            pin_str[i] = '\0'; // End the string
            break; // Exit the loop
        } 
        else if (ch == 8) { // 8 is the ASCII code for the Backspace key
            if (i > 0) {
                i--;
                printf("\b \b"); // Erase the last asterisk from the screen
            }
        }
        else if (i < 19) { // Prevent buffer overflow
            pin_str[i] = ch;
            i++;
            printf("*"); // Print an asterisk for feedback
        }
    }

    // Convert the entered string of characters back to an integer
    entered_pin = atoi(pin_str);

    printf("\n"); // Move to a new line after input is complete

    // Compare the entered PIN with the correct PIN
    if (entered_pin == correct_pin) {
        printf("This is my first C program\n");
    } else {
        printf("Access denied!\n");
    }

    printf("\nPress any key to exit.");
    getch(); // Wait for a key press before closing

    return 0;
}