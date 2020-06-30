#include "expression.h"
#include "stack.h"
#include "stack.cpp"
#include<iomanip>
#include<cstring>
#include<cmath>

expression::expression()
{
	infix = NULL;
	postfix = NULL;
	prefix = NULL;
	length = -1;
}

bool expression::create_infix(char *x, int len)
{
	int i = 0;
	delete infix;
	if (len == 0) // Empty expression
	{
		infix = NULL;
		return false;
	}
	length = len;
	infix = new char[len + 1];
	while (x[i] != '\0') // Copy expression
	{
		infix[i] = x[i];
		i++;
	}
	infix[i] = '\0';
	if (!is_valid()) // Check expression validity
	{
		delete infix;
		infix = NULL;
		length = -1;
		return false;
	}
	return true;
}

void expression::infix_to_postfix()
{
	delete postfix;
	postfix = new char[length + 1];
	stack<char> base_stack;
	int i = 0, k = 0;
	std::cout << std::endl << "-------------------------------------------------------------------------------------------------------";
	std::cout << std::endl << "| Considered Symbol | Postfix string (after previous pass) | Current stack contents (top at the left) |";
	std::cout << std::endl << "-------------------------------------------------------------------------------------------------------";
	while (infix[i] != '\0')
	{
		if (is_alpha(infix[i])) // Add variable to postfix expression
			postfix[k++] = infix[i++];
		else if (infix[i] == '(') // Push opening parenthesis to stack
			base_stack.push(infix[i++]);
		else if (infix[i] == ')') // Pop all stack contents
		{
			while (base_stack.peek() != '(')
				postfix[k++] = base_stack.pop();
			base_stack.pop();
			i++;
		}
		else // Handle operator according to precedence and associativity rules
		{
			while ((!base_stack.is_empty()) && (base_stack.peek() != '(') && (precedence(base_stack.peek()) > precedence(infix[i])))
				postfix[k++] = base_stack.pop();
			if ((!base_stack.is_empty()) && (base_stack.peek() != '(') && (precedence(base_stack.peek()) == precedence(infix[i])))
				if (associativity(infix[i]) == LTR)
					postfix[k++] = base_stack.pop();
			base_stack.push(infix[i++]);
		}
		postfix[k] = '\0';
		std::cout << std::endl << "| " << std::setw(19) << infix[i - 1] << " | " << std::setw(34) << postfix << " | ";
		base_stack.display();
		std::cout << std::endl << "-------------------------------------------------------------------------------------------------------";
	}
	while (!base_stack.is_empty()) // Pop all remaining stack contents
		postfix[k++] = base_stack.pop();
	postfix[k] = '\0';
	std::cout << std::endl << "| " << std::setw(19) << infix[i] << " | " << std::setw(34) << postfix << " | ";
	base_stack.display();
	std::cout << std::endl << "-------------------------------------------------------------------------------------------------------";
}

void expression::infix_to_prefix()
{
	delete prefix;
	int i = strlen(infix)-1;
	int k = length;
	prefix = new char[length + 1];
	prefix[k--] = '\0';
	stack<char> base_stack;
	std::cout << std::endl << "-------------------------------------------------------------------------------------------------------";
	std::cout << std::endl << "| Considered Symbol | Prefix string (after previous pass) | Current stack contents (top at the left) |";
	std::cout << std::endl << "-------------------------------------------------------------------------------------------------------";
	while (i >= 0)
	{
		if (is_alpha(infix[i])) // Add variable to postfix expression
			prefix[k--] = infix[i--];
		else if (infix[i] == ')') // Push closing parenthesis to stack
			base_stack.push(infix[i--]);
		else if (infix[i] == '(') // Pop all stack contents
		{
			while (base_stack.peek() != ')')
				prefix[k--] = base_stack.pop();
			base_stack.pop();
			i--;
		}
		else // Handle operator according to precedence and associativity rules
		{
			while ((!base_stack.is_empty()) && (base_stack.peek() != ')') && (precedence(base_stack.peek()) > precedence(infix[i])))
				prefix[k--] = base_stack.pop();
			if ((!base_stack.is_empty()) && (base_stack.peek() != ')') && (precedence(base_stack.peek()) == precedence(infix[i])))
				if (associativity(infix[i]) == RTL)
					prefix[k--] = base_stack.pop();
			base_stack.push(infix[i--]);
		}
		std::cout << std::endl << "| " << std::setw(18) << infix[i + 1] << " | " << std::setw(33) << prefix + k + 1 << " | ";
		base_stack.display();
		std::cout << std::endl << "-------------------------------------------------------------------------------------------------------";
	}
	while (!base_stack.is_empty()) // Pop all remaining stack contents
		prefix[k--] = base_stack.pop();
	std::cout << std::endl << "| " << std::setw(18) << ' ' << " | " << std::setw(33) << prefix+k+1 << " | ";
	base_stack.display();
	std::cout << std::endl << "-------------------------------------------------------------------------------------------------------";
}

