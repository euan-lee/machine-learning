#include <stdio.h>
#include <math.h>
#define eta 0.9

int neuron_num=0;
int epoch=0;
double delta[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
double w1_input_val[10] = {-0.5,-0.4,-0.3,-0.2,-0.1,0.0,0.1,0.2,0.3,0.4 };//w1_input_val[i]과  w2_input_val[i]은 
double w2_input_val[10] = {-0.5,-0.4,-0.3,-0.2,-0.1,0.0,0.1,0.2,0.3,0.4 };//한개의 neuron의 가중치이다.
double w_output_val[10] = {-0.5,-0.4,-0.3,-0.2,-0.1,0.0,0.1,0.2,0.3,0.4 };
double u[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void FeedForward(double x1,double x2,double target){
	double s_total=0;

	for(int i=0;i<neuron_num;i++){
		double s=x1*w1_input_val[i]+x2*w2_input_val[i];//뉴런에 입력과 w1,w2를 곱합
		u[i] = 1 / (1 + exp(-s));//sigmoid함수에 넣어줌
		s_total=u[i]*w_output_val[i];
	}

	u[neuron_num] = 1 / (1 + exp(-s_total));//세번째 뉴런(마지막 뉴런)
	
}

void FeedBackword(double x1,double x2,double target){
	delta[neuron_num] = (target-u[neuron_num])*u[neuron_num]*(1-u[neuron_num]);//마지막 뉴런의 델타 값
	
	for (int i = neuron_num-1; i >= 0; i--) {//마지막 아닌 뉴런의 델타 값
		delta[i] =u[i]*(1-u[i])*delta[neuron_num]*w_output_val[i];
	}

	for (int i=0;i<neuron_num; i++) {
		w_output_val[i]=w_output_val[i]+eta*delta[neuron_num]*u[i];
		w1_input_val[i]=w1_input_val[i]+eta*delta[i]*x1;
		w2_input_val[i]=w2_input_val[i]+eta*delta[i]*x2;
	}

}

void Error_back_propagation(double x1,double x2,double target){
	FeedForward(x1,x2,target);
	FeedBackword(x1,x2,target);
}

int main() {

	scanf("%d",&neuron_num);
	scanf("%d",&epoch);
	printf("epoch:%d neuron-number:%d \n",epoch,neuron_num);
	for(int i=0;i<epoch;i++){
		Error_back_propagation(1.0,1.0 ,1.0);
	}
}
