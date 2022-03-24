# machine-learning

.float vs double->double을 좀더 정확한 계산이 필요할 떄 사용!!

.파일은 공간복잡도에 포함되는가?
파일은 스트림을 통해 데이터를 통하고 이는 운영체제가 해줌(파일과 다리가 놓아졌다고 생각하자),마우스나 키보드와 같은 io장치라고 생각해도 됨

.부동 소수점 에러:
https://www.youtube.com/watch?v=vOO-oLS0H68

https://www.acmicpc.net/blog/view/3


.선언을 안했는데 데이터가 할당되는 경우가 있음

```c
#include<stdio.h>
int arr[3]={1,1,1,1};
int main(){
arr[4]=1;
printf("%d",arr[4]);

}

```
