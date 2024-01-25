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

    

if __name__ == "__main__":

    fig = plt.figure()
    
    os.system("grep 'node=0' CASSINI-And-Moons-ns-3-Mobility-Trace.mob > temp")
    data = read_file("temp")
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
    ax  = fig.add_subplot(111, projection='3d')
    ax.plot(X, Y, Z, 'green',label='CASSINI')

  
    os.system("grep 'node=1' CASSINI-And-Moons-ns-3-Mobility-Trace.mob > temp")
    data = read_file("temp")
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
    ax.plot(X, Y, Z, 'blue',label='Titan')
    
    
    os.system("grep 'node=2' CASSINI-And-Moons-ns-3-Mobility-Trace.mob > temp")
    data = read_file("temp")
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
    ax.plot(X, Y, Z, 'red',label='Rhea')

    
    
    
    os.system("grep 'node=3' CASSINI-And-Moons-ns-3-Mobility-Trace.mob > temp")
    data = read_file("temp")
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
    ax.plot(X, Y, Z, 'brown',label='Iapetus')


    
    os.system("grep 'node=4' CASSINI-And-Moons-ns-3-Mobility-Trace.mob > temp")
    data = read_file("temp")
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
    ax.plot(X, Y, Z, 'black',label='Dione') 





    #plt.title('Visualizing ns-3 Mobility Traces of CASSINI and Moons of Saturn', fontsize=16)
    plt.title('ns-3 Mobility Traces of CASSINI and Moons of Saturn w.r.t Earth', fontsize=16)
    plt.suptitle('J2000 Reference Frame - Duration : Jun 20, 2004 to Dec 1, 2005', fontsize=12)

    plt.legend(loc='lower left',bbox_to_anchor=(-0.4,0), fontsize='large', title='Spacecrafts and Moons')

    plt.show()



    #plotgif2(X, Y, Z)
