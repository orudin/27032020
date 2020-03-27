#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Question {
	string quetionText;
	string trueAnswer;
};
struct Quiz {
	string Title;
	Question questions[5];


};

void addQuiz();

void showQuizes();

void init();
void insertQuiz();
void passQuiz();


