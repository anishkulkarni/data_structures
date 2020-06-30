#include"Graph.h"
#include<queue>
#include<stack>
#include<iostream>

using namespace std;

Graph::Graph()
{
	head = NULL;
	user_count = 0;
}

user *Graph::create_user(std::string _name, date _DOB, user_friend *_friend_link, user *_next)
{
	user *temp = new user;
	temp->DOB = _DOB;
	temp->friend_link = _friend_link;
	temp->id = ++user_count;
	temp->name = _name;
	temp->next = _next;
	return temp;
}

void Graph::add_user(std::string _name, date _DOB, user_friend *_friend_link, user *_next)
{
	user *temp = head;
	if (head == NULL) // empty graph
	{
		head = create_user(_name, _DOB, NULL, NULL);
	}
	else // non empty graph
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = create_user(_name, _DOB, NULL, NULL);
	}
}


void Graph::add_friend(int uid, int fid, int comments)
{
	if (fid != uid) // no self-friending
	{
		user *src = head;
		while (src != NULL)
		{
			if (src->id == uid)
				break;
			src = src->next;
		}
		if (src != NULL) // first user found
		{
			user *dst = head;
			while (dst != NULL)
			{
				if (dst->id == fid)
					break;
				dst = dst->next;
			}
			if (dst != NULL) // second user found
			{
				if (src->friend_link == NULL)
				{
					src->friend_link = new user_friend;
					src->friend_link->comment_count = comments;
					src->friend_link->link = dst;
					src->friend_link->next = NULL;
				}
				else
				{
					user_friend *ftemp = new user_friend;
					ftemp->comment_count = comments;
					ftemp->link = dst;
					ftemp->next = NULL;
					user_friend *temp = src->friend_link;
					while (temp->next != NULL)
					{
						if (temp->link->id == fid)
							break;
						temp = temp->next;
					}
					if (temp->link->id == fid)
					{
						temp->comment_count += comments;
						cout << endl << "These two users are already friends comment count for user: " << temp->link->name << " updated";
					}
					else
						temp->next = ftemp;
				}
			}
			else
				cout << endl << "Friend with id: " << fid << " not found";
		}
		else
			cout << endl << "User with id: " << uid << " not found";
	}
	else
		cout << endl << "User cannot be friend with himself";
}

void Graph::display_users()
{
	if (head == NULL) // empty graph
		cout << endl << "Graph is empty";
	else // non empty graph
	{
		cout << endl << "| ID |        Name        |     DOB        |     Friends";
		cout << endl << "|    |                    | dd | mm | yyyy |";
		user *temp = head;
		while (temp != NULL)
		{
			cout << endl;
			cout << "| " << setw(2) << setfill('0') << temp->id << " | " << setw(18) << setfill('.') << temp->name << " | " << setw(2) << setfill('0') << temp->DOB.day << " | " << setw(2) << setfill('0') << temp->DOB.month << " | " << setw(4) << temp->DOB.year << " | ";
			user_friend *ftemp = temp->friend_link;
			while (ftemp != NULL)
			{
				cout << "  " << ftemp->link->name << "(" << ftemp->comment_count << " comments)";
				ftemp = ftemp->next;
			}
			temp = temp->next;
		}
	}
}

void Graph::DFS_display()
{
	if (head == NULL) // empty graph
		cout << endl << "Graph is empty";
	else // non empty graph
	{
		bool *visited = new bool[Graph::user_count];
		for (int i = 0; i < user_count; i++)
			visited[i] = false;
		stack<user *> base_stack;
		if (head == NULL)
			cout << endl << "Graph is empty";
		else
			base_stack.push(head);
		user *temp = NULL;
		cout << endl << "Non Recursive DFS traversal is:" << endl;
		while (!base_stack.empty())
		{
			temp = base_stack.top();
			base_stack.pop();
			visited[temp->id - 1] = true;
			cout << " - " << temp->name;
			user_friend *ftemp = temp->friend_link;
			while (ftemp != NULL)
			{
				if (visited[ftemp->link->id - 1] == 0)
				{
					base_stack.push(ftemp->link);
					visited[ftemp->link->id - 1] = 1;
				}
				ftemp = ftemp->next;
			}
		}
	}
}

void Graph::r_DFS_display()
{
	bool *visited=new bool[user_count];
	cout << endl << "Recursive DFS traversal is:" << endl;
	r_DFS(head,visited);
}

void Graph::r_DFS(user *head,bool *visited)
{
	visited[head->id-1]=true;
	cout << " - " << head->name;
	user_friend *ftemp = head->friend_link;
	while (ftemp != NULL)
	{
		if (visited[ftemp->link->id - 1] == false)
		{
			r_DFS(ftemp->link,visited);
		}
		ftemp = ftemp->next;
	}

}

