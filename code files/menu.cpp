#include <iostream>
#include <conio.h>
#include <process.h>
#include <string>

using namespace std;

void applyInfo(const char* exeName) {
	int choicetwo;
	cout << "1. Transfer information from text file\n";
	cout << "2. Entering information one by one into the text file\n";
	cin >> choicetwo;

	if (choicetwo == 1)
	{
		int error;
		error = _spawnl(P_WAIT, exeName,
			exeName, "readfile", "readfile", NULL);
		if (error == 0) cout << "Program launched successfully!\n";
		else {
			cout << "The program could not be opened!!!\n";
		}
	}
	else if (choicetwo == 2)
	{
		int choice = 0;
		while (choice !=2)
		{
			int error;
			error = _spawnl(P_WAIT, exeName,
				exeName, "input", NULL);
			if (error == 0)
			{
				cout << "Program launched successfully!\n";
				cout << "(1)Continue or (2)not";
				cin >> choice;
				switch (choice)
				{
				case 1:
					break;
				case 2:
					break;
				default:
					cout << "Wrong choice\n";
					_getch();
				}
			}
			else {
				cout << "The program could not be opened!!!\n";
				choice = 2;
			}		
		}
	}
	else {
		cout << "Wrong choice\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

int main() {
	
	int choice = 0;

	while (choice != 5)
	{
		cout << "Select from the options given below\n";
		cout << "1. Location\n";
		cout << "2. Tech\n";
		cout << "3. Cost\n";
		cout << "4. Report\n";
		cout << "5. #Exit Program\n";

		cout << "Enter Your Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			applyInfo("location.exe");
			break;
		case 2:
			applyInfo("tech.exe");
			break;
		case 3:
			applyInfo("cost.exe");
			break;
		case 4:
			int error;
			error = _spawnl(P_WAIT, "report.exe",
				"report.exe", "readfile", "readfile", NULL);
			if (error == 0) cout << "Program launched successfully!\n";
			else {
				cout << "The program could not be opened!!!\n";
			}
			break;
		case 5:
			break;
		default:
			cout << "Wrong choice\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}	
	}
	return 0;
}
