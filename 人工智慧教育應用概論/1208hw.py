# import matplotlib.pyplot as plt  # 匯入 matplotlib 以進行數據可視化
# import numpy as np  # 匯入 numpy 以進行數學操作
# from tensorflow.keras.layers import Dense, Flatten  # 匯入 Dense 和 Flatten 層
# from tensorflow.keras.models import Sequential  # 匯入 Sequential 模型類型
# from tensorflow.keras.datasets import mnist  # 匯入 MNIST 資料集模組
# import tensorflow as tf  # 匯入 TensorFlow 套件
# import random
# from tensorflow import keras  # 從 TensorFlow 中匯入 Keras 模組
# from sklearn import datasets
# from sklearn.model_selection import train_test_split
# from sklearn.neighbors import KNeighborsClassifier
# from sklearn.preprocessing import StandardScaler


# print("TensorFlow 和 Keras 匯入成功！")  # 確認成功匯入套件

# iris = datasets.load_iris()
# X  = iris.data
# y= iris.target

# scaler = StandardScaler()
# X = scaler.fit_transform(X)

# X_train, X_test, y_train, y_test = train_test_split(
#     iris["data"], iris["target"], test_size=0.3,random_state=42)


# model = Sequential([  # 使用 Sequential 建立模型

#     Flatten(input_shape=(28, 28)),  # 將 28x28 的圖片展平成一維向量

#     Dense(128, activation='relu'),  # 第一層，全連接層，有 128 個神經元，使用 ReLU 激活函數

#     Dense(10, activation='softmax')  # 第二層，輸出層，有 10 個神經元，使用 Softmax 激活函數

# ])


# # 編譯模型

# model.compile(optimizer='adam', loss='sparse_categorical_crossentropy',
#               metrics=['accuracy'])  # 使用 Adam 優化器和損失函數進行編譯

# # 訓練模型

# model.fit(X_train, y_train, epochs=5, verbose=1)  # 使用訓練資料訓練模型 5 個週期

# # 隨機選擇一筆測試資料進行預測
# random_idx = random.randint(0, X_test.shape[0] - 1)  # 隨機選擇一個索引
# sample = X_test[random_idx]  # 測試資料中的隨機樣本
# sample_true_label = y_test[random_idx]  # 實際標籤
# sample_reshaped = sample.reshape(1, -1)  # 調整形狀以符合模型輸入要求

# # 預測種類
# prediction = model.predict(sample_reshaped)
# predicted_label = np.argmax(prediction)  # 找到最大可能性的索引

# print(f"模型預測的種類: {iris.target_names[predicted_label]} ({predicted_label})")
# print(f"實際種類: {iris.target_names[sample_true_label]} ({sample_true_label})")
import numpy as np
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
import random

# 載入 Iris 資料集
iris = datasets.load_iris()
X = iris.data  # 特徵數據
y = iris.target  # 目標標籤

# 資料標準化（有助於提升模型性能）
scaler = StandardScaler()
X = scaler.fit_transform(X)

# 分割資料集為訓練集與測試集
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42)

# 建立神經網路模型
model = Sequential([
    Dense(16, activation='relu', input_shape=(X.shape[1],)),  # 第一層，有 16 個神經元
    Dense(8, activation='relu'),  # 第二層，有 8 個神經元
    Dense(3, activation='softmax')  # 輸出層，3 個神經元（對應 3 種花）
])

# 編譯模型
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy', metrics=['accuracy'])

# 訓練模型
model.fit(X_train, y_train, epochs=250)  # 訓練 50 個週期

# 隨機選擇一筆測試資料進行預測
random_idx = random.randint(0, X_test.shape[0] - 1)  # 隨機選擇一個索引
sample = X_test[random_idx]  # 測試資料中的隨機樣本
sample_true_label = y_test[random_idx]  # 實際標籤
sample_reshaped = sample.reshape(1, -1)  # 調整形狀以符合模型輸入要求

# 預測種類
prediction = model.predict(sample_reshaped)
predicted_label = np.argmax(prediction)  # 找到最大可能性的索引

# 輸出結果
print(f"模型預測的種類: {iris.target_names[predicted_label]} ({predicted_label})")
print(f"實際種類: {iris.target_names[sample_true_label]} ({sample_true_label})")
