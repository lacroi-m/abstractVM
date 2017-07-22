//
// stack.cpp for stack.cpp in /home/duchet_t/rendu/Piscine_synthese_tek2/abstractVM_2016/srcs
// 
// Made by thomas duchet
// Login   <duchet_t@epitech.net>
// 
// Started on  Fri Jul 21 11:42:06 2017 thomas duchet
// Last update Sat Jul 22 15:00:07 2017 thomas duchet
//

#include "../incs/Stack.hpp"

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
  this->StackFunction[11] = &Stack::my_load;
  this->StackFunction[12] = &Stack::my_store;
  this->StackFunction[13] = &Stack::my_print;
  this->StackFunction[14] = &Stack::my_exit;
  this->StackFunction[15] = NULL;
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
  //aff_vector(cmd);
  std::cout<<"PUSH"<<std::endl;
  //  aff_vector(this->cmd);
  //  if (arg[1].find_first_of("int16") == 0)
  if (cmd[1].compare("int8") == 0)
    //  std::cout<<"ca passe en int8"<<std::endl;
    //stack.push(createInt8(cmd[2]));
  if (cmd[1].compare("int16") == 0)
    //std::cout<<"ca passe en int16"<<std::endl;
    // stack.push(createInt16(cmd[2]));
  if (cmd[1].compare("int32") == 0)
    //std::cout<<"ca passe en int32"<<std::endl;
    //stack.push(createInt32(cmd[2]));
  if (cmd[1].compare("float") == 0)
    //stack.push(createFloat(cmd[2]));
  if (cmd[1].compare("double") == 0)
    //stack.push(createDouble(cmd[2]));
  if (cmd[1].compare("bigdecimal") == 0)
    // stack.push(createBigdecimal(cmd[2]));
    {
  //aff_vector(stack);
    }
}
    /* if (cmd[1].compare("int16") == 0)
       stack.push_back(createInt16(cmd[2]);*/

void                            Stack::my_pop(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"POP"<<std::endl;
}

void				Stack::my_dump(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"DUMP"<<std::endl;
}

void                            Stack::my_clear(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"CLEAR"<<std::endl;
}

void                            Stack::my_dup(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"DUP"<<std::endl;
}

void                            Stack::my_swap(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"SWAP"<<std::endl;
}

void                            Stack::my_assert(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"ASSERT"<<std::endl;
}

void                            Stack::my_add(__attribute__((unused))std::vector<std::string> cmd) {
  //  aff_vector(cmd);
  std::cout<<"ADD"<<std::endl;
}

void                            Stack::my_sub(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"SUB"<<std::endl;
}

void                            Stack::my_mul(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"MUL"<<std::endl;
}

void                            Stack::my_div(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"LOAD"<<std::endl;
}

void                            Stack::my_load(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"LOAD"<<std::endl;
}

void                            Stack::my_store(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"STORE"<<std::endl;
}

void				Stack::my_print(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"PRINT"<<std::endl;
}

void				Stack::my_exit(__attribute__((unused))std::vector<std::string> cmd) {
  std::cout<<"EXIT"<<std::endl;
}