float expression::evaluate_postfix()
{
	int i;
	float value, operand_1, operand_2;
	stack<float> base_stack;
	for (i = 0; postfix[i] != '\0'; i++)
	{
		if (is_alpha(postfix[i])) // Get value for operand and push to stack
		{
			std::cout << std::endl << "Enter the value of " << postfix[i] << ": ";
			std::cin >> value;
			base_stack.push(value);
		}
		else // Operate on top 2 elements of stack and push result to stack
		{
			operand_1 = base_stack.pop();
			operand_2 = base_stack.pop();
			base_stack.push(operate(postfix[i], operand_2, operand_1));
		}
		std::cout << std::endl << "----------------------------------------------------------------";
		std::cout << std::endl << "| Considered Symbol | Current stack contents (top at the left) |";
		std::cout << std::endl << "----------------------------------------------------------------";
		std::cout << std::endl << "| " << std::setw(17) << postfix[i] << " | ";
		base_stack.display();
		std::cout << std::endl << "----------------------------------------------------------------";
	}
	return base_stack.pop();
}

float expression::evaluate_prefix()
{
	int i;
	float value, operand_1, operand_2;
	stack<float> base_stack;
	for (i = strlen(prefix) - 1; i >= 0; i--)
	{
		if (is_alpha(prefix[i])) // Get value for operand and push to stack
		{
			std::cout << std::endl << "Enter the value of " << prefix[i] << ": ";
			std::cin >> value;
			base_stack.push(value);
		}
		else // Operate on top 2 elements of stack and push result to stack
		{
			operand_1 = base_stack.pop();
			operand_2 = base_stack.pop();
			base_stack.push(operate(prefix[i], operand_1, operand_2));
		}
		std::cout << std::endl << "----------------------------------------------------------------";
		std::cout << std::endl << "| Considered Symbol | Current stack contents (top at the left) |";
		std::cout << std::endl << "----------------------------------------------------------------";
		std::cout << std::endl << "| " << std::setw(17) << prefix[i] << " | ";
		base_stack.display();
		std::cout << std::endl << "----------------------------------------------------------------";
	}
	return base_stack.pop();
}

float expression::operate(char x, float operand_1, float operand_2)
{
	switch (x)
	{
	case '+':
		return operand_1 + operand_2;
		break;
	case '-':
		return operand_1 - operand_2;
		break;
	case '*':
		return operand_1 * operand_2;
		break;
	case '/':
		return operand_1 / operand_2;
		break;
	case '^':
		return pow(int(operand_1), int(operand_2));
		break;
	case '%':
		return(int(operand_1) % int(operand_2));
		break;
	}
}

int expression::precedence(char x)
{
	switch (x)
	{
	case '+':
		return 1;
		break;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 2;
		break;
	case '%':
		return 3;
		break;
	case '^':
		return 4;
		break;
	}
}

associativity_val expression::associativity(char x)
{
	switch (x)
	{
	case '+':
		return LTR;
		break;
	case '-':
		return LTR;
		break;
	case '*':
		return LTR;
		break;
	case '/':
		return LTR;
		break;
	case '%':
		return LTR;
		break;
	case '^':
		return RTL;
		break;
	}
}

bool expression::is_alpha(char x)
{
	if ((x >= 'a'&&x <= 'z') || (x >= 'A'&&x <= 'Z'))
		return true;
	else
		return false;
}

bool expression::is_valid()
{
	stack<char> base_stack;
	int operator_count = 0, operand_count = 0;
	for (int i = 0; infix[i] != '\0'; i++)
	{
		if (is_alpha(infix[i]))
			operand_count++;
		else if (infix[i] == '(') // Push opening parenthesis
			base_stack.push(infix[i]);
		else if (infix[i] == ')') // Pop opening parenthesis for every closing parenthesis
		{
			if (!base_stack.is_empty())
				base_stack.pop();
			else
				return false;
		}
		else
			operator_count++;
	}
	if ((operator_count != operand_count - 1) || (!base_stack.is_empty())) // Invalid if operands != operators + 1 or parenthesis don't match
		return false;
	else
		return true;
}

bool expression::is_postfix()
{
	if (postfix == NULL)
		return false;
	else if (postfix[0] == '\0')
		return false;
	else
		return true;
}

bool expression::is_prefix()
{
	if (prefix == NULL)
		return false;
	else if (prefix[0] == '\0')
		return false;
	else
		return true;
}

bool expression::is_infix()
{
	if (infix == NULL)
		return false;
	else if (infix[0] == '\0')
		return false;
	else
		return true;
}

int expression::expression_length(char *x)
{
	int i = 0,length=0;
	while (x[i] != '\0')
	{
		if (x[i] != ')' && x[i] != '(')
			length++;
		i++;
	}
	return length;
}

void expression::display_prefix()
{
	std::cout << prefix;
}

void expression::display_postfix()
{
	std::cout << postfix;
}

void expression::display_infix()
{
	std::cout << infix;
}

expression::~expression()
{
	if(infix!=NULL)
		delete infix;
	if(postfix!=NULL)
		delete postfix;
	if(prefix!=NULL)
		delete prefix;
}
