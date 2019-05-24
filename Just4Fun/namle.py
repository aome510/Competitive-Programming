def quicksort(n):
    if len(n)>1:
        i=0 # leftbound
        j=len(n)-2 # rightbound
        mid=(i+j+1)//2
        n[mid],n[j+1]=n[j+1],n[mid]
        pivot=n[len(n)-1]
        f=0
        while i<len(n) and f==0:
            if n[i]>=pivot :
                while 1:
                    
                    if j<i:
                        n[len(n)-1],n[i]=n[i],n[len(n)-1]
                        pivot=n[i]
                        f=1
                        break
                    elif n[j]<pivot:
                        n[j],n[i]=n[i],n[j]
                        break
                    else:
                        j -= 1
            else:
                i += 1
        left=n[:i];
        right=n[i+1:]
       
                        
        quicksort(left)
        quicksort(right)
        print(left, n[i], right)
        n[:]=left+[n[i]]+right 
    # print(n)
quicksort([9,6,7,12,1,2,5,6])