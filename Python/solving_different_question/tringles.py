def equilateral(sides):
    print(sides)
    if sides[0]>0 and sides[1] >0 and sides[2] >0:
        if (sides[0] == sides[1] == sides[2]) > 0 :
            return True
        else:
            return False
    else:
        return False
    pass

# print(equilateral([1,1,1]))



def isosceles(sides):
    for i in range(0 , len(sides)):
        for j in range(i+1 , len(sides)):
            print(i , j)
            if sides[i] == sides[j]:
                sum = sides[i] + sides[j] 
                print(sum)
                for i in range(0 , len(sides)):
                    if sum < sides[i]:
                        return False
                else:
                    return True
                
    return False
    
    pass



# print(isosceles([3, 4, 1]))





def scalene(sides):
    if sides[0]>0 and sides[1] >0 and sides[2] >0:
        check = True
        for i in range(0 , len(sides)):
            for j in range(i+1 , len(sides)):
                sum = sides[i] + sides[j]
                print(sum)
                for k in range(0 , len(sides)):
                    if sum < sides[k] or sides[i] == sides[j] :
                        return False

        return True
    else:
        return False
    pass


print(scalene([5, 4, 6]))


