//
// main.cpp for  in /home/lacroi_m/pisicne/abstractVM_2016
// 
// Made by Maxime Lacroix
// Login   <lacroi_m@epitech.net>
// 
// Started on  Wed Jul 19 19:22:54 2017 Maxime Lacroix
// Last update Fri Jul 21 22:11:00 2017 thomas duchet
//

#include "vm.hpp"
#include "parse_read.hpp"
#include "parsing.hpp"
#include "Stack.hpp"
#include <string>

int	main(int ac, char **av)
{
  Stack		stack;

  if (ac == 2)
    {
      Parsing	parsing(av[1]);
      stack.manage_func(parsing.get_map());
    }
  else if (ac == 1)
    {
      ParseRead	parseRead(std::cin);
      stack.manage_func(parseRead.get_map());
    }
  return (0);
}
