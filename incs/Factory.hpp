//
// Factory.hpp for  in /home/lacroi_m/pisicne/abstractVM_2016
// 
// Made by Maxime Lacroix
// Login   <lacroi_m@epitech.net>
// 
// Started on  Thu Jul 20 14:44:40 2017 Maxime Lacroix
// Last update Thu Jul 20 19:31:22 2017 Maxime Lacroix
//

#ifndef _FACTORY_H_
 #define _FACTORY_H_

#include "IOperand.hpp"
#include <cstdint>
#include <iostream>

class	Factory : public IOperand
{
  //  template<IOperand T> 
  //  static	IOperand* createOperand(eOperandType type, const std::string& value){}

  void	createint8(const std::string& value){(void)value;};
  void	createint16(const std::string& value){(void)value;};
  void	createint32(const std::string& value){(void)value;};
  void	createFloat(const std::string& value){(void)value;};
  void	createDouble(const std::string& value){(void)value;};
  void	createBigDecimal(const std::string& value){(void)value;};

  
  /*
  IOperand*	createint8(const std::string& value);
  IOperand*	createint16(const std::string& value);
  IOperand*	createint32(const std::string& value);
  IOperand*	createFloat(const std::string& value);
  IOperand*	createDouble(const std::string& value);
  IOperand*	createBigDecimal(const std::string& value);*/

};

#endif /*_FACTORY_H_*/
