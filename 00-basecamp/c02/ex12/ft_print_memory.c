/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:46:00 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/08 18:33:00 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned long int n, unsigned int size)
{
	unsigned char	hexa[16];
	unsigned int	temp_size;
	char			*hex;

	hex = "0123456789abcdef";
	temp_size = size;
	while (temp_size--)
	{
		hexa[temp_size] = hex[n % 16];
		n /= 16;
	}
	write(1, &hexa[0], size);
}

void	print_memory_address(void *addr)
{
	unsigned long int int_addr;

	int_addr = (unsigned long int)(addr);
	print_hex(int_addr, 16);
	write(1, ": ", 2);
}

void	print_hex_content_twice(void *addr, unsigned int add, unsigned int size)
{
	unsigned long int add_address;

	add_address = (unsigned long int)addr + add;
	if (size > add)
		print_hex(*(unsigned long int *)(add_address), 2);
	else
		write(1, "  ", 2);
	if (size > add + 1)
		print_hex(*(unsigned long int *)(add_address + 1), 2);
	else
		write(1, "  ", 2);
	write(1, " ", 1);
}

void	print_content(void *add)
{
	char *c;

	c = (char *)(add);
	if (32 <= *c && *c <= 126)
		write(1, c, 1);
	else
		write(1, ".", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int add_address;
	unsigned int add_content;

	add_address = 0;
	while (add_address < size)
	{
		print_memory_address(addr + add_address);
		add_content = add_address;
		while (add_content < 16 + add_address)
		{
			print_hex_content_twice(addr, add_content, size);
			add_content += 2;
		}
		add_content = add_address;
		while (add_content < 16 + add_address && add_content < size)
		{
			print_content(addr + add_content++);
		}
		write(1, &"\n", 1);
		add_address += 16;
	}
	return (addr);
}
