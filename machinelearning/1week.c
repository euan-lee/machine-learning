#include <stdio.h>
#include <math.h> 
//텍스트 파일 읽기
//읽은 함수 데이터에 집어 넣기
//결과값 y 아웃풋 데이터에 넣기
//변수 선언
double Sum=0.0;
double w1=0.0;
double w2=0.0;
double setha=0.1;
struct data{
    double x1;
    double x2;
};
int flag=0;
int one=1;
int zero=0;
void input_data_on_text_and_file_open(){
    FILE *fp;
    fp = fopen("data.txt", "w");//없으면 만듦
    
    if(fp == NULL){
        printf("file open failed\n");
    }

    else{
        printf("file open success\n");
        
        for(double i=-1.0;i<1.0;i=i+0.1){ 
            for(double j=-1.0;j<1.0;j=j+0.1){
                    fprintf(fp,"%.1lf %.1lf\n",i,j);
            }
        }
    }
     fclose(fp);
}

void input_w1_w1_setha(){
        printf("plz put w1 and w2 setha");
        //입력값 범위 조정해줘잉
        scanf("%lf %lf %lf",&w1,&w2,&setha);
        printf("w1,w2,setha is %f %f %f",w1,w2,setha);
    }

int perceptron(double x1,double x2,double w1,double w2,double setha){
    printf("x1:%lf x2:%lf w1:%lf w2:%lf setha:%lf\n",x1,x2,w1,w2,setha);
    
    Sum=(x1*w1)+(x2*w2);
    Sum=round(100*Sum)/100;
    setha=round(100*setha)/100;
    if(Sum>setha){
        flag=1;
        printf("flag:%d",flag);
    }
    else {
        flag=0;
        printf("flag is %d",flag);
    }
}





void read_file_and_find_y(){
    FILE *fp2= fopen("result.txt", "w");//없으면 만듦
    FILE *fp = fopen("data.txt", "r");    // hello.txt 파일을 읽기 모드(r)로 열기. 
    struct data data;
    if(fp == NULL){
        printf("file open failed\n");
    }
    else{
        printf("file open success (for read)\n");
        while(!((fscanf(fp, "%lf %lf",&data.x1,&data.x2))==EOF)){
        perceptron(data.x1,data.x2, w1, w2,setha);                                                                                                                                                                                                                                                                                          
        if(flag==1){                                                                                                                                
            fprintf(fp2," %d\n",flag);
        }
        else{
            fprintf(fp2," %d\n",flag);
        }
        }
        fclose(fp);
        fclose(fp2);
    }                                
    
}

int main (){
    input_data_on_text_and_file_open();
  
    input_w1_w1_setha();
    
    read_file_and_find_y();
      
}







