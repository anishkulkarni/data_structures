#include <iostream>
#include<ctime>
#include"Graph.h"
using namespace std;

int main()
{
	int choice;
	Graph g;
	do
	{
		cout << "Menu\n1. Create User\n2. Display All Users\n3. Add friend\n4. Find user with maximum friends\n5. Find user with maximum comments\n6. Find user with birthday in this month\n7. Display DFS traversal\n8. Display BFS traversalS\n9. Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: // Case to create new user
		{
			string name;
			date DOB;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter date of birthday (dd mm yyyy): ";
			cin >> DOB.day >> DOB.month >> DOB.year;
			g.add_user(name, DOB);
			cout << endl << endl;
			break;
		}
		case 2: // Case to display all users
			g.display_users();
			cout << endl << endl;
			break;
		case 3: // Case to add friend
			int uid, fid, com1, com2;
			cout << "Enter id of user: ";
			cin >> uid;
			cout << "Enter id of friend: ";
			cin >> fid;
			cout << "Enter comments of user on friend: ";
			cin >> com1;
			cout << "Enter comments of friend on user: ";
			cin >> com2;
			g.add_friend(uid, fid, com1);
			g.add_friend(fid, uid, com2);
			cout << endl << endl;
			break;
		case 4: // Case to find user/s with maximum friends
			g.max_degree_node();
			cout << endl << endl;
			break;
		case 5: // Case to find user/s with maximum comments
			g.max_comments_node();
			cout << endl << endl;
			break;
		case 6: // Case to find user/s having birthday in specified month
			{
				//cout << endl << "Enter current month: ";
				time_t now = time(0);
				tm *ltm = localtime(&now);
				//cin >> choice;
				//g.birthday_nodes(choice);
				g.birthday_nodes(ltm->tm_mday,1 + ltm->tm_mon,ltm->tm_year);
				cout << endl << endl;
				break;
			}
		case 7: // Case to display DFS traversal
			g.DFS_display();
			g.r_DFS_display();
			cout << endl << endl;
			break;
		case 8: // Case to display BFS traversal
			g.BFS_display();
			cout << endl << endl;
			break;
		case 9: // Case to exit
			return 0;
			cout << endl << endl;
			break;
		default: // Case to handle invalid choice
			cout << endl << "Invalid choice" << endl << endl;
			break;
		}
	} while (1);
	return 0;
}
