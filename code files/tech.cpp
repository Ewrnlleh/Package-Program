#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char* argv[]) {


    if (argc == 3) {
        string fileName;
        cout << "Please Enter file name or path(with .txt):";
        cin >> fileName;
        ifstream infile(fileName);

        string tmp;
        if (infile)
        {
            std::cout << "Successful!";
        }
        else
        {
            std::cout << "failed to open " + fileName + "\n";
            return 0;
        }

        ofstream outfile("tech.txt");
        string content = "";
        int i;

        for (i = 0; infile.eof() != true; i++) // get content of infile
            content += infile.get();

        i--;
        content.erase(content.end() - 1);   // erase last character

        cout << i << " characters read...\n";
        infile.close();

        outfile << content; // output
        outfile.close();
        return 0;

    }

    if (argc == 2) {
        string serverId;
        string speed;
        string capacity;

        cout << "Enter SERVER ID:";
        cin >> serverId;
        cout << "Enter SPEED:";
        cin >> speed;
        cout << "Enter CAPACITY:";
        cin >> capacity;

        std::ofstream outfile;

        outfile.open("tech.txt", std::ios_base::app);
        outfile << serverId + " " + speed + " " + capacity + " " + "\n";

    }

    return 0;

}