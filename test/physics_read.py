import numpy as np 
import os 
import matplotlib.pyplot as plt 

DATATYPE = np.float64
PATH_VEL_TRUE = "velocity_true.dat" 
PATH_VEL_ODE = "velocity_ode.dat" 
PATH_POS_TRUE = "position_true.dat" 
PATH_POS_ODE = "position_ode.dat" 
FILENAME = "test_logs"
TIME_INC = 1.0/60.0 #see physics_test.c


def main () : 

    velocity_true = read_test (PATH_VEL_TRUE) 
    velocity_ode = read_test (PATH_VEL_ODE) 
    position_true = read_test (PATH_POS_TRUE) 
    #position_ode = read_test (PATH_POS_ODE) 

    time = np.arange(0, len(velocity_true)) * TIME_INC

    velocity_error = max_err (velocity_true, velocity_ode) 
    #position_error = max_err (position_true, position_ode)

    fig, ax = plt.subplots (nrows = 1, ncols = 2, figsize = (10,4)) 

    ax[0].plot (time, velocity_true, label = "True")
    ax[0].plot (time, velocity_ode, label = "Approximation")  
    ax[0].set_ylabel ("Velocity Y (m/s)")
    ax[0].set_xlabel ("Time (s)")
    ax[0].legend (loc = 4)

    ax[1].plot (time, position_true, label = "True")
    #ax[1].plot (time, velocity_ode, label = "Approximation")  
    ax[1].set_ylabel ("Position Y (m)")
    ax[1].set_xlabel ("Time (s)") 
    ax[1].legend (loc = 4)
    
    plt.show ()

    #should add something to calulate max error of approxiamtion from true

    return 0


def read_test (test_file):
     
    script_dir = os.path.dirname (os.path.abspath(__file__))
    file_dir = os.path.join (script_dir, FILENAME)
    path = os.path.join (file_dir, test_file)
    data = np.fromfile (path, dtype = DATATYPE, count = -1)

    return data 

def max_err (true_data, ode_data):
    
    per_err = 0 
    
    for i in range (0, len(true_data) ): 
        
        if true_data[i] != 0 :
            err_i = abs (true_data[i] - ode_data[i]) / true_data[i] * 100
        
            if err_i > per_err: 
                per_err = err_i 

    return per_err


if __name__ == "__main__" : 
    main ()