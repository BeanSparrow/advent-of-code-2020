#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int inputLineRead(int xSlope, int ySlope)
{
    //Creates an input file stream
    fstream in("input.in", fstream::in);

    std::string tobogganMapRow; //variable to hold input

    //Counters
    int treesHit{0};
    int xPos{0};
    int yPos{0};

    //Read Each Line
    while (in >> tobogganMapRow)
    {
        //Visualization Characters
        char tree = '#';
        string myToboggan = "@";

        //Determine Character Element Index of tobogganMapRow String
        int xPosModulus = xPos % tobogganMapRow.size();

        //Check for 'Tree' and increase counter
        if (yPos % ySlope == 0)
        {

            if (tobogganMapRow[xPosModulus] == tree)
            {
                treesHit++;
            }

            //Replace string character with '@' for visualization
            tobogganMapRow.replace(xPosModulus, 1, myToboggan);

            //std::cout << tobogganMapRow << "\n";

            xPos += xSlope;
        }

        //Increment Line Count
        yPos++;
    }

    //Close the File Stream
    in.close();

    return treesHit;
}

int resultLooper()
{
    //Provided Slope Combos
    int slopeArr[5][2] = {
        {1, 1},
        {3, 1},
        {5, 1},
        {7, 1},
        {1, 2}};

    //Result Array to store each Loop Result
    std::vector<int> resultArr;

    //Variable to store Result Array Reduce Value
    unsigned long int result{1};

    //Loop Through All Slope Combos
    for (int i = 0; i < (sizeof(slopeArr) / sizeof(slopeArr[0])); i++)
    {
        resultArr.push_back(inputLineRead(slopeArr[i][0], slopeArr[i][1]));
    }

    //Reduce ResultArr
    for (int j = 0; j < resultArr.size(); j++)
    {
        result *= resultArr[j];
    }
    return result;
}

int main()
{
    unsigned long int result = resultLooper();
    //Report
    std::cout << result;
    return 0;
}