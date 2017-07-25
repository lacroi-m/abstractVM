//
// Factory.cpp for  in /home/lacroi_m/pisicne/abstractVM_2016
// 
// Made by Maxime Lacroix
// Login   <lacroi_m@epitech.net>
// 
// Started on  Fri Jul 21 12:45:48 2017 Maxime Lacroix
// Last update Tue Jul 25 15:16:18 2017 Maxime Lacroix
//

#include "Factory.hpp"
#include "Types.hpp"
#include "Exception.hpp"

IOperand*	Factory::createInt8(const std::string& value)
{
  try
    {
      std::int8_t	container(std::stoi(value));
      
      if (container < -127 && container < 127)
	throw Exception("Canot convert '" + value + "' to Int16");  
      return (dynamic_cast<IOperand *> (new Int8(container)));
    }
  catch(std::invalid_argument& e){
    throw Exception("Canot convert '" + value + "' to Int8");}
  return (NULL);
}
IOperand*	Factory::createInt16(const std::string& value)
{
  try
    {
      std::int16_t	container(std::stoi(value));
      return (dynamic_cast<IOperand *> (new Int16(container)));
    }
  catch(std::invalid_argument& e){
    throw Exception("Canot convert '" + value + "' to Int16");}
  return (NULL);
}

IOperand*	Factory::createInt32(const std::string& value)
{
  try{
    float		tmp(std::stof(value));
    if ((int)tmp > 2147483647 || (int)tmp < -2147483647)
      throw (Exception("ovetflow int32"));
    std::int32_t	container(std::stoi(value));
    return (dynamic_cast<IOperand *> (new Int32(container)));
  }
  catch(std::invalid_argument& e){
    throw Exception("Canot convert '" + value + "' to Int32");}
  return (NULL);
}

IOperand*	Factory::createFloat(const std::string& value)
{
  try{
    float		container(std::stod(value));
    return (dynamic_cast<IOperand *> (new Float(container)));
  }
  catch(std::invalid_argument& e){
    throw Exception("Canot convert '" + value + "' to Int32");}
}

IOperand*	Factory::createDouble(const std::string& value)
{
  try{
    double	container(std::stod(value));
    return (dynamic_cast<IOperand *> (new Double(container)));
  }
  catch(std::invalid_argument& e){
    throw Exception("Canot convert '" + value + "' to Int32");}
}

IOperand*	Factory::createBigDecimal(const std::string& value)
{
  return (dynamic_cast<IOperand *> (new BigDecimal(value)));
}


IOperand*	 Factory::createOperand(eOperandType type, const std::string& value)
{
  Factory	test;

  if (type == eOperandType::Int8)
    return (test.createInt8(value));
  if (type == eOperandType::Int16)
    return (test.createInt16(value));
  if (type == eOperandType::Int32)
    return (test.createInt32(value));
  if (type == eOperandType::Double)
    return (test.createDouble(value));
  if (type == eOperandType::Float)
    return (test.createFloat(value));
  return (test.createBigDecimal(value));
}
/*
IOperand* Int8::operator+(const IOperand &rhs) const
{
  //  Find biggiest type between both
  //  Operate berween both and stock and return in the highst
  switch (rhd.getType())
    {
    case: eOperandTtpe::Int8
	;
    case: eOperandTtpe::Int16
	;
    case: eOperandTtpe::Int32
	;
    case: eOperandTtpe::Float
	;
    case: eOperandTtpe::Double
	;
    case: eOperandTtpe::BigDecimal
	;
    case: eOperandTtpe::Int8
	;
    }
  m_nbr += rhs;
  return *this;
}
IOperand* operator-(const IOperand &rhs) const
{
  m_nbr  -= rhs;
  return *this;
}
IOperand* operator*(const IOperand &rhs) const
{
  m_nbr  *= rhs;
  return *this;
}
IOperand* operator/(const IOperand &rhs) const
{
  m_nbr = m_nbr / rhs;
  return *this;
}
IOperand* operator%(const IOperand &rhs) const {
  m_nbr %= rhs;
  return *this;
*/
