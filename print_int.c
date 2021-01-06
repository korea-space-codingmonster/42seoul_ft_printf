
#include "ft_printf.h"

char     *process_precision(t_tag *tt, char *res, char *box)//res = 123
{
    int res_len;

    res_len = ft_strlen(res);//res의 수
    if (res[0] == '0' && tt->prcs == 0)
        res = "";//printf("%d",0);
    if (tt->prcs <= res_len)
        return (res);
    box = fill_box(tt->prcs, '0');//일단 0으로 가득 채운다
    if (box == NULL)
        return (NULL);
    ft_strcpy(&box[tt->prcs - res_len], res);
    return (box);
}

char    *process_width(t_tag *tt, char *res, char *box)
{

}

int     print_int(t_tag *tt, va_list ap, char *res)
{
    t_box *box;
    int i;

    i = 0;
    box = box_create();//출력할 문자를 담을 메모리 할당
    res = prepare_sign(tt, res);//출력할 문자가 -인자 + 인지 공백 존재 여부 확인
    if ((res = process_precision(tt, res, box->prcs)) == NULL ||
            (res = process_width(tt, res, box->width)) == NULL)
    {
        free_box(box);
        return (0);
    }
    while (res[i] != '\0')
    {
        ft_putchar(res[i]);
        i++;
        tt->nbyte++;
    }
    free(box);
    return (0);
}
