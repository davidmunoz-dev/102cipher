/*
** 102cipher.c for 102cipher in /home/colett_j/rendu/102cipher
**
** Made by Jean-baptiste Colette
** Login   <colett_j@epitech.net>
**
** Started on  Mon Nov 23 15:29:11 2015 Jean-baptiste Colette
** Last update Sun Nov 29 20:23:31 2015 Jean-baptiste Colette
*/

#include "../include/my.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
  int	a;
  int	x;
  int	i;
  int	k;
  int	z;
  char	*str;
  char	*str2;
  int	dimension;
  int	start_zero;
  int	start_un;
  int	p;
  int	taille;
  
  dimension = 0;
  i = 0;
  a = 0;
  k = 0;
  x = 0;
  z = 0;
  p = 0;
  if (argc == 1 || argc == 2 || argc == 3)
    {
      my_putstr("Error: Bad arguments\n");
      my_putstr("./102cipher message key flag\n");
      return (84);
    }
  if (argv[3][0] == '0')
    {
      while (my_strlen(argv[2]) > dimension)
	{
	  p = p + 1;
	  dimension = p * p;
	}
      str2 = malloc(dimension);
      my_strcpy(str2, argv[2]);
      if (my_strlen(argv[2]) != dimension)
	{
	  start_zero = dimension - (dimension - my_strlen(argv[2])) + 1;
	  while (start_zero != dimension)
	    {
	      str2[start_zero] = 0;
	      start_zero ++;
	    }
	}
      p = 0;
      while (my_strlen(argv[1]) > taille)
	{
	  p = p + 1;
	  if (dimension == 4)
	    taille = p * 2;
	  else if (dimension == 1)
	    taille = p * 1;
	  else if (dimension == 0)
	    return (84);
	  else if (dimension == 9)
	    taille = p * 3;
	  else if (dimension == 16)
	    taille = p * 4;
	  else if (dimension == 25)
	    taille = p * 5;
	  else if (dimension == 36)
	    taille = p * 6;
	}
      str = malloc(taille);
      my_strcpy(str, argv[1]);
      if (my_strlen(argv[1]) != taille)
	{
	  start_un = taille - (taille - my_strlen(argv[1])) + 1;
	  while (start_un != taille)
	    {
	      str[start_un] = 0;
	      start_un ++;
	    }
	}
      my_putstr("Key matrix :");
      my_putchar(10);
      while (i != dimension)
	{
	  my_printf("%d", (str2[i]));
	  i = i + 1;
	  k = k + 1;
	  if (dimension == 9) 
	    {
	      if (k == 3)
		{
		  my_putchar(10);
		  k = 0;
		}
	      else
		my_putchar('\t');
	    }
	  else if (dimension == 1)
	    {
	      if (k == 1)
		{
		  my_putchar(10);
		  k = 0;
		}
	      else
		my_putchar('\t');
	    }
	  else if (dimension == 4)
	    {
	      if (k == 2)
		{
		  my_putchar(10);
		  k = 0;
		}
	      else
		my_putchar('\t');
	    }
	  else if (dimension == 16)
	    {
	      if (k == 4)
		{
		  my_putchar (10);
		  k = 0;
		}
	      else
		my_putchar('\t');
	    }
	  else if (dimension == 36)
	    {
	      if (k == 6)
		{
		  my_putchar(10);
		  k = 0;
		}
	      else
		my_putchar('\t');
	    }
	  else if (dimension == 25)
	    {
	      if (k == 5)
		{
		  my_putchar (10);
		  k = 0;
		}
	      else
		my_putchar('\t');
	    }
	}
      my_putchar(10);
      my_putstr("Encrypted Message:");
      my_putchar(10);
      if (dimension == 9)
	{
	  while(x != taille)
	    {
	      my_printf("%d",((str[x] * str2[a]) + (str[x + 1] * str2[a + 3]) + (str[x + 2] * str2[a + 6])));
	      my_putchar(' ');
	      a = a + 1;
	      z = z + 1;
	      if (z == 3)
		{
		  x = x + 3;
		  a = 0;
		  z = 0;
		}
	    }
	}
      else if (dimension == 16)
	{
	  while (x != taille)
	    {
	      my_printf("%d", ((str[x] * str2[a]) + (str[x + 1] * str2[a + 4]) + (str[x + 2] * str2[a + 8]) + (str[x + 3] * str2[a + 12])));
	      my_putchar(' ');
	      a = a + 1;
	      z = z + 1;
	      if (z == 4)
		{
		  x = x + 4;
		  z = 0;
		  a = 0;
		}
	    }
	}
      else if (dimension == 25)
	{
	  while (x != taille)
	    {
	      my_printf("%d", ((str[x] * str2[a]) + (str[x + 1] * str2[a + 5]) + (str[x + 2] * str2[a + 10]) + (str[x + 3] * str2[a + 15]) + (str[x + 4] * str2[a + 20])));
	      my_putchar(' ');
	      a = a + 1;
	      z = z + 1;
	      if (z == 5)
		{
		  x = x + 5;
		  z = 0;
		  a = 0;
		}
	    }
	}
      else if (dimension == 36)
	{
	  while (x != taille)
	    {
	      my_printf("%d", ((str[x] * str2[a]) + (str[x + 1] * str2[a + 6]) + (str[x + 2] * str2[a + 12]) + (str[x + 3] * str2[a + 18]) + (str[x + 4] * str2[a + 24]) + (str[x + 5] * str2[a + 30])));
	      my_putchar(' ');
	      a = a + 1;
	      z = z + 1;
	      if (z == 6)
		{
		  x = x + 6;
		  z = 0;
		  a = 0;
		}
	    }
	}
      else if (dimension == 4)
	{
	  while(x != taille)
	    {
	      my_printf("%d",((str[x] * str2[a]) + (str[x + 1] * str2[a + 2])));
	      if (x + 1 != taille)
		  my_putchar(' ');
	      a = a + 1;
	      z = z + 1;
	      if (z == 2)
		{
		  x = x + 2;
		  z = 0;
		  a = 0;
		}
	    }
	}
      else if (dimension == 1)
	{
	  while(x != taille)
	    {
	      my_printf("%d", (argv[1][x] * argv[2][0]));
	      if (x + 1 != taille)
		my_putchar(' ');
	      x = x + 1;
	    }
	}
      else if (dimension == 0)
	{
	  while(x != taille)
	    {
	      my_printf("%d", (argv[1][x]));
	      x = x + 1;
	    }
	}
      my_putchar(10);
    }
  else if (argv[3][0] == '1')
    {
      return (0); 
    }
  else if (argv[3][0] != '1' || argv[3][0] != '0')
    return (84);
  return (0);
}
