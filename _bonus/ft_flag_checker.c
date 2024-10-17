#include "ft_printf_bonus.h"
#include "../libft/libft.h"

int is_flag(char c)
{
    return (ft_strchr("#+-0 ", c) != NULL);
}

t_flags parse_format(const char *str)
{
    t_flags flags = {0};
    const char *ptr = str;

    if (*ptr != '%')
    {
        flags.error = true;
        return (flags);
    }
    ptr++;
    while (is_flag(*ptr))
    {
        if (*ptr == '#')
            flags.adapter = true;
        else if (*ptr == '-')
            flags.minuszero = '-';
        else if (*ptr == '0' && flags.minuszero != '-')
            flags.minuszero = '0';
        else if (*ptr == '+')
            flags.plusspace = '+';
        else if (*ptr == ' ' && flags.plusspace != '+')
            flags.plusspace = ' ';
        ptr++;
    }
    if (is_flag(*ptr))
    {
        flags.error = true;
        return (flags);
    }
    flags.length = 0;
    while (ft_isdigit(*ptr))
    {
        flags.length = flags.length * 10 + (*ptr - '0');
        ptr++;
    }
    if (*ptr == '.')
    {
        ptr++;
        flags.precision = 0;
        while (ft_isdigit(*ptr))
        {
            flags.precision = flags.precision * 10 + (*ptr - '0');
            ptr++;
        }
    }
    else
        flags.precision = -1;
    if (ft_isalpha(*ptr))
    {
        flags.modifier = *ptr;
    }
    else
        flags.error = true;
    return (flags);
}

void print_flags(const t_flags *flags)
{
    printf("Adapter (#): %d\n", flags->adapter);
    printf("MinusZero (-/0): %c\n", flags->minuszero);
    printf("PlusSpace (+/space): %d\n", flags->plusspace);
    printf("Length: %d\n", flags->length);
    printf("Precision: %d\n", flags->precision);
    printf("Modifier: %c\n", flags->modifier);
    printf("Error: %d\n", flags->error);
}

int main()
{
    const char *test = "%##-# ++ 20.5s";

    t_flags flags1 = parse_format(test);

    printf("Test 1: %s\n", test);
    print_flags(&flags1);

    return (0);
}
