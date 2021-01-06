
#include "ft_printf.h"

char        *prepare_sign(t_tag *tt, char *res)
{
    if (res[0] == '-')
    {
        tt->sign = '-';
        res++;
    }
    else if (tt->plus == ENABLED)
    {
        tt->sign = '+';
    }
    else
    {
        tt->sign = ' ';
    }
    return (res);
}
