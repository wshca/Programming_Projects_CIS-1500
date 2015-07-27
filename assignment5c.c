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
   char hiddenword[7];
   int wordsize;

   printf("Enter a word (up to 6 letters): ");
   scanf("%s",hiddenword);
   wordsize = strlen(hiddenword);

   printf("\n");
   printf("Welcome to H A N G M A N");
   printf("\n");

   play_hangman(hiddenword, wordsize);

   return 0;
}

//Play the handman game
int play_hangman(char hiddenword[7], int wordsize)
{
    int index;
    int runloop1;
    int foundcharinword;
    char storechar;
    char guessedword[7];
    char originalword[7];
    char lettersguessed[64];
    int playthegame=0;
    int countguesses=-1;
    int foundchar=-2;
    int playerwins=0;

    for (index=0;index<wordsize;index++)
    {
        guessedword[index] = '-';
    }

    for (index=0;index<wordsize;index++)
    {
        originalword[index] = hiddenword[index];
    }

    printf("You must attempt to guess a word of lenth: %d\n",wordsize);
    draw_hangman(guessedword,wordsize,0);

    while(playthegame==0)
    {
        countguesses++;
        runloop1=0;
        while (runloop1==0)
        {
            printf("Guess a character? ");
            gets(&storechar);
            runloop1=1;
            for (index=0;index<countguesses;index++)
            {
                if (storechar == lettersguessed[index])
                {
                  printf("The character %c is already in the list, please enter a new one.\n",storechar);
                  runloop1=0;
                  index=countguesses;
                }
            }
        }
        lettersguessed[countguesses] = storechar;

        foundcharinword=0;
        for (index=0;index<7;index++)
        {
           if (storechar==hiddenword[index])
           {

               guessedword[index] = storechar;
               hiddenword[index] = '?';
               foundcharinword=1;
               foundchar++;
               if (foundchar>=wordsize) playerwins=1;
           }
        }

        draw_hangman(guessedword,wordsize,0);
        draw_hangman(lettersguessed,countguesses,1);

        if(foundcharinword==0)
        {
            draw_hangman(lettersguessed,countguesses,2);
        }

        if(countguesses>=10 || playerwins==1)
        {
            playthegame=1;
        }
    }

    printextralines(playerwins, countguesses, originalword);

    return 0;
}

//Do the painting to the screen
int draw_hangman(char outputword[64],int wordsize, int caseprint)
{
    int index;

    switch(caseprint){
    case 0:
       printf("    ");
    break;
    case 1:
       printf("Previous guesses: ");
       wordsize++;
    break;
    case 2:
       printf("Incorrect guess: %d",wordsize);
    break;
    }

    if (caseprint !=2)
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
int printextralines(int playerwins, int numberoftries, char hiddenword[7])
{
    if (playerwins==1)
    {
        printf("The player wins the game with %d tries.\n",numberoftries);
    }
    else
    {
        printf("The player lost the game. %d tries were not enough to get to the word %s.\n",numberoftries,hiddenword);
    }
}
