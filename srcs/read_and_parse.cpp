/*
** Loris
*/

#include "parse_read.hpp"
#include "commands.hpp"
#include "value.hpp"

ParseRead::ParseRead(std::istream &cin) {
  std::string		tmp;
  std::stringstream	content;
  
  while (getline(cin, tmp)
	 && std::strncmp(tmp.c_str(), ";;", 2) != 0)
    content << tmp << std::endl;
  _content = content.str();
  checkContent();
}

void                            ParseRead::suppress_errors() {
  Commands                      *com = new Commands();
  Values			*val = new Values();
  std::vector<std::string>	value = val->get_values();
  std::vector<std::string>      commands = com->get_commands();
  bool                          valid = false;

  for (std::map<std::string, std::vector<std::string>>::iterator it = _clean_map.begin(); it != _clean_map.end(); ++it) {
    valid = false;
    for (std::vector<std::string>::iterator ite = commands.begin(); ite != commands.end(); ++ite) {
      if (it->second[0] == *ite)
        valid = true;
    }
    if (valid == false) {
      std::cout << "Unknown or misspelled command at " << it->first << std::endl;
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
                  << " with the command" << it->second[0]
                  << std::endl;
        exit(84);
      }
    }
    else
      if (std::distance(it->second.begin(), it->second.end()) > 1) {
	std::cerr << "Error at " << it->first
                  << " with the command" << it->second[0]
                  << std::endl;
        exit(84);
      }
  }
  auto it = _clean_map.end();
  it--;
  if (it->second[0] != "exit") {
   std::cerr << "Expected EXIT command in the file" << std::endl;
    exit(84);
  }
}


void                            ParseRead::print_me_the_map() {
  for (std::map<std::string, std::vector<std::string>>::iterator it = _clean_map.begin(); it != _clean_map.end(); ++it) {
    std::cout << "--[" << it->first << "]--" << std::endl;
    for (std::vector<std::string>::iterator ite = it->second.begin(); ite != it->second.end(); ++ite)
      std::cout << "this vector's element --> " << *ite << std::endl;
  }
}

std::vector<std::string>        ParseRead::split_line(std::string &line) {
  std::vector<std::string>      splited;
  std::string                   buf;

  std::replace(line.begin(), line.end(), '(', ' ');
  std::replace(line.begin(), line.end(), ')', ' ');
  std::istringstream            tmp(line);
  while (getline(tmp, buf, ' '))
    splited.push_back(buf);
  return (splited);
}

void					 ParseRead::checkContent() {
  std::istringstream                    toParse(_content);
  std::string                           tmp;
  int                                   i = 1;

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
}

