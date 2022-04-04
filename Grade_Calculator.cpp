// Project #3
// Professor Ali - CS 1428, Section #254 - March 7, 2019
// This program will calculate the grades of 3 courses for 3 students
// Last modified March 6,2019

  #include <iostream>
  #include <iomanip>
  #include <string>
  #include <fstream>
  using namespace std;

  int main ()

  {
      //declaring the constant integer values for the letter grade needed later in the code
      const double A_SCORE = 90.0,
                   B_SCORE = 80.0,
                   C_SCORE = 70.0,
                   D_SCORE = 60.0;
      const double F_SCORE = 0.0;
      //declaring variables
      int age, years, num_of_students;
      double test1, test2, test3, test4, test5, finalGrade;
      char letterGrade;
      string name, address, telephone, socialsecurity, courses, congrats_note, warning_note, header;

      //opening the input and output files to allow information to be taken from one and assigned into another
      ifstream idata;
      idata.open("Project3_A04702178_Input.txt");
      ofstream odata;
      odata.open("Project3_A04702178_Output.txt");

      // fallback if input isnt opened correctly
      if (!idata)
      {
          cout << "cant open the input file successfully";
          return 1;
      }

      getline(idata, congrats_note);
      if(congrats_note.length()>100)
      {
          cout <<"The string exceeds the range";
      }


      getline(idata, warning_note);
      if(warning_note.length()>100)
      {
          cout << "The string exceeds the range";
      }


      getline(idata, header);
      if(header.length()>40)
      {
          cout << "The string exceeds the range";
      }

        //setting up do while loop to validate that a number of at least 3 is inputted otherwise the program cannot run
      do
      {
          cout << "How many students are being calculated?" << " ";
          cin >> num_of_students;

          if(num_of_students < 3)
      {
          cout << "The number of students needs to be at least 3";
      }

      }
      while (num_of_students < 3);



        //establishing an outer for loop to read the input string variables for each of the 3 students
          for (int count=1; count<=num_of_students; count++)
          {
              odata << setw(48) << header << endl;

                //using getline to read the input without error, and then validating the value
                //This process is repeated for all other string values
              getline(idata, name);
              if (name.length()>50)
              {
                  cout << "out of variable range";
              }

              odata << setw(38) << right << "Name of Student:\t" << left << name << endl;

              idata >> age;
              if (age < 1 || age > 90)
              {
                  cout << "out of variable range";
              }

              odata << setw(38) << right << "Age:\t" << left << age << endl;

              idata.ignore();
              getline(idata, address);
              if (address.length()>60)
              {
                  cout << "out of variable range";
              }

              odata << setw(38) << right << "Address:\t" << left << address << endl;

              idata >> years;
              if (years < 1 || years > 25)
              {
                  cout << "out of variable range";
              }

              odata << setw(38) << right << "Number of years at Texas:\t" << left << years << endl;

              idata.ignore();
              getline(idata, telephone);
              if(telephone.length()>50)
              {
                  cout << "out of variable range";
              }

              odata << setw(38) << right << "Telephone Number:\t" << left << telephone << endl;

              getline(idata, socialsecurity);
              if(socialsecurity.length()>50)
              {
                  cout << "out of variable range";
              }

              odata << setw(38) << right << "Student Soc. Security #:\t" << left << socialsecurity << endl;



                    {   //establishing an inner for loop to read the grades for 3 courses for each student
                        for (int course = 1; course <= 3; course++)
                        {
                            //inputting information and then validating it
                            //Process is repeating for all double values as well as the const int values
                            odata << fixed << setprecision(1) << showpoint;
                            getline(idata, courses);
                            odata << setw(38) << right << "Course Number:\t" <<courses<< left << endl;
                            if (courses.length()>20)
                            {
                                cout << "out of variable range";
                            }

                            idata >> test1;
                            if (test1 < 1 || test1 > 100)
                            {
                                cout << "Grade for Test 1 is not valid";
                            }
                            odata << setw(38) << right << "Test #1:\t" << left << test1 << endl;


                            idata >> test2;
                            if (test2 < 1 || test2 > 100)
                            {
                                cout << "Grade for Test 2 is not valid";
                            }
                            odata << setw(38) << right << "Test #2:\t" << left << test2 << endl;


                            idata >> test3;
                            if (test3 < 1 || test3 > 100)
                            {
                                cout << "Grade for Test 3 is not valid";
                            }
                            odata << setw(38) << right << "Test #3:\t" << left << test3 << endl;


                            idata >> test4;
                            if (test4 < 1 || test4 > 100)
                            {
                                cout << "Grade for Test 4 is not valid";
                            }
                            odata << setw(38) << right << "Test #4:\t" << left << test4 << endl;


                            idata >> test5;
                            if (test5 < 1 || test5 > 100)
                            {
                                cout << "Grade for Test 5 is not valid";
                            }
                            odata << setw(38) << right << "Test #5:\t" << left << test5 << endl;


                            finalGrade = (test1*.10)+(test2*.15)+(test3*.20)+(test4*.25)+(test5*.30);
                            odata << setw(36-courses.length()) << right << "Numerical Grade in " << courses << ":""\t" << finalGrade << "%" << left << endl;



                            //use if/else statements to establish a letter grade using the value assigned to finalGrade variable
                            if (finalGrade >= A_SCORE && finalGrade <= 100)
                            {

                              odata << setw(36-courses.length()) << right << "Letter Grade in "<< courses << ":\t" << 'A' << endl;

                            }
                            else if (finalGrade >= B_SCORE && finalGrade < A_SCORE)
                            {

                              odata << setw(36-courses.length()) << right << "Letter Grade in "<< courses << ":\t" << 'B' << endl;

                            }
                            else if (finalGrade >= C_SCORE && finalGrade < B_SCORE)
                            {

                              odata << setw(36-courses.length()) << right << "Letter Grade in "<< courses << ":\t" << 'C' << endl;

                            }
                            else if (finalGrade >= D_SCORE && finalGrade < C_SCORE)
                            {

                              odata << setw(36-courses.length()) << right << "Letter Grade in "<< courses << ":\t" << 'D' << endl;

                            }
                            else if (finalGrade >= F_SCORE && finalGrade < D_SCORE)
                            {

                              odata << setw(36-courses.length()) << right << "Letter Grade in "<< courses << ":\t" << 'F' << endl;

                            }
                            else if (finalGrade < 0 || finalGrade > 100)
                            {

                              cout << "This is not a valid grade, please check your input.";

                            }
                            //use if/else statements to determine what note is displayed based on finalGrade value
                            if (finalGrade < 70 && finalGrade >= 0)
                            {
                              odata << setw(60) << warning_note << endl;
                            }
                            else if (finalGrade >= 95 && finalGrade <=100)
                            {
                              odata << setw(50) << congrats_note << endl;
                            }
                            idata.ignore();


                        }
                    odata << endl;
                    } //end of loop 2



      odata << endl;
      } //end of loop 1











      // closing the opened input and output files
      idata.close();
      odata.close();

      //RETURN CONTROL TO PROGRAM
      return 0;

  }
