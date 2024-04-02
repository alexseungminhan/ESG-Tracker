#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Linked_list.h"

using namespace std;

Linked_list::Linked_list() :head(nullptr), tail(nullptr) {}

void Linked_list::add_list(node* new_node) {
	if (head == nullptr) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = new_node;
	}

}

void Linked_list::print_list() {
	cout << "\033[31m--------Search Result--------\033[0m" << endl;

	node* cur = head;

	int cnt = 1;

	if (head == nullptr) cout << "empty list" << endl;
	else {
		while (cur != nullptr) {
			cout << "\033[37m" << cnt << "\033[O" << "-----------------" << endl;
			cout << "\033[33mCompany name:\033[O" << cur->name << '('<<cur->ticker<<')'<<endl;
			cout << "\033[34mExchange market:\033[O" << cur->exchange_market << endl;

			cout<< "\033[36mEnvironment score:\033[O" << cur->environment_score << '(' << cur->environment_grade << ')' << endl;
			cout<<"Social score:" << cur->social_score << '(' << cur->social_grade << ')' << endl;
			cout<<"Governance score:" << cur->governance_score << '(' << cur->governance_grade << ')' << endl;
			cout<<"Total score:" << cur->total_score << '(' << cur->total_grade << ')' << endl;
			cnt++;
			cur = cur->next;
		}
		cout << "\033[37m \033[O" << endl;

	}
}

Linked_list* Linked_list::find_name(string name, int sort1, int sort2) {
	node* cur = head;

	Linked_list* new_linked_list = new Linked_list;

	string lower_name = ""; 
	for (int i = 0; i < name.size();i++) {
		if (name[i] >= 65 && name[i] <= 90) lower_name += (name[i] + 32);
		else lower_name += name[i];
	}

	if (head == nullptr) {
		cout << "\033[31mNo Result\033[0m" << endl;
		return nullptr;
	}

	while (cur != nullptr) {
		string lower_cur = ""; 
		for (int i = 0; i < cur->name.size();i++) {
			if (cur->name[i] >= 65 && cur->name[i] <= 90) lower_cur += (cur->name[i] + 32);
			else lower_cur += cur->name[i];
		}
		if (lower_cur.find(lower_name) != string::npos) {

			node* new_node = new node;
			new_node->name = cur->name;
			new_node->ticker = cur->ticker;
			new_node->exchange_market = cur->exchange_market;

			new_node->environment_grade = cur->governance_grade;
			new_node->social_grade = cur->social_grade;
			new_node->governance_grade = cur->governance_grade;

			new_node->environment_score = cur->environment_score;
			new_node->social_score = cur->social_score;
			new_node->governance_score = cur->governance_score;

			new_node->total_grade = cur->total_grade;
			new_node->total_score= cur->total_score;

			new_node->next = nullptr;

			new_linked_list->add_list(new_node);
		}
		cur = cur->next; 
	}

	sort_by(new_linked_list, sort1, sort2); 
	return new_linked_list; 
}

Linked_list* Linked_list::find_ticker(string ticker, int sort1, int sort2) {
	node* cur = head;

	Linked_list* new_linked_list = new Linked_list;

	string lower_ticker = ""; 
	for (int i = 0; i < ticker.size();i++) {
		if (ticker[i] >= 65 && ticker[i] <= 90) lower_ticker += (ticker[i] + 32);
		else lower_ticker += ticker[i];
	}

	if (head == nullptr) {
		cout << "\033[31mNo Result\033[0m" << endl;
		return nullptr;
	}

	while (cur != nullptr) {
		string lower_cur = "";
		for (int i = 0; i < cur->ticker.size();i++) {
			if (cur->ticker[i] >= 65 && cur->ticker[i] <= 90) lower_cur += (cur->ticker[i] + 32);
			else lower_cur += cur->ticker[i];
		}
		if (lower_cur.find(lower_ticker) != string::npos) {

			node* new_node = new node;

			new_node->name = cur->name;
			new_node->ticker = cur->ticker;
			new_node->exchange_market = cur->exchange_market;

			new_node->environment_grade = cur->governance_grade;
			new_node->social_grade = cur->social_grade;
			new_node->governance_grade = cur->governance_grade;

			new_node->environment_score = cur->environment_score;
			new_node->social_score = cur->social_score;
			new_node->governance_score = cur->governance_score;

			new_node->total_grade = cur->total_grade;
			new_node->total_score = cur->total_score;

			new_node->next = nullptr;

			new_linked_list->add_list(new_node);
		}
		cur = cur->next;
	}

	sort_by(new_linked_list, sort1, sort2);
	return new_linked_list;
}

