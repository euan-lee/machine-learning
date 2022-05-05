#include <stdio.h>
#include <math.h>
#define eta 0.4
#define epoch 1

int neuron_num=0;
double sum=0;

double first_weight[2][10]={
    {-0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4 },//x1(0)->neuron
    {-0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4 }//x2(1)->neuron
};

double second_weight[10][1]={{-0.5},{-0.5},{-0.5},{-0.5},{-0.5},{-0.5},{-0.5},{-0.5},{-0.5},{-0.5}};    

double input__layer_bias_weight[10]={-0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4};

double first__layer_bias_weight=0.5;

double U[2][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};

int bias_mode=0;

double delta[2][10]={{0,},{0,}};//[layer][neuron_number]

void ChooseMode(){
    printf("choose mode 1:with bias 2:without bias\n");
    scanf("%d",&bias_mode);
    if(bias_mode==1){
        printf("with bias\n");
    }else{
        printf("without bias\n");
    }
       
}

void ChooseNeuron(){
    printf("choose the number of neuron\n");
    scanf("%d",&neuron_num);
    printf("neuron_num:%d\n",neuron_num);
}

double Sigmoid(double sum){
    double result=0;
    result=1/(1 + exp(-sum));
      return result;
}

void FeedForward(double x1,double x2,double target){
      //1st hidden layer 순회

        for(int i=0;i<neuron_num;i++){
            printf("------first layer u[0][%d]------\n",i);
            printf("first_weight[0][%d]:%lf\n",i, first_weight[0][i]);   
            printf("first_weight[1][%d]%lf\n",i, first_weight[1][i]);  
            printf("input__layer_bias_weight[%d]%lf\n",i,input__layer_bias_weight[i]);  
            sum=x1*+first_weight[0][i]+x2*first_weight[1][i];  
            if(bias_mode==1){
                sum=sum+1*input__layer_bias_weight[i];
            }
            printf("sum:%lf\n",sum);
            U[0][i]=Sigmoid(sum);
            printf("u[0][%d] is %lf\n",i,U[0][i]);
        }
            //last layer
        sum=0;
        for(int j=0;j<neuron_num;j++){
            printf("------result  u[1][0]------\n");
            printf("U[0][%d]:%lf\n",j,U[0][j]);
            printf("second_weight[%d][0]%lf\n",j,second_weight[j][0]);
            printf("U[0][%d]*second_weight[%d][0]:%lf\n",j,j,U[0][j]*second_weight[j][0]);
            sum=sum+U[0][j]*second_weight[j][0];
        }
        if(bias_mode==1){
            sum=sum+1*first__layer_bias_weight;
        }
            printf("sum:%lf\n",sum);
            U[1][0]=Sigmoid(sum);
            printf("result:U[1][0]:%lf\n",U[1][0]);
            printf("-----feedforward end!-------------\n");
    }
  
void FeedBackward(double x1,double x2,double target){
  printf("-------------feed backward---------------\n");
  
    //last delta(find delta)-ok
    delta[1][0]=(target-U[1][0])*U[1][0]*(1-U[1][0]);
    printf("updated delta[1][0]:%lf\n",delta[1][0]);

    //1-layer
    for(int j=0;j<neuron_num;j++){
        delta[0][j]=U[0][j]*(1-U[0][j])*second_weight[j][0]*delta[1][0];
        printf("updated delta[0][%d]:%lf\n",j,delta[0][j]);
    }

    //update second_weight
    for(int i=0;i<neuron_num;i++){
            second_weight[i][0]= second_weight[i][0]+eta*delta[1][0]*U[0][i];
            printf("updated second_weight[%d][0]:%lf\n",i,second_weight[i][0]);
    }

    if(bias_mode==1){
        first__layer_bias_weight=first__layer_bias_weight+eta*delta[1][0]*1;
    }

    for(int i=0;i<neuron_num;i++){
        first_weight[0][i]=first_weight[0][i]+eta*delta[0][i];
        first_weight[1][i]=first_weight[1][i]+eta*delta[0][i];
        printf(" first_weight[0][%d]:%lf\n",i,first_weight[0][i]);
        printf(" first_weight[1][%d]:%lf\n",i,first_weight[1][i]);
    }

    if(bias_mode==1){
        for(int i=0;i<neuron_num;i++){
            input__layer_bias_weight[i]=input__layer_bias_weight[i]+eta*delta[0][i]*1;
            printf(" input__layer_bias_weight[%d]:%lf\n",i,input__layer_bias_weight[i]);
        }
    }
}
  


double Error_back_propagation(double x1, double x2, double target) {
    FeedForward(x1,x2,target);
    FeedBackward(x1,x2,target);
}


int main(){
   double x1,x2,target=0;
   double error=0;
    ChooseMode();
    ChooseNeuron();
    FILE *fp = fopen("test.txt","r");    // hello.txt 파일을 읽기 모드로 열기.  
    if(fp == NULL){
        printf("file open failed\n");
    }
    FILE *fp2 = fopen("result.txt","w"); 
    //3.epoch값 만큼 반복-ok
    for(int i=0;i<epoch;i++){  
    error=0;
    while(!((fscanf(fp, "%lf %lf %lf \n",&x1,&x2,&target))==EOF)){
        printf("x1:%lf\n",x1);
        printf("x2:%lf\n",x2);
        printf("taret:%lf\n",target);
        Error_back_propagation(x1,x2,target);
        error=error+fabs(target-U[1][0]);
        
    }
    printf("error %lf\n",error);
    printf("epoch:%d\n",i);
    //error와 epoch값을 txt file에 쓴다.(주의 사항!!:error>0.5이면 1아니면 0으로 설정한다.)(변수 설정을 위에다가 해야할 듯??!!)

    fprintf(fp2, "%d %lf\n",i,error);
    //다시 3으로 이동(epoch++);
    }   
    fclose(fp);   
    fclose(fp2);   
}
