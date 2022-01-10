import numpy as np
import pandas as pd
impor seaborn as sns
import matplotlib.pyplot as plt
print("yup")

df = pd.read_csv('train_cancer.csv', header=None)

#sns.set_theme()

#ax = sns.swarmplot(x="hi", y="lol", data=df)

#plt.show()
ax = sns.boxplot(data=pd.melt(df))
plt.show()
print(df)
