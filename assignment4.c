// Assignment 4
// CIS*1500 - Introduction to Programming
//
// Name:
// StudentID:
//
// November 3rd 2012
//
#include <stdlib.h>  //standard library for a c program
#include <stdio.h>   //library for the input and output like printf and scanf
#include <time.h>    //time function later used for the random function

//Global Variable to make it simple
int gamematrix[3];//Store the game in a vector as we only have to know how many stones are in a row

int main()
{
   int countNumberOfStones = 1;
   int playernumber = 1;

   printf("Welcome to the Game of Nim\n");//Display welcome message
   printf("Enter the number of rocks in each row: ");//Ask user for initial game status
   scanf("%d %d %d",&gamematrix[0],&gamematrix[1],&gamematrix[2]);//Note that matrix index starts with 0 for the first line

   draw_nim(); //Draw the game

   while (countNumberOfStones>0)
   {
       play_nim(playernumber);//Call the game function

       draw_nim(); //Draw the game

       countNumberOfStones = gamematrix[0] + gamematrix[1] + gamematrix[2];//Count the number of stones in the game left

       if (countNumberOfStones>0)//Only change player number if we are not done
       {
          if (playernumber==1)//Rotate the playernumber after the game
          {
              playernumber=2;
          }
          else
          {
              playernumber=1;
          }
       }
   }//End of the while loop
   printf("Player %d Wins!\n",playernumber);

   return 0;
}

//Play the game
int play_nim(int playernumber)
{
    int rownumber;
    int numberofrocks;
    int reprompt = 1;

    //Ask user for his choice
    while (reprompt==1)
    {
       printf("Player %d - Row and number of rocks: ",playernumber);
       scanf("%d %d",&rownumber,&numberofrocks);

       //Check input, if input makes sense, go ahead with the game
       if (rownumber < 4)
       {
           if (numberofrocks < gamematrix[rownumber-1]+1) //do it in two loop so we don't get a runtime error
           {
               //Do the math (remove the stones)
               gamematrix[rownumber-1] = gamematrix[rownumber-1]-numberofrocks;
               //End loop as the input was valid
               reprompt = 0;
           }
       }
       if (reprompt==1) printf("Invalid move. Try again.\n");
    }

    return 0;
}

//Draw the current state of the program
int draw_nim()
{
    //Local variables
    int i;
    int rownumber;
    int stonenumber;

    printf("\n");//Draw an empty line
    for (rownumber=0;rownumber<3;rownumber++)
    {
        //Draw line
        printf("ROW %d: ",rownumber+1);//Draw first section of the line (note that we count with 0 but display 1)
        for (stonenumber=0;stonenumber<gamematrix[rownumber];stonenumber++)
        {
            printf("O");//Draw for every element in the matrix an O
        }
        printf("\n");//Draw now the new line character
    }
    printf("\n");//Draw an empty line

    return 0;
}
