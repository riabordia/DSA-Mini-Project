#include <stdio.h>

char a[5000],b[5000],res[5000];

int main()
{     a[0]=0,b[0]=1;
      int carry=0,stopper=1,number;
      printf("Enter n for nth Fibonacci term : ");
      scanf("%d",&number);
      for(int i=0;i<number;i++){
          for(int j=0;j<stopper;j++){
            res[j]=a[j]+b[j]+carry;
            int checker=res[j];
            carry=0;
            int now=res[j];
            if(now>=10){
              res[j]=now%10;
              carry=now/10;
            }
            if(j==stopper-1 && checker>=10){
              res[j+1]=a[j+1]+b[j+1]+carry;
              carry=0;
              stopper++;
              break;
            }
          }
            for(int j=stopper;j>=0;j--){
              b[j]=a[j];
              a[j]=res[j];
            }
        }
        int pass=0;
        for(int j=stopper;j>=0;j--){
          if(pass==1 || res[j]!=0){
            printf("%d",res[j]);
            pass=1;
          }
        }
}
