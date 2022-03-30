#include <stdio.h>
#include <math.h> 
#define etha 0.5

int x1[4]={0,0,1,1};
int x2[4]={0,1,0,1};
int target[4]={0};
double sum=0.0;
double w1=0.0;
double w2=0.0;
double Sum=0.0;
double tetha=0.0;
int line_check[4]={0,};
int cal_y[4]={0,};

void Line_check_reset(){
	for(int line=0;line<4;line++){
		line_check[line]=0;
	}
}

void Input_w1_w1_tetha(){
        printf("plz put w1 and w2 tetha");
        scanf("%lf %lf %lf",&w1,&w2,&tetha);
        printf("w1,w2,setha is %f %f %f\n",w1,w2,tetha);
    }


void And(){
	for(int line=0;line<4;line++){
		printf("x1 is %d",x1[line]);
		printf("x2 is %d",x2[line]);
		target[line]=x1[line]*x2[line];
		printf("y is %d\n",target[line]);
	}
};

void Or(){
	for(int line=0;line<4;line++){
		printf("x1 is %d",x1[line]);
		printf("x2 is %d",x2[line]);
		target[line]=x1[line]+x2[line];
		if(target[line]>0){
			target[line]=1;
		}
		printf("y is %d\n",target[line]);
	}
};
	

void Perceptron(int line){
	sum=x1[line]*w1+x2[line]*w2;
	//sum=round(100*Sum)/100;
   // tetha=round(100*tetha)/100;
	printf("perceptron sum is %lf\n",sum);
	if(sum>=tetha){
    	cal_y[line]=1;
    }
    else{
        cal_y[line]=0;
    }  
		printf("---------------");
	printf("line is%d\n",line);
	printf("x1 is %d\n",x1[line]);
	printf("x2 is %d\n",x2[line]);
	printf("target is %d\n",target[line]);
	printf("sum is %lf\n",sum);
	printf("tetha is %lf\n",tetha);
	printf("w1 is %lf\n",w1);
	printf("w2 is %lf\n",w2);

	if(cal_y[line]==target[line]){
		line_check[line]=1;
		printf("correct \n");
	}
	else{
		    if(cal_y[line]==0&&x1[line]==1){ 
                printf("error1\n");
                w1=w1+0.5*w1;
            }
            
            if(cal_y[line]==0&&x2[line]==1){
                printf("error2\n");
                w2=w2+0.5*w2;
            }
            
            if(cal_y[line]==1&&x1[line]==1){
                printf("error3\n");
                w1=w1-0.5*w1;
            }
           
            if(cal_y[line]==1&&x2[line]==1){
                printf("error4\n");
                w2=w2-0.5*w2;
				
            }
			printf("after w1 is %lf\n",w1);
			printf("after w2 is %lf\n",w2);
	}
//	Compare(line); 
}


void Check(){
	
	for(int line=0;line<4;line++){
		Perceptron(line);
	}
}

void Go(int cnt){
 
    if(cnt==5){//100회 반복시!!
         printf("can't get the result\n");
         return ;
     }
   
    if(line_check[0]==1&&line_check[1]==1&&line_check[2]==1&&line_check[3]==1){//조건이 전부 맞으면!!
        printf("happy ending\n");
        return ;
    }
    
	Line_check_reset();

    printf("cnt is %d\n",cnt);
    Check();
    cnt++;
    Go(cnt);
 }

int main(){
	Input_w1_w1_tetha();
	//And();
	Or();
	Go(0);
}
