//
// stack.cpp for stack.cpp in /home/duchet_t/rendu/Piscine_synthese_tek2/abstractVM_2016/srcs
// 
// Made by thomas duchet
// Login   <duchet_t@epitech.net>
// 
// Started on  Fri Jul 21 11:42:06 2017 thomas duchet
// Last update Tue Jul 25 16:07:23 2017 thomas duchet
//

#include "../incs/Stack.hpp"
#include "../incs/IOperand.hpp"
#include "../incs/Types.hpp"
#include "../incs/Factory.hpp"
#include "../incs/value.hpp"
#include "Exception.hpp"

Stack::Stack() {
  this->commands.push_back("push");
  this->commands.push_back("pop");
  this->commands.push_back("dump");
  this->commands.push_back("clear");
  this->commands.push_back("dup");
  this->commands.push_back("swap");
  this->commands.push_back("assert");
  this->commands.push_back("add");
  this->commands.push_back("sub");
  this->commands.push_back("mul");
  this->commands.push_back("div");
  this->commands.push_back("mod");
  this->commands.push_back("load");
  this->commands.push_back("store");
  this->commands.push_back("print");
  this->commands.push_back("exit");

}

Stack::~Stack() {}

void				Stack::fill_ptr_tab() {
  this->StackFunction[0] = &Stack::my_push;
  this->StackFunction[1] = &Stack::my_pop;
  this->StackFunction[2] = &Stack::my_dump;
  this->StackFunction[3] = &Stack::my_clear;
  this->StackFunction[4] = &Stack::my_dup;
  this->StackFunction[5] = &Stack::my_swap;
  this->StackFunction[6] = &Stack::my_assert;
  this->StackFunction[7] = &Stack::my_add;
  this->StackFunction[8] = &Stack::my_sub;
  this->StackFunction[9] = &Stack::my_mul;
  this->StackFunction[10] = &Stack::my_div;
  this->StackFunction[11] = &Stack::my_mod;
  this->StackFunction[12] = &Stack::my_load;
  this->StackFunction[13] = &Stack::my_store;
  this->StackFunction[14] = &Stack::my_print;
  this->StackFunction[15] = &Stack::my_exit;
  this->StackFunction[16] = NULL;

  int i = 0;
  while (i < 16)
    {
      this->registre_tab[i] = NULL;
      i++;
    }
}

std::vector<std::string>	Stack::get_commands() {
  return this->commands;
}

std::stack<IOperand *>		Stack::get_stack() {
  return this->stack;
}

void	aff_vector(std::vector<std::string> vector)
{
  for (std::vector<std::string>::iterator it = vector.begin(); it != vector.end(); ++it)
    std::cout<<"["<<*it<<"]"<<std::endl;
}

void    Stack::manage_func(__attribute__((unused))std::map<std::string, std::vector<std::string>, std::less<std::string>> _clean_map)
{
  std::string		tmp;
  unsigned int          i;
  unsigned int			j;
  std::vector<std::string>	cmd;

  this->fill_ptr_tab();
  for (std::map<std::string, std::vector<std::string>>::iterator it = _clean_map.begin(); it != _clean_map.end(); ++it) {
    for (std::vector<std::string>::iterator ite = it->second.begin(); ite != it->second.end(); ++ite) {
      if (ite == it->second.begin())
	{
	  cmd.clear();
	  j = 0;
	  while (j != it->second.size())
	    {
	      cmd.push_back(it->second[j]);
	      j++;
	    }
	  tmp = *ite;
	  for (i = 0; i != this->get_commands().size(); i++) {
	    if (tmp.compare(this->get_commands()[i]) == 0)
	      (this->*StackFunction[i])(cmd);
	  }
	}
    }
  }
}

void                            Stack::my_push(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"PUSH"<<std::endl;
  
  if (cmd[1].compare("int8") == 0)
    stack.push(Factory::createOperand(eOperandType::Int8, cmd[2]));
  if (cmd[1].compare("int16") == 0)
    stack.push(Factory::createOperand(eOperandType::Int16,cmd[2]));
  if (cmd[1].compare("int32") == 0)
    stack.push(Factory::createOperand(eOperandType::Int32,cmd[2]));
  if (cmd[1].compare("float") == 0)
    stack.push(Factory::createOperand(eOperandType::Float,cmd[2]));
  if (cmd[1].compare("double") == 0)
    stack.push(Factory::createOperand(eOperandType::Double,cmd[2]));
  if (cmd[1].compare("bigdecimal") == 0)
    stack.push(Factory::createOperand(eOperandType::BigDecimal,cmd[2]));
}

void                            Stack::my_pop(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"POP"<<std::endl;
  if (stack.empty() == true)
    throw Exception("Cant pop, stack empty");
  else
    stack.pop();
}

std::string			Stack::del_zero(std::string number)
{
  int		i = number.size();

  while (number[--i] == '0' && i >= 0);
    i--;
  if (number[i] == '.')
    i--;
  number = number.substr(0, i + 1);
  return number;
}

void				Stack::my_dump(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"DUMP"<<std::endl;

  for (std::stack<IOperand*> dump = stack; !dump.empty(); dump.pop())
    {
      if ((int)eOperandType::Int32 > (int)dump.top()->getType() && (int)dump.top()->getType() != (int)eOperandType::BigDecimal)
	std::cout << std::stoi(dump.top()->toString()) << '\n';
      else
	std::cout << del_zero(std::to_string(std::stod(dump.top()->toString()))) << '\n';
    }
}

void                            Stack::my_clear(__attribute__((unused))std::vector<std::string> cmd) {
  while (!stack.empty())
    stack.pop();
  std::cerr<<"CLEAR"<<std::endl;
}

