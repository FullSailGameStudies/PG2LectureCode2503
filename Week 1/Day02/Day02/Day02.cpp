#include <iostream>
#include <string>
#include <vector>
#include <Console.h>

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

//& - reference variable
//pass by reference (ALIAS) - prevents a copy
//when to use? if the parameter type is a class
void PrintMe(std::vector<int>& numies)
{
    for (int i = 0; i < numies.size(); i++)
    {
        std::cout << numies[i] << "\n";
    }
}

//pass by value (COPY)
//whatToSay gets its value COPIED to it from another location
void SayHi(std::string whatToSay)
{
    Console::WriteLine(whatToSay, ConsoleColor::Green);
}

void FillGrades(std::vector<float>& course,float& minGrade, float& maxGrade)
{
    minGrade = 101;
    maxGrade = 0;
    for (int i = 0; i < 10; i++)
    {
        course.push_back( rand() % 10001 / 100.0f);
        if (course[i] < minGrade) minGrade = course[i];
        if (course[i] > maxGrade) maxGrade = course[i];
    }
}
void PrintGrades(const std::vector<float>& course, const float& minGrade,const float& maxGrade)
{
    Console::WriteLine("\n\n---PG2 2503---", ConsoleColor::Yellow);
    for (int i = 0; i < course.size(); i++)
    {
        std::cout << course[i] << "\n";
    }
    std::cout << "Min Grade: " << minGrade << "\nMax grade: " << maxGrade << "\n\n";
}

int main()
{
    std::vector<int> numbers;
    for (size_t i = 0; i < 10; i++)
    {
        numbers.push_back(rand());
    }

    std::vector<int>numbers2 = numbers;//copy
    std::vector<int>& nums = numbers;//no copy
    PrintMe(nums);//giving my variable to a different scope
    SayHi("Hello Gotham");
    std::string city = "Central City";
    SayHi(city);
    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector
            3) call the method
            4) after calling, print the vector

    */
    std::vector<float> grades;
    float min, max;
    FillGrades(grades, min, max);
    PrintGrades(grades, min, max);

    // modify FillGrades to return the min and max grades through parameters


    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    for (int i = 0; i < 10; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);//size: ?  capacity: ?
    }
    float avg = average(highScores);



    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    //erase all scores < 2500

    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}