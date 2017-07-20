//
// values.cpp for values.cpp in /home/duchet_t/rendu/Piscine_synthese_tek2/abstractVM_2016/srcs
// 
// Made by thomas duchet
// Login   <duchet_t@epitech.net>
// 
// Started on  Thu Jul 20 14:31:52 2017 thomas duchet
// Last update Thu Jul 20 14:50:26 2017 thomas duchet
//

#include "../incs/value.hpp"
#include "../incs/vm.hpp"

Values::Values() {
  this->values.push_back("int 8");
  this->values.push_back("int 16");
  this->values.push_back("int 32");
  this->values.push_back("float");
  this->values.push_back("double");
  this->values.push_back("bigdecimal");
}

Values::~Values() {}

std::vector<std::string> Values::get_values() {
  return (this->values);
}
