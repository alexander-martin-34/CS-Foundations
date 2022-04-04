/* NAME: <Alexander Martin>  */

#include <iostream>
using namespace std;

int main() {

    int midi_chlorians;
    double age, iq, jedi_level;
    // TO-DO: Declare the rest of the variables (age, iq, jedi_level)

    // Prompt the user for midi-chlorian count and store:
    cout << "What is your midi-chlorian count?" << endl;
    cin >> midi_chlorians;
    cout << "What is your age?";
    cin >> age;
    cout << "What is your IQ?";
    cin >> iq;
    cout << "Your Jedi Level is " << ( midi_chlorians * age)/(90000- iq * iq);

    // TO-DO: Prompt for and store the user's age and iq:

    // TO-DO: Calculate and assign the user's Jedi level to the
    //        appropriate variable:

    // TO-DO: Display the user's Jedi Level to the console:

    // Exit the program:
    return 0;
}
