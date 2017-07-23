//
// IOperand.hpp for  in /home/lacroi_m/pisicne/abstractVM_2016
// 
// Made by Maxime Lacroix
// Login   <lacroi_m@epitech.net>
// 
// Started on  Thu Jul 20 14:47:43 2017 Maxime Lacroix
// Last update Sun Jul 23 18:51:38 2017 thomas duchet
//

#ifndef _IOPERAND_H_
 #define _IOPERAND_H_
#include <string>

enum class eOperandType : int
  {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    BigDecimal
  };

class	IOperand
{
public:
  virtual	std::string toString() const = 0; //string that represents the instance
  virtual	eOperandType getType() const = 0; //returnes thr Type of instance

  virtual	IOperand* operator+(const IOperand &rhs) const = 0;
  virtual	IOperand* operator-(const IOperand &rhs) const = 0;
  virtual	IOperand* operator*(const IOperand &rhs) const = 0;
  virtual	IOperand* operator/(const IOperand &rhs) const = 0;
  virtual	IOperand* operator%(const IOperand &rhs) const = 0;
  
  virtual	~IOperand() {}
};

#endif /*IOPERAND_H_*/
