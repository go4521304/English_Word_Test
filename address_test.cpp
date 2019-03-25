#include <iostream>
#include <fstream>
#include <string>
#include <random>
using namespace std;

int main()
{
	string word[1000][2];

	int word_N = 0;
	int word_Out;

	ifstream in("./1단어.txt", ios::in);
	ofstream out("./2단어_문제.txt", ios::trunc);

	string buffer;

	while (getline(in, buffer))
	{
		for (int i = 0; i < (int)buffer.size(); ++i)
		{
			if (buffer.at(i) == '\t')
			{
				word[word_N][0] = buffer.substr(0, i);
				word[word_N][1] = buffer.substr(i + 1, buffer.size()-1);
				word_N++;
				break;
			}
		}
	}

	cout << "단어의 개수 : " << word_N << endl;
	cout << "시험 볼 단어의 개수를 입력해주세요. : " << endl;

	cin >> word_Out;

	default_random_engine dre;
	uniform_int_distribution<int> range(0, word_Out - 1);

	int i;

	for (i = 0; i < word_Out; ++i)
	{
		int temp = range(dre);
		while (word[temp]->compare("0") == 0)
			temp = range(dre);
		out << word[temp][0] << "	" << word[temp][1] << endl;
		word[temp][0] = "0";
	}

	in.close();
	out.close();
}