// Assignment 3
// CIS*1500 - Introduction to Programming
//
// Name:
// StudentID:
//
// October 23rd 2012
//
#include <stdlib.h>  //standard library for a c program
#include <stdio.h>   //library for the input and output like printf and scanf
#include <time.h>    //time function later used for the random function

//Global Variable to make it simple
int winCounter;
int lostCounter;
int tieCounter;

int main()
{
    char classicExtended;
    int selection=0;

    //Ask user what version he wants to play
    printf("Do you want to play (C)lassic or (E)xtended version?\n");
    printf("Please choose C or E: ");
    scanf("%c",&classicExtended);         //get selection by the user
    selection = (int) classicExtended;    //convert input char into integer for comparison in the if statement

    if ((selection==99) || (selection==67)) //converted values for c=99,C=67
    {
        // Call the original Rock Paper Scissors function
        rpsFunction();
    }

    if ((selection==101) || (selection==69)) //converted values for e=101,E=69
    {
        // Call the extended Rock Paper Scissors Lizard Spock function
        rpslsFunction();
    }

    return 0;
}

// Classic version
int rpsFunction()
{
    int numberOfGames;
    int gameIndex;

    //Ask user how many games he wants to play and do the looping until done
    printf("Welcome to Rock-Paper-Scissors\n");
    printf("How many games do you want?\n");
    scanf("%d",&numberOfGames);
    printf("\n");

    for (gameIndex=1; gameIndex<numberOfGames+1; gameIndex++)
    {
        rpsFunctionSub(gameIndex);//call the actual game routine
    }

    printf("The player won: %d out of %d games.\n",winCounter,numberOfGames);
    printf("The computer won: %d out of %d games.\n",lostCounter,numberOfGames);
    printf("There where %d ties out of %d games.\n",tieCounter,numberOfGames);

    return 0;
}

// Subroutine of the classic function
int rpsFunctionSub(int gameIndex)
{
    int playerChoice;    //Store the player's choice
    int computerChoice;  //Store the computer's choice

    // Present the game and request input
    printf("Game number %d\n",gameIndex);
    printf("3=Rock,2=Scissors,1=Paper\n");
    printf("What is your choice?\n");
    scanf("%d",&playerChoice);

    // Generate random number for answer by computer player
    srand(time(NULL));//reinitalize the random number every time we access it
    computerChoice = (rand() % 3) + 1;

    // Tell the player the computer's selection
    printf("This is my choice: ");
    if (computerChoice==1)
    {
        printf("paper\n");
    }
    if (computerChoice==2)
    {
        printf("scissors\n");
    }
    if (computerChoice==3)
    {
        printf("rock\n");
    }

    //Draw case
    if (playerChoice==computerChoice)
    {
        printf("Tie Game - No Winner\n");
        tieCounter++;
    }
    //Player wins the game
    if ((playerChoice==3 && computerChoice==2) || (playerChoice==2 && computerChoice==1) || (playerChoice==1 && computerChoice==3))
    {
        printf("You Win!\n");
        winCounter++;
    }
    //Computer wins the game
    if ((playerChoice==3 && computerChoice==1) || (playerChoice==2 && computerChoice==3) || (playerChoice==1 && computerChoice==2))
    {
        printf("You Lost!\n");
        lostCounter++;
    }

    printf("\n");

    return 0;
}


// Extended version with Lizard and Spock
int rpslsFunction()
{
    int numberOfGames;
    int gameIndex;


    //Ask user how many games he wants to play and do the looping until done
    printf("Welcome to Rock-Paper-Scissors-Lizard-Spock\n");
    printf("How many games do you want?\n");
    scanf("%d",&numberOfGames);
    printf("\n");

    for (gameIndex=1; gameIndex<numberOfGames+1; gameIndex++)
    {
        rpslsFunctionSub(gameIndex);//call the actual game routine
    }

    printf("The player won: %d out of %d games.\n",winCounter,numberOfGames);
    printf("The computer won: %d out of %d games.\n",lostCounter,numberOfGames);
    printf("There where %d ties out of %d games.\n",tieCounter,numberOfGames);

    return 0;
}

// Subroutine of the extended Spock version of the game
int rpslsFunctionSub(int gameIndex)
{
    int playerChoice;    //Store the player's choice
    int computerChoice;  //Store the computer's choice

    // Present the game and request input
    printf("Game number %d\n",gameIndex);
    printf("5=Spock,4=Lizard,3=Rock,2=Scissors,1=Paper\n");
    printf("What is your choice?\n");
    scanf("%d",&playerChoice);

    // Generate random number for answer by computer player
    srand(time(NULL));//reinitalize the random number every time we access it
    computerChoice = (rand() % 5) + 1;

    // Tell the player the computer's selection
    printf("This is my choice: ");
    if (computerChoice==1)
    {
        printf("paper\n");
    }
    if (computerChoice==2)
    {
        printf("scissors\n");
    }
    if (computerChoice==3)
    {
        printf("rock\n");
    }
    if (computerChoice==4)
    {
        printf("lizard\n");
    }
    if (computerChoice==5)
    {
        printf("Spock\n");
    }

    //Draw case
    if (playerChoice==computerChoice)
    {
        printf("Tie Game - No Winner\n");
        tieCounter++;
    }

    if (playerChoice==1)
    {
        if (computerChoice==3 || computerChoice==5)
        {
            printf("You Win!\n");
            winCounter++;
        }
        else
        {
            printf("You Lost!\n");
            lostCounter++;
        }
    }

    if (playerChoice==2)
    {
        if (computerChoice==1 || computerChoice==4)
        {
            printf("You Win!\n");
            winCounter++;
        }
        else
        {
            printf("You Lost!\n");
            lostCounter++;
        }
    }

    if (playerChoice==3)
    {
        if (computerChoice==2 || computerChoice==4)
        {
            printf("You Win!\n");
            winCounter++;
        }
        else
        {
            printf("You Lost!\n");
            lostCounter++;
        }
    }

    if (playerChoice==4)
    {
        if (computerChoice==1 || computerChoice==5)
        {
            printf("You Win!\n");
            winCounter++;
        }
        else
        {
            printf("You Lost!\n");
            lostCounter++;
        }
    }

    if (playerChoice==5)
    {
        if (computerChoice==2 || computerChoice==3)
        {
            printf("You Win!\n");
            winCounter++;
        }
        else
        {
            printf("You Lost!\n");
            lostCounter++;
        }
    }

    printf("\n"); //add a new line to the end

    return 0;
}

