//
// value.hpp for value.hpp in /home/duchet_t/rendu/Piscine_synthese_tek2/abstractVM_2016/incs
// 
// Made by thomas duchet
// Login   <duchet_t@epitech.net>
// 
// Started on  Thu Jul 20 14:19:59 2017 thomas duchet
// Last update Thu Jul 20 14:51:14 2017 thomas duchet
//

#ifndef VALUE_HPP_
# define VALUE_HPP_

#include <vector>
#include <iostream>
#include "vm.hpp"

class	Values
{
private:
  std::vector<std::string> values;
public:
  Values();
  ~Values();
  std::vector<std::string> get_values();
};

#endif /* VALUE_HPP_ */
