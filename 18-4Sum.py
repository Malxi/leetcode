nums = [-3,-2,-1,0,0,1,2,3]
target = 0

def fourSum(nums, target):
    nums.sort()
    N = len(nums)
    nums_4sum = []
    nums_set = set(nums)
    nums_dic = {}
    res_set = set([])
    res = []
    nums_sets = []
    res_dic = {}

    if  N < 4:
        return []

    for i in range(0, N):
        nums_sets.append(set(nums[i:]))

    st = N - 1
    ed = 0
    for i in range(0, N - 3):
        min = sum(nums[i: i + 4])
        max = nums[i] + nums[N-1] + nums[N-2] + nums[N-3]
        if target >= min and target <= max:
            if st > i:
                st = i
            if ed < i:
                ed = i
    if st > ed:
        return []

    '''
    for i in range(st, ed + 1):
        a = nums[i]
        for j in range(i + 1, N - 2):
            b = nums[j]
            for k in range(j + 1, N - 1):
                c = nums[k]
                d = target - a - b - c
                #print(a, b, c, d)
                if d in nums_sets[k + 1]:
                    res_set.add(str([a, b, c, d]))
                    #res_dic[str([a, b, c, d])] = [a, b, c, d]
    '''
    
    for i in range(st, ed + 1):
        a = nums[i]
        for j in range(i + 1, N - 2):
            b = nums[j]
            cd = target - a - b
            low = j + 1
            high = N - 1
            while low < high:
                c = nums[low]
                d = nums[high]
                if c + d == cd:
                    res_set.add(str([a, b, c, d]))
                    low += 1
                    high -= 1
                elif c + d < cd:
                    low += 1
                else:
                    high -= 1
            if low < high:
                res_set.add(str([a, b, c, d]))
    
    for i in res_set:
        res.append(eval(i))

    return res

print(fourSum(nums, target))  
