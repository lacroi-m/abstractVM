//
// Types.hpp for  in /home/lacroi_m/pisicne/abstractVM_2016
// 
// Made by Maxime Lacroix
// Login   <lacroi_m@epitech.net>
// 
// Started on  Fri Jul 21 10:44:16 2017 Maxime Lacroix
// Last update Mon Jul 24 10:37:37 2017 Maxime Lacroix
//


#ifndef _TYPES_H_
#define _TYPES_H_
#include "IOperand.hpp"
#include <cstdint>
#include <cstdlib>
#include <string>
#include <iostream>

class	Int8: public IOperand// -128 to 127
{
public:
  std::int8_t	m_nbr;
  Int8(const std::int8_t& nbr) : m_nbr(nbr){};
  ~Int8();
  virtual std::string toString() const {return(std::to_string(m_nbr));} //string that represents the instance
  virtual eOperandType getType() const {return (eOperandType::Int8);} //returnes thr Type of instance
  IOperand* operator+(const IOperand &rhs) const {(void)rhs;return (NULL);}
  IOperand* operator-(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator*(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator/(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator%(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  /*
  IOperand* operator+(const IOperand &rhs) const = 0;
  IOperand* operator-(const IOperand &rhs) const = 0;
  IOperand* operator*(const IOperand &rhs) const = 0;
  IOperand* operator/(const IOperand &rhs) const = 0;
  IOperand* operator%(const IOperand &rhs) const = 0;*/
};

class	Int16: public IOperand // -32,768 to 32,767
{
public:
  const std::int16_t	m_nbr;
  Int16(std::int16_t nbr) : m_nbr(nbr){};
  
  virtual std::string toString() const {return(std::to_string(m_nbr));} //string that represents the instance
  eOperandType getType() const {return (eOperandType::Int16);} //returnes thr Type of instance
    IOperand* operator+(const IOperand &rhs) const {(void)rhs;return (NULL);}
  IOperand* operator-(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator*(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator/(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator%(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  /*
  IOperand* operator+(const IOperand &rhs) const = 0;
    IOperand* operator-(const IOperand &rhs) const = 0;
    IOperand* operator*(const IOperand &rhs) const = 0;
    IOperand* operator/(const IOperand &rhs) const = 0;
    IOperand* operator%(const IOperand &rhs) const = 0;*/
};

class	Int32: public IOperand // -2,147,483,648 to 2,147,483,647
{
public:
  const std::int32_t	m_nbr;
  Int32(std::int32_t nbr) : m_nbr(nbr){};
  virtual std::string toString() const {return(std::to_string(m_nbr));} //string that represents the instance
  virtual eOperandType getType() const {return (eOperandType::Int32);} //returnes thr Type of instance
  IOperand* operator+(const IOperand &rhs) const {(void)rhs;return (NULL);}
  IOperand* operator-(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator*(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator/(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator%(const IOperand &rhs) const  {(void)rhs;return (NULL);}

  /*    IOperand* operator+(const IOperand &rhs) const = 0;
    IOperand* operator-(const IOperand &rhs) const = 0;
    IOperand* operator*(const IOperand &rhs) const = 0;
    IOperand* operator/(const IOperand &rhs) const = 0;
    IOperand* operator%(const IOperand &rhs) const = 0;*/
};

class	Float: public IOperand // -3.4E+38 to +3.4E+38
{
public:
  const float		m_nbr;
  Float(float nbr) : m_nbr(nbr){};
  virtual std::string toString() const {return(std::to_string(m_nbr));} //string that represents the instance
  virtual eOperandType getType() const {return (eOperandType::Float);} //returnes thr Type of instance
  IOperand* operator+(const IOperand &rhs) const {(void)rhs;return (NULL);}
  IOperand* operator-(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator*(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator/(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator%(const IOperand &rhs) const  {(void)rhs;return (NULL);}
 
  /*  IOperand* operator+(const IOperand &rhs) const = 0;
  IOperand* operator-(const IOperand &rhs) const = 0;
  IOperand* operator*(const IOperand &rhs) const = 0;
  IOperand* operator/(const IOperand &rhs) const = 0;
  IOperand* operator%(const IOperand &rhs) const = 0;*/
};

class	Double: public IOperand // -1.7E+308 to +1.7E+308
{
public:
  const double	m_nbr;
  Double(double nbr) : m_nbr(nbr){};
  virtual std::string toString() const {return(std::to_string(m_nbr));} //string that represents the instance
  virtual eOperandType getType() const {return (eOperandType::Double);} //returnes thr Type of instance
    IOperand* operator+(const IOperand &rhs) const {(void)rhs;return (NULL);}
  IOperand* operator-(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator*(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator/(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator%(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  /*  IOperand* operator+(const IOperand &rhs) const = 0;
    IOperand* operator-(const IOperand &rhs) const = 0;
    IOperand* operator*(const IOperand &rhs) const = 0;
    IOperand* operator/(const IOperand &rhs) const = 0;
    IOperand* operator%(const IOperand &rhs) const = 0;*/

};

class	BigDecimal: public IOperand // infinit number
{
public:
  const std::string	m_nbr;
  BigDecimal(const std::string nbr) : m_nbr(nbr){};
  virtual std::string toString() const {return(m_nbr);} //string that represents the instance
  virtual eOperandType getType() const {return (eOperandType::BigDecimal);} //returnes thr Type of instance
  IOperand* operator+(const IOperand &rhs) const {(void)rhs;return (NULL);}
  IOperand* operator-(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator*(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator/(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  IOperand* operator%(const IOperand &rhs) const  {(void)rhs;return (NULL);}
  /*
    IOperand* operator+(const IOperand &rhs) const = 0;
    IOperand* operator-(const IOperand &rhs) const = 0;
    IOperand* operator*(const IOperand &rhs) const = 0;
    IOperand* operator/(const IOperand &rhs) const = 0;
    IOperand* operator%(const IOperand &rhs) const = 0;*/
};

#endif /*TYPES_H_*/
