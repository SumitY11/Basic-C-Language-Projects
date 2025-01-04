/*Number Guessing Game
  Author: Sumit Yeotkar */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
    int random , guess ;
    int no_of_guess = 0;
    srand(time(NULL));

    printf("WELCOME TO NUMBER GUESSING GAME");
    random = rand() % 100 + 1;// Generates a Random Number between 1 to 100

    do{
        printf("\nPlease enter a Number between 1 to 100:");
        scanf("%d", &guess);
        no_of_guess++ ;

        if(guess < random){
            printf("Guess Larger Number. \n");
        }else if (guess > random){
            printf("Guess Smaller Number. \n");
        }else{
            printf("\nCongratulations!!! You Have Made a Correct Guess in %d Attempts \n", no_of_guess);
        }

    }while (guess != random);

    printf("THANKS FOR PLAYING\n");
    printf("Developed by : SUMIT YEOTKAR\n");
    printf("Email: sumityeotkar11@gmail.com");

}