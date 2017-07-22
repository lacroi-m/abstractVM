//
// Factory.cpp for  in /home/lacroi_m/pisicne/abstractVM_2016
// 
// Made by Maxime Lacroix
// Login   <lacroi_m@epitech.net>
// 
// Started on  Fri Jul 21 12:45:48 2017 Maxime Lacroix
// Last update Sat Jul 22 18:22:52 2017 Maxime Lacroix
//

#include "Factory.hpp"
#include "Types.hpp"
#include "Exception.hpp"

IOperand*	createInt8(const std::string& value)
{
  std::string	valuee(value);
  std::string	ogvalue(valuee.substr(valuee.find("(") + 1, valuee.find(")")));
  std::int8_t	container(std::stoi(ogvalue));
  
  if (!container || (container < -127 && container > 126))
    throw Exception("Canot convert '" + value + "' to Int8\n");  
  return (dynamic_cast<IOperand *> (new Int8(container)));
}
IOperand*	createInt16(const std::string& value)
{
  std::string	valuee(value);
  std::string	ogval(valuee.substr(valuee.find("(") + 1, valuee.find(")")));
  std::int16_t	container(std::stoi(ogval));
  if (!container || (container < -32767 && container > 32766))
    throw Exception("Canot convert '" + value + "' to Int16\n");
  return (dynamic_cast<IOperand *> (new Int8(container)));
}

IOperand*	createInt32(const std::string& value)
{
  std::string	valuee(value);
  std::string	ogval(valuee.substr(valuee.find("(") + 1, valuee.find(")")));
  std::int32_t	container(std::stoi(ogval));
  if (!container || (container < -2147483647 && container > 2147483647))
    throw Exception("Canot convert '" + value + "' to Int32\n");
  return (dynamic_cast<IOperand *> (new Int8(container)));
}

IOperand*	createFloat(const std::string& value)
{
  std::string	valuee(value);
  std::string	ogval(valuee.substr(valuee.find("(") + 1, valuee.find(")")));
  float		container(std::stof(value));
  if (!container || (container < -(sizeof(float)) && container > sizeof(float)))
    throw Exception("Canot convert '" + value + "' to Float\n");
  return (dynamic_cast<IOperand *> (new Int8(container)));
}

IOperand*	createDouble(const std::string& value)
{
  std::string	valuee(value);
  std::string	ogval(valuee.substr(valuee.find("(") + 1, valuee.find(")")));
  double	container(std::stod(value));
  if (!container || (container < -(sizeof(double)) && sizeof(double) > 127))
    throw Exception("Canot convert '" + value + "' to Double\n");
  return (dynamic_cast<IOperand *> (new Int8(container)));
}

IOperand*	createBigDecimal(const std::string& value)
{
  std::string	valuee(value);
  std::string	ogval(valuee.substr(valuee.find("(") + 1, valuee.find(")")));
  return (dynamic_cast<IOperand *> (new BigDecimal(ogval)));
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
}
*/
