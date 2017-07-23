//
// Stack.hpp for stack.hpp in /home/duchet_t/rendu/Piscine_synthese_tek2/abstractVM_2016/incs
// 
// Made by thomas duchet
// Login   <duchet_t@epitech.net>
// 
// Started on  Thu Jul 20 19:35:50 2017 thomas duchet
// Last update Sun Jul 23 14:06:13 2017 thomas duchet
//

#ifndef STACK_HPP_
# define STACK_HPP_

#include "../incs/Factory.hpp"
#include "../incs/parsing.hpp"
#include "../incs/IOperand.hpp"
#include <stack>

class Stack;

typedef  void (Stack::*StackFunc)(std::vector<std::string> cmd);

class	Stack
{
private:
  std::vector<std::string>		commands; /* la tableau de tt les commandes */
  std::vector<std::string>		cmd; /* ma commande et ses arguments */
  std::stack<IOperand *>		stack; /* La stack */ 
public:
  Stack();
  ~Stack();

  void					fill_cmd(std::map<std::string,std::vector<std::string>, std::less<std::string>>);
  void					manage_func(std::map<std::string,std::vector<std::string>, std::less<std::string>>);
  std::stack<IOperand *>		get_stack();
  std::vector<std::string>		get_commands();
  void					fill_ptr_tab();
  StackFunc		                StackFunction[16];
  void					my_push(std::vector<std::string> cmd);
  void					my_pop(std::vector<std::string> cmd);
  void					my_dump(std::vector<std::string> cmd);
  void					my_clear(std::vector<std::string> cmd);
  void					my_dup(std::vector<std::string> cmd);
  void					my_swap(std::vector<std::string> cmd);
  void					my_assert(std::vector<std::string> cmd);
  void					my_add(std::vector<std::string> cmd);
  void					my_sub(std::vector<std::string> cmd);
  void					my_mul(std::vector<std::string> cmd);
  void					my_div(std::vector<std::string> cmd);
  void					my_load(std::vector<std::string> cmd);
  void					my_store(std::vector<std::string> cmd);
  void					my_print(std::vector<std::string> cmd);
  void					my_exit(std::vector<std::string> cmd);
};

#endif /* STACK_HPP_ */
