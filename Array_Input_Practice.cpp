
    #include <iostream>
    #include <iomanip>
    #include <string>
    #include <cmath>
    using namespace std;

    int main ()

    {
      string name;
      int socialsecurity, finalGrade;
      double test1, test2, Final;


      cout << "Name of Student:" "\t" << endl;
      cin >> name;
      cout << "Student Soc. Security #:" "\t" << endl;
      cin >> socialsecurity;
      cout << "Test 1:" "\t" << endl;
      cin >> test1;
      cout << "Test 2:" "\t" << endl;
      cin >> test2;
      cout << "Final Exam:" "\t" << endl;
      cin >> Final;
      finalGrade =((test1*.25)+(test2*.25)+(Final*.50));

      cout << "\t""\t""Student Grades" << endl;
      cout << "Department of Computer Science, Texas State University" << endl;
      cout << "\t""\t""Name of Student:""\t" <<name<< endl;
      cout << "\t""Student Soc. Security #:""\t" <<socialsecurity<< endl;
      cout << "\t""\t""\t""Test 1:""\t""\t"<<test1<< endl;
      cout << "\t""\t""\t""Test 2:""\t""\t"<<test2<< endl;
      cout << "\t""\t""\t""Final Exam:""\t" <<Final<< endl;
      cout << "\t""\t""\t""Grade:""\t""\t"<<finalGrade<< endl;


    return 0;

    }
