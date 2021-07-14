#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ofstream outFile("report.txt", ios::out);
    ifstream in1("location.txt");
    ifstream in2("tech.txt");
    ifstream in3("cost.txt");
    string tmp;
    if (in1 >> tmp && in2 >> tmp && in3 >> tmp) // or if(std::getline(infile, tmp))
    {
        std::cout << "Successful!";

        int count = 0; // line number count (starts at 1)
        string line;

        outFile << "location.txt\n>>";
        while (getline(in1, line)) // only loop when read succeeds
        {
            outFile << line << '\n'; // copy line to output
            ++count; // keep track
        }

        outFile << "\ntech.txt\n>>";
        while (getline(in2, line))
        {
            outFile << line << '\n';
            ++count;
        }

        outFile << "\ncost.txt\n>>";
        while (getline(in3, line))
        {
            outFile << line << '\n';
            ++count;
        }
        cout << count << " lines read...\n";
    }
    else
    {
        std::cout << "failed to open!!. Please firstly enter information into the 3 databases here contain 3 text file\n";
    }
   

}