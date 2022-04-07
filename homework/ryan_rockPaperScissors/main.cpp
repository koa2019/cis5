/*
 * File:   main.cpp
 * Author: Ryan Baella
 * Created on March 22nd, 2022, 10:40 AM
 * Purpose:  Rock Paper Scissors
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <cstring>   //String Library
using namespace std;

int main(int argc, char** argv) {
    //Set the Random Number Seed

    //Declare Variables
    char P1, P2; //The 2 players in the game
    string winner; //Winner

    //Initial Variables
    cout << "Rock Paper Scissors Game" << endl;
    cout << "Input Player 1 and Player 2 Choices" << endl;
    cin>>P1;
    cin>>P2;

    // conditional checks if P1's input is lowercase and then
    // reassigns P1's value to its corresponding capital letter
    if (P1 == 'r') {
        P1 = 'R';
    } else if (P1 == 's') {
        P1 = 'S';
    } else if (P1 == 'p') {
        P1 = 'P';
    }

    // conditional checks if P2's input is lowercase and then
    // reassigns P2's value to its corresponding capital letter    
    if (P2 == 'r') {
        P2 = 'R';
    } else if (P2 == 's') {
        P2 = 'S';
    } else if (P2 == 'p') {
        P2 = 'P';
    }


    //Map the Inputs to the Outputs
    if (P1 == P2)winner = "Nobody wins.";

        /*  else if (P1 == 'P') {
                     if (P2 == 'S') winner = "Scissors cuts paper.";
            }   
         */
        // this code is a translation of the code above on lines 61-63
    else if ((P1 == 'P') && P2 == 'S') {
        winner = "Scissors cuts paper.";
    }
        /*    else if (P1 == 'P') {
                if (P2 == 'R') winner = "Paper covers rock.";
            }
         */
        // this code is a translation of the code above on lines 71-73
    else if ((P1 == 'P') && P2 == 'R') {
        winner = "Paper covers rock.";
    }
        // change the next 4 else if expressions below, 
        // so they look similar to my code above
        // once you get your code working. Delete any code you don't need
        // and format its spacing
    else if (P1 == 'R') {
        if (P2 == 'P') winner = "Paper covers rock.";
    }
    else if (P1 == 'R') {
        if (P2 == 'S') winner = "Rock breaks scissors.";
    }
    else if (P1 == 'S') {
        if (P2 == 'R') winner = "Rock breaks scissors.";
    }
    else if (P1 == 'S') {
        if (P2 == 'P') winner = "Scissors cuts paper.";
    } else {
        cout << "Invalid entry";
    }

    // DELETE all of your lowercase conditionals  below because 
    // we converted the inputs into capital letters

    /*    else if (P1 == 's') {
            if (P2 == 'p')winner = "Scissors cuts paper.";
            else winner = "Scissors cuts paper.";
        } 
        else if (P1 == 's') {
            if (P2 == 'r')winner = "Rock breaks scissors.";
            //else winner = "Rock breaks scissors.";
        } 
        else if (P1 == 'p') {
            if (P2 == 's')winner = "Scissors cuts paper.";
            //else winner = "Paper covers rock.";
        } 
        else if (P1 == 'p') {
            if (P2 == 'r')winner = "Paper covers rock.";
            //else winner = "Paper covers rock.";
        } 
        else if (P1 == 'r') {
            if (P2 == 'p')winner = "Paper covers rock.";
            //else winner = "Rock breaks scissors.";
        } 
        else if (P1 == 'r') {
            if (P2 == 's')winner = "Rock breaks scissors.";
            //else winner = "Scissors cuts paper.";
        } 
     */

    //Display the Inputs and Outputs
    cout << winner;

    //Exit the code
    return 0;
}