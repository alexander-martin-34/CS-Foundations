/***************************
Name: Alexander Martin
Date: 05/02/2020
Problem Number: 7
Hours spent working on project: 31
Instructor: Komogortsev, TSU
**************************/


#define STACK_SIZE 256

#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;


class Dynstack
{
    //Declare private members for Dynstack
private:
    int top;
    int stackSize;
    char * stackArr; //Dynamic array

    //Declare public members for Dynstack
public:
    //Constructor
    Dynstack(int size)
    {
        stackSize = size;
        stackArr = new char(size);
        top = -1;
    }

    //Destructor
    ~Dynstack(){};

    /*******************************************
     * function: probeEmpty() -
     * check if the Dynstack has values in it or not
     * input: none
     * output: true || false
     ********************************************/
    bool probeEmpty()
    {
        bool probe = false;

        if(top < 0)
            probe = true;

        return probe;
    }


    /***********************************
     * function: probeFull() -
     * check if the Dynstack is full or not
     * input: none
     * output: true || false
     **********************************/
    bool probeFull()
    {
        bool probe = false;

        if((top > (STACK_SIZE - 1)) ||
           (top == (STACK_SIZE - 1)))
            probe = true;

        return probe;
    }

    /*************************
     * function: pop() -
     * remove characters from the Dynstack
     * input: none
     * output: c || null
     *************************/
    char pop()
    {
        if((top > 0) || (top == 0))
        {
            char i = (*(stackArr + top));
            top--;
            return i;
        }

        else
            return '\0';
    }

    /*******************************
     * function: push() -
     * psuh characters into the Dynstack
     * input: char i
     * output: true || false
     ******************************/
    bool push(char i)
    {
        bool probe = false;

        if(top < (STACK_SIZE - 1))
        {
            probe =  true;
            top++;
            (*(stackArr + top)) = i;
        }

        //If Dynstack is full, you can't push to it
        if(probeFull())
            probe = false;

        return probe;
    }
};


/*******************************************
* function: probeMatch() -
* check if the characters are elements or not
* input: char i1, char i2
* output: true || false
********************************************/
bool probeMatch(char i1, char i2)
{
    bool probe = false;

    if((i1 == ')') && (i2 == '('))
        probe = true;

    if((i1 == ']') && (i2 == '['))
        probe = true;

    return probe;
}


/******************************************************
* function: probeBalance() -
* return if the elements in the expression are balanced
* input: none
* output: true || false
*******************************************************/
bool probeBalance(char * eq)
{
    //Variables
    bool probe = true;
    Dynstack stackProbe(STACK_SIZE); //Create object
    int equationSize = strlen(eq); //Get equation size

    //Loop through every element in expression
    for(int position = 0; position < equationSize; position++)
    {
        //If left element found, push to Dynstack
        if(((*(eq + position)) == '(') || ((*(eq + position)) == '['))
            stackProbe.push((*(eq + position)));

            //If right element found, check if its opposite is in Dynstack
        else if(((*(eq + position)) == ')') ||
                ((*(eq + position)) == ']'))
        {
            //If elements do not match, return false
            if(probeMatch((*(eq + position)),
                          stackProbe.pop()) == false)
                probe = false; //return false
        }
    }

    //Last probe to see if there is an element missing
    if(stackProbe.probeEmpty() == false)
        probe = false;

    return probe;
}

//Main function to test the functions to see if balanced expression or not
/***************************************************************
* function: main() -
* test all functions to prove if expressions are balanced
* input: int arg1, char * arg2[]
* output: true || false
**********************************/
int main(int arg1, char * arg2[])
{
    //Variables for files
    ofstream fout;
    ifstream fin;
    fout.open("exp_output.dat", ios::app);
    string fileName;
    string equationVar;

    //Get equation
    char * equation;

    //Open input file
    cout << "Enter file name: ";
    cin >> fileName;
    fin.open(fileName.c_str());

    //Check input file opens
    if(fin.fail())
    {
        cout << "Error: input file did not open." << endl;
        return -1;
    }

    //Check output file opens
    if(fout.fail())
    {
        cout << "Error: output file did not open." << endl;
        return -1;
    }

    //Read in the file
    while(getline(fin,equationVar))
    {
        //Variables for counting elements
        int leftBrack = 0;
        int leftParen = 0;
        int rightBrack = 0;
        int rightParen = 0;
        int brackDifference = 0;
        int parenDifference = 0;

        //Flags are true if right element preceeds left element
        bool rightBrackFlag = false;
        bool rightParenFlag = false;

        //Flag for if there are more than 6 errors in equation
        bool errorFlag = false;

        //Variables for expression and expression size
        int size = equationVar.length();
        equation = new char[size];
        strcpy(equation, equationVar.c_str());

        //Loop through each char in expression
        for(int index = 0; index < size; index++)
        {
            //Increment count for each element
            if(equation[index] == '(')
                leftParen++;
            else if(equation[index] == '[')
                leftBrack++;
            else if(equation[index] == ')')
                rightParen++;
            else if(equation[index] == ']')
                rightBrack++;

            //Create a flag for if there is a right element
            //before left element
            if(rightBrack > leftBrack)
                rightBrackFlag = true;

            if(rightParen > leftParen)
                rightParenFlag = true;
        }

        //Display the equation in output file
        fout << equation;

        //Display that expression is valid if elements are balanced
        if(probeBalance(equation) == true)
            fout << "  === valid expression";

            //Display what is wrong with expression if not balanced
        else
        {
            //Error if 6+ errors:
            if((leftBrack + rightBrack + leftParen + rightParen) > 6)
            {
                fout << "  Error: More than 6 missing elements ";
                errorFlag = true;
            }

            //If there are less than 6 errors,
            //give generic missing message
            if(!errorFlag)
                fout << " === missing: ";

            brackDifference = leftBrack - rightBrack;
            parenDifference = leftParen - rightParen;

            //Display what is missing if uneven # of brackets
            if((leftBrack != rightBrack) && !errorFlag)
            {
                if(rightBrack > leftBrack)
                    fout << (rightBrack - leftBrack) << " [ ";
                if(leftBrack > rightBrack)
                    fout << (leftBrack - rightBrack) << " ] ";
            }

            //Display what is missing if uneven # of parentheses
            if((leftParen != rightParen) && !errorFlag)
            {
                if(rightParen > leftParen)
                    fout << (rightParen - leftParen) << " ( ";
                if(leftParen > rightParen)
                    fout << (leftParen - rightParen) << " ) ";
            }

            //Display what is missing with equation with same #
            //of elements, but it is not balanced properly
            if((leftBrack == rightBrack) && (leftParen == rightParen) && !errorFlag)
            {
                //Display what expression is missing
                if((leftBrack == rightBrack) &&
                   (leftBrack != 0) && (rightBrack != 0) && rightBrackFlag)
                    fout << rightBrack << " ] " << leftBrack << " [ ";
                if((leftParen == rightParen) &&
                   (leftParen != 0) && (rightParen != 0) && rightParenFlag)
                    fout << rightParen << " ) " << leftParen << " ( ";
            }
        }

        //Seperate each line
        fout << "\n";

    }//Close the while loop reading in the input file

    return 0;
}



