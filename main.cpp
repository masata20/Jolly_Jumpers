#import <iostream>
#import <sstream> // istringstrem
#import <string> // string line to use getline, and store

using namespace std;

const int MAX_SIZE = 3000;

int abs_value(int); // return absolute value of given integer

void array_init(bool [], int n);

void process_array(bool [], int); // store true if given int value exist
bool test_array(bool [], int); // check the array if all indices have true or false


void display_array(bool [], int); // for debuggin

int main()
{
	
	bool hashed_array[MAX_SIZE]; // it will store 1 if there is the same index number with the difference of two succesive input numbers
	string line;

	while (getline(cin, line))
	{
		if (line == "") break;

		istringstream iss(line);

		int n = 0;
		iss >> n; // first represents the number of digits in the line

		array_init(hashed_array, n+1);
		int current_value;
		int previous_value;
		for ( int i = 0; i < n; i++)
		{
			iss >> current_value;
			if (i != 0)
			{
				int diff = current_value - previous_value;


				process_array(hashed_array, abs_value(diff));

			//	cout << "difference between " << current_value << "and"
			//		<< previous_value << "is " << abs_value(diff) << endl;
			}

			previous_value = current_value;
		}

		//display_array(hashed_array, n);

		if (test_array(hashed_array, n))
			cout << "Jolly" << endl;
		else
			cout << "Not Jolly" << endl; 

	}


	return 0;

}

int abs_value(int value)
{
	if (value < 0)
		value *= -1;

	return value;
}

void process_array(bool arr[], int diff)
{	
	if (diff < MAX_SIZE)
	{
	//	cout << "make index " << diff << " is true" << endl;
		arr[diff] = true;
	}

}

bool test_array(bool arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (!arr[i])
			return false;
	}

	return true;
}

void display_array(bool arr[], int n)
{
	for (int i = 1; i < n; i++)
		cout << "index " << i << " has " << arr[i] << endl;

}

void array_init(bool arr[], int n)
{

	for (int i = 0; i < n+1; i++)
		arr[i] = false;
}



