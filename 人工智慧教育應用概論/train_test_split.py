from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier

# 將 Iris 資料集切割為訓練集和測試集
iris = datasets.load_iris()
X_train, X_test, y_train, y_test = train_test_split(iris["data"], iris["target"], test_size=0.3)

# print("X_train = " + str(X_train))
# print("X_test = " + str(X_test))
knn = KNeighborsClassifier()
knn.fit(X_train, y_train)
print("預測",knn.predict(X_test))
print("實際",y_test)
print("預測模型的準確度:", round(knn.score(X_test, y_test) * 100, 2), "%")
