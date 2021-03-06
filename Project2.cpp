/****************************************
Name: Alexander Martin
Date: 2/20/2020
Problem Number: 2
Hours spent solving this problem: 18
Instructor: Komogortsev, TSU
*****************************************/


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Global constants.
const int MAX_CLASS_SIZE = 40;

// Function prototypes
int LoadArrays(char[][11], char[][13], char[][7], int[][6], int &);
void SortScores(int[][6], int);
void CalcAverage(int[][6], double [], int);
void AssignLetterGrade(double[], char[], int, int &, int &, int &, int &, int &);
void OutputFile(char[][11], char[][13], char[][7], double[], char[], int, int,
                int, int, int, int);


int main ()
{

    int error_code = 0;
    int class_size = 0;
    int a_count = 0, b_count = 0, c_count = 0, d_count = 0, f_count = 0;


    char fname [MAX_CLASS_SIZE] [11];
    char lname [MAX_CLASS_SIZE] [13];
    char id [MAX_CLASS_SIZE] [7];
    int scores [MAX_CLASS_SIZE][6];
    double averages [MAX_CLASS_SIZE];
    char letter_grades [MAX_CLASS_SIZE];




    SortScores (scores, class_size);


    CalcAverage(scores, averages, class_size);


    AssignLetterGrade(averages, letter_grades, class_size, a_count, b_count,
                      c_count, d_count, f_count);


    OutputFile(fname, lname, id, averages, letter_grades, class_size, a_count,
               b_count, c_count, d_count, f_count);

    // Hooray!
    return 0;
}


int LoadArrays(char fname[][11], char lname[][13], char id[][7], int scores
[][6], int & class_size)
{

    ifstream fin;
    fin.open("student_input.dat");


    for (int j = 0; (!fin.eof()) && j < MAX_CLASS_SIZE; ++j)
    {
        while (isspace((char) fin.peek()) != 0)
        {
            fin.ignore();
        }
        for (int i = 0; i < 10; ++i)
        {
            fin >> fname[j][i];

            // Checking to see if we hit the end of fname.
            if (isspace((char) fin.peek()) != 0)
            {
                fname[j][i+1] = '\0';
                i += 100; // Breaking the loop.
            }

        }
        while (isspace((char) fin.peek()) != 0)
        {
            fin.ignore();
        }
        for (int i = 0; i < 12; ++i)
        {
            fin >> lname[j][i];

            // Checking to see if we hit the end of lname.
            if (isspace((char) fin.peek()) != 0)
            {
                lname[j][i+1] = '\0';
                i += 100; // Breaking the loop.
            }

        }
        while (isspace((char) fin.peek()) != 0)
        {
            fin.ignore();
        }
        for (int i = 0; i < 6; ++i)
        {
            fin >> id[j][i];

            // Checking to see if we hit the end of id.
            if (isspace((char) fin.peek()) != 0)
            {
                id[j][i+1] = '\0';
                i += 100; // Breaking the loop.
            }

        }
        while (isspace((char) fin.peek()) != 0)
        {
            fin.ignore();
        }
        for (int i = 0; i < 6; ++i)
        {
            fin >> scores[j][i];
            // Makes sure all scores are positive.
            if (scores[j][i] < 0)
            {
                return 1;
            }
            // Checking to see if we hit the last score.
            while (isspace((char) fin.peek()) != 0 && (char) fin.peek() != '\n')
            {
                fin.ignore();
            }
            // Display warning to console if only 5 grades
            if (((char) fin.peek() == '\n' || fin.eof()) && i == 4)
            {
                cout << "WARNING:\nStudent ID: " << id[j] << " will have"
                                                             " their average computed with only 5 grades.\n\n";
                i+= 100; // Break out loop.
            }
        }
        while (isspace((char) fin.peek()) != 0)
        {
            fin.ignore();
        }
        ++class_size;
    }
    //done
    fin.close();
    return 0;
}

/****************************************************************************
 SortScores -   This function receives the scores array and the actual class
              size. The function then sorts each row of the scores array
               so that the lowest score is element 0 and can easily be
                excluded from average calculations.
*/
void SortScores (int scores [][6], int class_size)
{
    // Declare needed variables.
    int min_index = 0;
    int min_value = 0;


    for (int i = 0; i < class_size; ++i) // i is rows in array
    {
        for (int j = 0; j < 5; ++j) // j is columns (individual scores)
        {
            min_index = j;
            min_value = scores [i][j];
            for (int k = j + 1; k < 6; ++k) // k is for checking values
            {
                if (scores [i][k] < min_value)
                {
                    min_index = k;
                    min_value = scores [i][k];
                }
            }
            scores [i][min_index] = scores [i][j];
            scores [i][j] = min_value;
        }
    }

    return;
}

/****************************************************************************
* CalcAverage - This function receives the scores array, the averages array,
                and the actual class size. It then moves through the scores
                array adding the scores (excluding the lowest score) and
                calculates the average and saves it to the averages array.
*/
void CalcAverage(int scores [][6], double averages [], int class_size)
{
    // Declare needed variables.
    double sum = 0.0;

    // Calculate averages
    for (int i = 0; i < class_size; ++i)
    {
        for (int j = 1; j < 6; j++) // Start j at 1 so lowest is always skipped
        {
            sum += scores [i][j];
        }

        averages [i] = (sum / 5.0);
        sum = 0.0;
    }

    return;
}

/****************************************************************************
* AssignLetterGrade - This function receives the averages array, the letter
                      grades array, and the actual class size. It reads each
                      average and assigns a corresponding letter grade.
*/
void AssignLetterGrade(double averages[], char letter_grades[], int class_size,
                       int & a, int & b, int & c, int & d, int & f)
{
    // Step through the averages and assign corresponding letter grades.
    for (int i = 0; i < class_size; ++i)
    {
        if (averages[i] >= 89.5)
        {
            letter_grades[i] = 'A';
            ++a;
        }
        else if (averages[i] >= 79.5)
        {
            letter_grades[i] = 'B';
            ++b;
        }
        else if (averages[i] >= 69.5)
        {
            letter_grades[i] = 'C';
            ++c;
        }
        else if (averages[i] >= 59.5)
        {
            letter_grades[i] = 'D';
            ++d;
        }
        else
        {
            letter_grades[i] = 'F';
            ++f;
        }
    }

    return;
}

/****************************************************************************
* OutputFile - This function receives the necessary parallel storage arrays
*               and outputs the information to the output file in the
*               required format.
*/
void OutputFile(char fname[][11], char lname[][13], char id[][7], double
average[], char letter_grade[], int class_size, int a, int b,
                int c, int d, int f)
{
    // Setup output file and decimal precision.
    ofstream fout;
    fout.open("student_results.dat");
    fout << setprecision(1) << fixed;

    // Time for the grand finale. Output everything to the file.
    fout << "Final Averages (" << class_size << " students)";
    fout << "\n\n";
    fout << "Last Name\t First Name\t ID\tAverage\t\tGrade\n";
    fout << "-----------------------------------------------------\n";
    for (int i = 0; i < class_size; ++i)
    {
        fout << setw(14) << left << lname [i];
        fout << setw(14) << left << fname [i];
        fout << id [i] << "\t ";
        fout << average [i] << "\t\t ";
        fout << letter_grade [i] << endl;
    }
    fout << "-----------------------------------------------------\n\n";
    fout << "Class Grade Distribution:\n";
    fout << "A's = " << a << endl;
    fout << "B's = " << b << endl;
    fout << "C's = " << c << endl;
    fout << "D's = " << d << endl;
    fout << "F's = " << f;

    // Cleanup.
    fout.close();
    return;
}