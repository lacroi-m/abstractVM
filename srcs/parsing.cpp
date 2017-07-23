/*
** Loris
*/

#include "parsing.hpp"
#include "commands.hpp"
#include "value.hpp"
#include "Exception.hpp"
#include <cstring>
#include <regex>

Parsing::Parsing(const char *path) {
  std::string		tmp;
  std::stringstream	content;
  std::ifstream		file(path, std::ifstream::in);

  if (file.is_open())
    while (getline(file, tmp))
      content << tmp << std::endl;
  else
    throw Exception("Exception while opening/reading the file");
  _content = content.str();
  checkContent();
}

void				Parsing::suppress_errors() {
  Commands			*com = new Commands();
  Values			*val = new Values();
  std::vector<std::string>	commands = com->get_commands();
  std::vector<std::string>	value = val->get_values();
  bool				valid = false;

  for (std::map<std::string, std::vector<std::string>>::iterator it = _clean_map.begin(); it != _clean_map.end(); ++it) {
    valid = false;
    for (std::vector<std::string>::iterator ite = commands.begin(); ite != commands.end(); ++ite) {
      if (it->second[0] == *ite)
	valid = true;
    }
    if (valid == false) {
      std::cout << "Unknown command at " << it->first << std::endl;
      exit(84);
    }
  }
  for (std::map<std::string, std::vector<std::string>>::iterator it = _clean_map.begin(); it != _clean_map.end(); ++it) {
    valid = false;
    if (it->second[0] == "push" || it->second[0] == "load" || it->second[0] == "assert" || it->second[0] == "store") {
      for (std::vector<std::string>::iterator ite = value.begin(); ite != value.end(); ++ite) {
	if (std::distance(it->second.begin(), it->second.end()) > 1 && (it->second[1] == *ite)) {
	  valid = true;
	}
      }
      if (valid == false) {
	std::cerr << "Error at " << it->first
		  << " with the command " << it->second[0]
		  << std::endl;
	exit(84);
      }
    }
    else
      if (std::distance(it->second.begin(), it->second.end()) > 1) {
	std::cerr << "Error at " << it->first
		  << " with the command " << it->second[0]
		  << std::endl;
	exit(84);
      }
  }
  auto it = _clean_map.end();
  if (it == _clean_map.begin())
    exit(84);
  it--;
  if (it->second[0] != "exit")
    throw Exception("Expected EXIT command in the file");
}

void				Parsing::show_me_the_map() {
  for (std::map<std::string, std::vector<std::string>>::iterator it = _clean_map.begin(); it != _clean_map.end(); ++it) {
    std::cout << "--[" << it->first << "]--" << std::endl;
    for (std::vector<std::string>::iterator ite = it->second.begin(); ite != it->second.end(); ++ite)
      std::cout << "this vector's element --> " << *ite << std::endl;
  }
}

std::vector<std::string>	Parsing::split_line(std::string &line) {
  std::vector<std::string>	splited;
  std::string			buf;
  std::string			regint =  "^\\s*-?[0-9]{1,10}\\s*$";
  std::regex                    ints(regint);
  std::string			regdec =  "^\\s*-?[0-9]{1,10}\\.?[0-9]{1,6}s*$";
  std::regex                    decimals(regdec);
  std::string			regbigdec =  "^\\s*-?[0-9]{1,10}\\.?[0-9]{1,12}s*$";
  std::regex                    bigdecimals(regbigdec);

  std::replace(line.begin(), line.end(), '(', ' ');
  std::replace(line.begin(), line.end(), ')', ' ');
  std::istringstream	       	tmp(line);
  while (getline(tmp, buf, ' ')) {
    splited.push_back(buf);
  }
  if (splited[0] == "push" || splited[0] == "load" || splited[0] == "assert" || splited[0] == "store") {
    if (std::strncmp(splited[1].c_str(), "int", 3) == 0) {
      if (std::regex_match(splited[2], ints) == false) {
	std::cerr << "Bad integer value in the command : "
		  << splited[0] << " " << splited[1]
		  << " of value (" << splited[2] << ")" << std::endl;
	exit(84);
      }
    }
    else if (std::strncmp(splited[1].c_str(), "bigdecimal", 10) == 0) {
      if (std::regex_match(splited[2], bigdecimals) == false) {
	std::cerr << "Bad bigdecimal value in the command : "
		  << splited[0] << " " << splited[1]
		  << " of value (" << splited[2] << ")" << std::endl;
	exit(84);
      }
    }
    else {
      if (std::regex_match(splited[2], decimals) == false) {
	std::cerr << "Bad decimal value in the command : "
		  << splited[0] << " " << splited[1]
		  << " of value (" << splited[2] << ")" << std::endl;
	exit(84);
      }
    }
  }
  return (splited);
}

void					Parsing::checkContent() {
  std::istringstream			toParse(_content);
  std::string				tmp;
  int					i = 1;

  while (getline(toParse, tmp)) {
    if (tmp.length() > 1 && tmp.c_str()[0] != ';') {
      if (i < 10)
	_clean_map.insert(std::pair<std::string, std::vector<std::string>>("line0" + std::to_string(i), split_line(tmp)));
      else
	_clean_map.insert(std::pair<std::string, std::vector<std::string>>("line" + std::to_string(i), split_line(tmp)));
    }
    if (std::strncmp(tmp.c_str(), "exit", 4) == 0) {
      suppress_errors();
      return ;
    }
    i++;
  }
  suppress_errors();
}

std::map<std::string,std::vector<std::string>, std::less<std::string>>	Parsing::get_map(){
  return this->_clean_map;
}
