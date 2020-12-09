#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

//Converts Binary to Decimal
int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

//Reads Input File
void inputLineRead()
{
    

    //Input Stream
    fstream in("input.in", fstream::in);
    std::string line;

    //Highest Seat ID found
    int highestSeatID{0};

    while (in >> line)
    {
        //Max Binary Value for Rows and Columns
        int rowBinary = 1111111;
        int colBinary = 111;

        //Subtracts from Max Binary Value depending on F or L 
        for(int i = 0; i < line.length(); i++){
            if (line[i] == 'F'){
                rowBinary -= pow(10, (6-i));
            }
            if(line[i] == 'L'){
                colBinary -= pow(10, (2-(i-7)));
            }
        }
        
        //Converts binary row and col to decimal
        int row = binaryToDecimal(rowBinary);
        int col = binaryToDecimal(colBinary);

        //Algorithm for Identifying Seat ID
        int seatID = row * 8 + col;

        //Keep highest found value
        if(seatID > highestSeatID){
            highestSeatID = seatID;
        }
    }

    //Report Highest Seat ID
    std::cout << highestSeatID << endl;
}

int main()
{
    inputLineRead();
    return 0;
}