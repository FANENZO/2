import tensorflow as tf  # 深度學習工具

from tensorflow.keras import Sequential  # 幫助我們建立神經網路模型

from tensorflow.keras.layers import Flatten, Dense  # 常用的層

from tensorflow.keras.datasets import mnist  # 手寫數字資料集

import matplotlib.pyplot as plt  # 幫助我們畫圖檢查結果


# 處理資料

(x_train, y_train), (x_test, y_test) = mnist.load_data()  # 載入訓練和測試資料

x_train, x_test = x_train / 255.0, x_test / 255.0  # 把像素值縮放到 0-1 範圍

#說明：

# x_train：訓練圖片（用來教電腦學習）。
# y_train：訓練圖片的正確答案。
# x_test：測試圖片（用來檢查電腦的學習效果）。
# y_test：測試圖片的正確答案。
# 設計模型

# 建立神經網路模型
model = Sequential([

    Flatten(input_shape=(28, 28)),  # 把 28x28 的圖片展平成一條數列

    Dense(128, activation='relu'),  # 使用 ReLU 函數的隱藏層

    Dense(10, activation='softmax')  # 使用 Softmax 函數的輸出層

])


# 說明：

# 第一層 Flatten：把圖片展平成一維數列。
# 第二層 Dense + ReLU：過濾不重要的訊號，專注有用的訊息。
# 第三層 Dense + Softmax：輸出每個數字的機率。
# 訓練模型

# 設定訓練方法
model.compile(

    optimizer='adam',  # 優化學習速度的方法

    loss='sparse_categorical_crossentropy',  # 訓練過程中計算猜錯的程度

    metrics=['accuracy']  # 顯示模型的準確率

)


# 訓練模型

history = model.fit(

    x_train, y_train,  # 訓練資料和對應答案

    epochs=5,  # 訓練 5 次

    validation_data=(x_test, y_test)  # 用測試資料檢查效果

)

# 檢查結果

# 畫圖檢查準確率


plt.plot(history.history['accuracy'], label='訓練準確率')  # 訓練準確率

plt.plot(history.history['val_accuracy'], label='測試準確率')  # 測試準確率

plt.xlabel('訓練次數')  # x 軸標籤

plt.ylabel('準確率')  # y 軸標籤

plt.legend()  # 圖例

plt.title('訓練與測試準確率比較')  # 圖表標題

plt.show()  # 顯示圖表
