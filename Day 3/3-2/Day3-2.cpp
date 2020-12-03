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

    //Read Each Line
    while (in >> tobogganMapRow)
    {
        //Visualization Characters
        char tree = '#';
        string myToboggan = "@";

        //Determine Character Element Index of tobogganMapRow String
        int xPosModulus = xPos % tobogganMapRow.size();

        //Check for 'Tree' and increase counter
        if (tobogganMapRow[xPosModulus] == tree)
        {
            treesHit++;
        }

        //Replace string character with '@' for visualization
        tobogganMapRow.replace(xPosModulus, 1, myToboggan);

        std::cout << tobogganMapRow << "\n";

        xPos += xSlope;
    }

    //Close the File Stream
    in.close();

    return treesHit;
}

int main()
{
    int slopeArr[5][2] = {
        {1, 1},
        {3, 1},
        {5, 1},
        {7, 1},
        {1, 2}};

    std::vector<int> resultArr;

    int result{1};

    // for (int i=0; i < (sizeof(slopeArr) / sizeof(slopeArr[0])); i++){
    //     resultArr.push_back(inputLineRead(slopeArr[i][0], slopeArr[i][1]));
    // }

    std::cout << result;
    return 0;
}