/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:55:47 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/15 15:30:03 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_lower_and_upper(int *upper, int upval, int *lower, int loval)
{
	*lower = loval;
	*upper = upval;
}

void	lower_verification(char *str, int *upper, int *lower, int i)
{
	if (*upper == 1)
		str[i] -= 32;
	*upper = 0;
	*lower = 1;
}

void	upper_verification(char *str, int *upper, int *lower, int i)
{
	if (*lower == 1)
		str[i] += 32;
	*upper = 0;
	*lower = 1;
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int upper;
	int lower;

	i = 0;
	upper = 1;
	lower = 0;
	while (str[i] != '\0')
	{
		if ((97 <= str[i] && str[i] <= 122))
			lower_verification(str, &upper, &lower, i);
		else if ((65 <= str[i] && str[i] <= 90))
			upper_verification(str, &upper, &lower, i);
		else if ((48 <= str[i] && str[i] <= 57))
			set_lower_and_upper(&upper, 0, &lower, 1);
		else
			set_lower_and_upper(&upper, 1, &lower, 0);
		i++;
	}
	return (str);
}
