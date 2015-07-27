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
   //Store the word the user enters
   char enteredword[6];

   //Request the word to be used in the game
   printf("Enter a word (up to 6 letters): ");
   //Store the entered string in the array of char, note we se gets to increase safety
   gets(enteredword);

   //Show the initial messages to the user
   printf("\n");
   printf("Welcome to H A N G M A N\n");

   //Start the game routine
   play_hangman(enteredword);

   return 0;
}

//Play the handman game
int play_hangman(char enteredword[6])
{
    int lengthofword, index, guesscounter, won, runforever, foundcharinword;
    char onechar, guessedword[6], storechars[64];
    int gameover=0;
    int charcounter=0;
    int countfound=0;

    //Calculate the length of the entered word to show the proper number of '-'
    lengthofword = strlen(enteredword);
    //Print the notice to the user about the length of the word he has to guess
    printf("You must attempt to guess a word of lenth: %d\n",lengthofword);

    //Preset the values of the vector displaying the successful guesses and the '-' initially
    for (index=0;index<lengthofword;index++)
    {
        guessedword[index]='-';
    }

    //Print the empty word to the user display
    draw_hangman(guessedword,lengthofword,1);

    //Play the game until we won or the we lost
    won=0;//Reset the won variable to 0 (not won)
    while(gameover==0 && won==0)
    {
        charcounter++;
        runforever=0;
        while (runforever==0)
        {
            //Ask user for input and store it
            printf("Guess a character? ");
            gets(&onechar);
            runforever=1; //Hope we don't find it in the list
            for (index=0;index<charcounter;index++)
            {
                if (onechar == storechars[index])
                {
                  printf("You already used the character %c, please enter a new one.\n",onechar);//Notify user that this character is already used
                  runforever=0;//Set it back to 0 so we ask the user again for a new character
                  index=charcounter;
                }
            }
        }
        //As we loop until we found a valid char we now can store the accepted one, also increment the variable so we will store the next one in another location
        storechars[charcounter] = onechar;

        foundcharinword=0;//Reset to 0 so we know when it is found (=1)
        for (index=0;index<=5;index++)//Note the indices start with 0 and go to 5 for the 6th element
        {
           if (onechar==enteredword[index])
           {
               guessedword[index] = onechar;
               enteredword[index] = ' ';//Remove the character from the word so we don't find it again
               foundcharinword=1;
               countfound++;//increment found counter so we know when we are done
               if (countfound==lengthofword) won=1;//We won and can leave the loop
           }
        }

        //Draw the two lines for the game, hangman as well as the guessed characters
        draw_hangman(guessedword,lengthofword,1);
        draw_hangman(storechars,charcounter+1,2);

        if(foundcharinword==0)
        {
            printf("Incorrect guess: %d\n",charcounter);
        }

        if (charcounter>=10) gameover=1;
    }

    //Display the final result of the game
    if (won==1)
    {
        printf("You won, with %d guesses.\n",charcounter);
    }
    else
    {
        printf("You lost.\n");
    }

    return 0;
}

//Draw the current state of the word (including '-' if needed)
int draw_hangman(char printword[64],int lengthofword, int option)
{
    int index;//local index counter

    if (option==1)
    {
        printf("    ");//Draw the prefix spaces
    }

    if (option==2)
    {
        printf("Previous guesses: ");//Draw the line which is static
    }

    //Universal part of the draw function
    for (index=0;index<lengthofword;index++)
    {
       printf("%c",printword[index]);//Draw the characters of the guesses word
    }
    printf("\n");//Finish up with a new line char

    return 0;
}


