from sklearn import datasets
import pandas as pd
from sklearn.model_selection import train_test_split

iris = datasets.load_iris()

x = pd.DataFrame(iris["data"], columns=iris["feature_names"])
X_train, X_test, y_train, y_test = train_test_split(
    iris["data"], iris["target"], test_size=0.3)

print(x)