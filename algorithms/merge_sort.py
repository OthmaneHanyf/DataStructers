
def sort(list):
    
    m = len(list) // 2
    if m >= 1 :
        L = list[:m]
        R = list[m:]

        sort(L)
        sort(R)
        
        i = 0
        j = 0
        k = 0
        while ( i < len(L) and j < len(R) ):
            if(L[i] < R[j]):
                list[k] = L[i]
                i += 1
            else :
                list[k] = R[j]
                j += 1
            k += 1
        if ( i < len(L) ):
            list[k:] = L[i:]
        if ( j < len(R) ):
            list[k:] = R[j:]
        
def main():
    list = [2, 1, 7, 3, 6, 5, 8, 4, 0]
    sort(list)
    print("Sorted list ==> ", list)

if __name__=="__main__":
    main()