import pandas as pd
from sklearn import datasets

iris = datasets.load_iris()
x = pd.DataFrame(iris["data"], columns=iris["feature_names"])

print(x)

