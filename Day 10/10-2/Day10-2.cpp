#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void readInputToArray()
{
    //Creates an input file stream
    fstream in("input.in", fstream::in);

    std::vector<int> adapters;

    int line; //variable to hold input

    //Counters
    int sequentialCount{1};
    std::vector<int> multiplySequentialCounts;
    unsigned long long int answerMulti{0};

    while (in >> line)
    {
        adapters.push_back(line);
        //std::cout << line << endl;
    }

    //Add 0
    adapters.push_back(0);

    sort(adapters.begin(), adapters.end());

    //Add 3+Max
    adapters.push_back(3 + adapters[adapters.size() - 1]);

    //Reverse Order
    sort(adapters.rbegin(), adapters.rend());

    //Determine Runs of Sequential Numbers
    for (int i = 0; i < adapters.size() - 1; i++)
    {
        //std::cout << adapters[i] << endl;
        if (adapters[i] - adapters[i + 1] == 1)
        {
            sequentialCount++;
        }
        else
        {
            if (sequentialCount == 3)
            {
                multiplySequentialCounts.push_back(2);
            }
            if (sequentialCount == 4)
            {
                multiplySequentialCounts.push_back(4);
            }
            if (sequentialCount == 5)
            {
                multiplySequentialCounts.push_back(7);
            }
            if (sequentialCount == 6)
            {
                multiplySequentialCounts.push_back(15);
            }
            std::cout << sequentialCount << endl;
            sequentialCount = 1;
        }
    }

    answerMulti = multiplySequentialCounts[0];

    for (int j = 1; j < multiplySequentialCounts.size(); j++)
    {

        answerMulti *= multiplySequentialCounts[j];
    }

    answerMulti *= sequentialCount;
    std::cout << answerMulti;
    //Close the File Stream
    in.close();
}
int main()
{
    readInputToArray();
    return 0;
}