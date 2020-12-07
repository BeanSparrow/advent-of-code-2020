#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>


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

    //Array to fill with found SeatIDs
    std::vector<int> seatArr;

    //My Seat ID
    int mySeatID{0};

    while (in >> line)
    {
        //Max Binary Values for Rows and Columns
        int rowBinary = 1111111;
        int colBinary = 111;

        //Subtracts value from Max Binary based on Front of Left Values
        for(int i = 0; i < line.length(); i++){
            if (line[i] == 'F'){
                rowBinary -= pow(10, (6-i));
            }
            if(line[i] == 'L'){
                colBinary -= pow(10, (2-(i-7)));
            }
        }
        
        //Find Decimal values for Row and Column
        int row = binaryToDecimal(rowBinary);
        int col = binaryToDecimal(colBinary);

        //Algorithm for Identifying Seat ID
        int seatID = row * 8 + col;
        
        //Insert into Seat Array
        seatArr.push_back(seatID);
    }

    //Sort Seat Array
    sort(seatArr.begin(), seatArr.end());
    
    //Find missing seat
    for(int j = 0; j < seatArr.size() -1; j++){
        if(seatArr[j] != (seatArr[j + 1]-1)){
            mySeatID = seatArr[j] +1;
        }
    }

    //Report my Seat ID
    std:: cout << mySeatID;
}

int main()
{
    inputLineRead();
    return 0;
}