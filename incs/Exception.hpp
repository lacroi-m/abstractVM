#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

class Exception : std::exception
{
public:
  Exception(const std::string &msg);
  
  void operator=(const std::string &);
  const char* what() const noexcept override;
private:
  std::string m_msg;
};

#endif // EXCEPTION_HPP_
