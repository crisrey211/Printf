
#include <stdio.h>
#include <stdarg.h>

void ft_putchar(char c, size_t *printed_chars_counter)
{
    write(1, &c, 1);
    (*printed_chars_counter)++;
}

void ft_putstr(char *c, size_t *printed_chars_counter)
{
    if (!c)
        c = "(null)";
    while (*c)
    {
        ft_putchar(*c, printed_chars_counter);
        c++;
    }
}

void ft_selector(char *str, size_t *printed_chars_counter, va_list vargs)
{
    if (*str == 'c')
        ft_putchar(va_arg(vargs, int), printed_chars_counter);
    else if (*str == 's')
        ft_putstr(va_arg(vargs, char*), printed_chars_counter);
}

int ft_printf(char const *str, ...) {
    va_list vargs;
    size_t printed_chars_counter = 0;

    if (!str)
        return 0;

    va_start(vargs, str);

    while (*str) {
        if (*str == '%') {
            str++;
            ft_selector((char *)str, &printed_chars_counter, vargs);
        } else 
            ft_putchar(*str, &printed_chars_counter);
        str++;
    }

    va_end(vargs);
    return printed_chars_counter;
}

#include <stdio.h>

int main(void)
{
    int len1, len2;

    len1 = ft_printf("Hola %s, tu edad es %d y tu inicial es %c.\n", "Carlos", 25, 'C');
    len2 = printf("Hola %s, tu edad es %d y tu inicial es %c.\n", "Carlos", 25, 'C');
    ft_printf("Mi printf: %d caracteres.\n", len1);
    printf("Printf real: %d caracteres.\n", len2);

    ft_printf("Un número hexadecimal: %x, %X\n", 255, 255);
    ft_printf("Un puntero: %p\n", main);
    ft_printf("Un número sin signo: %u\n", 4294967295u);
    ft_printf("Porcentaje: %%\n");
    return 0;
}

