/*
** Loris
*/

#include "parsing.hpp"
#include "commands.hpp"
#include "value.hpp"

Parsing::Parsing(const char *path) {
  std::string		tmp;
  std::stringstream	content;
  std::ifstream		file(path, std::ifstream::in);

  if (file.is_open())
    while (getline(file, tmp))
      content << tmp << std::endl;
  else {
    std::cerr << "Exception while opening/reading the file : " << path << std::endl;
    exit(84);
  }
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
      _clean_map.erase(it);
      it--;
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
	_clean_map.erase(it);
	it--;
      }
    }
    else
      if (std::distance(it->second.begin(), it->second.end()) > 1) {
	_clean_map.erase(it);
	it--;
      }
  }
  auto it = _clean_map.end();
  it--;
  if (it->second[0] != "exit")
    exit(84);
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
  std::replace(line.begin(), line.end(), '(', ' ');
  std::replace(line.begin(), line.end(), ')', ' ');
  std::istringstream	       	tmp(line);
  while (getline(tmp, buf, ' '))
    splited.push_back(buf);
  return (splited);
}

void		Parsing::checkContent() {
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
    i++;
  }
  suppress_errors();
  show_me_the_map();
}
