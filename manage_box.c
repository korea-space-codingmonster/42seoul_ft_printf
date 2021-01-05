#include "ft_printf.h"

void    box_create(void)
{
    t_box *tb;

    if ((tb = (t_box *)malloc(sizeof(t_box))) == ERROR)
        return (ERROR);
    
}