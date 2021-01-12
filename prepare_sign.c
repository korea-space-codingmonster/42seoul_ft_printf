
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

char    *process_sign(char *box, t_tag *tt, int res_len)
{   
    if (tt->sign == '\0')
        return (box);
    if ((tt->zero_fill == ENABLED && tt->prcs == DISABLED)
			|| tt->left_aligned == ENABLED)
        box[0] = tt->sign;
    else
        box[tt->width - res_len - 1] = tt->sign;
    return (box);
}