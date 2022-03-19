// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
  int low = 0, high = size - 1, count = 0, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (*(arr + mid) == value) {
      count++;
      break;
    } else {
      if (*(arr + mid) < value)
        low = mid + 1;
      else
        high = mid - 1;
    }
  }
  if (count != 0) {
    for (int i = mid + 1; *(arr + i) == value; i++)
      count++;
    for (int i = mid - 1; *(arr + i) == value; i--)
      count++;
  }
  return count;
}

int countSameElPairs(int elAmount) {
  if (elAmount == 1)
    return 0;
  return countSameElPairs(elAmount - 1) + elAmount - 1;
}

int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = i + 1; j < len; j++)
      if (*(arr + i) + *(arr + j) == value)
        count++;
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = len - 1; j > i; j--)
      if (*(arr + i) + *(arr + j) == value)
        count++;
  return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0, j = len - 1;
  for (int i = 0; i <= j; i++) {
    int secondAmount = cbinsearch(arr, len, *(arr + j));
    bool isNextSame = *(arr + i) == *(arr + i + 1);
    if (*(arr + i) + *(arr + j) == value) {
      if (*(arr + i) == *(arr + j)) {
        count += countSameElPairs(j - i + 1);
        break;
      }
      count += secondAmount;
    }
    if (!isNextSame && *(arr + i + 1) + *(arr + j) != value)
      j -= secondAmount;
  }
  return count;
}
