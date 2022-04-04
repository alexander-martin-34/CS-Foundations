#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//defining structure with having arrays
struct StudentArrayData {
//Define Arrays
string nonNumeric[3][9];
int numeric[3][2];
double numeric2[3][3][6];
char letterGrade[3][3];
};

StudentArrayData stuData;
int students;
//Define Floating point variables.
const double A_Score = 90;
const double B_Score = 80;
const double C_Score = 70;
const double D_Score = 60;
//open files.
ifstream idata;
ofstream odata;
int inputData(string[][9], int[][2], double[][3][6], char[][3]);
void outputData(string[][9], int[][2], double[][3][6], char[][3]);
void validateData(string[][9]);
void validateData(int[][2]);
void letGrade(string[][9], int[][2], double[][3][6], char[][3], StudentArrayData);
void writetoFile(StudentArrayData);


int main()
{

string nonNumeric[3][9];
int numeric[3][2];
double numeric2[3][3][6];
char letterGrade[3][3];

    //get number of students
    cout << "Enter the number of Students: ";
    cin >> students;
    //loop for student information
        while(students != 3)      // students != 3
        {
        cout << "Invalid range of students, please enter number less than or equal to 3" << endl;
        cin >> students;
        }
        inputData(nonNumeric, numeric, numeric2, letterGrade);
        outputData(nonNumeric, numeric, numeric2, letterGrade);
        validateData(nonNumeric);
        validateData(numeric);
        letGrade(nonNumeric, numeric, numeric2, letterGrade, stuData);
        writetoFile(stuData);
    return 0;
}



void validateData(string nonNumeric[][9])
{
    for(int j = 0; j < 3; j++)
{
//Heading for the Output File.

            //checking whether the students name is within a reasonable range.
                if(nonNumeric[j][1].length() > 100)
                {
                odata << "Student Name was too long" << endl;
                continue;
                }
                //checking whether the students address is in reasonable range.
                if(nonNumeric[j][2].length() > 100)
                {
                odata << "Student address was too long" << endl;
                continue;
                }

                if(nonNumeric[j][3].length() > 100)
                {
                odata << "Input was not in the valid range" << endl;
                break;
                }


                    if(nonNumeric[j][4].length() > 16)
                    {
                    odata << "Student telephone number was too long" << endl;
                    continue;
                    }

                    //11 is the max social number.
                    //checking whether the social is within a reasonable range.
                        if(nonNumeric[j][5].length() > 11)
                        {
                        odata << "Student social was too long" << endl;
                        continue;


}
}}


void validateData(int numeric[][2])
        {
        for(int j = 0; j < 3; j++)
        {
        //checking whether age is between 1 and 90
        if(numeric[j][0] < 90 || numeric[j][0] > 1)
        {
        odata << "Age was not in the valid range" << endl;
        break;
        }

        //checking whether number of years is between 1 and 90
        if(numeric[j][1] < 90 || numeric[j][1] > 1)
        {
        odata << "Number of years at Texas state was not in the valid range" << endl;
        break;
        }}}
int inputData(string nonNumeric[][9], int numeric[][2], double numeric2[][3][6], char lettergrade[][3]) //need all arrays
        {
        //reading from the input file.
            idata.open("Project6_A04702178_Input.txt");
            if(!idata)
            {
            cout << "Error in opening file" << endl;
            }
            for(int j = 0; j < 3; j++)
{
//Heading for the Output File.
            nonNumeric[j][0] = "Students Grade Sheet, Department of Computer Science, Texas State University";

                getline(idata, nonNumeric[j][1]);
                //checking whether the students name is within a reasonable range.

                getline(idata, nonNumeric[j][2]);
                //checking whether the students address is in reasonable range.

                getline(idata, nonNumeric[j][3]);

                getline(idata, nonNumeric[j][4]);

                getline(idata, nonNumeric[j][5]);

                idata >> numeric[j][0];

                idata >> numeric[j][1];


                    return 0;
            }
}

