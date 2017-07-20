//
// command.cpp for commans.cpp in /home/duchet_t/rendu/Piscine_synthese_tek2/abstractVM_2016/srcs
// 
// Made by thomas duchet
// Login   <duchet_t@epitech.net>
// 
// Started on  Thu Jul 20 13:59:44 2017 thomas duchet
// Last update Thu Jul 20 14:50:21 2017 thomas duchet
//

#include "../incs/commands.hpp"
#include "../incs/vm.hpp"

Commands::Commands() {
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

Commands::~Commands() {}

std::vector<std::string>	Commands::get_commands() {
  return (this->commands);
}
