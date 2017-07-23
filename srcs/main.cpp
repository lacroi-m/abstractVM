//
// main.cpp for  in /home/lacroi_m/pisicne/abstractVM_2016
// 
// Made by Maxime Lacroix
// Login   <lacroi_m@epitech.net>
// 
// Started on  Wed Jul 19 19:22:54 2017 Maxime Lacroix
// Last update Sun Jul 23 16:53:15 2017 Maxime Lacroix
//

#include "Exception.hpp"
#include "vm.hpp"
#include "parse_read.hpp"
#include "parsing.hpp"
#include "Stack.hpp"
#include <string>

int	main(int ac, char **av)
{
  try
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
      else
	throw Exception("Are you able to follow a simple usage ?");
    }
  catch(Exception const& exc)
    {
      std::cerr << "Execption catched :\n" << exc.what() << std::endl;
      return (84);
    }
  return (0);
}
