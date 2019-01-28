import cv2

def mkarr(i, j):
  return (i,j)
def save(arr, path):
  count = arr.shape[0]
  arr = arr * 127.5 + 127.5
  for i in range(count):
    cv2.imwrite(path  + str(i) + ".png", arr[i])