#include "ft_printf.h"

//printf("-%d", -123);
//*res = -123;(문자열)
//printf("%.d",123);
int     print_int(t_tag *tt, va_list ap, char *res)
{
    t_box *box;

    box = box_create(void);

    process_precison(tt, res);
}