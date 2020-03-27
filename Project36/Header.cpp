#include "Header.h"
#include <fstream>


Quiz* quizes;
int countQuzizes=0;

const int coun = 5;




void insertQuiz(Quiz quiz)
{
	Quiz* temp = new Quiz[countQuzizes + 1];
	for (int i = 0; i < countQuzizes; i++)
	{
		temp[i] = quizes[i];

	}
	temp[countQuzizes] = quiz;

	countQuzizes++;
	quizes = new Quiz[countQuzizes];
	for (int i = 0; i < countQuzizes; i++)
	{
		quizes[i] = temp[i];

	}
	delete[]temp;

}

void init()
{
	ifstream fin;
	fin.open("Quizes.txt");
	bool isOpen = fin.is_open();
	if (isOpen == true) {
		while (!fin.eof())
		{
			Quiz getQuiz;
			fin >> getQuiz.Title;
			if (getQuiz.Title != "") {
				for (int i = 0; i < coun; i++)
				{
					fin >> getQuiz.questions[i].quetionText;
					fin >> getQuiz.questions[i].trueAnswer;

				}
			}
			else { break; }
			insertQuiz(getQuiz);
		}
	}
	else {
		cout << "Error" << endl;

	}
	
	
	


}



void passQuiz()
{
	int selectQuiz = 0;
	int score = 0;
	cout << "Enter number quiz for star pass -> ";
	cin >> selectQuiz;
	selectQuiz--;
	cout << endl;
	cout << "you started passng " << quizes[selectQuiz].Title << endl;
	for (int i = 0; i < coun; i++)
	{
		cout << quizes[selectQuiz].questions[i].quetionText << endl;
		string tempAnswer = "";
		cout << "your answer -> ";
		cin >> tempAnswer;
		if (quizes[selectQuiz].questions[i].trueAnswer == tempAnswer) {
			cout << "It's true answer! (+20 score)" << endl;
				score += 20;
		}
		else {
			cout << "Its false answer (((" << endl;
		}
		
	}

	cout << "Your result:" << score << " / 100" << endl;
}




void addQuiz()
{
	ofstream fout;
	fout.open("Quizes.txt", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen==true) {

		Quiz* temp = new Quiz[countQuzizes + 1];
		for (int i = 0; i < countQuzizes; i++)
		{
			temp[i] = quizes[i];

		}
		cout << "Enter quiz title ";
		cin >> temp[countQuzizes].Title;

		for (int i = 0; i < coun; i++)
		{
			cout << "Enter" << i + 1 << "/5 question -> ";
			cin >> temp[countQuzizes].questions[i].quetionText;
			cout << "Enter correct answer for this question -> ";
			cin >> temp[countQuzizes].questions[i].trueAnswer;

		}
		fout << temp[countQuzizes].Title << endl;
		for (int i = 0; i < 5; i++)
		{
			fout << temp[countQuzizes].questions[i].quetionText << endl;
			fout << temp[countQuzizes].questions[i].trueAnswer << endl;

		}
		countQuzizes++;
		quizes = new Quiz[countQuzizes];
		for (int i = 0; i < countQuzizes; i++)
		{
			quizes[i] = temp[i];

		}
		delete[]temp;
	}
	else {
		cout << "Error" << endl;
	}
}

void showQuizes()
{
	for (int i = 0; i < coun; i++)
	{
		cout << i + 1 << ". " << quizes[i].Title << endl;
	}
	cout << endl;

}


