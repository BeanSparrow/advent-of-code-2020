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
    int value3;

    //Loop through array comparing each number to each number until sum = 2020
    for (int i = 0; i < inputNums.size() - 2; i++)
    {
        for (int j = 1; j < inputNums.size() - 1; j++)
        {
            for (int k = 2; k < inputNums.size(); k++)
            {
                if (inputNums[i] + inputNums[j] + inputNums[k] == 2020)
                {
                    //Once sume is found assign values to variables
                    value1 = inputNums[i];
                    value2 = inputNums[j];
                    value3 = inputNums[k];
                }
            }
        }
    }

    std::cout << "Your numbers are: " << value1 << " and " << value2 << " and " << value3 << "\n";

    //Multiply Variables to Find Answer
    int value4 = value1 * value2 * value3;

    std::cout << "The answer is: " << value4;
}

int main()
{
    readInputToArray();
    return 0;
}