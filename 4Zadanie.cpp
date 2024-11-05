#include <iostream>
#include "vector.h"
#include <string>
using namespace std;

bool isUpper(char c)
{
	return 65 <= c && c <= 90;
}

bool isCorrectWord(const string&  word)
{
	int upperCounter = 0;
	for (char sym : word)
	{
		if (isUpper(sym)) upperCounter++;
	}
	if (upperCounter == 1) return true;
	return false;
}

void fillDictionary(int wordAmount, Myvector<string>& wordList)
{
	string input = "";
	for (int i = 0; i < wordAmount; i++)
	{
		cin >> input;
		if (isCorrectWord(input)) wordList.MPUSH(input);
		else
		{
			cout << "Word isn`t correct in wasn`t added to dictionary!" << endl;
		}
	}
}

Myvector<string> handleInputLine(string& inputLine)
{
	Myvector<string> processedWords;
	string word = "";

	for (char sym : inputLine)
	{
		if (sym == ' ')
		{
			if (!word.empty())  
			{
				processedWords.MPUSH(word);
				word = "";
			}
		}
		else word += sym; 
	}
	if (!word.empty()) processedWords.MPUSH(word); 
	return processedWords;
}

string toLower(const string& word)
{
	string lowerWord = "";
	for (char sym : word)
	{
		lowerWord += tolower(sym);
	}
	return lowerWord;
}

int isInDictionary(const string& word, Myvector<string> dictionary)
{
	string lowerWord = toLower(word);

	for (int j = 0; j < dictionary.size(); j++)
	{
		string dictWord = dictionary.MGET(j);

		
		if (lowerWord == toLower(dictWord))
		{
			
			if (word == dictWord) return 1;  
			else return 0;  
		}
	}

	return 2;  
}

void findWrongWords(Myvector<string> text, Myvector<string> dictionary)
{
	Myvector<string> incorrectWords;
	int incorrectCounter = 0;

	for (int i = 0; i < text.size(); i++)
	{
		int checkResult = isInDictionary(text.MGET(i), dictionary);

		
		if (checkResult == 1) continue;

		
		if (checkResult == 0)
		{
			incorrectCounter++;
			incorrectWords.MPUSH(text.MGET(i));
		}
		
		else if (checkResult == 2 && !isCorrectWord(text.MGET(i)))
		{
			incorrectCounter++;
			incorrectWords.MPUSH(text.MGET(i));
		}
	}

	cout << "This text has " << incorrectCounter << " incorrect word(s)!" << endl;
	incorrectWords.print();
}

int main()
{
	Myvector<string> dictionary;
	string wordNum;
	getline(cin, wordNum);
	if (stoi(wordNum) != 0)
	{
		fillDictionary(stoi(wordNum), dictionary);
	}
	cin.get();
	string userInput;
	getline(cin, userInput);
	Myvector<string> text = handleInputLine(userInput);
	findWrongWords(text, dictionary);
	return 0;
}