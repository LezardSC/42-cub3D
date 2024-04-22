import random

width = 200
height = 150

file = open("maps/real_map.cub", "w")

file .write("NO textures/wall_north.xpm\nSO textures/wall_south.xpm\nWE textures/wall_west.xpm\nEA textures/wall_east.xpm\n\nF 119,207,238\nC 0,255,0\n\n")

i = 0
n = False

while i < height:
    j = 0
    while j < width:
        random_number = random.randint(1, 30)
        if i == 0 or i == height - 1 or j == 0 or j == width - 1:
            file.write("1")
        else:
            file.write("0")
        j+=1
    file.write("\n")
    i+=1
file.close()