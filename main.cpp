#include <iostream>
#include <queue>
#include "File.h"
#include "Linked_list.h"
using namespace std;

int main() {
	Get_file* file = new Get_file("ESG_data.csv");
	
	Linked_list* esg_list = file->get_list(); 
	
	Linked_list* result = new Linked_list; 

	cout << "\033[31m--------Public Company ESG Ratings--------\033[0m" << endl;

	cout << "Search: 0.search all 1. find by name 2. find by ticker 3. find by industry" << endl;
	cout << "\033[36mfind by:\033[0m";

	int select;
	cin >> select;

	cout << "sort by 1. environment score 2.social score 3. governance score 4. total score" << endl;
	cout << "\033[36msort by:\033[0m";
	int sort2;
	cin >> sort2;

	cout << "sort by 1. ascending order 2.descending order" << endl;
	cout << "\033[36msort by:\033[0m";
	int sort1;
	cin >> sort1;

	if (select == 0) { //search all
		result = esg_list->sort_by(esg_list, sort1, sort2);
		result->print_list();
	}

	if (select == 1) { //search by name
		cout << "\033[36mname:\033[0m";
		string name;
		cin >> name;
		result = esg_list->find_name(name, sort1, sort2);
		result->print_list();
	}

	if (select == 2) { //search by ticker
		cout << "\033[36mticker:\033[0m";
		string ticker;
		cin >> ticker;
		result = esg_list->find_ticker(ticker, sort1, sort2);
		result->print_list();
	}

	if (select == 3) { //search by industry
		cout << "\033[36mindustry:\033[0m";
		string industry;
		cin >> industry;
		result = esg_list->find_industry(industry, sort1, sort2);
		result->print_list();
	}
	

}
