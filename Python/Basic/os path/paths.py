import os

# print(os.path)

# if (os.path.exists("hello.txx")):
#     os.mkdir("hello.txt")
    
    
for i in range(101, 200):
    os.mkdir(f"folder {i+1}.txt")

# print("The cround working directru is = " ,os.getcwd())

for i in range(0, 10):
    os.rename(f"file {i+1}" , f"filesss {i+1}.txt")


# folder = os.listdir("D:\study\own study\Python\Basic\os path")
# print(folder)

# for i in folder:
#     os.remove(i)