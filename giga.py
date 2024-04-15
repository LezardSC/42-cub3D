width = 800
height = 40

file = open("gigatesteur.cub", "w")

file .write("NO textures/wall_north.xpm\nSO textures/wall_south.xpm\nWE textures/wall_west.xpm\nEA textures/wall_east.xpm\n\nF 255,255,255\nC 0,255,0\n\n")

i = 0

while i < height:
    j = 0
    while j < width:
        if i == 0 or i == height - 1 or j == 0 or j == width - 1:
            file.write("1")
        else:
            file.write("0")
        j+=1
    file.write("\n")
    i+=1