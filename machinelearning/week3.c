#include <stdio.h>
#include <math.h> 
#define etha 0.5

int x1[]={0,1};
int x2[]={0,1};
int visited[4]={0,};
double Sum=0.0;
double w1=0.0;
double w2=0.0;
double tetha=0.0;
int y[4]={1,};
int cal_y[4]={0,};
int break_flag=0;

int Err(int target,int real){
	int result=0;
	result=target-real;
	return result;
}

void Or(){//y or로 해버리기
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

void And(){//y and 연산하기
    int  num=0;
    printf("and operation");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("x1%d x2 %d\n",x1[i],x2[j]);
            y[num]=x1[i]*x2[j];
            printf("y is %d\n",y[num]);
            num++;
        }
    }
}

int visit_reset(){//y의 4개 연산이 맞는지 확인하는 과정에서 초기화 과정
    for(int i=0;i<4;i++){
        visited[i]=0;
    }
}

void perceptron(int i,int j,int k){//play the perceptron
            Sum=(x1[i]*w1)+(x2[j]*w2);
            Sum=round(100*Sum)/100;
            tetha=round(100*tetha)/100;
            if(Sum>=tetha){
                cal_y[k]=1;
            }
            else{
                cal_y[k]=0;
            }    
}


void check(){//00,01,10,11,이 맞는지 확인
    int k=0;
	int err=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            perceptron(i,j,k);//00,01,00,11이 맞는지 확인 
        
            if(cal_y[k]==y[k]){//k번쨰 줄 연산 완료 에러 없음
               visited[k]=1;              
            }

            else if(cal_y[k]==0&&x1[i]==1){//k번쨰 줄 연산 완료 에러 있음
              	int err=Err(y[k],cal_y[k]);
				printf("err is  %d x[i]%d,x[j]%d\n ",err,x1[i],x2[j]);
                w1=w1+(etha*w1*x1[i]+etha*w1*x2[j]);
                break_flag=1;
                break;   
            }
            
            else if(cal_y[k]==0&&x2[j]==1){//k번쨰 줄 연산 완료 에러 있음
               	int err=Err(y[k],cal_y[k]);
				printf("err is  %d x[i]%d,x[j]%d\n ",err,x1[i],x2[j]);
                w2=w2+(etha*w2*x1[i]+etha*w2*x2[j]);
                break_flag=1; 
                break;
            }
            
            else if(cal_y[k]==1&&x1[i]==1){//k번쨰 줄 연산 완료 에러 있음
                int err=Err(y[k],cal_y[k]);
				printf("err is  %d x[i]%d,x[j]%d\n ",err,x1[i],x2[j]);
                w1=w1-(etha*w1*x1[i]+etha*w1*x2[j]);
                break_flag=1; 
                break;
            }
           
            else if(cal_y[k]==1&&x2[j]==1){//k번쨰 줄 연산 완료 에러 있음
                int err=Err(y[k],cal_y[k]);
				printf("err is  %d x[i]%d,x[j]%d\n ",err,x1[i],x2[j]);
                w2=w2-(etha*w2*x1[i]+etha*w2*x2[j]);
                break_flag=1;
                break;
            }
            
			k++;//i,j가 안맞아 무조건 여기에 있어야함

        }
        if(break_flag==1){
            visit_reset();
            printf("visit reset");
            break_flag=0;
            break;
        }
    }
    printf("check\n");
}


 void go(int cnt){
 
    if(cnt==100){//100회 반복하고 조건 탈출
         printf("can't get the result\n");
         return ;
     }
   
    if(visited[0]==1&&visited[1]==1&&visited[2]==1&&visited[3]==1){//4개가 맞다면 조건 탈출
       
	    printf("w1:%lf w2:%lf\n",w1,w2);
        FILE *fp = fopen("hello.txt", "w");   
        fprintf(fp,"%lf\n",w1); 
        fprintf(fp,"%lf\n",w2); 
        fprintf(fp,"%lf\n",tetha); 
        fclose(fp);    // 파일 포인터 닫기

        return ;
    }
    

     printf("cnt is %d\n",cnt);
     check();
     cnt++;
     go(cnt);
 }
    
    
void input_w1_w1_tetha(){//입력
        printf("plz put w1 and w2 tetha");
        scanf("%lf %lf %lf",&w1,&w2,&tetha);
        printf("w1,w2,setha is %f %f %f",w1,w2,tetha);
    }


int main(){
    input_w1_w1_tetha();//ok
    Or();//ok
    //And();
    go(0);//ok
}
