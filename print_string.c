
#include "ft_printf.h"

char *process_precision(t_tag *tt, char *box, char *res)
{
    if (tt->prcs == DISABLED || tt->prcs != 0 && tt->prcs > ft_strlen(res))
        return (res);
    box = malloc(sizeof(char) * (tt->prcs + 1));
    if (box == NULL)
        return (NULL);
    
}

int     print_string(t_tag *tt, va_list ap, char *res)
{
    t_box *box;
    int     flag;

    flag = DISABLED;
    if (res == NULL)
    {
        res = ft_strndup("(null)", 6);
        flag = ENABLED;
    }
    box = box_create();
    if ((res = process_precision(tt, box->prcs, res)) == NULL
            || (res = process_width(tt, box->width, res)) == NULL)
            {
                free_box(box);
                return (ERROR);
            }
    

    return (0);
}
//res = unsigned char
//box메모리 설정 -> box안에 unsigned char string