//Mahad Saleem // I210475@nu.edu.pk

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "stack.h"
#include "queue.h"
using namespace cv;
using namespace std;





int task4(string path1 = "\\Images\\Img2.png") {

	//cout << path1;
	string path = "C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 2" + path1 + ".png";
	string wrpath = "C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 2\\Images\\";

	//string gndPath = "C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\Ground Truths\\IMD043_lesion.bmp";
	cv::Mat img = cv::imread(path, 0);
	namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);

	cv::imshow("First OpenCV Application", img);


	stack<int> stk;
	int lsz = 500000;
	int* labels = new int [lsz] {0};

	int label = 10, l = 0;

	for (int i = 1; i < img.rows; i++)
	{
		for (int j = 1; j < img.cols; j++)
		{

			Scalar up = img.at<uchar>(i, j);
			Scalar left = img.at<uchar>(i, j);
			Scalar lD = img.at<uchar>(i, j);
			Scalar rD = img.at<uchar>(i, j);

			if (up.val[0] == 255)
			{
				up = img.at<uchar>(i - 1, j);
				left = img.at<uchar>(i, j - 1);
				lD = img.at<uchar>(i - 1, j - 1);
				rD = img.at<uchar>(i - 1, j + 1);
				if (up.val[0] == 0 && left.val[0] == 0 && lD.val[0] == 0 && rD.val[0] == 0)
				{

					img.row(i).col(j) = label;
					label += 1;
					//cout << label << " ";
				}
				else if (up.val[0] != 0 || left.val[0] != 0 || lD.val[0] != 0 || rD.val[0] != 0)
				{
					int arr[4] = { 0 };
					arr[0] = left.val[0];
					arr[1] = lD.val[0];
					arr[2] = up.val[0];
					arr[3] = rD.val[0];

					int min = 999999;

					for (int m = 0; m < 4; m++)
					{
						if (min > arr[m] && arr[m] != 0)
						{
							min = arr[m];
							/*	if (min != 0)
									cout << min << " ";*/
						}
					}
					labels[l] = min;
					img.row(i).col(j) = min;
					l++;
					//cout << l << " ";
				}




			}


		}


	}

	//cout << label<<endl;







	cv::imshow("First OpenCV Application", img);
	cv::waitKey(0);



	for (int j = img.cols - 1; j > 0; j--)
	{
		for (int i = img.rows - 1; i > 0; i--)
		{

			Scalar curr = img.at<uchar>(i, j);
			Scalar next = img.at<uchar>(i, j + 1);
			Scalar up = img.at<uchar>(i - 1, j);
			Scalar left = img.at<uchar>(i, j - 1);
			Scalar lD = img.at<uchar>(i - 1, j - 1);
			Scalar rD = img.at<uchar>(i - 1, j + 1);


			if (curr.val[0] != up.val[0] && curr.val[0] != 0 && up.val[0] != 0) {
				img.row(i - 1).col(j) = curr.val[0];
			}
			/*if (curr.val[0] != val1 && curr.val[0] != 0) {
				if (next.val[0] == val1 || left.val[0] == val1 || dn.val[0] == val1 || rD.val[0] == val1 || lD.val[0] == val1) {
					img.row(i).col(j) = val1;
				}
			}*/





		}

	}

	for (int i = img.rows - 1; i > 0; i--)
	{
		for (int j = img.cols - 1; j > 0; j--)
		{

			Scalar curr = img.at<uchar>(i, j);
			Scalar prev = img.at<uchar>(i, j - 1);
			Scalar up = img.at<uchar>(i - 1, j);
			Scalar left = img.at<uchar>(i, j - 1);
			Scalar lD = img.at<uchar>(i - 1, j - 1);
			Scalar rD = img.at<uchar>(i - 1, j + 1);


			if (curr.val[0] != prev.val[0] && curr.val[0] != 0 && prev.val[0] != 0) {
				img.row(i).col(j - 1) = curr.val[0];
			}
			/*if (curr.val[0] != val1 && curr.val[0] != 0) {
				if (next.val[0] == val1 || left.val[0] == val1 || dn.val[0] == val1 || rD.val[0] == val1 || lD.val[0] == val1) {
					img.row(i).col(j) = val1;
				}
			}*/





		}

	}


	//cv::imshow("First OpenCV Application", img);
	//cv::waitKey(0);


	int objs[300]{ 0 }, k = 0;
	bool isDuplicate = false;

	cout << endl;

	for (int i = 0; i < img.rows; i++)
	{

		for (int j = 0; j < img.cols; j++)
		{

			Scalar curr = img.at<uchar>(i, j);
			isDuplicate = false;

			if (curr.val[0] != 0) {

				for (int o = 0; o < 300; o++)
				{
					if (curr.val[0] == objs[o]) {
						isDuplicate = true;
						break;
					}
				}
				if (!isDuplicate) {
					objs[k] = curr.val[0];
					k++;
				}
			}



			/*if (curr.val[0] == 105) {

				img.row(i).col(j) = 255;
			}
			else
			{
				img.row(i).col(j) = 0;

			}*/



		}

	}

	cv::Mat img1;

	for (int l = 0; l < k; l++)
	{
		cout << objs[l] << " ";
		img1 = img.clone();

		for (int i = 0; i < img1.rows; i++)
		{

			for (int j = 0; j < img1.cols; j++)
			{

				Scalar curr = img1.at<uchar>(i, j);





				if (curr.val[0] == objs[l]) {

					img1.row(i).col(j) = 255;
				}
				else
				{
					img1.row(i).col(j) = 0;

				}



			}


		}

		cv::imshow("not First OpenCV Application", img1);
		cv::waitKey(0);
		imwrite(wrpath + to_string(l+rand()) + ".png", img1);


	}








	/*cv::imshow("not First OpenCV Application", img);
	cv::waitKey(0);*/
	cv::destroyAllWindows();
	return k;


}

