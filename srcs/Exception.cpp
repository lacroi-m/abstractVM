#include "Exception.hpp"

Exception::Exception(const std::string &mssg) : m_mssg(mssg) {}

void Exception::operator=(const std::string &mssg) {
  m_mssg = mssg;
}

const char *Exception::what() const noexcept { return m_mssg.c_str();}
