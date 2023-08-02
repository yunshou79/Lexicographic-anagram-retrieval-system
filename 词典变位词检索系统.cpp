// Program to find all anagrams of a given word, using a dictionary

// read from a file

#include <iostream>

#include <fstream>

#include <string>

#include <vector>

#include <algorithm>

#include <iterator>

using namespace std;

typedef istream_iterator<string> string_input;





// ��ӭ����

void welcome()

{

	cout << "******************* A search system for anagrams******************\n"

		<< "Find all the variants of a given string in the dictionary" << endl;

}



// ����ʵ��ļ�,���Դʵ䵥��.���дʵ�������

void readDict(vector<string> & dictionary)

{

	// ���û���ȡ�ļ�����

	cout << "Please enter a dictionary name" << endl;

	string dictionary_name; 

	cin >> dictionary_name;

	// ���ļ�

	ifstream ifs(dictionary_name.c_str());

	// �����쳣

	if (!ifs.is_open()) 

	{

		cerr << "Exception: file"<< dictionary_name 

			<< "Can't find " << endl;

		exit(1);

	}

	cout << "Reading file..." << flush;

	// ���ʵ��ļ����ݶ��뵽�ַ�������dictionary��

	copy(string_input(ifs), string_input(),

		back_inserter(dictionary));

	// Ϊ���ں���Ĳ��Ҳ������Դʵ�����

	sort(dictionary.begin(),dictionary.end());

	// ����ʵ�����

	cout << "Word file is ready,Dictionary contains " 

		<< dictionary.size() << " words\n\n";

	// �ر��ļ�

	ifs.close();

}


// ��ȡ�û����ʣ����ұ�λ�ʲ����

void analyseAnagram(const vector<string> & dictionary)

{

	cout << "Please input a word: " << endl;

	// ʹ��������������p�����û��ӱ�׼������cin������ַ�����

	// ֱ���û�������������־

	for (string_input p(cin); p != string_input(); ++p) 

	{

		cout << "Find the anagram of the input word..." << endl;

		string word = *p;

		// ������word�����Ա�����ȫ����

		sort(word.begin(), word.end());

		// ��¼�Ƿ��ڴʵ��в��ұ�λ�ʳɹ�

		bool found_one = false;



		do 

		{

			if (binary_search(dictionary.begin(),

					dictionary.end(),

					word))

			// �Դʵ�Ĵ������ж��ֲ��ң�������ҳɹ���

			// ����ñ�λ�ʣ�����found_oneΪtrue

			{

				cout << "  " << word ;

				found_one = true;

			}

		} while (next_permutation(word.begin(), word.end()));

			// ��ð��մʵ�˳�����һ�����У�����ɹ�����ʼ��һ�ֲ���

		// û���ҵ�������

		if (!found_one) 

			cout << "  Sorry, no anagram found\n";



		// ��ʾ��ʼ׼���µĹ���

		cout << "\nPlease enter the next word " 

			<< "Ctrl+Z Terminate the program: " << endl;

	}

}

int main() 

{

	welcome();

	vector<string> dictionary;

	readDict(dictionary);

	analyseAnagram(dictionary);



	system("pause");

	return 0;

}



