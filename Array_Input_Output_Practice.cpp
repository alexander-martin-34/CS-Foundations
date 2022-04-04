    #include <iostream>
    #include <iomanip>
    #include <string>
    #include <cmath>
    #include <fstream>
    using namespace std;

    int main ()

    {
        //declaring the constant integer values for the letter grade needed later in the code
        const int A_SCORE = 90,
                  B_SCORE = 80,
                  C_SCORE = 70,
                  D_SCORE = 60;
        //declaring variables
        int age, years, numofstuds;
        double test1, test2, test3, test4, test5, finalGrade;
        char letterGrade;
        string name, address, telephone, socialsecurity;

        //opening the input and output files to allow information to be taken from one and assigned into another
        ifstream idata;
        idata.open("Project2_A04702178_Input.txt");
        ofstream odata;
        odata.open("Project2_A04702178_Output.txt");

        // fallback if input isnt opened correctly
        if (!idata)
        {
            cout << "cant open the input file successfully";
            return 1;
        }

        //Declaring the input values and assigning them to there respective variable
        while (numofstuds <= 3)
          {
            idata >> ws;
            getline(idata, name);
            idata >> age;
            idata.ignore();
            getline(idata, address);
            idata >> years;
            idata.ignore();
            getline(idata, telephone);
            idata >> socialsecurity;
            idata >> test1;
            idata >> test2;
            idata >> test3;
            idata >> test4;
            idata >> test5;
            numofstuds++;


        // using odata as our output name couting to the output file the desired values based upon the the correlating classification
            odata << setw(44) << "Student Grade Sheet" << endl;
            odata << right << setw(32) <<  "Name of Student:" << "\t" << left << name << endl;
            odata << right << setw(32) << "Age:" << "\t" << left << age << endl;
            odata << right << setw(32) << "Address:" << "\t" << left << address << endl;
            odata << right << setw(32) << "Number of years at Texas State:" << "\t" << left << years << endl;
            odata << right << setw(32) << "Telephone Number:" << "\t" << left << telephone << endl;
            odata << right << setw(32) << "Student Social Security #:" << "\t" << left << socialsecurity << endl;
            odata << right << setw(32) << "Test #1:" << "\t" << left << fixed << setprecision(1) << test1 << endl;
            odata << right << setw(32) << "Test #2:" << "\t" << left << fixed << setprecision(1) << test2 << endl;
            odata << right << setw(32) << "Test #3:" << "\t" << left << fixed << setprecision(1) << test3 << endl;
            odata << right << setw(32) << "Test #4:" << "\t" << left << fixed << setprecision(1) << test4 << endl;
            odata << right << setw(32) << "Final Exam:" << "\t" << left << fixed << setprecision(1)<< test5 << endl;
            finalGrade = (test1 * .10) + (test2  * .15) + (test4 * .25) + (test5 * .30) + (test3 * .20);
            odata << right << setw(32) << "Numerical Grade:" << "\t" << left << fixed << setprecision(1) << finalGrade << endl;
          }
        // Using if else statements to assign the correct letter grade to the corresponding numerical grade
        if (finalGrade >= A_SCORE)
        {
            letterGrade = 'A';

        }
        else if (finalGrade >= B_SCORE)
        {
            letterGrade = 'B';
        }
        else if (finalGrade >= C_SCORE)
        {
            letterGrade = 'C';
        }
        else if (finalGrade >= D_SCORE)
        {
            letterGrade = 'D';
        }

        odata << right << setw(32) <<  "Letter Grade:" << "\t" << left << letterGrade << endl;

        if (finalGrade >= 95)
        {
            odata << "\t" << "Great Moves Keep Up the Good Work Killer, Papa Bless!" << endl;
        }
        else if (finalGrade <70l)
        {
            odata << "\t" <<  "Come Now You Can Do Better Than This Chief!" << endl;
        }





        // closing the opened input and output files
        idata.close();
        odata.close();

        //RETURN CONTROL TO PROGRAM
        return 0;

    }
