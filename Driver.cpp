/*****************************************************************
    Title:      Driver.cpp
    Date:       7-23-2023
    Author:     Zack Enright
    Purpose:    To demonstrate a Singly-Linked List solution for
    the fox chicken and grain puzzle game
******************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include "Bank.h"
using namespace std;

int main()
{
    //Print the welcome statment / game explination
    cout <<"        Welcome to Fox, Chicken, and Grain" << endl;
    cout << endl;
    cout << "A farmer must get his fox, chicken, and grain safely" << endl;
    cout << "across a river from the south bank to the north bank." << endl;
    cout << "The farmer can take at most one thing with him when" << endl;
    cout << "he makes a trip across. Unfortunately, if the farmer"  << endl;
    cout << "leaves the fox and the chicken together, the fox will " << endl;
    cout << "eat the chicken. If the farmer leaves the chicken " << endl;
    cout << "and the grain together, the chicken will eat the grain." << endl;
    cout << endl;
    cout << "Help the farmer by entering the name of what you " << endl;
    cout << "want him to carry on his next trip to the opposite bank." << endl;
    cout << "If you want the farmer to cross the river without " << endl;
    cout << "carrying anything, enter 'nothing' at the prompt." << endl;
        
    //creates 2 banks that will run in parallel
    BankList southBank;
    BankList northBank;

    //Creates output file that will record the run
    ofstream OutPutFile("OutPutFile.txt");

    //fill the list with the starting characters
    southBank.appendNode(0);
    southBank.appendNode(1);
    southBank.appendNode(2);

    //set/print farmer location
    FarmerLocation(0, OutPutFile);

    string userInput;
    bool playAgain = true;
    int turnCount = -1;

    //The repeatable part of the game is put into a loop
    while (playAgain)
    {
        //updates what turn number it is
        turnCount++;
        
        //print both starting lists
        cout << "\nSouth bank:\n";
        cout << southBank.displayList() << "\n\n";
        cout << "North bank:\n";
        cout << northBank.displayList() << "\n\n";

        //send each bank update to txt file
        OutPutFile << "\nSouth bank:\n";
        OutPutFile << southBank.displayList() << "\n\n";
        OutPutFile << "North bank:\n";
        OutPutFile << northBank.displayList() << "\n\n";

        //prompt user and store data into userInput
        cout << "What should the farmer take?: ";
        getline(cin, userInput);

        //sends promt and userinput to txt file
        OutPutFile << "What should the farmer take?: " << userInput << endl;

        //if the farmer is on the north bank update the bank accordingly
        if(turnCount % 2 == 0)
        {
            //if they choose to do nothing respond that the farmer brought nothing
            if (userInput == "nothing")
            {
                cout << "\nThe farmer takes nothing.\n";

                //sends same output to txt file
                OutPutFile << "\nThe farmer takes nothing.\n";
            }
            //else check what the input was and move the node accordingly
            else
            {
                
                if(userInput == "fox")
                {
                    southBank.deleteNode(0);
                    northBank.appendNode(0);
                }
                else if(userInput == "chicken")
                {
                    southBank.deleteNode(1);
                    northBank.appendNode(1);
                }
                else
                {
                    southBank.deleteNode(2);
                    northBank.appendNode(2);
                }
            cout << "\nThe farmer takes the " << userInput << " with him.\n\n";

            //sends same output to txt file
            OutPutFile << "\nThe farmer takes the " << userInput << " with him.\n\n";
            }
        }
        //else the farmer is on the south bank update the bank accordingly
        else
        {
            if (userInput == "nothing")
            {
                cout << "\nThe farmer takes nothing.\n\n";
            }
            else
            {
                if(userInput == "fox")
                {
                    northBank.deleteNode(0);
                    southBank.appendNode(0);
                }
                else if(userInput == "chicken")
                {
                    northBank.deleteNode(1);
                    southBank.appendNode(1);
                }
                else
                {
                    northBank.deleteNode(2);
                    southBank.appendNode(2);
                }
            cout << "\nThe farmer takes the " << userInput << " with him.\n\n";
            }
        }


        //Moves the farmer between banks
        if(turnCount % 2 == 0)
            FarmerLocation(1, OutPutFile);
        else
            FarmerLocation(0, OutPutFile);

        //checks if you lost by calling GameChecker()
        if((turnCount % 2 == 1) && (northBank.GameChecker(turnCount)))
        {
            //depending on what was brought over it changes the lose statment
            cout << "\n";
            if (userInput == "fox")
            {
                cout << "The chicken ate the grain";
                //sends same output to txt file
                OutPutFile << "The chicken ate the grain";
            }
            else if(userInput == "grain")
            {
                cout << "The fox ate the chicken";
                //sends same output to txt file
                OutPutFile << "The fox ate the chicken";
            }
            else
            {
                cout << "The fox ate the chicken";
                //sends same output to txt file
                OutPutFile << "The fox ate the chicken";
            }
            
            //prompts user that they lost and asks if they want to play again
            cout << "! You lost!\n\n";   
            cout << "Play again? (y/n): ";

            //sends same output to txt file
            OutPutFile << "! You lost!\n\n"; 
            OutPutFile << "Play again? (y/n): ";

            getline(cin, userInput);

            //checks if they want to play again, if not stops loop
            if (userInput != "y")
                playAgain = false;

            //reset both banks
            southBank.deleteNode(1);
            southBank.deleteNode(0);
            southBank.deleteNode(2);
            northBank.deleteNode(1);
            northBank.deleteNode(0);
            northBank.deleteNode(2);
            southBank.appendNode(0);
            southBank.appendNode(1);
            southBank.appendNode(2);
            FarmerLocation(0, OutPutFile);
            turnCount = -1;
        }
        else if((turnCount % 2 == 0) && (southBank.GameChecker(turnCount)))
        {
            //depending on what was brought over it changes the lose statment
            cout << "\n";
            if (userInput == "fox")
            {
                cout << "The chicken ate the grain";
                //sends same output to txt file
                OutPutFile << "The chicken ate the grain";
            }
            else if(userInput == "grain")
            {
                cout << "The fox ate the chicken";
                //sends same output to txt file
                OutPutFile << "The fox ate the chicken";
            }
            else
            {
                cout << "The fox ate the chicken";
                //sends same output to txt file
                OutPutFile << "The fox ate the chicken";
            }
            
            //prompts user that they lost and asks if they want to play again
            cout << "! You lost!\n\n";   
            cout << "Play again? (y/n): ";

            //sends same output to txt file
            OutPutFile << "! You lost!\n\n"; 
            OutPutFile << "Play again? (y/n): ";

            getline(cin, userInput);

            //checks if they want to play again, if not stops loop
            if (userInput != "y")
                playAgain = false;

            //reset both banks
            southBank.deleteNode(1);
            southBank.deleteNode(0);
            southBank.deleteNode(2);
            northBank.deleteNode(1);
            northBank.deleteNode(0);
            northBank.deleteNode(2);
            southBank.appendNode(0);
            southBank.appendNode(1);
            southBank.appendNode(2);
            FarmerLocation(0, OutPutFile);
            turnCount = -1;
        }
        //checks if the north bank has all three characters in it
        else if (northBank.getLength() == 3)
        {
            //prompts user that they won and asks if they want to play again
            cout << "\nCongratulations! You safely transported all the items to the north bank!\n\n";
            cout << "Play again? (y/n): ";

            //sends same output to txt file
            OutPutFile << "\nCongratulations! You safely transported all the items to the north bank!\n\n";
            OutPutFile << "Play again? (y/n): ";

            getline(cin, userInput);

            //checks if they want to play again, if not stops loop
            if (userInput != "y")
                playAgain = false;

            //reset both banks
            southBank.deleteNode(1);
            southBank.deleteNode(0);
            southBank.deleteNode(2);
            northBank.deleteNode(1);
            northBank.deleteNode(0);
            northBank.deleteNode(2);
            southBank.appendNode(0);
            southBank.appendNode(1);
            southBank.appendNode(2);
            FarmerLocation(0, OutPutFile);
            turnCount = -1;
        }
    }
    return 0;
}