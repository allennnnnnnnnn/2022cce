# 2022cce
# week06
# 06-1畫星星
```cpp
#include <stdio.h>
int main()
{
    for(int i=5; i>0; i--){
        for(int j=0 ; j<i ; j++){
             printf("*");
        }
            
    }
}
```
# 06-2星星金字塔
```cpp
#include <stdio.h>
int main()
{
    for(int i=1;i<=5;i++){
        int space=5-i, star=2*i-1;
        for(int k=0;k<space;k++)printf(" ");
        for(int k=0; k<star;k++)printf("*");
        printf("\n");
    }

}
```
# 06-3最大公因數
```cpp
#include <stdio.h>
int main()
{
    printf("請輸入兩個整數,要約分: ");
    int a,b;
    scanf("%d %d",&a,&b);
    int ans;
    for(int i=1;i<=a;i++){
        if(a%i==0 && b%i==0){
            ans=i;
        }
    }
    printf("ans: %d 可約分",ans);
}
```
# 06-4 輾轉相除法
```cpp 
#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d",&a,&b);
    while(1){
        c=a%b;
        printf("老大:%d 老二:%d 老三:%d\n",a,b,c);
        if(c==0) break;
        a=b;
        b=c;
    }
    printf("答案b:%d",b);
}
```
# week07
# 07-1 
```cpp
#include <stdio.h>
int main()
{
    int n=9876543210;
    printf("int 印出來 %d\n",n);


    long long int a=9876543210;
    printf(" long long int 印出來 %lld\n",a);

}
```
# week07-2
```cpp
#include <stdio.h>
int main()
{
    long long int a,b;
    scanf("%lld %lld ", &a, &b );

    long long int ans ;
    for(long long int i=1;i<=a ; i++){
        if(a%i==0 && b%i==0) ans = i;
    }
    printf("最大公因數是:%lld\n",ans);
}
```
# week07-3
```cpp
#include <stdio.h>
int main()
{
    long long int a,b,c;
    scanf("%lld %lld",&a,&b);
    while(1){
        c = a % b;
        printf("a:%lld b:%lld c:%lld\n",a,b,c);
        if(c==0) break;
        a=b;
        b=c;
    }
    printf("答案是: %lld\n",b);
}
```
# week07-4
```cpp
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    printf("現在的個位數:%d\n",n%10);
    n = n / 10 ;
    printf("現在的個位數:%d\n",n%10);
    n = n / 10 ;
    printf("現在的個位數:%d\n",n%10);
    n = n / 10 ;
    printf("現在的個位數:%d\n",n%10);
    n = n / 10 ;
    printf("現在的個位數:%d\n",n%10);
    n = n / 10 ;
    printf("現在的個位數:%d\n",n%10);
    n = n / 10 ;
    printf("現在的個位數:%d\n",n%10);
    n = n / 10 ;
    printf("現在的個位數:%d\n",n%10);
    n = n / 10 ;
    printf("現在的個位數:%d\n",n%10);
    n = n / 10 ;
    printf("現在的個位數:%d\n",n%10);
    n = n / 10 ;
}
```
