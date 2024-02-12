nums = [9, 1, -3, 2, 4, 8, 3, -1, 6, -2, -4, 7]

sorted_nums = sorted(nums, key=lambda x: (x >= 0, x))

print(sorted_nums)
