#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include<iostream>
#include<string>
#include <vector>
#include <queue>

using namespace std;

typedef struct node { //company node
	
	string ticker;
	string name;
	string exchange_market;
	string industry;

	string environment_grade;
	string social_grade;
	string governance_grade;

	int environment_score;
	int social_score;
	int governance_score;

	int total_score;
	string total_grade;

	node* next;
	

} node;

class Linked_list {
	node* head;
	node* tail; 

public:
	Linked_list();
	void add_list(node* new_node); //add node to linked list
	void print_list(); //print entire linked list

	
	Linked_list* find_name(string name, int sort1, int sort2); //find list by name
	Linked_list* find_ticker(string ticker, int sort1, int sort2); //find list by ticker
 
	Linked_list* find_industry(string industry, int sort1, int sort2); //find list by industry

	Linked_list* sort_by(Linked_list* list, int sort1, int sort2); 
	//sort list 
	//:param sort1: search by descending or ascending order
	//:param sort2: search by ranking or number of reviews

	Linked_list* resverse_list(Linked_list* list); //reverse linked list
	
};

#endif __LINKED_LIST_H__

