#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <cmath>

// Exercice 1
std::vector<std::string> split_string(std::string const& s);
bool is_floating(std::string const& s);
float npi_evaluate(std::vector<std::string> const& tokens);


// Exercice 2
enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN };
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value);
Token make_token(Operator op);

std::vector<Token> tokenize(std::vector<std::string> const& words);
float npi_evaluate(std::vector<Token> const& tokens);


// Exercice 3 (Conversion en NPI)
// enum class Operator {ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN};
int operator_precedence(Operator const op);
std::vector<Token> infix_to_npi_tokens(std::string const& expression);
void print_npi_expression(std::vector<Token> const& tokens);

