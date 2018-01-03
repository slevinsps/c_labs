import ctypes

lib = ctypes.CDLL('libarr.dll')

# int fibonachi(int *array, int n)
_fibonachi = lib.fibonachi
_fibonachi.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_fibonachi.restype = ctypes.c_int

def fibonachi(n):
    if (n < 0):
        return -1, None
    src = (ctypes.c_int * n)()
    err = _fibonachi(src, n)
    return err, list(src)

# int move_elements(int *array1, int *array2, int n);
_move_elements = lib.move_elements
_move_elements.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_move_elements.restype = ctypes.c_int

def move_elements(nums):
    count_elem1 = len(nums)
    arr1 = (ctypes.c_int * count_elem1)(*nums)
    arr2 = (ctypes.c_int * count_elem1)()
    count_elem2 = _move_elements(arr1, arr2, count_elem1)
    return count_elem2, list(arr2)


def test_fibonachi():
    # Тест 1:  5 чисел фибоначчи
    expected = [0,1,1,2,3]
    err, actual = fibonachi(5)
    if (err == 0 and expected == actual):
        print("Test 1 in test_fibonachi PASSED")
    else:
        print("Test 1 in test_fibonachi FAILED")
        print(expected)
        print(actual)
        
    # Тест 2:  1 число фибоначчи
    expected = [0]
    err, actual = fibonachi(1)
    if (err == 0 and expected == actual):
        print("Test 2 in test_fibonachi PASSED")
    else:
        print("Test 2 in test_fibonachi FAILED")
        print(expected)
        print(actual)
        
    # Тест 3:  2 числа фибоначчи
    expected = [0, 1]
    err, actual = fibonachi(2)
    if (err == 0 and expected == actual):
        print("Test 3 in test_fibonachi PASSED")
    else:
        print("Test 3 in test_fibonachi FAILED")
        print(expected)
        print(actual)
        
    # Тест 4:  на вход пришел 0
    expected = []
    err, actual = fibonachi(0)
    if (err == -1 and expected == actual):
        print("Test 4 in test_fibonachi PASSED")
    else:
        print("Test 4 in test_fibonachi FAILED")
        print(expected)
        print(err, actual)

    # Тест 5:  на вход пришло отрицательное значение
    expected = []
    err, actual = fibonachi(-5)
    if (err == -1):
        print("Test 5 in test_fibonachi PASSED")
    else:
        print("Test 5 in test_fibonachi FAILED")
        print(expected)
        print(err, actual)

def compare_array(arr1, arr2, n):
    for i in range(n):
        if (arr1[i] != arr2[i]):
            return 0
    return 1
            
def test_move_elements():
    # Тест 1:  нет одинаковых элементов
    nums = [1,2,3,4,5]
    expected = [1,2,3,4,5]
    count_elem, actual = move_elements(nums)
    if (count_elem == 5 and compare_array(expected, actual, count_elem)):
        print("Test 1 in test_move_elements PASSED")
    else:
        print("Test 1 in test_move_elements FAILED")
        print(expected)
        print(actual)
        
    # Тест 2:  все элементы одинаковы
    nums = [1,1,1,1,1,1,1,1]
    expected = [1]
    count_elem, actual = move_elements(nums)
    if (count_elem == 1 and compare_array(expected, actual, count_elem)):
        print("Test 2 in test_move_elements PASSED")
    else:
        print("Test 2 in test_move_elements FAILED")
        print(expected)
        print(actual)
        
    # Тест 3:  не все элементы одинаковы
    nums = [1, 2, 5, 2, 3, 1, 3, 9, 1]
    expected = [1, 2, 5, 3, 9]
    count_elem, actual = move_elements(nums)
    if (count_elem == 5 and compare_array(expected, actual, count_elem)):
        print("Test 3 in test_move_elements PASSED")
    else:
        print("Test 3 in test_move_elements FAILED")
        print(expected)
        print(actual)

    # Тест 4: пустой массив
    nums = []
    count_elem, actual = move_elements(nums)
    if (count_elem == -1):
        print("Test 4 in test_move_elements PASSED")
    else:
        print("Test 4 in test_move_elements FAILED")
        print(expected)
        print(count_elem, actual)
        
def main():
    test_fibonachi()
    test_move_elements()

main()
# print(fibonachi(10))
# print(move_elements((1,2,1,2,10,5,2,5)))
