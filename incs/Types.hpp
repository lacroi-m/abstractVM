// Last update Wed Jul 26 12:36:45 2017 Maxime Lacroix
//


#ifndef _TYPES_H_
#define _TYPES_H_
#include "IOperand.hpp"
#include "Factory.hpp"
#include "Exception.hpp"
#include <cstdint>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>

class	Int8: public IOperand// -128 to 127
{
public:
  double	m_nbr;
  Int8(const double& nbr) : m_nbr(nbr){};
  ~Int8();
  virtual std::string toString() const {std::stringstream ss; std::string con;ss<<m_nbr;ss>>con;return(con);} //string that represents the instance
  virtual eOperandType getType() const {return (eOperandType::Int8);} //returnes thr Type of instance
  IOperand* operator+(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss;
    double	add;
    /*    double add2;
    std::int32_t add3;
    float	add4;
    double	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {

	ss << rhs.toString();
	ss >> add;
	add = m_nbr + add;
	ss.clear();
	ss << add;
	ss >> str;
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
  
  IOperand* operator-(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss;
    float	add;
    //float	add;
    /*    std::int16_t add2;
	  std::int32_t add3;
	  float	add4;
    double	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = m_nbr - add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }

  IOperand* operator*(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss;
    double add;
    /*    std::int16_t add2;
    std::int32_t add3;
    float	add4;
    double	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = m_nbr * add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
  IOperand* operator/(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss; //std::string con;//ss<<m_nbr;ss>>con;
    double	add;
    /*    std::int16_t add2;
	  std::int32_t add3;
    float	add4;
    double	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	if (add == 0)
	  throw(Exception("WARNING !!! BLACK HOLE CREATED !!!\nprocess: abstractVM_2016 Abort():: entering the 4th dymention !"));
	add = m_nbr / add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
  IOperand* operator%(const IOperand &rhs) const
  {
        Factory*                                op;
    
    std::stringstream ss; std::string con;//ss<<m_nbr;ss>>con;
    std::int16_t	add;
    std::int16_t	nbr;
    /*    std::int16_t add2;
    std::int32_t add3;
    float	add4;
    double	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << m_nbr;
	ss >> nbr;
	ss.clear();
	ss << rhs.toString();
	ss >> add;
	add = nbr % add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  throw(Exception("cant % a float or double"));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
};

class	Int16: public IOperand // -32,768 to 32,767
{
public:
  //  const std::int16_t	m_nbr;
  double	m_nbr;
  Int16(double nbr) : m_nbr(nbr){};
  
  virtual std::string toString() const {std::stringstream ss; std::string con;ss<<m_nbr;ss>>con;return(con);} //string that represents the instance
  eOperandType getType() const {return (eOperandType::Int16);} //returnes thr Type of instane
  
  
  IOperand* operator+(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss;// std::string con;ss<<m_nbr;ss>>con;
    //  double	add;
    double add;
    /*    std::double add3;
    float	add4;
    int16_t	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = m_nbr + add;
	ss.clear();
	ss << add;
	ss >> str;
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(this->getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(rhs.getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
  
  IOperand* operator-(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss;
    //int8_t	add;
    //float	add;
    double add;
    /*std::double add3;
      float	add4;
      int16_t	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = m_nbr - add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }

  IOperand* operator*(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss;// std::string con;//ss<<m_nbr;ss>>con;
    double	add;
    //int16_t add;
    /*std::double add;
    float	add;
    int16_t	add;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = m_nbr * add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
  IOperand* operator/(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss;// std::string con;//ss<<m_nbr;ss>>con;
    double	add;
    //int16_t add;
    /* std::double add;
    float	add;
    int16_t	add;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	if (add == 0)
	  throw(Exception("WARNING !!! BLACK HOLE CREATED !!!\nprocess: abstractVM_2016 Abort():: entering the 4th dymention !"));
	add = m_nbr / add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
  IOperand* operator%(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss; std::string con;//ss<<m_nbr;ss>>con;
    std::int16_t	add;
    std::int16_t	nbr;
    //    int add;
    /*std::int32_t add3;
    float	add4;
    int16_t	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << m_nbr;
	ss >> nbr;
	ss.clear();
	ss << rhs.toString();
	ss >> add;
	add = nbr % add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  throw(Exception("cant modolilo a double or float <3"));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
};

class	Int32: public IOperand // -2,147,483,648 to 2,147,483,647
{
public:
  double	m_nbr;
  Int32(double nbr) : m_nbr(nbr){};
  virtual std::string toString() const {std::stringstream ss; std::string con;ss<<m_nbr;ss>>con;return(con);} //string that represents the instance
  virtual eOperandType getType() const {return (eOperandType::Int32);} //returnes thr Type of instance


  IOperand* operator+(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss;
    //  double	add;
    //int16_t add;
    double add;
    /*float	add4;*/
    double	addup;
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	ss >> addup;
	add = m_nbr + add;
	addup = m_nbr + addup;
	ss.clear();
	ss << add;
	ss >> str;
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
  
  IOperand* operator-(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss;
    //int8_t	add;
    //float	add;
    //int16_t add;
    double add;
    /*float	add4;
	int16_t	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = m_nbr - add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }

  IOperand* operator*(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss;
    //    int8_t	add;
    //    int16_t add;
    double add;
      /*float	add;
    int16_t	add;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = m_nbr * add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
  IOperand* operator/(const IOperand &rhs) const
  {
    Factory*                                op;
    
    std::stringstream ss;
    // int8_t	add;
    double add;
    /* std::double add;
    float	add;
    int16_t	add;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	if (add == 0)
	  throw(Exception("WARNING !!! BLACK HOLE CREATED !!!\nprocess: abstractVM_2016 Abort():: entering the 4th dymention !"));
	add = m_nbr / add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
  IOperand* operator%(const IOperand &rhs) const
  {
        Factory*                                op;
    
    std::stringstream ss; std::string con;//ss<<m_nbr;ss>>con;
    //int8_t	add;
    std::int32_t add;
    std::int32_t nbr;
    /*std::double add3;
    float	add4;
    int16_t	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << m_nbr;
	ss >> nbr;
	ss.clear();
	ss << rhs.toString();
	ss >> add;
	add = nbr % add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  throw(Exception("Ok bru let me explain I cant modulo a float or double"));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
};

class	Float: public IOperand // -3.4E+38 to +3.4E+38
{
public:
  const float		m_nbr;
  Float(float nbr) : m_nbr(nbr){};
  virtual std::string toString() const {std::stringstream ss; std::string con;ss<<m_nbr;ss>>con;return(con);} //string that represents the instance
  virtual eOperandType getType() const {return (eOperandType::Float);} //returnes thr Type of instance


  IOperand* operator+(const IOperand &rhs) const
  {
    Factory*                                op;

    std::stringstream ss; std::string con;//ss<<m_nbr;ss>>con;
    float add;
    /*    std::int16_t add2;
    std::double add3;
    float	add4;
    int16_t	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = m_nbr + add;
	ss.clear();
	ss << add;
	ss >> str;
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
  IOperand* operator-(const IOperand &rhs) const
  {
      Factory*                                op;
    
    std::stringstream ss;
    float	add;
    /*    std::int16_t add2;
    std::double add3;
    float	add4;
    int16_t	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = m_nbr - add;
	ss.clear();
	ss << add;
	ss >> str;
	if (add == 0)
	  {
	    str.clear();
	    str = "0";
	  }
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((IOperand*)(op->createOperand(rhs.getType(), (std::string)str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), (std::string)str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));//
  }
  
  IOperand* operator*(const IOperand &rhs) const
  {
      Factory*                                op;
    
    std::stringstream ss; std::string con;//ss<<m_nbr;ss>>con;
    float	add;
    /*    std::int16_t add2;
    std::int32_t add3;
    float	add4;
    int16_t	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = m_nbr * add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }

  IOperand* operator/(const IOperand &rhs) const
  {
  Factory*                                op;
    
    std::stringstream ss; std::string con;//ss<<m_nbr;ss>>con;
    float	add;
    /*    std::int16_t add2;
    std::int32_t add3;
    float	add4;
    int16_t	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	if (add == 0)
	  throw(Exception("WARNING !!! BLACK HOLE CREATED !!!\nprocess: abstractVM_2016 Abort():: entering the 4th dymention !"));
	add = m_nbr / add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
  IOperand* operator%(const IOperand &rhs) const{
    (void)rhs;
    throw Exception("Cant modulo a float .");}
};
  
 class	Double: public IOperand // -1.7E+308 to +1.7E+308
  {
public:
  const double	m_nbr;
  Double(double nbr) : m_nbr(nbr){};
  virtual std::string toString() const {std::stringstream ss; std::string con;ss<<m_nbr;ss>>con;return(con);} //string that represents the instance
  virtual eOperandType getType() const {return (eOperandType::Double);} //returnes thr Type of instance



    IOperand* operator+(const IOperand &rhs) const
    {
      Factory*                                op;
      
      std::stringstream ss; std::string con;//ss<<m_nbr;ss>>con;
      double	add;
    /*    std::int16_t add2;
    std::int32_t add3;
    float	add4;
    double	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = add + m_nbr;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
  IOperand* operator-(const IOperand &rhs) const
  {
      Factory*                                op;
    
    std::stringstream ss; std::string con;//ss<<m_nbr;ss>>con;
    double	add;
    /*    std::int16_t add2;
    std::int32_t add3;
    float	add4;
    double	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = m_nbr - add;
	ss.clear();
	ss << add;
	ss >> str;
	if (add == 0)
	  {
	    str.clear();
	    str = "0";
	  }
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((IOperand*)(op->createOperand(rhs.getType(), (std::string)str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), (std::string)str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));//
  }
  
  IOperand* operator*(const IOperand &rhs) const
  {
      Factory*                                op;
    
    std::stringstream ss; std::string con;//ss<<m_nbr;ss>>con;
    double	add;
    /*    std::int16_t add2;
    std::int32_t add3;
    float	add4;
    double	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	add = m_nbr * add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }

  IOperand* operator/(const IOperand &rhs) const
    {
      Factory*                                op;
    
    std::stringstream ss; std::string con;//ss<<m_nbr;ss>>con;
    double	add;
    /*    std::int16_t add2;
    std::int32_t add3;
    float	add4;
    double	add5;*/
    std::string str;
    if (rhs.getType() != eOperandType::BigDecimal && this->getType() != eOperandType::BigDecimal)
      {
	ss << rhs.toString();
	ss >> add;
	if (add == 0)
	  throw(Exception("WARNING !!! BLACK HOLE CREATED !!!\nprocess: abstractVM_2016 Abort():: entering the 4th dymention !"));
	add = m_nbr / add;
	ss.clear();
	ss << add;
	ss >> str;
	
	if ((int)this->getType() < (int)rhs.getType() && (int)this->getType() < (int)eOperandType::Float)
	  return ((op->createOperand(rhs.getType(), str)));
	else
	  return ((IOperand*)(op->createOperand(this->getType(), str)));
      }
    return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));
  }
    IOperand* operator%(const IOperand &rhs) const{
      (void)rhs;
      throw Exception("Cant modulo a double .");}    
 };

class	BigDecimal: public IOperand // infinit number
{
public:
  const std::string	m_nbr;
  BigDecimal(const std::string nbr) : m_nbr(nbr){};
  virtual std::string toString() const {return(m_nbr);} //string that represents the instance
  virtual eOperandType getType() const {return (eOperandType::BigDecimal);} //returnes thr Type of instance

  IOperand* operator+(const IOperand &rhs) const{Factory* op;return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));};
  IOperand* operator-(const IOperand &rhs) const{Factory* op;return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));};
  IOperand* operator*(const IOperand &rhs) const{Factory* op;return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));};
  IOperand* operator/(const IOperand &rhs) const{Factory* op;return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));};
  IOperand* operator%(const IOperand &rhs) const{Factory* op;return(op->createOperand(eOperandType::BigDecimal, rhs.toString()));};
};

#endif /*TYPES_H_*/
