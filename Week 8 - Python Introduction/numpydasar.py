import numpy as np

arr = np.array([1, 2, 3, 4],dtype=int)
print(arr)
medianData = np.median(arr)
print(medianData)
meanData = np.mean(arr)
summaryData = np.sum(arr)
print(meanData, summaryData)

arr21 = np.array([1, 2, 3, 4]) #satu dimensi arrray
arr22= np.array([1, 2, 3, 4]) #satu dimensi arrray
arr3 = np.array([[1,2,3],[4,5,6]])#dua dimensi arrray
arr4 = np.array([[1,2,3],[4,5,6]]) #dua dimensi arrray
checkDimension = arr4.ndim
checkShape = arr4.shape
checkDataType = arr4.dtype
print(checkDimension, checkShape, checkDataType)


resultMultiplication = arr3 * arr4
anotherResultMultiplication = arr21 * arr22
print(resultMultiplication)
print(anotherResultMultiplication)