//
// Factory.cpp for  in /home/lacroi_m/pisicne/abstractVM_2016
// 
// Made by Maxime Lacroix
// Login   <lacroi_m@epitech.net>
// 
// Started on  Fri Jul 21 12:45:48 2017 Maxime Lacroix
// Last update Wed Jul 26 04:05:39 2017 Maxime Lacroix
//

#include "Factory.hpp"
#include "Types.hpp"
#include "Exception.hpp"

IOperand*	Factory::createInt8(const std::string& value)
{

    try{
    std::string			valuee(value);
    std::stringstream		ss;
    ss << valuee;
    std::int8_t			container;
    ss >> container;
    
    return (dynamic_cast<IOperand *> (new Float(container)));
  }
  catch(std::invalid_argument& e){
    throw Exception("Canot convert to Float");}
}

IOperand*	Factory::createInt16(const std::string& value)
{
    try{
    std::string			valuee(value);
    std::stringstream		ss;
    ss << valuee;
    std::int16_t			container;
    ss >> container;
    
    return (dynamic_cast<IOperand *> (new Int16(container)));
  }
  catch(std::invalid_argument& e){
    throw Exception("Canot convert to Float");}
}

IOperand*	Factory::createInt32(const std::string& value)
{

    try{
    std::string			valuee(value);
    std::stringstream		ss;
    ss << valuee;
    std::int32_t			container;
    ss >> container;
    
    return (dynamic_cast<IOperand *> (new Int32(container)));
  }
  catch(std::invalid_argument& e){
    throw Exception("Canot convert to Float");}
}

IOperand*	Factory::createFloat(const std::string& value)
{
  try{
    std::string			valuee(value);
    std::stringstream		ss;
    ss << valuee;
    float			container;
    ss >> container;
    
    return (dynamic_cast<IOperand *> (new Float(container)));
  }
  catch(std::invalid_argument& e){
    throw Exception("Canot convert to Float");}
}

IOperand*	Factory::createDouble(const std::string& value)
{
    try{
    std::string			valuee(value);
    std::stringstream		ss;
    ss << valuee;
    double			container;
    ss >> container;
    
    return (dynamic_cast<IOperand *> (new Double(container)));
  }
  catch(std::invalid_argument& e){
    throw Exception("Canot convert to Double");}
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
