import pandas as pd
import matplotlib.pyplot as mat

data = {
    "score":[100,50,55,52,None],
    "num":[2,65,8,None,6]
}
df = pd.DataFrame(data)
data_clean =  df.dropna()


mat.bar(data_clean["score"], data_clean["num"])
mat.xlabel('score')
mat.ylabel('number')
mat.title('student score')
mat.show()

