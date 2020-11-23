from typing import List


def bubble_sort(v: List[int]):
    n: int = len(v)

    for i in range(n - 1, 0, -1):
        swapped: bool = False
        for j in range(0, i):
            if v[j] > v[j + 1]:
                v[j], v[j + 1] = v[j + 1], v[j]
                swapped = True

        if not swapped:
            break
    return v
