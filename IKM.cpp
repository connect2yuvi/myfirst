#include<iostream> 
#include<string> 
#include<set>
#include<vector>

using namespace std;

//Function to find number of times string in set occured in string L
int findOccurence(std::set<string> &unique, string &L)
{
	int count = 0;
	for (auto it : unique)
	{
		size_t found = L.find(it);
		while (found != string::npos)
		{
			count++;
			found = L.find(it, found + 1);
		}
	}
	return count;
}
#if 0
int main()
{
	string S, L;
	unsigned short int slenght, lLength, type1, type2, type3;
	slenght = lLength = type1 = type2 = type3 = 0;
	//vector<char> appendChar = { 'A', 'G', 'C', 'T' };
	char appendChar[] = { 'A', 'G', 'C', 'T' };

	while (true)
	{
		getline(cin, S);
		if (!S.compare("0") || S.empty())
			break;		

		//extract S and L which is seperated by ' '
		std::size_t found = S.find(' ');
		L = S.substr(found + 1);
		S.erase(found);

		slenght = S.length();
		lLength = L.length();

		//checking for constraints
		if ((slenght > lLength) || (slenght < 2) || 
			(lLength < slenght) || (lLength > 100))
		{
			std::cout << "Enter valid string" << endl;
			S.clear();
			L.clear();
			continue;
		}	

		type1 = type2 = type3 = 0;

		//type1
		std::set<string> unique_strings{ S };
		type1 = findOccurence(unique_strings, L);

		//type2		
		unique_strings.clear();
		string temp;
		for (int i = 0; i < slenght; i++)
		{
			temp = S;
			temp.erase(i, 1); //deleting one character from S
			unique_strings.insert(temp); //insert into set
		}
		type2 = findOccurence(unique_strings, L);
		
		//type3
		//make unique strings by appending the characters at each position in string S
		//store them in set
		unique_strings.clear();
		//for (vector<char>::iterator t = appendChar.begin(); t != appendChar.end(); ++t)
		for (int t = 0; t < 4; t++)
		{
			for (int i = 0; i < slenght + 1; i++)
			{
				temp = S;				
				if (i == 0)
					temp = appendChar[t] + temp;
				else
					temp.insert(i, 1, appendChar[t]);

				unique_strings.insert(temp);
			}
		}
		type3 = findOccurence(unique_strings, L); 
		
		std::cout << type1 << " " << type2 << " " << type3 << endl;

	}//end while
	return 0;
}

#endif