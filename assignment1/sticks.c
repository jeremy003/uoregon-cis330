#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int getUserChoice() {
    /* TODO: Prompt the user "Player 1: How many sticks do you take (1-3)?" and return
       an integer. Check that the value is valid (1, 2, or 3) and print an error if
       is not, then ask again until a valid number is entered. You can exit the program with
       exit(1);
     */
     int user_choice = 0;


     // Repeatedly prompt user for an integer until the entered number is between 1 and 3
     while (user_choice < 1 || user_choice > 3) {
       printf("Player 1: How many sticks do you take (1-3)? ");
       scanf("%d", &user_choice);

       // Consume char from buffer in case the user enters a char instead of integer. Prevents infinite loop.
       getchar();
     }

     return user_choice;
}

int getComputerChoice(int current_sticks) {

    /* get a pseudo-random integer between 1 and 3 (inclusive) */
    int rand_choice = rand() % 3 + 1;

    if (rand_choice > current_sticks) return current_sticks;

    printf("Computer picks %d stick(s).\n", rand_choice);

    /* Optionally replace with additional logic for the computer's strategy */

    return rand_choice;
}


int main(int argc, char** argv)
{
    int user, computer, number_sticks;


    srand (time(NULL)); /* for reproducible results, you can call srand(1); */

    printf("Welcome to the game of sticks!\n");
    printf("How many sticks are there on the table initially (10-100)? ");
    scanf("%d", &number_sticks);

    /* TODO: check that num_sticks is between 10 and 100 (inclusive) and print
                    an error and exit, if it is not. */

    if (number_sticks < 10 || number_sticks > 100) {
      printf("invalid number of sticks, exiting program\n");
      exit(1);
    }

    /* TODO: Main game loop:
      While some sticks remain:
        1. Human: Get number of sticks by calling getUserChoice
        2. Computer: get number of sticks by calling getComputerChoice
        3. Output the computer's choice, e.g., "Computer selects 3."
        3. Update number_sticks
        4. Print the current number of sticks, e.g., "There are 2 sticks on the board."
      After all sticks are gone, output the result of the game,
      e.g., "Computer wins." or "Computer loses."
     */

     // Repeat proccess while there are sticks remaining
     while (number_sticks > 0) {
       // Prompt user for number to take from sticks, subtract from current remaining sticks
       number_sticks -= getUserChoice();

       // Check if there are no remaining sticks. If so, computer wins.
       if (number_sticks <= 0) {
         printf("Computer wins.\n");
       } else {
         printf("Number of sticks remaining: %d\n", number_sticks);

         // Generate number of sticks the computer takes, subtract from current remaining sticks
         number_sticks -= getComputerChoice(number_sticks);

         // Check if there are no remaining sticks. If so, computer loses
         if (number_sticks <= 0) {
           printf("Computer loses.\n");
         } else {
           printf("Number of sticks remaining: %d\n", number_sticks);
         }
       }
     }

    return 0;
}
