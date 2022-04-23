#include <stdio.h>
#include <math.h>
#define neuron_num 2
#define eta 0.4

double w1_input[3] = { -0.5, -0.4, -0.3, };
double w2_input[3] = { -0.5, -0.4, -0.3, };
double w_output[3] =  { -0.5, -0.4, -0.3, };
double w_bias[3] = { -0.5, -0.4, -0.3, };
int bias=0;
double U[3] = {0,0,0};
double delta[3] = {0,0,0};

double err = 0;

void FeedForward(double x1,double x2){
    	double S = 0, S_output = 0; 
	for (int i = 0; i <neuron_num; i++) {
		S = x1* w1_input[i] + x2 * w2_input[i];
		if(bias == 1) S += w_bias[i];
		U[i] = 1 / (1 + exp(-S));
		S_output += U[i] * w_output[i];
	}
	if (bias == 1) S_output += w_bias[neuron_num];
	U[neuron_num] = 1 / (1 + exp(-S_output));
	
	
}

void FeedBckward(double x1, double x2, double target){
    delta[neuron_num] = (target-U[neuron_num])*U[neuron_num]*(1-U[neuron_num]);
	for (int i = neuron_num- 1; i >= 0; i--) {
		delta[i] = U[i] * (1 - U[i]) * delta[neuron_num] * w_output[i];
	}
	for (int i = 0; i < neuron_num; i++) {
		w_output[i] = w_output[i] + eta * delta[neuron_num] * U[i];
		w1_input[i] = w1_input[i] + eta * delta[i] * x1;
		w2_input[i] = w2_input[i] + eta * delta[i] * x2;
		w_bias[i] = w_bias[i] + eta * delta[i];
	}
	w_bias[neuron_num] += eta * delta[neuron_num];
}

void Error_back_propagation(double x1, double x2, double target) {
    FeedForward(x1,x2);
	FeedBckward(x1,x2,target);
}


void show(){
for(int i = 0; i < neuron_num; i++){
		printf("W%d<-%d : %lf\n", i + 3, 0, w_bias[i]);
		printf("W%d<-%d : %lf\n", i + 3, 1, w1_input[i]);
		printf("W%d<-%d : %lf\n", i + 3, 2, w2_input[i]);;
	}

	//위의 중간 layer 로 들어오는 w 값을 출력한 이후에 output 쪽에 연결된 w 값을 출력한다.
	for (int i = 0; i <neuron_num; i++) {
		printf("W%d<-%d : %lf\n", neuron_num + 3, i + 3, w_output[i]);
	}
};

void ChooseMode(){
    printf("choose mode 1:with bias 2:without bias\n");
    scanf("%d",&bias);
    printf("bias:%d",bias);
}

int main() {
	double x1 = 0, x2 = 0, t = 0;
    ChooseMode();
    Error_back_propagation(1.0,1.0,1.0);
    show();
	return 0;
}