void                            Stack::my_dup(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"DUP"<<std::endl;
  IOperand		*tmp;
  if (stack.empty() == true)
    throw Exception("can't dup, stack empty");
  else
    {
      tmp = stack.top();
      stack.push(tmp);
    }
}

void                            Stack::my_swap(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"SWAP"<<std::endl;
  IOperand	*tmp;
  IOperand	*tmp2;

  if (stack.size() >= 2)
    {
      tmp = stack.top();
      stack.pop();
      tmp2 = stack.top();
      stack.pop();
      stack.push(tmp);
      stack.push(tmp2);
    }
  else
    throw Exception("can't swap, stack doesnt contain 2 elements");
}

void                            Stack::my_assert(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"ASSERT"<<std::endl;
  IOperand		*tmp;
  IOperand		*nb_cmd;

  if (stack.empty() == true)
    throw Exception("can't assert, satck empty");
  else
    {
      tmp = stack.top();
      if (cmd[1].compare("int8") == 0)
	nb_cmd = Factory::createOperand(eOperandType::Int8, cmd[2]);
      if (cmd[1].compare("int16") == 0)
	nb_cmd = Factory::createOperand(eOperandType::Int16,cmd[2]);
      if (cmd[1].compare("int32") == 0)
	nb_cmd = Factory::createOperand(eOperandType::Int32,cmd[2]);
      if (cmd[1].compare("float") == 0)
	nb_cmd = Factory::createOperand(eOperandType::Float,cmd[2]);
      if (cmd[1].compare("double") == 0)
	nb_cmd = Factory::createOperand(eOperandType::Double,cmd[2]);
      if (cmd[1].compare("bigdecimal") == 0)
	nb_cmd = Factory::createOperand(eOperandType::BigDecimal,cmd[2]);
      if ((tmp->getType() != nb_cmd->getType()) || (tmp->toString().compare(nb_cmd->toString()) != 0))
	throw Exception ("Assert exception");
    }
}

void                            Stack::my_add(__attribute__((unused))std::vector<std::string> cmd) {
  if (stack.size() < 2)
    throw(Exception("Cant add. Stack doesnt have atleast 2 elements."));
  IOperand*       first = stack.top();
  stack.pop();
  IOperand*       second = (IOperand&)*first + (IOperand&)*stack.top();
  stack.pop();
  stack.push(((IOperand*)second));
  std::cerr<<"ADD"<<std::endl;
}

void                            Stack::my_sub(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"SUB"<<std::endl;
  if (stack.size() < 2)
    throw(Exception("Cant sub. Stack doesnt have atleast 2 elements."));
  const IOperand*       first = stack.top();
  stack.pop();
  const IOperand*       second = (const IOperand&)*stack.top() - (const IOperand&)*first;
  stack.pop();
  stack.push(((IOperand*)second));
}

void                            Stack::my_mul(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"MUL"<<std::endl;
  if (stack.size() < 2)
    throw(Exception("Cant mul. Stack doesnt have atleast 2 elements."));
  const IOperand*       first = stack.top();
  stack.pop();
  const IOperand*       second = (const IOperand&)*first * (const IOperand&)*stack.top();
  stack.pop();
  stack.push(((IOperand*)second));
}

void                            Stack::my_div(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"DIV"<<std::endl;
  if (stack.size() < 2)
    throw(Exception("Cant div. Stack doesnt have atleast 2 elements."));
  const IOperand*       first = stack.top();
  stack.pop();
  const IOperand*       second = (const IOperand&)*stack.top() - (const IOperand&)*first;
  stack.pop();
  stack.push(((IOperand*)second));
}

void                            Stack::my_mod(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"DIV"<<std::endl;
  if (stack.size() < 2)
    throw(Exception("Cant mod. Stack doesnt have atleast 2 elements."));
  const IOperand*       first = stack.top();
  stack.pop();
  const IOperand*       second = (const IOperand&)*stack.top() - (const IOperand&)*first;
  stack.pop();
  stack.push(((IOperand*)second));
}

void                            Stack::my_load(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"LOAD"<<std::endl;
  IOperand		*tmp;

  if ((cmd[1].compare("int8") == 0) || (cmd[1].compare("int16") == 0) || (cmd[1].compare("int32") == 0))
    {
      if (registre_tab[stoi(cmd[2])] == NULL)
	throw Exception("Can't load, this register is empty");
      else
	{
	  tmp = registre_tab[stoi(cmd[2])];
	  stack.push(tmp);
	}
    }
  else
    throw Exception("can't load, this register isn't integer");
}

void                            Stack::my_store(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"STORE"<<std::endl;
  if ((cmd[1].compare("int8") == 0) || (cmd[1].compare("int16") == 0) || (cmd[1].compare("int32") == 0))
    {
      std::cout<<cmd[2]<<std::endl;
      if (stoi(cmd[2]) < 0 || stoi(cmd[2]) > 15)
	throw Exception("can't store, register doesn't exist");
      else
	{
	  registre_tab[stoi(cmd[2])] = stack.top();
	  stack.pop();
	}
    }
  else
    throw Exception("can't store, this register isn't integer");
}

void				Stack::my_print(__attribute__((unused))std::vector<std::string> cmd) {
  std::cerr<<"PRINT"<<std::endl;
  char				tmp;
  int				i;
  if (stack.top()->getType() != eOperandType::Int8)
    throw Exception("Value at top of stack isn't a 8-bit Integer");
  else
    {
      i = std::stoi(stack.top()->toString());
      tmp = (char)i;
      std::cout<<tmp<<std::endl;
    }
}

void				Stack::my_exit(__attribute__((unused))std::vector<std::string> cmd) {
  exit(0);
  std::cerr<<"EXIT"<<std::endl;
}
