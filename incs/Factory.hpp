//
// Factory.hpp for  in /home/lacroi_m/pisicne/abstractVM_2016
// 
// Made by Maxime Lacroix
// Login   <lacroi_m@epitech.net>
// 
// Started on  Thu Jul 20 14:44:40 2017 Maxime Lacroix
// Last update Sun Jul 23 15:56:59 2017 thomas duchet
//

#ifndef _FACTORY_H_
 #define _FACTORY_H_

#include "IOperand.hpp"
#include <iostream>



class	Factory
{
public:
  Factory(){}
  static	IOperand* createOperand(eOperandType type, const std::string& value);					
private:
  IOperand*	createInt8(const std::string& value);
  IOperand*	createInt16(const std::string& value);
  IOperand*	createInt32(const std::string& value);
  IOperand*	createFloat(const std::string& value);
  IOperand*	createDouble(const std::string& value);
  IOperand*	createBigDecimal(const std::string& value);
};

#endif /*_FACTORY_H_*/
