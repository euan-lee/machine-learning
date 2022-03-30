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
double err_sum=0;

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
		printf("correct AND err is 0\n");
	}
	else{
		w1=w1+w1*etha*(target[line]-cal_y[line])*x1[line];
		w2=w2+w2*etha*(target[line]-cal_y[line])*x2[line];
		printf("after w1 is %lf\n",w1);
		printf("after w2 is %lf\n",w2);
		err_sum=err_sum+(0.5)*(target[line]-cal_y[line])*(target[line]-cal_y[line]);
		
	}
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
		FILE *fp = fopen("hello.txt", "w");    // hello.txt 파일을 쓰기 모드(w)로 열기.
        fprintf(fp,"%lf\n",w1); 
        fprintf(fp,"%lf\n",w2); 
        fprintf(fp,"%lf\n",tetha); 
        fclose(fp);    // 파일 포인터 닫기
        return ;
    }
	
	Line_check_reset();
  //  fprintf(fp3,"%lf\n",w1); 
  //  fprintf(fp3,"%lf\n",w2); 
    Check();
//	fprintf(fp3,"%lf\n",err_sum); 
	err_sum=0.0;
    cnt++;
    Go(cnt);
	
 }

int main(){
	Input_w1_w1_tetha();
	//And();
	Or();
	// hello.txt 파일을 쓰기 모드(w)로 열기.
	Go(0); 
	
}
