import matplotlib.pyplot as plt
from math import cos, sin, radians

def main () :
    
    points = points_innit()
    fig, graphic, lines = graphic_xz_innit(points)
    
    while(1) :
        prompt = input("Input angle-of-attack in degrees. Enter 'q' to quit: ") 
        if prompt == 'q': 
            plt.close(fig)
            break
        
        elif float(prompt) >= -360.0 and float(prompt) <= 360.0 : 
            rotation(points,float(prompt)) 
            graphic_update (lines, fig, points) 
            
    print (0)


def points_innit() :
    
    p0 = [0,0,0]
    p1 = [0,0,1]
    p2 = [0,0,2.5]
    p3 = [1.5,0,1]
    p4 = [4,0,1]
    p5 = [4,0,0]
    p6 = [6,0,0]
    p7 = [0.75,0,2.5]
    
    return ([p0,p1,p2,p3,p4,p5,p6,p7])


def graphic_xz_innit (points) : 
    
    plt.ion() 
    fig, graphic = plt.subplots(nrows=1, ncols=1, figsize = (10,5))

    graphic.set_xlim(-7, 10)
    graphic.set_ylim(-7, 7)
    graphic.set_xticks([])
    graphic.set_yticks([]) 
    graphic.set_xlabel("iv")
    graphic.set_ylabel("kv")
    clr = 'r'
    
    lines = graphic.plot([points[0][0],points[1][0]],[points[0][2],points[1][2]], clr,
                 [points[0][0],points[5][0]],[points[0][2],points[5][2]], clr,
                 [points[5][0],points[6][0]],[points[5][2],points[6][2]], clr,
                 [points[4][0],points[6][0]],[points[4][2],points[6][2]], clr, 
                 [points[4][0],points[5][0]],[points[4][2],points[5][2]], clr,
                 [points[3][0],points[4][0]],[points[3][2],points[4][2]], clr, 
                 [points[1][0],points[3][0]],[points[1][2],points[3][2]], clr,
                 [points[1][0],points[2][0]],[points[1][2],points[2][2]], clr,
                 [points[2][0],points[7][0]],[points[2][2],points[7][2]], clr,
                 [points[7][0],points[3][0]],[points[7][2],points[3][2]], clr)
    
    plt.show()
    
    return fig, graphic, lines



def rotation (points,phi) : 

    phi = -1*radians(phi) 
    for pi in points : 

        px = pi[0]
        py = pi[1]
        pz = pi[2]
        
        pi[0] = px*cos(phi)+pz*sin(phi)
        pi[1] = py
        pi[2] = pz*cos(phi)-px*sin(phi)
        



def graphic_update (lines, fig, points) : 

    lines[0].set_data([points[0][0],points[1][0]],[points[0][2],points[1][2]])
    lines[1].set_data([points[0][0],points[5][0]],[points[0][2],points[5][2]])
    lines[2].set_data([points[5][0],points[6][0]],[points[5][2],points[6][2]])
    lines[3].set_data([points[4][0],points[6][0]],[points[4][2],points[6][2]])
    lines[4].set_data([points[4][0],points[5][0]],[points[4][2],points[5][2]])
    lines[5].set_data([points[3][0],points[4][0]],[points[3][2],points[4][2]])
    lines[6].set_data([points[1][0],points[3][0]],[points[1][2],points[3][2]])
    lines[7].set_data([points[1][0],points[2][0]],[points[1][2],points[2][2]])
    lines[8].set_data([points[2][0],points[7][0]],[points[2][2],points[7][2]])
    lines[9].set_data([points[7][0],points[3][0]],[points[7][2],points[3][2]])

    fig.canvas.draw_idle() 

    


if __name__ == "__main__" :
    main()
    