string extractTagName(string tag) {

	string result;


	for (int i = 0; i < tag.length(); i++)
	{
		if (tag[i] != '|' && tag[i] != '\\') {
			result += tag[i];
		}
	}

	return result;

}

bool validExpression(string exp) {



	stack<char> stk;

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(') {
			stk.push(exp[i]);
		}
		else if (exp[i] == ')')
		{
			if (stk.sizeofstack() == 0)
			{
				return false;
			}
			stk.pop();
		}
	}

	for (int i = 0; i < exp.length() - 1; i++)
	{
		if ((exp[i] >= 'a' && exp[i] <= 'z') && (exp[i + 1] >= 'a' && exp[i + 1] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') && (exp[i + 1] >= 'A' && exp[i + 1] <= 'Z')) {
			stk.push(exp[i]);
		}

	}
	if (stk.sizeofstack() != 0) {
		return false;
	}

	if (!((exp[0] >= 'a' && exp[0] <= 'z') || (exp[0] >= 'A' && exp[0] <= 'Z') || (exp[0] >= '0' && exp[0] <= '9') || exp[0] == '(')) {
		return false;
	}
	if (!((exp[exp.length() - 1] >= 'a' && exp[exp.length() - 1] <= 'z') || (exp[exp.length() - 1] >= 'A' && exp[exp.length() - 1] <= 'Z') || (exp[exp.length() - 1] >= '0' && exp[exp.length() - 1] <= '9')
		|| (exp[exp.length() - 1] == ')'))) {
		return false;
	}

	return true;

}

bool compareTags(string strtTag, string endTag) {

	strtTag = extractTagName(strtTag);
	endTag = extractTagName(endTag);

	if (strtTag == endTag) {
		//cout << strtTag << "\t" << endTag << endl;
		return true;
	}

	return false;

}

