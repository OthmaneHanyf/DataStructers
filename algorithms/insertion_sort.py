def sort(list):
    for i in range(1, len(list)) :
        value = list[i]
        j = i
        while ( j > 0 and list[j-1] > value ) :
            list[j] = list[j-1]
            j -= 1
        list[j] = value

def main():
    list = [3, 2, 4, 1, 5]
    sort(list)
    print(list)

if __name__=="__main__":
    main()