void Graph::BFS_display()
{
	if (head == NULL) // empty graph
		cout << endl << "Graph is empty";
	else // non empty graph
	{
		int *visited = new int[Graph::user_count];
		for (int i = 0; i < user_count; i++)
			visited[i] = 0;
		queue<user *> base_queue;
		base_queue.push(head);
		user *temp = NULL;
		cout << endl << "BFS traversal on is:" << endl;
		while (!base_queue.empty())
		{
			temp = base_queue.front();
			base_queue.pop();
			visited[temp->id - 1] = 1;
			cout << " - " << temp->name;
			user_friend *ftemp = temp->friend_link;
			while (ftemp != NULL)
			{
				if (visited[ftemp->link->id - 1] == 0)
				{
					base_queue.push(ftemp->link);
					visited[ftemp->link->id - 1] = 1;
				}
				ftemp = ftemp->next;
			}
		}
	}
}

void Graph::max_degree_node()
{
	if (head == NULL) // empty graph
		cout << endl << "Graph is empty";
	else // non empty graph
	{
		int max_degree = 0;
		int degree = 0;
		int *visited = new int[Graph::user_count];
		for (int i = 0; i < user_count; i++)
			visited[i] = 0;
		queue<user *> base_queue;
		base_queue.push(head);
		user *temp = NULL;
		user_friend *ftemp = NULL;
		while (!base_queue.empty())
		{
			degree = 0;
			temp = base_queue.front();
			base_queue.pop();
			visited[temp->id - 1] = 1;
			ftemp = temp->friend_link;
			while (ftemp != NULL)
			{
				degree++;
				ftemp = ftemp->next;
			}
			if (degree >= max_degree)
				max_degree = degree;
			ftemp = temp->friend_link;
			while (ftemp != NULL)
			{
				if (visited[ftemp->link->id - 1] == 0)
				{
					base_queue.push(ftemp->link);
					visited[ftemp->link->id - 1] = 1;
				}
				ftemp = ftemp->next;
			}
		}
		cout << endl << "The nodes having maximum friends: " << max_degree << " are:";
		temp = head;
		while (temp != NULL)
		{
			ftemp = temp->friend_link;
			degree = 0;
			while (ftemp != NULL)
			{
				degree++;
				ftemp = ftemp->next;
			}
			if (degree == max_degree)
			{
				cout << endl << "<" << temp->name << ">";
				ftemp = temp->friend_link;
				while (ftemp != NULL)
				{
					cout << " - " << ftemp->link->name;
					ftemp = ftemp->next;
				}
			}
			temp = temp->next;
		}
	}
}

void Graph::max_comments_node()
{
	if (head == NULL) // empty graph
		cout << endl << "Graph is empty";
	else // non empty graph
	{
		user *max_comments_node = NULL;
		int max_comments = 0;
		int comments = 0;
		user *temp = head;
		user_friend *ftemp = NULL;
		while (temp != NULL)
		{
			comments = 0;
			ftemp = temp->friend_link;
			while (ftemp != NULL)
			{
				comments += ftemp->comment_count;
				ftemp = ftemp->next;
			}
			if (comments > max_comments)
			{
				max_comments = comments;
				max_comments_node = temp;
			}
			temp = temp->next;
		}
		cout << endl << "The nodes having maximum comments: " << max_comments << " are:";
		temp = head;
		while (temp != NULL)
		{
			ftemp = temp->friend_link;
			comments = 0;
			while (ftemp != NULL)
			{
				comments+=ftemp->comment_count;
				ftemp = ftemp->next;
			}
			if (comments == max_comments)
			{
				cout << endl << "<" << temp->name << ">";
				ftemp = temp->friend_link;
				while (ftemp != NULL)
				{
					cout << " - " << ftemp->link->name << "(" << ftemp->comment_count << ")";
					ftemp = ftemp->next;
				}
			}
			temp = temp->next;
		}
	}
}

void Graph::birthday_nodes(int this_day,int this_month,int this_year)
{
	bool flag = false;
	if (head == NULL) // empty graph
		cout << endl << "Graph is empty";
	else // non empty graph
	{
		user *temp = head;
		while (temp != NULL)
		{
			if (temp->DOB.month == this_month)
			{
				if(flag == false)
				{
					cout<<endl;
					switch(this_month)
					{
					case 1:
						cout<<"January";
						break;
					case 2:
						cout<<"February";
						break;
					case 3:
						cout<<"March";
						break;
					case 4:
						cout<<"April";
						break;
					case 5:
						cout<<"May";
						break;
					case 6:
						cout<<"June";
						break;
					case 7:
						cout<<"July";
						break;
					case 8:
						cout<<"August";
						break;
					case 9:
						cout<<"September";
						break;
					case 10:
						cout<<"October";
						break;
					case 11:
						cout<<"November";
						break;
					case 12:
						cout<<"December";
					}
					cout<<" events:";
					flag = true;
				}
				cout << endl << temp->name ;
				if(temp->DOB.day==this_day)
					cout<<" has turned "<< this_year - temp->DOB.year + 1900 <<" years old today";
				else
					{
					if(temp->DOB.day<this_day)
						cout<<" turned ";
					else
						cout<<" turning ";
					cout<<this_year - temp->DOB.year + 1900<<" years old on "<< temp->DOB.day;
				}
			}
			temp = temp->next;
		}
	}
	if(flag == false)
		cout << endl <<"No events yet";
}

Graph::~Graph()
{
}