string tagsComplete(string fileName) {

	ifstream test1;
	string line;
	string startTag, endTag;
	stack<string> tagsStack, endtagsStack;

	int i = 0;
	test1.open(fileName);

	while (getline(test1, line)) {

		for (i = 0; i < line.length(); i++)
		{

			if (line[i] == '|') {

				startTag += line[i];
				i++;
				for (; line[i] != '|' && i < line.length(); i++)
				{
					startTag += line[i];

				}
				startTag += line[i];

				//cout << startTag << endl;

				if (startTag[1] != '\\')
				{
					tagsStack.push(startTag);
					//cout << startTag << endl;

				}
				if (startTag[1] == '\\') {

					endtagsStack.push(startTag);
					//cout << startTag << endl;


				}


				startTag.clear();

				//text.clear();
			}



		}
		//cout << endl;
		if (endtagsStack.sizeofstack() != 0 && tagsStack.sizeofstack() != 0) {

			string startTag1 = extractTagName(tagsStack.Peek()->val);
			string endTag1 = extractTagName(endtagsStack.Peek()->val);
			if (compareTags(startTag1, endTag1)) {
				tagsStack.pop();
				endtagsStack.pop();
				/*cout << "\n" << startTag;
				cout << "		 " << endTag << endl;*/
			}

		}

	}






	test1.close();
	//temp.print();

	stack<string> temp;


	//tagsStack.print();
	for (int i = 0; !tagsStack.isEmpty(); i++)
	{
		temp.push(tagsStack.Peek()->val);
		tagsStack.pop();

	}

	/*temp.print();

	cout << endl;
	endtagsStack.print();*/


	{

		string* arr1 = new string[temp.size];
		string* arr2 = new string[endtagsStack.size];
		int sz1 = temp.size;
		int sz2 = endtagsStack.size;

		for (int i = 0; i < sz1; i++)
		{
			arr1[i] = temp.Peek()->val;
			temp.pop();
			//cout << arr1[i];
		}
		//cout << endl;
		for (int j = 0; j < sz2; j++)
		{
			arr2[j] = endtagsStack.Peek()->val;
			endtagsStack.pop();

			//cout << arr2[j];

		}
		//cout << endl;
		for (int i = 0; i < sz1; i++)
		{
			for (int j = 0; j < sz2; j++)
			{
				string startTag1 = arr1[i];
				string endTag1 = arr2[j];
				if (compareTags(startTag1, endTag1)) {

					arr1[i] = "1";
					arr2[j] = "1";

				}

			}
		}

		for (int i = 0; i < sz1; i++)
		{
			//cout << arr1[i] ;
			if (arr1[i] != "1")
				return arr1[i];
		}
		//cout << endl;
		for (int i = 0; i < sz2; i++)
		{
			//cout << arr2[i];
			if (arr2[i] != "1")
				return arr2[i];
		}
		return "true";



	}


}



int prec(char c)
{
	if (c == '^' || c == '$')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}


string infixToPostfix(string s)
{
	string exp = s;
	s.clear();
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] != ' ')
			s += exp[i];
	}

	if (!validExpression(s)) {
		return "Invalid Expression";
	}

	stack<char> st;
	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c >= '0' && c <= '9'))
			result += c;


		else if (c == '(')
			st.push('(');

		else if (c == ')') {
			while (st.top->val != '(') {
				result += st.top->val;
				st.pop();
			}
			st.pop();
		}

		else {
			while (!st.isEmpty()
				&& prec(s[i]) <= prec(st.top->val)) {
				result += st.top->val;
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.isEmpty()) {
		result += st.top->val;
		st.pop();
	}

	//cout << result << endl;

	return result;
}


string infixToPrefix(string exp) {

	string s = exp;
	exp.clear();
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
			exp += s[i];
	}
	if (!validExpression(exp)) {
		return "Invalid Expression";

	}

	reverse(exp.begin(), exp.end());
	string prefx;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(') {
			exp[i] = ')';
		}
		else if (exp[i] == ')')
		{
			exp[i] = '(';

		}
	}
	prefx = infixToPostfix(exp);

	reverse(prefx.begin(), prefx.end());


	return prefx;

}


