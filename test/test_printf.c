#include <stdio.h>
#include <wchar.h>

int main()
{
    //printf("[%50lld]", 123456789LL);//[00000000000000000000000000000000000000000123456789]
    //printf("[%.50lld]", 1234567LL);//[                                         123456789]
    //printf("[%.*d]",10,123456789);
    //printf("[%.4d]",1234);//[-0123]
  //  printf("[%-10d]", -123);//[-123      ]
    //printf("[%0*d]", 10,123);
    //printf("[%-0*d]", 10,123);x
    //printf("[%0*-d]", 10,123);x//파싱 순서를 따져보면 안돼는 것을 알 수 있음
    //printf("%.d", 123);
    //printf("[%10d]", 123);
    //printf("[%*.d]",40,22222222);//[                                22222222]
    //printf("[%.*d]",40,22222222);//[0000000000000000000000000000000022222222]
    //printf("[%*d]", 6,1);//[     1]
    //printf("[%*d]", 4,1234567899999);//error
    //printf("[%d]", 10, 234923857234);//error


    //printf ("%d", 1234);
    //printf("[%4d]", 1234567);// width < res_len
    //printf("[%100d]", 12345);// width > res_len ---> box : 100 
    //printf("[%-4d]", 12345);// left_align
    //printf("[%-.10d]", 12345); //[0000012345]% precs가 있으면 0으로 채워짐
    //printf("[%-100d]", 123456789);
    //printf("[%-100d]", -12345);
    
    //printf("[%.12s]", "안녕하세요");//prcs = disalble
    //printf("[%.s]", "안녕하세요");//[]
    //printf("[%.30s]", "안녕하세요");//[안녕하세요]
    //printf("[%u]", -12345);//disable

    printf("[%x]", 768955);
}