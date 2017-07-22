//
// pointed_command.cpp for pointed_command.cpp in /home/duchet_t/rendu/Piscine_synthese_tek2/abstractVM_2016/incs
// 
// Made by thomas duchet
// Login   <duchet_t@epitech.net>
// 
// Started on  Thu Jul 20 19:31:45 2017 thomas duchet
// Last update Thu Jul 20 19:57:51 2017 thomas duchet
//

#include "../incs/stack.hpp"

Stack::Stack() {}

Stack::~Stack() {}

std::Stack<const T>		Stack::get_stack() {
  return this->stack;
}

std::vector<std::string>	Stack::get_cmd() {
  return this->cmd;
}
