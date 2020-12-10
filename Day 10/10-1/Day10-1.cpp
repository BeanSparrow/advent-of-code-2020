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
    int oneJoltDif{0};
    int threeJoltDif{0};
    int lastCheckJolts{0};
    int answer{0};

    while (in >> line)
    {
        adapters.push_back(line);
        //std::cout << line << endl;
    }

    sort(adapters.begin(), adapters.end());

    for (int i = 0; i < adapters.size(); i++)
    {
        if (adapters[i] - lastCheckJolts == 1)
        {
            oneJoltDif++;
        }
        if (adapters[i] - lastCheckJolts == 3)
        {
            threeJoltDif++;
        }

        lastCheckJolts = adapters[i];
    }

    answer = oneJoltDif * (threeJoltDif + 1);
    std::cout << answer;
    //Close the File Stream
    in.close();
}
int main()
{
    readInputToArray();
    return 0;
}