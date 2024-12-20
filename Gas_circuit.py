

# # # gas =  [1,2,3,4,5]
# # # cost = [3,4,5,1,2]
# # # i=0
# # # for i in range(( i % (len(gas)-1)),len(gas)):
# # #     sum=gas[i]
# # #     move= False
# # #     count=0
# # #     for j in range(i+1,len(gas)):
# # #         if j==i:
# # #             print(i)            
# # #             break 
# # #         if sum>=cost[j-1]:
# # #             sum= sum - cost[j-1] + gas[j]
# # #             move=True
# # #         else:
# # #             move=False
# # #             break
    
# # #     count+=1
    
# # #     if(count==len(gas)):
# # #         break
            
            
        
        


# # def can_complete_circuit(gas, cost):
# #     n = len(gas)
# #     for start in range(n):
# #         tank = 0
# #         possible = True
# #         for i in range(n):
# #             station = (start + i) % n
# #             tank += gas[station] - cost[station]
# #             if tank < 0:
# #                 possible = False
# #                 break
# #         if possible:
# #             return start
# #     return -1

# # gas = [1, 2, 3, 4, 5]
# # cost = [3, 4, 5, 1, 2]
# # print(can_complete_circuit(gas, cost))
# gas = [1, 2, 3, 4, 5]
# cost = [3, 4, 5, 1, 2]
# start = -1  # Initialize start index to -1
# for i in range(len(gas)):
#     tank = 0  # Initialize tank at each station
#     move = False
#     count = 0  # Initialize count to track how many stations have been visited
#     for j in range(i, i + len(gas)):  # Loop through all stations in a circular manner
#         station = j % len(gas)  # Calculate the actual station index in a circular manner
#         tank += gas[station] - cost[station]  # Refuel at the current station and consume gas to move to the next
#         if tank >= 0:  # If there's enough gas to move to the next station
#             move = True
#         else:  # If not enough gas
#             move = False
#             break
#         count += 1  # Increment count for each visited station
#     if move and count == len(gas):  # If able to complete the circuit and all stations visited
#         start = i  # Set the start index to the current index
#         break

# print(start)


gas = [1, 2, 3, 4, 5]
cost = [3, 4, 5, 1, 2]
start = -1  
n = len(gas)
for i in range(n):
    tank = 0 
    move = False
    count = 0  
    for j in range((i % (n-1))+1, n):  
        station = j % n  
        tank += gas[j-1] - cost[j-1]  
        if tank >= 0: 
            move = True
        else: 
            move = False
            break
        count += 1 
    if move and count == n:  
        start = i  
        break

print(start)
