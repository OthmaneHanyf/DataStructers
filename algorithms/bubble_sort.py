
def sort(list):
    tmp = 0
    for i in range(len(list)):
        for j in range(len(list) - 1, i, -1):
            if list[j-1] > list[j]:
                tmp = list[j]
                list[j] = list[j-1]
                list[j-1] = tmp

def main():
    list = [ 4, 3, 1, 5, 2, 6 ]
    sort(list)
    print(list)

if __name__ == "__main__":
    main()