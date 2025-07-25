import pandas as pd # 引入 Pandas庫,用於處理表相型數據 
from sklearn.preprocessing import StandardScaler, LabelEncoder #引入 Scikit-Learn 的標準化與類別編碼工具 
#建立一個假設的資料集,模擬有顧客的年齡、薪資和性別數據 
data  = pd.DataFrame({ 
  'Age': [20, 25, 30, 35], #年齡資料,單位為歲
  'Salary': [30000, 50000, 70000, 90000], #薪資資料,單位為新台幣 
  'Gender': ['Male', 'Female', 'Male', 'Female'] # 性別資料,Male 為男性,Female 為女性
})       


 #使用 StandardScaler 來進行數據標準化(讓數據均值為0,標準差為1) 
scaler  = StandardScaler()#建立標準化工具的實例 
data[['Age', 'Salary']] = scaler.fit_transform(data[['Age', 'Salary']]) #對Age 和 Salary 欄位進行標準化處理,結果會替代原本的數值 

#使用 LabelEncoder 來將類別型數據轉換為數字 
encoder  = LabelEncoder() #建立類別編碼工具的實例 
data['Gender']  = encoder.fit_transform(data['Gender']) #將Gender 欄位中的文字("Male', 'Female') 轉換為數字,Male -> 1, Female -> 0 #印出處理後的資料 
print(data) #顯示處理後的DataFrame,Age 和 Salary 已經被標準化,Gender 被轉換為數字