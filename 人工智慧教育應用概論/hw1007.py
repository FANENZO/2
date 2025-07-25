import numpy as np
import pandas as pd
import matplotlib.pyplot as mat

stu = {
    "score": [10,55,60,77,10],
    "stu_num" : [1,2,3,4,5]
}

df = pd.DataFrame(stu)

num = np.array(stu["score"])  
stu_counts = df['score'].value_counts()

print("平均分數:", np.mean(num))  
print("最高分:", df["score"].max())
mat.bar(stu_counts.index, stu_counts.values)
mat.xlabel('score')
mat.ylabel('number')
mat.title('student score')
mat.show()