string postfixToInfix(string exp) {

	string s = exp;
	string result;
	exp.clear();
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
			exp += s[i];
	}

	if (validExpression(exp)) {
		return exp;
	}

	stack<string> st;

	if ((exp[0] >= '0' && exp[0] <= '9')) {
		for (int i = 0; i < exp.length(); i++)
		{
			if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9')) {

				string operatore(1, exp[i]);
				st.push(operatore);
			}
			else
			{
				string operand1, operand2;
				if (!st.isEmpty()) {
					operand1 = st.top->val;
					st.pop();
				}
				if (!st.isEmpty()) {
					operand2 = st.top->val;
					st.pop();
				}

				st.push('(' + operand2 + exp[i] + operand1 + ')');



			}
		}
		result = st.top->val;
		string res;
		for (int i = 0; i < result.length(); i++)
		{
			if (!((result[i - 1] == '(') && ((result[i] == '*') || (result[i] == '*') || (result[i] == '/') || (result[i] == '+') || (result[i] == '-'))))
				res += result[i];
		}
		result = res;
	}
	else
	{
		for (int i = 0; i < exp.length(); i++)
		{
			if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9')) {

				string operatore(1, exp[i]);
				st.push(operatore);
			}
			else
			{
				string operand1 = st.top->val;
				st.pop();
				string operand2 = st.top->val;
				st.pop();

				st.push('(' + operand2 + exp[i] + operand1 + ')');

			}
			result = st.top->val;
		}

	}


	cout << result;
	//cout << result << endl;
	return result;
}

string getText(string line, string strtTag, int loc) {

	ifstream test1;
	string  tagName, expTag;
	string exp;
	int i = 0;
	i += loc;

	bool isTagEnd = true, isExp = false;

	for (; i < line.length(); i++)
	{
		int j = i;

		if (line[i] == '|') {

			do
			{
				tagName += line[j];
				j++;
				if (line[j] == ' ') {

					break;
				}
			} while (line[j] != '.' && j < line.length());
			if (tagName == strtTag) {
				expTag = tagName;
				//cout << tagName<<endl;
			}
			isTagEnd = !isTagEnd;
			i++;
		}
		if (isTagEnd) {
			if (expTag == strtTag) {

				for (; line[j] != '|'; j++)
				{
					exp += line[j];
					isTagEnd = false;
				}

				if (!isTagEnd)
				{
					isTagEnd = true;
					//cout << exp << endl;
					return exp;
				}

				expTag.clear();

				//cout << tagName<<endl;
			}


			//text.clear();
		}
		tagName.clear();

	}
	//cout << text;

	exp.clear();
	//cout << endl;


}




void extractText(string fileName) {

	ifstream test1;
	ofstream resultTxt;
	string line, tagName, expTag;
	string text;
	int i = 0;

	bool isTagEnd = true, isExp = false;

	test1.open(fileName);
	resultTxt.open("result.txt", ios::app);


	while (getline(test1, line)) {

		for (i = 0; i < line.length(); i++)
		{

			if (line[i] == '|') {
				//tagName += line[i];
				int j = i;

				do
				{
					tagName += line[j];
					j++;
					if (line[j] == ' ') {

						break;
					}
				} while (line[j] != '.' && j < line.length());
				if (tagName == "|post_exp|" || tagName == "|pre_exp|" || tagName == "|sol_exp|" || tagName == "|src|" || tagName == "|tab|") {
					expTag = tagName;
					if (expTag == "|tab|")
					{

						tagName.clear();
						text += "\t";
					}
					tagName.clear();
					//cout << tagName<<endl;
				}
				isTagEnd = !isTagEnd;
				i++;
			}
			if (isTagEnd) {
				text += line[i];

				if (expTag == "|post_exp|" || expTag == "|pre_exp|" || expTag == "|pre_exp|" || expTag == "|sol_exp|" || expTag == "|sol_exp|" || expTag == "|src|" || expTag == "|src|" || expTag == "|tab|") {

					//cout << expTag;
					//cout<<<<endl;
					if (expTag == "|post_exp|") {
						string postExp = infixToPostfix(getText(line, expTag, i - 10));

						text += postExp;
						i += getText(line, expTag, 0).length() - 1;

						//cout << text << endl;


						/*if (postExp == "Invalid Expression") {
							i = line.length() - 1;
						}*/
						//text += infixToPostfix(getText(line, expTag, 0));


					}
					else if (expTag == "|pre_exp|")
					{
						text += infixToPrefix(getText(line, expTag, 0));
						i += getText(line, expTag, 0).length() - 1;


					}
					else if (expTag == "|sol_exp|")
					{
						text += postfixToInfix(getText(line, expTag, 0));
						i += getText(line, expTag, 0).length() - 1;
					}
					else if (expTag == "|src|")
					{

						string st1 = getText(line, expTag, 0);
						string st2;

						for (int i = 0; i < st1.length(); i++)
						{
							if (st1[i] != ' ')
							{
								st2 += st1[i];
							}




						}

						int ans = task4(st2);
						text += to_string(ans);
						i += getText(line, expTag, 0).length() - 1;




					}


					expTag.clear();

					//cout << tagName<<endl;
				}


				//text.clear();
			}
			tagName.clear();



		}
		//cout << text;
		resultTxt << endl;
		resultTxt << text;
		text.clear();
		//cout << endl;

	}

	resultTxt.close();
	test1.close();


}

