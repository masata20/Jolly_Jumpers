#import <iostream>
#import <sstream> // istringstrem
#import <string> // string line to use getline, and store

using namespace std;

const int MAX_SIZE = 3000;

int abs_value(int);

int main()
{
	
	bool hashed_array[MAX_SIZE]; // it will store 1 if there is the same index number with the difference of two succesive input numbers
	string line;

	while (getline(cin, line))
	{
		if (line == "") break;

		istringstream iss(line);

		int n = 0;
		int current_value;
		int previous_value;
		while (iss >> current_value)
		{
			if (n != 0)
			{
				int diff = current_value - previous_value;

				cout << "difference between " << current_value << "and"
					<< previous_value << "is " << abs_value(diff) << endl;
			}
			
			//cout << "value is " << value << endl;

			previous_value = current_value;
			n++;
		}

	}


	return 0;

}

int abs_value(int value)
{
	if (value < 0)
		value *= -1;

	return value;
}
