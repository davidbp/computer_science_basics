
import sklearn
import pandas as pd
from sklearn import preprocessing
import sklearn.linear_model
from sklearn.linear_model import LogisticRegression

def label_to_int(x,mapping):
    return mapping[x]

if __name__ == "__main__":

    #folder_to_save = "results"
    data = pd.read_csv("./data/iris.csv")
    label_encoder    = preprocessing.OneHotEncoder()
    labels_colname   = data.columns[-1]
    Y                = data[labels_colname]
    label_dict       = {name:id for id, name in  enumerate(Y.unique())}
    Y                = Y.apply(label_to_int, args= (label_dict,))
    X                = data[data.columns[1:-1]]
    print("\n\t\tmodified after image")
    print("\nTraining model...")
    logreg = LogisticRegression(C=1e5, solver='lbfgs', multi_class='multinomial')
    logreg.fit(X, Y)
    y_hat = logreg.predict(X)
    result = pd.DataFrame({"predictions": y_hat})
    print("\nModel trained")
    result.to_csv("./result.csv", index=False)
    print("\nResults saved\n")

