#include <stdio.h>

int x1[]={0,1};
int x2[]={0,1};
int visited[3]={0,};
double Sum=0.0;
double w1=0.0;
double w2=0.0;
double tetha=0.0;
int y[4]={1,};
int cal_y[4]={0,};
int break_flag=0;

void Or(){
    int x=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
     
     if(x1[i]+x2[j]>=1){
     y[x]=1;    
     }
     else{
    y[x]=0;
     }
     x++;
    }

    }
}

void perceptron(int i,int j,int k){
            Sum=(x1[i]*w1)+(x2[j]*w2);
            printf("x1:%d x2:%d w1:%.20lf w2:%.20lf tetha:%lf sum:%.20lf\n",x1[i],x2[j],w1,w2,tetha,Sum);
            Sum=round(100*Sum)/100;
            tetha=round(100*tetha)/100;
            if(Sum>=tetha){
                cal_y[k]=1;
            }
            else{
                cal_y[k]=0;
            }    
}

void check(){
    int k=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            perceptron(i,j,k);
            printf("cal_y is %d real y is%d\n",cal_y[k],y[k]);
            printf("k is %d\n",k);
           
            if(cal_y[k]==y[k]){
               visited[k]=1;
                printf("continue\n"); 
                
            }

            else if(cal_y[k]==0&&x1[i]==1){ 
                printf("error1\n");
                 w1=w1+0.5*w1;
                break_flag=1;
                break;   
            }
            
            else if(cal_y[k]==0&&x2[j]==1){
                printf("error2\n");
                 w2=w2+0.5*w2;
                 break_flag=1; 
                 break;
            }
            
            else if(cal_y[k]==1&&x1[i]==1){
                printf("error3\n");
                 w1=w1-0.5*w1;
                break_flag=1; 
                break;
            }
           
            else if(cal_y[k]==1&&x2[j]==1){
                printf("error4\n");
                w2=w2-0.5*w2;
                break_flag=1;
                break;
            }
             k++;

        }
        if(break_flag==1){
            visited[0]=0;
            visited[1]=0;
            visited[2]=0;
            visited[3]=0;
            break_flag=0;
            break;
        }
    }
    printf("check\n");
}


 void go(int cnt){
 
     if(cnt==100){
         printf("can't get the result\n");
         return 0;
     }
   
    if(visited[0]==1&&visited[1]==1&&visited[2]==1&&visited[3]==1){
        printf("happy ending\n");
        return 0;
    }
    
     printf("cnt is %d\n",cnt);
     check();
     cnt++;
     go(cnt);
 }
    
    
void input_w1_w1_tetha(){
        printf("plz put w1 and w2 setha");
        scanf("%lf %lf %lf",&w1,&w2,&tetha);
        printf("w1,w2,setha is %f %f %f",w1,w2,tetha);
    }


int main(){
    input_w1_w1_tetha();//ok
    Or();//ok
    go(0);
  
}
