from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn import datasets
iris = datasets.load_iris()
X_train, X_test, y_train, y_test = train_test_split(
    iris["data"], iris["target"], test_size=0.3)

knn = KNeighborsClassifier()
knn.fit(X_train, y_train)
