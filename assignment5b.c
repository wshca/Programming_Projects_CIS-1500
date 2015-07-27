// Assignment 5
// CIS*1500 - Introduction to Programming
//
// Name:
// StudentID:
//
// November 3rd 2012
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
   //Store the word the user enters
   char storedstring[7];

   //Player 1 enters the secret word
   printf("Enter a word (up to 6 letters): ");
   //save the string
   scanf("%6s",storedstring);

   //Show the first messages to the user who sets up the game
   printf("\n");
   printf("Welcome to H A N G M A N\n");

   //Start the game routine
   play_hangman(storedstring);

   return 0;
}

//Play the handman game
int play_hangman(char storedstring[7])
{
    int stringsize;
    int index;
    int enteragain;
    int foundcharinword;
    char onechar;
    char guessedword[7];
    char originalword[7];
    char lettersguessed[64];
    int playthegame=0;
    int countguesses=-1;
    int foundchar=0;
    int winner=0;
    int initone=0;

    //For display purpose determine the length of the string
    stringsize = strlen(storedstring);
    //Print out the first game message to the actual player
    printf("You must attempt to guess a word of lenth: %d\n",stringsize);

    for (index=0;index<stringsize;index++)
    {
        originalword[index]= storedstring[index];
    }


    //Set the fixed string to the default values
    for (index=0;index<stringsize;index++)
    {
        guessedword[index]='-';
    }

    //Print the intial word with just the '-'
    draw_hangman(guessedword,stringsize,0);

    //Play the game
    while(playthegame==0)
    {
        countguesses++;
        enteragain=0;
        while (enteragain==0)
        {
            printf("Guess a character? ");

            scanf("%1s",&onechar);
            enteragain=1;
            for (index=0;index<countguesses;index++)
            {
                if (onechar == lettersguessed[index])
                {
                  printf("You already used the character %c, please enter a new one.\n",onechar);
                  enteragain=0;
                  index=countguesses;
                }
            }
        }
        lettersguessed[countguesses] = onechar;

        foundcharinword=0;
        for (index=0;index<stringsize;index++)
        {
           if (onechar==storedstring[index])
           {
               guessedword[index] = onechar;
               storedstring[index] = '&';
               foundcharinword=1;
               foundchar++;
               if (foundchar>=stringsize) winner=1;

           }
        }
        draw_hangman(guessedword,stringsize,0);
        draw_hangman(lettersguessed,countguesses,1);

        if(foundcharinword==0)
        {
            draw_hangman(lettersguessed,countguesses,2);
        }

        if (countguesses>=9 || winner==1) playthegame=1;
    }

    print_result(winner, countguesses, originalword);

    return 0;
}

//Do the painting to the screen
int draw_hangman(char outputword[64],int wordsize, int option)
{
    int index;//local index counter

    if (option==0)
    {
        printf("    ");
    }

    if (option==1)
    {
        printf("Previous guesses: ");
        wordsize++;
    }

    if (option==2)
    {
        printf("Incorrect guess: %d",wordsize+1);
    }

    //General section
    if (option==1 || option==0)
    {
       for (index=0;index<wordsize;index++)
       {
          printf("%c",outputword[index]);
       }
    }

    printf("\n");

    return 0;
}
//Final results of the game shown to the user
int print_result(int winner, int numberofguesses, char storedstring[7])
{
    if (winner==1)
    {
        printf("You are the winner of the game with %d guesses.\n",numberofguesses+1);
    }
    else
    {
        printf("You lost the game. %d guesses were not enough for you to find the word %s.\n",numberofguesses+1,storedstring);
    }


}
