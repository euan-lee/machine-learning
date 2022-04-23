#include <stdio.h>
#include <math.h>

double w1_input[3] = { -0.5, -0.4, -0.3 };
double w2_input[3] = { -0.5, -0.4, -0.3};
double w_output[3] = { -0.5, -0.4, -0.3};
double w_bias[3] = { -0.5, -0.4, -0.3};
double eta=0.4;
int w_range=2;

double U[3] = { 0, 0, 0};
double delta[3] = { 0, 0, 0 };


void Feedforward(double x1, double x2, double target){

    double S = 0, s_total = 0; 

	for (int i = 0; i < w_range; i++) {
		S = x1* w1_input[i] + x2 * w2_input[i]+w_bias[i];


		
		U[i] = 1 / (1 + exp(-S));


		s_total += U[i] * w_output[i];
	}

	s_total+= w_bias[w_range];

	U[w_range]=1/(1+exp(-s_total));
	
}

void Feedbackward(double x1, double x2, double target){
	delta[w_range]=(target-U[w_range])*U[w_range]*(1-U[w_range]);

	for (int i=w_range-1;i>=0;i--) {
		delta[i]=U[i]*(1-U[i])*delta[w_range]*w_output[i];
	}

	for (int i = 0; i < w_range; i++) {
		w_output[i]=w_output[i]+eta*delta[w_range] * U[i];
		w1_input[i]=w1_input[i]+eta*delta[i]*x1;
		w2_input[i]=w2_input[i]+eta*delta[i]*x2;
		w_bias[i]=w_bias[i]+eta*delta[i];
	}
	
	w_bias[w_range]+=eta*delta[w_range];
}

void show(){
    for(int i = 0; i < w_range; i++){
		printf("W%d%d : %lf\n", i + 3, 0, w_bias[i]);
		printf("W%d%d : %lf\n", i + 3, 1, w1_input[i]);
		printf("W%d%d : %lf\n", i + 3, 2, w2_input[i]);;
	}
	for (int i = 0; i < w_range; i++) {
		printf("W%d,%d : %lf\n", w_range + 3, i + 3, w_output[i]);
	}
}

void Error_back_propagation(double x1, double x2, double t) {
	Feedforward( x1,x2, t);
  Feedbackward( x1,x2, t);
}

int main() {
    Error_back_propagation(1.0,1.0 ,1.0);
    show();
	return 0;
}
