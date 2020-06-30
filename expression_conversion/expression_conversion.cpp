#include<iostream>
#include"expression.h"

using namespace std;

int main()
{
	int choice;
	char infix_expression[200];
	expression exp;
	do
	{
		cout << "Menu\n1. Input infix\n2. Display\n3. Infix to Postfix\n4. Infix to Prefix\n5. Evaluate as Postfix\n6. Evaluate as Prefix\n7. Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: // Case to input infix expression
			cout << "\nEnter expression string: ";
			cin >> infix_expression;
			if (exp.create_infix(infix_expression, expression::expression_length(infix_expression)))
				cout << endl << "Infix expression successfully saved";
			else
				cout << endl << "Given expression invalid, not saved";
			cout << endl << endl;
			break;
		case 2:
			if(exp.is_infix())
			{
				cout << endl << "Infix form: ";
				exp.display_infix();
				if(exp.is_postfix())
				{
					cout << endl << "Postfix form: ";
					exp.display_postfix();
				}
				else
					cout << "Enter a valid expression using option 1 and convert it to postfix using option 2";
				if(exp.is_infix())
				{
					cout << endl << "Prefix form: ";
					exp.display_prefix();
				}
				else
					cout << "Enter a valid expression using option 1 and convert it to prefix using option 3";
			}
			else
				cout << endl << "Enter a valid infix expression using option 1";
			cout << endl << endl;
			break;
		case 3: // Case to convert infix expression to postfix
			if (!exp.is_infix())
				cout << endl << "Enter a valid infix expression using option 1";
			else
			{
				exp.infix_to_postfix();
				cout << endl << "Given expression in postfix form is: ";
				exp.display_postfix();
			}
			cout << endl << endl;
			break;
		case 4: // Case to convert infix expression to prefix
			if (!exp.is_infix())
				cout << endl << "Enter a valid infix expression using option 1";
			else
			{
				exp.infix_to_prefix();
				cout << endl << "Given expression in prefix form is: ";
				exp.display_prefix();
			}
			cout << endl << endl;
			break;
		case 5: // Case to evaluate postfix expression
			if (exp.is_postfix())
				cout << endl << "Result = " << exp.evaluate_postfix();
			else
				cout << "Enter a valid expression using option 1 and convert it to postfix using option 2";
			cout << endl << endl;
			break;
		case 6: // Case to evaluate prefix expression
			if (exp.is_prefix())
				cout << endl << "Result = " << exp.evaluate_prefix();
			else
				cout << "Enter a valid expression using option 1 and convert it to prefix using option 3";
			cout << endl << endl;
			break;
		case 7: // Case to exit
			return 0;
			break;
		default: // Case to handle invalid inputs
			cout << "\nInvalid choice. Please try again"<<endl<<endl;
			break;
		}
	} while (1);
	return 0;
}
