#include<iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
int main() {
	
	string line_start= "AND3";
	string line_end = "F1";
	string key = "0";
	string file = "C:/Users/arina/Desktop/Course project/example.blif";

	string AND_gate = "11 1";
	string OR_gate = "-1 1\n1- 1";

	ifstream input;
	ofstream output;

	input.open(file);
	output.open("output.blif");

	if (!input.is_open()) 
	{
		cout << "can no open file"; return 0;
	}

	string tmp = "";
	while (!input.eof())
	{
		getline(input, tmp);
		size_t found1 = tmp.find(".input");
		if (found1 != string::npos)//==-1(не найдено)
		{
			tmp += " k";
		}
		size_t found2 = tmp.find(".output");
		if (found2 != string::npos)//вставляю доп.элемент в начало, если так нельзя - переделать
		{
			if (key == "0")
				output << ".input " << line_start << " k " << "key" << endl << OR_gate << endl;
			if (key == "1")
				output << ".input " << line_start << " k " << "key" << endl << AND_gate << endl;
		}
		size_t found3 = tmp.find(line_start);
		if (found3 != string::npos)//еделать
		{
			size_t found4 = tmp.find(line_end);
			if (found4 != string::npos) {
				tmp.replace(tmp.find(line_start), line_start.length(), "key");
			}
		}
		output << tmp << endl;
	}

	return 0;
}
