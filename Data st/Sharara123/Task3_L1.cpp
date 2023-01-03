//#include <iostream>
//using namespace std;
//
//
//
//int main() {
//
//	int* xptr = new int, * yptr = new int, * zptr = new int;
//
//	cout << "Enter three values: " << endl;
//	cin >> *xptr;
//	cin >> *yptr;
//	cin >> *zptr;
//
//	//PART (A)
//
//	if (*xptr > *yptr ) {
//		if (*xptr > *zptr) {
//
//			cout << "Greatest is: " << *xptr << endl;
//		}
//	}
//	else if(*yptr > *xptr)
//	{
//		if (*yptr > *zptr)
//		{
//			cout << "Greatest is: " << *yptr << endl;
//		}
//	}
//	else
//	{
//		cout << "Greatest is: " << *zptr << endl;
//	}
//
//	//PART(B)
//
//	int greatest = *xptr > *yptr && *xptr > *zptr ? *xptr : *yptr > *xptr && *yptr > *zptr ? *yptr : *zptr > *xptr && *zptr > *yptr ? *zptr : NULL;
//
//
//	cout << "part b greatest is : " << greatest << endl;
//
//	
//
//	return 0;
//}