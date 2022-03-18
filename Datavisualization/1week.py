import matplotlib.pyplot as plt
import numpy as np


f = open("data.txt",'r')
w1=float(input())
w2=float(input())
setha=float(input())
#y = w1/w2*x+setha
print(w1)
x1=[]
x2=[]
y=[]

plt.xlabel('X1-Axis')
plt.ylabel('X2-Axis')

plt.grid(True)
while True:
    line = f.readline()
    if not line: break
    haha=line.split()
    x1.append(haha[0])
    x2.append(haha[1])
    

for i in x1:
    y.append(w1/w2*float(i)+setha/w2)   
    
print(y)    
plt.scatter(x1,x2)
plt.plot(x1,y);
plt.show()
f.close()
