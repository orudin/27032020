#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

int main() {

	init();
	

	int action = 0;
	do
	{
		cout << "1. Add new quiz" << endl;
		cout << "Show and pass quizezes" << endl;
		cout << "Exit" << endl;
		cout << endl;
		cout << "Select action ->" << endl;
		cin >> action;
		switch (action)
		{
		case 1: {

			addQuiz();
			break;
		}

		case 2: {

			showQuizes();
			passQuiz();

			break;
		}

		case 3: {

			cout << "Goodbye" << endl;
			break;
		}
		
		default: {
			cout << "Error" << endl;
		}
			break;
		}

	} while (action!=3);



	return 0;
}