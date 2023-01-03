//#include <iostream>
//using namespace std;
//
//
//int main() {
//
//	float* ptr1 = new float; // DMA 
//	cout << "Enter score: " << endl;
//	do
//	{
//		cin >> *ptr1;
//
//	} while (*ptr1 < 0 || *ptr1 > 100);
//
//	float* ptr2 = ptr1;
//
//	if (*ptr2 >= 91 && *ptr2 <= 100)
//	{
//		cout << "A+" << endl;
//	}
//	else if(*ptr2 >= 81 && *ptr2 <= 90)
//	{
//		cout << "A" << endl;
//	}
//	else if (*ptr2 >= 71 && *ptr2 <= 80)
//	{
//		cout << "B" << endl;
//	}
//	else if (*ptr2 >= 61 && *ptr2 <= 70)
//	{
//		cout << "C" << endl;
//	}
//	else if (*ptr2 >= 51 && *ptr2 <= 60)
//	{
//		cout << "D" << endl;
//	}
//	else if (*ptr2 < 51)
//	{
//		cout << "F" << endl;
//	}
//
//	
//	delete ptr2;
//
//
//
//	return 0;
//}