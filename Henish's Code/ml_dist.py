from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.ensemble import RandomForestRegressor
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Importing Dataset
dataset = pd.read_csv("Henish\'s Code/myfile.csv")

# Independent Variable
X = dataset.iloc[:, 0].values
X = np.vstack(X)
# Dependent Variable
Y = dataset.iloc[:, 1].values

lin_reg = LinearRegression()
lin_reg.fit(X, Y)


# Training the Polynomial Regression Model on whole dataset
poly_reg = PolynomialFeatures(degree=2)
X_poly = poly_reg.fit_transform(X)
lin_reg_2 = LinearRegression()
lin_reg_2.fit(X_poly, Y)

# Visualising Linear Regression results
plt.scatter(X, Y, color="red")
plt.plot(X, lin_reg.predict(X), color="blue")
plt.title("Truth Or Bluff(Linear Modle)")
plt.xlabel("Position Level")
plt.ylabel("Salary")
plt.show()
# Visualising Polynomial Regression results
plt.scatter(X, Y, color="red")
plt.plot(X, lin_reg_2.predict(X_poly), color="blue")
plt.title("Truth Or Bluff(Polynomial Modle)")
plt.xlabel("Position Level")
plt.ylabel("Salary")
plt.show()

# Visualising Polynomial Regression with Higher degree and resolution
X_grid = np.arange(min(X), max(X), 10)
X_grid = X_grid.reshape((len(X_grid), 1))
plt.scatter(X, Y, color="red")
plt.plot(X_grid, lin_reg_2.predict(
    poly_reg.fit_transform(X_grid)), color="blue")
plt.title("Truth Or Bluff(Polynomial Modle)")
plt.xlabel("Position Level")
plt.ylabel("Salary")
plt.show()

# Predicting new result with Linear Regression
print(lin_reg.predict([[934]]))

# Predicting new Result with Polynomial Regression
print(lin_reg_2.predict(poly_reg.fit_transform([[934]])))
