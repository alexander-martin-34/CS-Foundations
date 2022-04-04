/* NAME: <Alexander Martin>  */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int user_num;  //user's choice
    int comp_num;  //computer's choice

    // Generate the computer's choice randomly:
    srand(time(NULL));
    comp_num = rand() % 3 + 1;

    // Get the user's choice:
    cout << "Natural Selection Game" << endl
         << " 1. Orange" << endl
         << " 2. Blue" << endl
         << " 3. Yellow" << endl
         << "Enter a number : ";
    cin >> user_num;
    cout << endl;


    // TODO: Determine if the user wins, loses, or ties (or enters invalid input):

    if (comp_num == 1 && user_num == 2)
    {
        cout << "Orange beats Blue! You Lose";
    }
    else if (comp_num == 2 && user_num == 3)
        cout << "Blue beats Yellow! You Lose";
    else if (comp_num == 3 && user_num == 1)
        cout << "Yellow beats Orange! You Lose";
    else if (comp_num == 2 && user_num == 1)
        cout << "Orange beats Blue! You Win!";
    else if (comp_num == 3 && user_num == 2)
        cout << "Blue beats Yellow! You Win!";
    else if (comp_num == 1 && user_num == 3)
        cout << "Yellow beats Orange! You Win!";
    else if (comp_num == 1 && user_num == 1)
        cout << "You both chose Orange! Its a tie!";
    else if (comp_num == 2 && user_num == 2)
        cout << "You both chose Blue! Its a tie!";
    else if (comp_num == 3 && user_num == 3)
        cout << "YOu both chose Yellow! Its a tie!";
    else if (user_num != 1, 2, 3)
    {
        cout << "Invalid Input. Terminating Program.";
        return 0;
    }



    // Exit the program:
    return 0;
}
