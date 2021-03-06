from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np

f_w1w2=open("w1w2.txt",'r')
f_err=open("err.txt",'r')
x1=[]
x2=[]
err=[]
xmin,xmax,ymin,ymax,zmin,zmax = -20, 20, -20, 20, -20,20
cmin,cmax=0,0
fig = plt.figure(figsize=(6, 6))
ax = fig.add_subplot(111, projection='3d')

while True:
    line = f_w1w2.readline()
    if not line: break
    haha=line.split()
    x1.append([float(haha[0])])
    x2.append([float(haha[1])])
    

while True:
    line = f_err.readline()
    if not line: break
    err.append([float(line)])
for number in range(len(err)):  
    if err[number][0]==0.0:    
        print(err[number][0])
        ax.scatter(x1[number][0],x2[number][0],err[number][0], c="red", marker='o', s=15, cmap='Greens')       
    else:
        ax.scatter(x1[number][0],x2[number][0],err[number][0], c="black", marker='o', s=15, cmap='Greens')     

plt.show() 
f_w1w2.close()
f_err.close()
