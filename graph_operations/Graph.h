#ifndef GRAPH_H_
#define GRAPH_H_

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct user;

struct date
{
	int day, month, year;
};

struct user_friend
{
	user *link;
	int comment_count;
	user_friend *next;
};

struct user
{
	int id;
	std::string name;
	date DOB;
	user_friend *friend_link;
	user *next;
};

class Graph
{
	user *head;
	int user_count;
public:
	Graph();
	user *create_user(std::string, date, user_friend *friend_link = NULL, user *_next = NULL);
	void add_user(std::string, date, user_friend *_friend_link = NULL, user *_next = NULL);
	void add_friend(int, int, int);
	void display_users();
	void DFS_display();
	void r_DFS_display();
	void r_DFS(user *,bool *);
	void BFS_display();
	void max_degree_node();
	void max_comments_node();
	void birthday_nodes(int,int,int);
	virtual ~Graph();
};

#endif
