//
// main.cpp for  in /home/lacroi_m/pisicne/abstractVM_2016
// 
// Made by Maxime Lacroix
// Login   <lacroi_m@epitech.net>
// 
// Started on  Wed Jul 19 19:22:54 2017 Maxime Lacroix
// Last update Wed Jul 19 19:49:41 2017 Maxime Lacroix
//

#include "vm.hpp"
#include "parse_read.hpp"
#include "parsing.hpp"

int	main(int ac, char **av)
{
  if (ac == 2)
    Parsing	parsing(av[1]);
  else if (ac == 1)
    ParseRead	parseRead(std::cin);
  else {
    std::cerr << "Are you able to follow a simple usage ?" << std::endl;
    exit(84);
  }   
  return (0);
}
