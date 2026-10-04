import matplotlib.pyplot as plt
from math import cos, sin, radians
import matplotlib.image as img


def main () :
    
    points = points_innit()
    fig, graphic, lines = graphic_innit(points)
    
    while(1) :
        prompt = input("Input angle-of-attack in degrees. Enter 'q' to quit: ") 
        if prompt == 'q': 
            plt.close(fig)
            break
        
        elif float(prompt) >= -360.0 and float(prompt) <= 360.0 : 
            rotation(points,float(prompt)) 
            graphic_xz_update (lines, fig, points) 

            
    print (0)


def points_innit() :
    
    p0 = [0,0,0]
    p1 = [-2,0,0.5]
    p2 = [-2,0,2]
    p3 = [-0.5,0,0.5]
    p4 = [2,0,0.5]
    p5 = [2,0,-0.5]
    p6 = [4,0,-0.5]
    p7 = [-1.25,0,2]
    p8 = [-2,0,-0.5]
    
    return ([p0,p1,p2,p3,p4,p5,p6,p7,p8])


def graphic_innit (points) : 
    
    plt.ion() 
    fig, graphic = plt.subplots(nrows=1, ncols=1, figsize = (10,10))

    x_min = -7
    x_max = 10
    y_min = -6
    y_max = 6
    
    graphic.set_xlim(x_min, x_max)
    graphic.set_ylim(y_min, y_max)
    graphic.set_xticks([])
    graphic.set_yticks([]) 
    graphic.set_xlabel("i")
    graphic.set_ylabel("k")
    clr = 'r'
    clr_ax = 'b'
    
    lines = graphic.plot(
                 [points[8][0],points[5][0]],[points[8][2],points[5][2]], clr,
                 [points[5][0],points[6][0]],[points[5][2],points[6][2]], clr,
                 [points[4][0],points[6][0]],[points[4][2],points[6][2]], clr, 
                 [points[4][0],points[5][0]],[points[4][2],points[5][2]], clr,
                 [points[3][0],points[4][0]],[points[3][2],points[4][2]], clr, 
                 [points[1][0],points[3][0]],[points[1][2],points[3][2]], clr,
                 [points[1][0],points[2][0]],[points[1][2],points[2][2]], clr,
                 [points[2][0],points[7][0]],[points[2][2],points[7][2]], clr,
                 [points[7][0],points[3][0]],[points[7][2],points[3][2]], clr,
                 [points[8][0],points[1][0]],[points[8][2],points[1][2]], clr)

    graphic.plot([0,x_max-1], [0,0], clr_ax,
                 [0,0], [0,y_min+2], clr_ax)
    
    plt.show()
    
    return fig, graphic, lines



def rotation (points,phi) : 

    phi = radians(phi) 
    for pi in points : 

        px = pi[0]
        py = pi[1]
        pz = pi[2]
        
        pi[0] = px*cos(phi)-pz*sin(phi)
        pi[1] = py
        pi[2] = pz*cos(phi)+px*sin(phi)
        



def graphic_xz_update (lines, fig, points) : 

    lines[0].set_data([points[8][0],points[5][0]],[points[8][2],points[5][2]])
    lines[1].set_data([points[5][0],points[6][0]],[points[5][2],points[6][2]])
    lines[2].set_data([points[4][0],points[6][0]],[points[4][2],points[6][2]])
    lines[3].set_data([points[4][0],points[5][0]],[points[4][2],points[5][2]])
    lines[4].set_data([points[3][0],points[4][0]],[points[3][2],points[4][2]])
    lines[5].set_data([points[1][0],points[3][0]],[points[1][2],points[3][2]])
    lines[6].set_data([points[1][0],points[2][0]],[points[1][2],points[2][2]])
    lines[7].set_data([points[2][0],points[7][0]],[points[2][2],points[7][2]])
    lines[8].set_data([points[7][0],points[3][0]],[points[7][2],points[3][2]])
    lines[9].set_data([points[8][0],points[1][0]],[points[8][2],points[1][2]])

    fig.canvas.draw_idle() 

    


if __name__ == "__main__" :
    main()
    
