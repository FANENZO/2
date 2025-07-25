import numpy as np
import pandas as pd
import matplotlib.pyplot as mat
a = []

stu = int(input("輸入有幾位學生: "))

for i in range(stu):
    score = int(input(f"輸入第 {i + 1} 位分數: "))
    a.append(score)

df = pd.DataFrame(a, columns=["Scores"])

num = np.array(a)

print("平均分數:", np.mean(num))
print("最高分:", df["Scores"].max())
mat.bar(df.count, df["Scores"])
mat.xlabel('score')
mat.ylabel('number')
mat.title('student score')
mat.show()
