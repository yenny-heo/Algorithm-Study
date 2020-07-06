import copy


def func(i, arr, opr):
    while i in opr:
        idx = opr.index(i)
        first = arr[idx]
        second = arr[idx + 1]
        del opr[idx]
        del arr[idx]
        del arr[idx]
        if i == '+':
            arr.insert(idx, int(first) + int(second))
        elif i == '-':
            arr.insert(idx, int(first) - int(second))
        elif i == '*':
            arr.insert(idx, int(first) * int(second))


def solution(exp):
    answer = 0
    operation = ['+', '-', '*']
    arr = []
    opr = []
    idx = 0
    # 연산자와 숫자 분리
    for i in range(0, len(exp)):
        if exp[i] == '+' or exp[i] == '-' or exp[i] == '*':
            arr.append(exp[idx:i])
            opr.append(exp[i])
            idx = i + 1
    arr.append(exp[idx:])
    # 경우의수
    for i in operation:
        arr1 = copy.copy(arr)
        opr1 = copy.copy(opr)
        func(i, arr1, opr1)
        for j in operation:
            if j == i: continue
            arr2 = copy.copy(arr1)
            opr2 = copy.copy(opr1)
            func(j, arr2, opr2)
            for k in operation:
                if k == i or k == j: continue
                arr3 = copy.copy(arr2)
                opr3 = copy.copy(opr2)
                func(k, arr3, opr3)
                if abs(arr3[0]) > answer:
                    answer = abs(arr3[0])

    return answer