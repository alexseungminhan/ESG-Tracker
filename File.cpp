#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include "File.h"

using namespace std;

Get_file::Get_file(string file_name) { 
	list = new Linked_list();
	string data;
	fstream fs; 

	fs.open(file_name, ios::in);

	for (int i = 0; i < 723; i++) {
		getline(fs, data, '\n'); 
		if (i == 0) continue;

		vector<string> ans = split_data(data);

		if (ans.size() > 0) {
			node* new_node = new node();


			new_node->ticker = ans[0];
			new_node->name = ans[1];
			new_node->exchange_market = ans[3];
			new_node->industry = ans[4];

			new_node->environment_grade = ans[7];
			new_node->social_grade = ans[9];
			new_node->governance_grade = ans[11];

			new_node->environment_score = stoi(ans[13]);
			new_node->social_score = stoi(ans[14]);
			new_node->governance_score = stoi(ans[15]);

			new_node->total_score = stoi(ans[16]);
			new_node->total_grade = ans[18];

			list->add_list(new_node);

		}

	}
}

vector<string> Get_file::split_data(string line) {

	vector<string> split_list;
	istringstream tokenStream(line);

	int cnt = 0;

	while (true) {
		string temp;
		getline(tokenStream, temp, ',');
		if (cnt < 20) split_list.push_back(temp);
		else break; 
		cnt++;
	}
	return split_list;
}

Linked_list* Get_file::get_list() {
	return list; 
}