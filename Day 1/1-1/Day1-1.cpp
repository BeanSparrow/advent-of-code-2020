#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void readInputToArray()
{
    //Creates Array to Hold Inputs
    std::vector<int> inputNums;

    //Creates an input file stream
    ifstream in("Day1 Inputs.txt", ios::in);

    int inputNum; //variable to hold input number

    //Read number using the extraction (>>) operator
    while (in >> inputNum)
    {
        //Add to the end of the array
        inputNums.push_back(inputNum);
    }

    //Close the File Stream
    in.close();

    //Initialize Value Variables
    int value1;
    int value2;

    //Loop through array comparing each number to each number until sum = 2020
    for (int i = 0; i < inputNums.size() - 1; i++)
    {
        for (int j = 1; j < inputNums.size(); j++)
        {
            if (inputNums[i] + inputNums[j] == 2020)
            {
                //Once sum is found assign values to variables
                value1 = inputNums[i];
                value2 = inputNums[j];
            }
        }
    }

    std::cout << "Your numbers are: " << value1 << " and " << value2 << "\n";

    //Multiply Variables to Find Answer
    int value3 = value1 * value2;

    std::cout << "The answer is: " << value3;
}

int main()
{
    readInputToArray();
    return 0;
}