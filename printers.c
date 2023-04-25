#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * _print_a_char - Prints a character
  * @args: A list of variadic arguments
  *
  * Return: The length of the character
  */
int _print_a_char(va_list args)
{
	char c = (va_arg(args, int));
	_write(c);
	return (1);
}

/**
  * _print_a_string - Prints a string
  * @args: A list of variadic arguments
  *
  * Return: The length of the string
  */
int _print_a_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			_write(arg[i]);
			i++;
		}

		return (i);
	}

	_write('(');
	_write('n');
	_write('u');
	_write('l');
	_write('l');
	_write(')');
	return (6);
}

/**
  * _print_a_integer - Prints an integer
  * @args: A list of variadic arguments
  *
  * Return: The length of the string
  */
int _print_a_integer(va_list args)
{
	int count = 1, x = 0;
	unsigned int y = 0;

	y = va_arg(args, int);
	x = y;
	if (x < 0)
	{
		_write('-');
		x = x * -1;
		y = x;
		count += 1;
	}
	while (y > 9)
	{
		y = y / 10;
		count++;
	}

	_recursion_integer(x);
	return (count);
}

/**
  * _recursion_integer - Prints a integer
  * @a: integer to print
  *
  * Return: Nothing
  */
void _recursion_integer(int a)
{
	unsigned int t;

	t = a;
	if (t / 10)
		_recursion_integer(t / 10);
	_write(t % 10 + '0');
}
