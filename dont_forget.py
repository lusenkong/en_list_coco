
import sys
import random

if __name__ =="__main__":
    vocalibary = sys.argv[1]
    last_row = int(sys.argv[2])
    select_words = int(sys.argv[3])
    flag = int(sys.argv[4])

    index_list = []
    index_hard_list = []
    file = open(vocalibary,mode='r')
    lines = file.readlines()
    file.close()

    if last_row >= len(lines):
        exit(0)

    i = 0
    table_of_words = {}
    while i < last_row+1:
        if '\t \t' in lines[i]:
            sp = lines[i].strip().split(' ')
            sp1 = []
            sp1.append(sp[0].strip())
            sp1.append(sp[1].strip())
            i+=1
            j = i
            label = ""
            while j<last_row+1:
                if '\t \t' not in lines[j]:
                    label+=lines[j]
                    j+=1
                else:
                    table_of_words[sp1[0]] = [sp1[1],label.strip()]
                    index_list.append(sp1[0])

                    if label.strip()!='':
                        index_hard_list.append(sp1[0])
                    break
        else:
            i+=1
    if flag ==0:
        list_of_random_items = random.sample(index_list, select_words)
    
        for index in list_of_random_items:
            print(index, table_of_words[index])
    elif flag ==1:
        list_of_random_items = random.sample(index_hard_list, select_words)
        for index in list_of_random_items:
            print(index, table_of_words[index])
    