int getPrioirity(string fileName) {


	ifstream test1;
	ofstream resultTxt;
	string line, tagName, expTag;
	string text;
	int i = 0;

	bool isTagEnd = true, isExp = false;

	test1.open(fileName);


	while (getline(test1, line)) {

		if (i == 2) {


			for (int j = 0; j < line.length(); j++)
			{
				if (line[j] >= '0' && line[j] <= '9') {
					text += line[j];
				}
			}
			i = stoi(text);
			//cout <<  i;
			break;
		}

		i++;

	}

	test1.close();

	return i;


}





void task3(int files) {

	ofstream resultTxt;

	Queue<int> allfiles, fixed;

	int hits = 0, faults = 0;

	for (int i = 1; i <= files; i++)
	{
		allfiles.Enqueue(getPrioirity("Test_files/Test-" + to_string(i) + ".txt"));
	}


	for (int i = 1; i <= files; i++)
	{

		if (fixed.search(allfiles.front->data)) {
			allfiles.Dequeue();
			hits++;
		}
		else
		{
			if (fixed.size < 4) {
				if (!fixed.search(allfiles.front->data)) {
					fixed.Enqueue(allfiles.retFront());
					allfiles.Dequeue();
					faults++;
				}
			}
			else if (fixed.size >= 4)
			{
				if (!fixed.search(allfiles.front->data)) {

					fixed.Dequeue();
					fixed.Enqueue(allfiles.retFront());
					allfiles.Dequeue();

					faults++;
				}
			}
		}

		//cout << fixed.retFront() << " ";

	}



	cout << "\nhits: " << hits << endl;
	cout << "faults: " << faults << endl;

	resultTxt.open("result.txt", ios::app);

	resultTxt << endl;

	resultTxt << "LRU Result: " << "  hits: " << hits << "  faults: " << faults;

	resultTxt.close();

}

void ErrorDetection(int files) {


	string fileName;


	for (int i = 1; i <= files; i++)
	{
		fileName = "Test_files/Test-" + to_string(i) + ".txt";

		if (tagsComplete(fileName) != "true")
		{
			ofstream resultTxt;

			resultTxt.open("result.txt", ios::app);


			resultTxt << "Syntax Error";

			resultTxt.close();


		}
		else {

			extractText(fileName);

		}

	}


	task3(files);





}

int main() {


	stack<string> tagsStack;

	//cout << tagsComplete("Test_files/Test-7.txt");
	ErrorDetection(7);
	/*cout << getPrioirity("Test_files/Test-2.txt");
	tagsStack.print();*/

	//task3(7);

	//1//3//4//6

	return 0;
}

