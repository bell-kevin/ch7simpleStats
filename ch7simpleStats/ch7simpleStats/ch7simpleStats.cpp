#include <iostream>
using namespace std;
class SimpleStat
{
private:
	int largest; // The largest number recieved so far
	int smallest; // The smallest number recieved so far
	int sum; // The sum of all numbers recieved
	int count; // How many numbers have been recieved
	bool isNewLargest(int); // private class function
	bool isNewSmallest(int); // private class function
public:
	SimpleStat(); // Default constructor
	bool addNumber(int); // Add a number to the stats
	double calcAverage(); // Calculate the average
	int getSmallest() { return smallest; }
	int getLargest() { return largest; }
	int getCount() { return count; } // Return the count
};
//***********************************************************
// The default constructor initializes the class variables. *
//***********************************************************
SimpleStat::SimpleStat()
{
	largest = sum = count = 0;
	smallest = 9999999;
}
//***********************************************************
// The addNumber function adds a number to the stats. *
//***********************************************************
bool SimpleStat::addNumber(int num) {
	bool goodNum = true;
	if (num >= 0) {
		sum += num;
		count++;
		if (isNewLargest(num))
			largest = num;
		if (isNewSmallest(num))
			smallest = num;
}
	else
		goodNum = false;
	return goodNum;
}
//***********************************************************
// The isNewSmallest function determines if the number passed
// is smaller than the smallest number in the stats. *
//***********************************************************
bool SimpleStat::isNewSmallest(int num) {
	if (num < smallest)
		return true;
	else
		return false;
}
//***********************************************************
// The isNewLargest function determines if the number passed
// is larger than the largest number in the stats. *
//***********************************************************
bool SimpleStat::isNewLargest(int num) {
	if (num > largest)
		return true;
	else
		return false;
}
//***********************************************************
// The calcAverage function calculates the average of the *
// numbers. *
//***********************************************************
double SimpleStat::calcAverage() {
	if (count > 0)
		return static_cast<double>(sum) / count;
	else
		return 0;
}
//***********************************************************
// The main function creates a SimpleStat object and calls *
// its member functions. *
//***********************************************************
int main()
{
	int num;
	SimpleStat statHelper;
	cout << "Chapter 7 Simple Stats by Kevin Bell\n\n";
	cout << "Please enter the set of non-negative integer values you want to average. Separate each value with a space. Enter a -1 to end the set.\n\n";
	cin >> num;
	while (num >= 0) {
		if (statHelper.addNumber(num))
			cin >> num;
	} // end while
	cout << "You entered " << statHelper.getCount() << " numbers." << endl;
	cout << "The sum of the numbers is " << statHelper.calcAverage()*statHelper.getCount() << endl;
	cout << "The largest number you entered was " << statHelper.getLargest() << endl;
	cout << "The smallest number you entered was " << statHelper.getSmallest() << endl;
	cout << "The average of the numbers you entered is " << statHelper.calcAverage() << endl;
	system("pause");
	return 0;
}
