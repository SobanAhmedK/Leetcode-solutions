# Imagine there is a circle of red and blue tiles. The color of the tiles is represented by the array tileColors,
# where tileColors[i] = 0 means that the ith tile is red, whereas tileColors[i] = 1 means that the ith tile is blue.
# We want to determine whether the tiles that are next to each other in the circle have alternating colors - 
# the ith tile should have a different color than both the (i+1)th and the (i-1)th neighboring tiles. Given an 
# integer size, we want to know how many groups of size consecutive tiles have alternating colors. Note that because 
# tileColors represents a circle, the first and last tiles (elements in the array) are considered to be next to each 
# other. Also note that you are not expected to provide the most optimal solution, but a solution with time 
# complexity not worse than O(tileColors.length²) will fit within the execution time limit.
# Example: • For tileColors = [0, 1, 0, 1, 1] and size = 3, the output should be solution(tileColors, size) = 3.


tiles= [0, 1, 0, 1, 1,3,34,4,5,5]
size=3
count=0
current=0%len(tiles)
next=(current+1)%len(tiles)
for tile in range(len(tiles)):
        different=False
        for i in range(size-1):
            if(tiles[current]!=tiles[next]):
                different=True
                current=(current+1)%len(tiles)
                next=(next+1)%len(tiles)
            else:
                different=False
                current=(current+1)%len(tiles)
                next=(next+1)%len(tiles)
                break
        if(different):
            count=count+1
       

print(count)
        
            
            
                
                