void letGrade(string nonNumeric[][9], int numeric[][2], double numeric2[][3][6], char lettergrade[][3], StudentArrayData stuData)
        {
            for(int j = 0; j < 3; j++)
            {
            //loop for courses
            for(int k = 0; k < 3; k++)
            {
            getline(idata, stuData.nonNumeric[j][6+k]);
            if(stuData.nonNumeric[j][6].length() > 11)
            {
            odata << "Course number was too large" << endl;
            continue;
            }
            stuData.numeric2[j][k][5] = 0;
            double percent =.1;
            //loop five tests
            for(int l = 0; l < 5; l++)
            {
            idata >> stuData.numeric2[j][k][l];
            if(stuData.numeric2[j][k][l] > 1.00 || stuData.numeric2[j][k][l] < 100.00)
            {
            odata << "Test score was not in valid range" << endl;
            break;
            }
            idata.ignore();
            //calculate grade
                stuData.numeric2[j][k][5] = stuData.numeric2[j][k][5] + (stuData.numeric2[j][k][l] * percent);
                percent += .05;
                }
                if(stuData.numeric2[j][k][5] >= A_Score)
                {
                stuData.letterGrade[j][k] = 'A';
                }
                else if(stuData.numeric2[j][k][5] >= B_Score)
                {
                stuData.letterGrade[j][k] = 'B';
                }
                else if(stuData.numeric2[j][k][5] >= C_Score)
                {
                stuData.letterGrade[j][k] = 'C';
                }
                else if(stuData.numeric2[j][k][5] >= D_Score)
                {
                stuData.letterGrade[j][k] = 'D';
                }
                else
                {
                stuData.letterGrade[j][k] = 'F';
                }
                }
            }
        }

void outputData(string nonNumeric[][9], int numeric[][2], double numeric2[][3][6], char lettergrade[][3]) //should have all of your arrays inside
{
odata.open("Project6_A04702178_Output.txt"); //Printing to the output file

}


        void writetoFile(StudentArrayData stuData)
        {
            for(int i = 0; i <3; i++)
            {
            odata << setw(32) << stuData.nonNumeric[i][0] << endl;
            odata << setw(32) << "Name of Student:" << "\t" << stuData.nonNumeric[i][1] << endl;
            odata << setw(32) << "Student ID:" << "\t" << stuData.nonNumeric[i][3] << endl;
            odata << setw(32) << "Age:" << "\t" << stuData.numeric[i][0] << endl;
            odata << setw(32) << "Address:" << "\t" << stuData.nonNumeric[i][2] << endl;
            odata << setw(32) << "Number of years at Texas State:" << "\t" << stuData.numeric[i][1] << endl;
            odata << setw(32) << "Telephone Number:" << "\t" << stuData.nonNumeric[i][4] << endl;
            odata << setw(32) << "Student Social Security #:" << "\t" << stuData.nonNumeric[i][5] << endl << endl;
                for(int k = 0; k < 3; k++)
                {
                odata << setw(32) << "Course #:" << " " << stuData.nonNumeric[i][6+k] << endl;
                    for(int j = 0; j < 5; j++)
                    {
                    odata << setw(30) << "Test #" << j + 1 << ":" << "\t" << stuData.numeric2[i][k][j] << endl;
                    }
                    odata << fixed << setw(32) << "Numerical Grade:" << "\t" << stuData.numeric2[i][k][5] << endl;
                    odata << setw(32) << "Letter Grade:" << "\t" << stuData.letterGrade[i][k] << endl;
                    if(stuData.numeric2[i][k][5] >= A_Score)
                   {
                    odata << setw(32) << "\t" << "Congratulations! Papa Bless!" << endl;
                    }
                    else if(stuData.numeric2[i][k][5] < D_Score)
                    {
                    odata << setw(32) << "\t" << "You can do better than this, Trust in the Fupa" << endl;
                    }
                    odata << endl << endl;
                    }
                    }
        idata.close();
        odata.close();
        }


