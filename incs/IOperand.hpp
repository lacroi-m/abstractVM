//
// IOperand.hpp for  in /home/lacroi_m/pisicne/abstractVM_2016
// 
// Made by Maxime Lacroix
// Login   <lacroi_m@epitech.net>
// 
// Started on  Thu Jul 20 14:47:43 2017 Maxime Lacroix
// Last update Thu Jul 20 19:16:32 2017 Maxime Lacroix
//

#ifndef _IOPERAND_H_
 #define _IOPERAND_H_
#include <string>

typedef enum eOperandType
  {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    BigDeciamal
  }	     eOperandType;

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
