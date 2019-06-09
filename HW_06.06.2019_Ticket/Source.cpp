#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
#include<fstream>
#include"Ticket.h"
#include"Filter.h"
#include"Sort_by.h"
using namespace std;


int main() {

	ifstream in_file("in2.txt");
	list<ticket> ts;
	int n;
	string str1, str2;
	string feature;

	if (!in_file)
		cerr << "file open error" << endl;
	else {
		while (in_file >> n >> str1 >> str2) {//пока идет считывание
			ts.push_back(ticket(n, str1, str2));
		}
	}

	cout << "Enter feature to sort by: flight, departure, passenger" << endl;
	cin >> feature;
	ts.sort(SortBy2(feature)); //in the LIST SortBy is the inner method
	for_each(ts.begin(), ts.end(), [](ticket t) {cout << t << endl; });

	ticket t;
	cout << "Enter the needed date" << endl;
	cin >> str1;
	t.getDeparture() = str1;
	for_each(ts.begin(), ts.end(), filter2("departure", t));
	cout << endl;

	cout << "Enter ticket to delete" << endl;
	ticket t2;
	cin >> t2;
	//cin >> n >> str1 >> str2;
	//ticket t2(n, str1, str2);
	ts.erase(remove_if(ts.begin(), ts.end(),
		[t2](ticket a) {
		return (t2 == a);
	}
	), ts.end());
	for_each(ts.begin(), ts.end(), [](ticket t) {cout << t << endl; });

	system("pause");
	return 0;
}