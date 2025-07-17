
#include <iostream>
#include <string>

int playingWithHasFunctions(const std::string& inpString);
int dbHashFunction(std::string name, int age, char sex);

int main() {
    int hashValue1 = playingWithHasFunctions("AOIUDFH");
    int hashValue2 = playingWithHasFunctions("This is a key...");

    std::cout << hashValue1 << std::endl;
    std::cout << hashValue2 << std::endl;


    std::cout << "\nData base example" << std::endl;
    int dbHashValue = dbHashFunction("Coen", 21, 'M');
    int dbHashValue2 = dbHashFunction("Carmen", 21, 'F');
    std::cout << dbHashValue << std::endl;
    std::cout << dbHashValue2 << std::endl;

    return 0;
}

int playingWithHasFunctions(const std::string& inpString) {

    int runningSum = 0;
    for (const char& c : inpString) {
        runningSum += int(c);
    }
    return runningSum % 50;

}


int dbHashFunction(std::string name, int age, char sex) {

    int runningSum = 0;
    for (const char& c : name) {
        runningSum += int(c);
    }

    runningSum += (age * age);

    switch(sex) {
        case 'M':
            runningSum *= 100;
            break;
        case 'F':
            runningSum *= 10;
            break;
        default:
            break;
    }

    return runningSum % 7;
}
