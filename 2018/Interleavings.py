All interleavings of given two strings

def interleave(a, b):
    result = [[]]
    for i in range(1, len(b) + 1):
        result.append([b[0:i]])    
    for i in range(len(a)):
            result[0] = [a[0:i + 1]]
    for j in range(1, len(b) + 1):
        print( result[j], result[j-1])
        first = []
        for s in result[j]:
            first.append(s + a[i])
        second = []
        for s in result[j - 1]:
            second.append(s + b[j - 1])
        result[j] = first + second
    return result[len(b)]

def interleave(a, b):
    if len(a) == 0 and len(b) == 0:
    	return []
    if len(a) == 0:
        return [b]
    if len(b) == 0:
        return [a]
    arr1 = [a[0] + s for s in interleave(a[1:], b)]
    arr2 = [b[0] + s for s in interleave(a, b[1:])]
    return arr1 + arr