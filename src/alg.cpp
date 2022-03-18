// Бинарный поиск количества элементов, равных value, в массиве
int cbinsearch(int *arr, int size, int value) {
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

// Подсчёт количества пар одинаковых элементов при количестве elAmount этих элементов в массиве
int countSameElPairs(int elAmount) {
  if (elAmount == 1)
    return 0;
  return countSameElPairs(elAmount - 1) + elAmount - 1;
}

// Подсчёт уникальных пар перебором
int countPairs1(int *arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = i + 1; j < len; j++)
      if (* (arr + i) + *(arr + j) == value)
        count++;
  return count;
}

// Подсчёт уникальных пар с отбрасыванием лишних значений
int countPairs2(int *arr, int len, int value)
{
  int count = 0, countLeft = 1, countRight = 1, i = 0, j = len - 1;
  while (i <= j) {
    bool isNextLeftSame = *(arr + i + 1) == *(arr + i),
      isPreviousRightSame = *(arr + j - 1) == *(arr + j);
    if (isNextLeftSame) {
      countLeft++;
      i++;
    }
    if (isPreviousRightSame) {
      countRight++;
      j--;
    }
    if (!isNextLeftSame && !isPreviousRightSame) {
      count += countLeft * countRight;
      i++;
      j--;
      countLeft = countRight = 1;
    }
  }
  return count;
}

// Подсчёт уникальных пар с помощью бинарного поиска
int countPairs3(int *arr, int len, int value)
{
  int count = 0;
  for (int i = 0; *(arr + i) <= value / 2; i += cbinsearch(arr, len, *(arr + i))) {
    if (*(arr + i) * 2 != value)
      count += cbinsearch(arr, len, *(arr + i)) * cbinsearch(arr, len, value - *(arr + i));
    else
      count += countSameElPairs(cbinsearch(arr, len, *(arr + i)));
  }
  return count;
}
