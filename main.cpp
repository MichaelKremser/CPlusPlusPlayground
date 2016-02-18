#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm> // required for "for_each"

using namespace std;

void use_vector_pushpop();
void use_vector_iter();
void use_list();
void use_cpp11array();

int main (int argc, char *argv[])
{
	use_vector_pushpop();
	use_vector_iter();
	use_list();
	use_cpp11array();
	
	return 0;
}

void use_list()
{
	std::list<string> words;
	words.push_back("Hallo ");
	words.push_back("Welt!");
	list<string>::iterator iter;
	for (iter = words.begin(); iter != words.end(); ++iter)
	{
		cout << *iter;
	}
	cout << endl;
}

void use_cpp11array()
{
	// Requires "-std=c++11" command line option to g++
	std::array<std::string, 2> words = { "Hello ", "world!" };
	cout << "for loop" << endl;
	for (auto & word : words)
	{
		cout << word;
	}
	cout << endl;
	cout << "for_each" << endl;
	// auto does not work in place of string
	for_each (words.begin(), words.end(), [](string word) { cout << word; } );
	cout << endl;
}

void fill_words(std::vector<string> *words)
{
	words->push_back("Hello ");
	words->push_back("world!");
}

void use_vector_iter()
{
	std::vector<string> words;
	fill_words(&words);
	vector<string>::iterator iter;
	for (iter = words.begin(); iter != words.end(); ++iter)
	{
		cout << *iter;
	}
	cout << endl;
}

void use_vector_pushpop()
{
	std::vector<string> words;
	fill_words(&words);
	
	while (!words.empty())
	{
		string word = words.front();
		words.pop_back();
		cout << word;
	}
	cout << endl;
}