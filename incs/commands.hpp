//
// command.hpp for command.hpp in /home/duchet_t/rendu/Piscine_synthese_tek2/abstractVM_2016/incs
// 
// Made by thomas duchet
// Login   <duchet_t@epitech.net>
// 
// Started on  Thu Jul 20 13:57:04 2017 thomas duchet
// Last update Thu Jul 20 14:52:00 2017 thomas duchet
//

#ifndef COMMANDS_HPP_
# define COMMANDS_HPP_

#include "vm.hpp"

class		Commands
{
private:
  std::vector<std::string> commands;
public:
  Commands();
  ~Commands();
  std::vector<std::string> get_commands();
};

#endif /* COMMANDS_HPP_ */
