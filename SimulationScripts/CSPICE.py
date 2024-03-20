import os
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

if __name__ == "__main__":
    spDict = {
        "node=0": {"name": "MERCURY", "color": "green"},
        "node=1": {"name": "VENUS", "color": "blue"},
        "node=2": {"name": "EARTH", "color": "brown"},
        "node=3": {"name": "MARS", "color": "orange"},
        "node=4": {"name": "JUPITER", "color": "black"}
    }
    
    # Create a single figure and subplot outside the loop
    fig = plt.figure() 
    ax = fig.add_subplot(111, projection='3d')

    for node, attributes in spDict.items():
        # Read data directly from the file
        with open("SPICE-ns-3-Mobility-Trace.mob") as file:
            data = file.readlines()

        X = []
        Y = []
        Z = []

        # Extract XYZ coordinates from each line of data
        for line in data:
            if node in line:
                pos_start = line.index("pos=") + 4
                pos_end = line.index("vel=") - 1
                XYZ_list = line[pos_start:pos_end].split(":")
                X.append(float(XYZ_list[0]))
                Y.append(float(XYZ_list[1]))
                Z.append(float(XYZ_list[2]))

        # Plot XYZ coordinates for the current node
        ax.plot(X, Y, Z, color=attributes['color'], label=attributes['name'])

    # Move legend, title, and supertitle outside the loop to avoid duplication
    plt.legend(loc='lower left', bbox_to_anchor=(-0.4, -0.1), fontsize='small', title='Spacecrafts')
    plt.title('Visualizing SPICE-ns-3 Mobility Traces of Planets', fontsize=16)
    plt.suptitle('J2000 Reference Frame - Duration : June 06, 1998 to Dec 12, 1999', fontsize=12)

    plt.show()
