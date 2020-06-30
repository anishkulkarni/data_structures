#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include<iostream>

enum associativity_val { RTL, LTR };

class expression
{
	char *infix;
	char *postfix;
	char *prefix;
	int length;
public:
	expression();
	bool create_infix(char *,int);
	void infix_to_postfix();
	void infix_to_prefix();
	float evaluate_postfix();
	float evaluate_prefix();
	static bool is_alpha(char);
	static int precedence(char);
	static associativity_val associativity(char);
	bool is_valid();
	static float operate(char, float, float);
	static int expression_length(char *);
	bool is_postfix();
	bool is_prefix();
	bool is_infix();
	void display_prefix();
	void display_postfix();
	void display_infix();
	~expression();
};

#endif
