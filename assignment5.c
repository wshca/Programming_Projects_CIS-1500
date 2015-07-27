// Assignment 5
// CIS*1500 - Introduction to Programming
//
// Name:
// StudentID:
//
// November 3rd 2012
//
#include <stdlib.h>  //standard library for a c program
#include <stdio.h>   //library for the input and output like printf and scanf
#include <string.h>

int main()
{
   char localword[6];
   int wordlength;

   //Ask user to enter the word
   printf("Enter a word (up to 6 letters): ");
   gets(localword);//For security reasons we use fgets over scanf (which will return a warning)
   wordlength = strlen(localword);

   //Welcome message
   printf("\nWelcome to H A N G M A N\n");

   //play the actual game
   printf("You must attempt to guess a word of lenth: %d\n",wordlength);
   play_hangman(localword,wordlength);

   return 0;
}

//Play the hangman with the user
int play_hangman(char localword[6],int wordlength)
{
    int numberofguesses=1;
    char partialword[6];
    char guessedchars[256];
    char onechar;
    int numberofchar=0;
    int index;
    int found;
    int countfound=0;
    int reprompt=0;

    //preset the partial word
    for (index=0;index<wordlength;index++)
    {
        partialword[index]='-';
    }

    while(numberofguesses<=10)
    {
        //Draw the current hangman (or the word guessed so far
        draw_hangman(partialword,wordlength);

        numberofchar++;
        //Ask for char and do some work with it
        reprompt=0;
        while (reprompt==0)
        {
            printf("Guess a character? ");
            gets(&onechar);
            //This section catches the double input of char and ask for reenter
            for (index=0;index<numberofchar;index++)
            {
                if (onechar == guessedchars[index])
                {
                    printf("You already used the character %c, please enter a new one.\n",onechar);
                }
                else
                {
                    reprompt=1;
                }
            }
        }
        guessedchars[numberofchar] = onechar;

        //Draw the current guessed characters
        draw_guessword(guessedchars,numberofchar);
        //Check if the char is one of the existing ones
        found=0;
        for (index=0;index<6;index++)
        {
           if (onechar==localword[index])
           {
               partialword[index] = onechar;
               localword[index] = '@';
               found=1;
               countfound++;
               if (countfound==wordlength) numberofguesses=99;//if we found all chars, we are done
           }
        }

        if(found==0)
        {
            //Guess was wrong, so count up and print message to user
            numberofguesses++;//increment the counter
            printf("Incorrect guess: %d\n",numberofguesses);
        }


    }

    return numberofguesses;
}

int draw_hangman(char partialword[6],int wordlength)
{
    int index;

    printf("    ");
    for (index=0;index<wordlength;index++)
    {
       printf("%c",partialword[index]) ;
    }
    printf("\n");

    return 0;
}

//Draw the current status of the game
int draw_guessword(char guessedchars[256],int numberofchar)
{
    int index;

    printf("Previous guesses: ");
    for (index=0;index<=numberofchar;index++)
    {
       printf("%c",guessedchars[index]) ;
    }
    printf("\n");

    return 0;
}