Linked_list* Linked_list::find_industry(string industry, int sort1, int sort2) {
	node* cur = head;

	Linked_list* new_linked_list = new Linked_list;
	
	string lower_category = "";

	for (int i = 0; i < industry.size();i++) {
		if (industry[i] >= 65 && industry[i] <= 90) lower_category += (industry[i] + 32);
		else lower_category += industry[i];
	}

	if (head == nullptr) {
		cout << "\033[31mNo Result\033[0m" << endl;
		return nullptr;
	}

	while (cur != nullptr) {
		string lower_cur = "";
		for (int i = 0; i < cur->industry.size();i++) {

			if (cur->industry[i] >= 65 && cur->industry[i] <= 90) lower_cur += (cur->industry[i] + 32);
			else lower_cur += cur->industry[i];
		}
		if (lower_cur.find(lower_category) != string::npos) {
			node* new_node = new node;

			new_node->name = cur->name;
			new_node->ticker = cur->ticker;
			new_node->exchange_market = cur->exchange_market;

			new_node->environment_grade = cur->governance_grade;
			new_node->social_grade = cur->social_grade;
			new_node->governance_grade = cur->governance_grade;

			new_node->environment_score = cur->environment_score;
			new_node->social_score = cur->social_score;
			new_node->governance_score = cur->governance_score;

			new_node->total_grade = cur->total_grade;
			new_node->total_score = cur->total_score;

			new_node->next = nullptr;

			new_linked_list->add_list(new_node);

		}
		cur = cur->next;
	}

	new_linked_list = sort_by(new_linked_list, sort1, sort2);
	return new_linked_list;
	
}

Linked_list* Linked_list::resverse_list(Linked_list* list) {

	Linked_list* new_linked_list1 = new Linked_list();

	node* cur = list->head;

	while (cur != nullptr) {
		node* temp = new node;

		temp->name = cur->name;
		temp->ticker = cur->ticker;
		temp->exchange_market = cur->exchange_market;
		temp->industry = cur->industry;

		temp->environment_grade = cur->environment_grade;
		temp->social_grade = cur->social_grade;
		temp->governance_grade = cur->governance_grade;

		temp->environment_score = cur->environment_score;
		temp->social_score = cur->social_score;
		temp->governance_score = cur->governance_score;

		temp->total_grade = cur->total_grade;
		temp->total_score = cur->total_score;


		temp->next = new_linked_list1->head;

		new_linked_list1->head = temp;
		cur = cur->next;
	}

	return new_linked_list1;
}

Linked_list* Linked_list::sort_by(Linked_list* list, int sort1, int sort2) {

	node* prev = nullptr;
	node* cur = head;

	for (node* cur = list->head; cur != nullptr; ) {
		bool che = true;
		node* prev2 = nullptr;
		int order[5] = { 0, cur->environment_score,cur->social_score, cur->governance_score, cur->total_score };
		for (node* cur2 = list->head;cur2 != cur;cur2 = cur2->next) {
			int order2[5] = { 0, cur2->environment_score,cur2->social_score, cur2->governance_score, cur2->total_score };

			if (order2[sort2] > order[sort2]) {

				if (prev != nullptr)prev->next = cur->next;
				if (prev2 != nullptr)prev2->next = cur;
				if (cur != nullptr)cur->next = cur2;

				che = false;
				if (cur2 == head) head = cur;
				if (cur == tail) tail = prev;
				break;

			}

			prev2 = cur2;
		}

		if (che)prev = cur;
		if (che == false)cur = prev->next;
		else  cur = cur->next;

	}
	if (sort1 == 1) return list; 
	else return resverse_list(list); 

}