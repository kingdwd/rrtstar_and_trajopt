import numpy as np
import matplotlib
#matplotlib.use('Agg')
import matplotlib.pyplot as plt
import os

from math import pi, atan, cos, sin

# State is: [theta1, theta2, theta1_dot, theta2_dot]

def plot(states, obstacles, seconds, cost, length, id_num):
    print states
    
    plt.clf()
    plt.cla()

    fig = plt.figure(1)
    ax = fig.axes[0]
    ax.set_axis_bgcolor('white')
    ax.set_aspect('equal')

    # Plot obstacles
    if len(obstacles.shape) == 1: # If it is a 1D array, make it a 2D column array
        obstacles = np.transpose([obstacles])

    num_obstacles = obstacles.shape[1]

    for i in range(num_obstacles):
        x_center = obstacles[0,i]
        x_size = obstacles[1,i] 
        y_center = obstacles[2,i]
        y_size = obstacles[3,i]

        # Compute corners of obstacle region 
        # [x_min, x_min, x_max, x_max]
        x_min = x_center - .5*x_size; x_max = x_center + .5*x_size;
        x = [x_min, x_min, x_max, x_max]
        # [y_min, y_max, y_max, y_min]
        y_min = y_center - .5*y_size; y_max = y_center + .5*y_size;
        y = [y_min, y_max, y_max, y_min]

        ax.fill(x, y, 'r')
    
    # way to manually set axes
    #ax.axis([x_min, x_max, y_min, y_max])

    for i in range(0, states.shape[1]):

	l1x = length * cos(states[0,i] - pi/2)
	l1y = length * sin(states[0,i] - pi/2)

	l2x = l1x + length * cos(states[0,i] - pi/2 + states[1,i])
	l2y = l1y + length * sin(states[0,i] - pi/2 + states[1,i])

        # Plot the end looking thing
        plt.plot([l2x], [l2y], 'ko', markersize=5)
	plt.plot([0, l1x, l2x], [0, l1y, l2y], color=[float(i)/float(states.shape[1]), 0,float(states.shape[1]-i)/float(states.shape[1])],linewidth=2.0)

    plt.title('Cost: ' + str(cost))

    #plt.show(block=False)
    plt.pause(.1)
    
    # way to save the plot
    save('pics/{0}_seconds_{1}'.format(seconds, id_num), ext="png", close=False, verbose=False)
    
    # do pause in python so plot can be resized etc.
    """
    pause = True
    if (pause):
        print("Type 'save' to save this figure into a pdf file as 'pics/<number of seconds>_seconds.pdf'")
        print("Otherwise, press Enter to continue.")
        user_says = raw_input()
        if user_says.strip() == 'save':
            save('pics/{0}_seconds'.format(seconds), 'pdf')
    """

       
def save(path, ext='png', close=True, verbose=True):
    """Save a figure from pyplot.
     
    Parameters
    ----------
    path : string
    The path (and filename, without the extension) to save the
    figure to.
     
    ext : string (default='png')
    The file extension. This must be supported by the active
    matplotlib backend (see matplotlib.backends module). Most
    backends support 'png', 'pdf', 'ps', 'eps', and 'svg'.
     
    close : boolean (default=True)
    Whether to close the figure after saving. If you want to save
    the figure multiple times (e.g., to multiple formats), you
    should NOT close it in between saves or you will have to
    re-plot it.
     
    verbose : boolean (default=True)
    Whether to print information about when and where the image
    has been saved.
     
    """
    # Extract the directory and filename from the given path
    directory = os.path.split(path)[0]
    filename = "%s.%s" % (os.path.split(path)[1], ext)
    if directory == '':
        directory = '.'
     
    # If the directory does not exist, create it
    if not os.path.exists(directory):
        os.makedirs(directory)
     
    # The final path to save to
    savepath = os.path.join(directory, filename)
     
    if verbose:
        print("Saving figure to '%s'..." % savepath),
     
    # Actually save the figure
    plt.savefig(savepath)
    # Close it
    if close:
        plt.close()
     
    if verbose:
        print("Done")
    
