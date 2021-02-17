
def sort(list):
    for i in range(len(list)):
        min_value = list[i]
        min_index = i
        for j in range(i, len(list)):
            if list[j] < min_value:
                min_value = list[j]
                min_index = j
        if i != min_index :
            tmp = list[min_index]
            list[min_index] = list[i]
            list[i] = tmp

def main():
    list = [4, 2, 1, 6, 5, 3]
    sort(list)
    print(list)

if __name__ == "__main__" :
    main()