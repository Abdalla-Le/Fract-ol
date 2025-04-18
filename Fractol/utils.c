#include "fractol.h"

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	result = 0.0;
	fraction = 0.1;
	sign = 1;
	i = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i] - '0') * fraction;
			fraction *= 0.1;
			i++;
		}
	}
	return (result * sign);
}

int	is_valid_float(char *str)
{
	int	i = 0;
	int	has_dot = 0;

	// aceita sinal no início
	if (str[i] == '-' || str[i] == '+')
		i++;

	if (str[i] == '\0') // só sinal, sem número
		return (0);

	while (str[i])
	{
		if (str[i] == '.')
		{
			if (has_dot) // já tem um ponto?
				return (0);
			has_dot = 1;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
