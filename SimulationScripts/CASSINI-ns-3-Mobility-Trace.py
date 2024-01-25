###############################################################################
# The Python Script developed for the Research work on
#
#     Design and Implementation of Novel Protocols for Deep Space Network 
#            Using SPICE Toolkit and Kernels Under ns-3
# 
# Developed by :           Jason Pandian,(pandiajason@gmail.com)
#                          Assistant Professor, Department of Computer Science and Engineering,
#                          Tamilnadu College of Engineering, Coimbatore.
#                          Affiliated to Anna University, Chennai,
#                          India.
# 
# 
# Declaration"
# This project uses binary version of NASA/NAIF's SPICE tool kit and
# Some of the Text and Binary version of SPICE Kernels/Data
###############################################################################
#!/bin/python
import os
import sys
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def read_file(file_path):
    with open(file_path) as f:
        data = f.readlines()
    f.close()
    return data

def plotfig(X, Y, Z):
    fig = plt.figure()
    #ax = Axes3D(fig)
    #ax.scatter3D(X, Y, Z, cmap='blue')
    ax  = fig.add_subplot(111, projection='3d')
    ax.plot(X, Y, Z)
    #ax.plot3D(X, Y, Z, 'green')
   # print(X)
    plt.legend(loc='upper left',  bbox_to_anchor=(-0.1, 1), fontsize='small', title='CASSINI Spacecraft')
    plt.title('Visualizing ns-3 Mobility Traces of CASSINI around Saturn', fontsize=16)
    #plt.title('Visualizing ns-3 Mobility Traces of CASSINI with respect to Earth', fontsize=16)
    plt.suptitle('J2000 Reference Frame - Duration : Jun 20, 2004 to Dec 1, 2005', fontsize=12)   
    plt.show()

    


def plotgif(X, Y, Z):
    fig = plt.figure()
    #ax = Axes3D(fig)
    plt.ion()

    ax  = fig.add_subplot(111, projection='3d')
    #ax.set_xlim(-250,250)
    #ax.set_ylim(-250,250)
    #ax.set_zlim(-250,250)    
    plt.legend(loc='upper left', bbox_to_anchor=(-0.1, 1), fontsize='small', title='CASSINI Spacecraft')
    plt.title('Visualizing ns-3 Mobility Traces of CASSINI around Saturn', fontsize=16)
    plt.suptitle('J2000 Reference Frame - Duration : Jun 20, 2004 to Dec 1, 2005', fontsize=12)    
    for i in range(0, len(X)):
        #ax.scatter3D(X[i], Y[i], Z[i], cmap='blue')
        ax.plot3D(X[:i], Y[:i], Z[:i], 'green')
        #ax.plot(X[i], Y[i], Z[i])
        plt.pause(0.1)

    	
    plt.show()
    


if __name__ == "__main__":

    data = read_file(sys.argv[1])
    X = []
    Y = []
    Z = []

    for i in range(len(data)):
        str = data[i]
        s = str.index("pos=") + 4
        e = str.index("vel=") - 1
        XYZ_list = str[s:e].split(":")
        X.append(float(XYZ_list[0]))
        Y.append(float(XYZ_list[1]))
        Z.append(float(XYZ_list[2]))

    X = np.asarray(X)
    Y = np.asarray(Y)
    Z = np.asarray(Z)

    if sys.argv[2] == 'gif':
        plotgif(X, Y, Z)
    else:
        plotfig(X, Y, Z)




