// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Console.h"
#include "Input.h"



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */

    std::string fileName = "2503.csv";
    std::string path = "C:/temp/2503/";
    std::string finalPath = path + fileName;

    char delimiter = '$';
    //1) open the file
    std::ofstream outFile(finalPath);
    if (outFile.is_open())
    {
        //2) write to the file
        //  <<  insertion operator
        outFile << "Aquaman literally stinks.";
        outFile << delimiter << 13.7;
        outFile << delimiter << true;
        outFile << delimiter << 7;
        outFile << delimiter << "Batman RULES!";
    }
    else
        std::cout << finalPath << " could not be opened.\n";

    //3) close the file
    outFile.close();

    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */
    //1) open the file
    std::ifstream inFile(finalPath);
    if (inFile.is_open())
    {
        //2) read the file

        std::string input;
        //reads until the \n OR until the end of the file
        std::getline(inFile, input);
        //std::cout << input << "\n";//debug print

        //parse the data out of the string
        //use getline and stringstream
        std::stringstream inputStream(input);
        std::string data;

        std::getline(inputStream, data, delimiter);
        std::cout << data << "\n";

        //read the double
        std::getline(inputStream, data, delimiter);
        double dData = std::stod(data);
        std::cout << dData << "\n";

        //read the bool
        std::getline(inputStream, data, delimiter);
        //use a try-catch block to handle exceptions
        try
        {
            //the code that might throw an exception goes inside the try block
            bool bData = std::stoi(data);
            std::cout << bData << "\n";
        }
        catch (const std::exception&)
        {
            //the code to HANDLE the exception goes into the catch block
            std::cout << data << " is not the right format. Expected an integer.\n";
        }

        //read the int
        std::getline(inputStream, data, delimiter);
        int iData = std::stoi(data);
        std::cout << iData << "\n";

        //read the string
        std::getline(inputStream, data, delimiter);
        std::cout << data << "\n";
    }
    else
        std::cout << finalPath << " could not be opened.\n";

    //3) close the file
    inFile.close();

    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */

    std::ifstream inFile2(finalPath);

    std::string line;
    //while (std::getline(inFile2, line))
    //{

    //}
    while (!inFile2.eof())
    {

    }
    inFile2.close();




    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
}