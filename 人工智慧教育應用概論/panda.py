import pandas as pd 
data= {
    "day": ["周一", "周二", "周三", "周四", "周五", "周六", "周日"],
    "money":[50,60,70,60,80,50,60]
 }

df = pd.DataFrame(data)

print(df)

save = df["money"].sum()

print(save)

# max = df["money"].idxmax(),"day"
print(df.loc[df["money"].idxmax(), "day"] )