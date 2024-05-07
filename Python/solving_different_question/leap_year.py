def leap_year(year):
    print(year)
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        print("Its leap year")
    else:
        print("It is not")
        
    pass

leap_year(17)


