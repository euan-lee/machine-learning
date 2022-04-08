#include <stdio.h>
#include <math.h> 
#define etha 0.05

int x1[4]={0,0,1,1};
int x2[4]={0,1,0,1};
int target[4]={0};
double sum=0.0;
double w1=2.0;
double w2=0.0;
double tetha=0.0;
int line_check[4]={0,};
int cal_y[4]={0,};
double err_sum=0;
int cnt=0;

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

	cal_y[line]=x1[line]*w1+x2[line]*w2-tetha;
	printf("cal _y is %d\n",cal_y[line]);
	if(cal_y[line]==target[line]){
		line_check[line]=1;
	}
	else{
		printf("w1,w2,setha is %f %f %f\n",w1,w2,tetha);
		printf("line %d error \n",line);
		w1=w1+w1*etha*(target[line]-cal_y[line])*x1[line];
		w2=w2+w2*etha*(target[line]-cal_y[line])*x2[line];
		err_sum=err_sum+(0.5)*(target[line]-cal_y[line])*(target[line]-cal_y[line]);
		printf("err_desu %lf\n",err_sum); 
	}
}

void Check(){
	for(int line=0;line<4;line++){
		Perceptron(line);
	}
}

int main(){

	Input_w1_w1_tetha();
	And();
	//Or();	

	FILE *w1_desu = fopen("w1.txt", "w");    
	FILE *w2_desu = fopen("w2.txt", "w");  
	FILE *err_desu = fopen("err.txt", "w");   

	while(1){
	
	if(cnt==100){//100회 반복시!!
		fclose(w1_desu);
		fclose(w2_desu); 
		fclose(err_desu);  
		break;
    }

	if(line_check[0]==1&&line_check[1]==1&&line_check[2]==1&&line_check[3]==1){//조건이 전부 맞으면!!
    	printf("happy ending\n");
		fclose(w1_desu);
		fclose(w2_desu); 
		fclose(err_desu);   
    	break;
    }
	Line_check_reset();
	Check();
	printf("cnt is %d\n",cnt);
	printf("why w1 is %lf\n",w1);
	printf("why w2 is %lf\n",w2);
	printf("err_desu %lf\n",err_sum); 
	fprintf(w1_desu,"%lf %lf\n",w1,w2);
   // fprintf(w2_desu,"%lf\n",w2);
	fprintf(err_desu,"%lf\n",err_sum);  
	cnt++;
	err_sum=0.0;
	}

	
}
