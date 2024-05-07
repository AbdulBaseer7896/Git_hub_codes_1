import pandas as pd
import matplotlib.pyplot as plt

# Series
a = [1,3,5]
b = pd.Series(a, index= [1,2,3])
print(b)

# series  Dictionary

c = {"Name": "Baseer", "Fname":"Qazi"}
d = pd.Series(c)
print(d)

# Data Frame

data = {
    'Car   :':["honda", "city", "BMQ"],
    "Model :":[3,4,6]
}
df = pd.DataFrame(data)
print(df)

# print(pd.options.display.max_rows)

print(df.info)

print(df["Model :"].fillna("Hellooo", inplace=True))
print("this i", df)

df.plot()
plt.show()