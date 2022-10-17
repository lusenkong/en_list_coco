
import sys
import random

if __name__ =="__main__":
    
    vocalibary = sys.argv[1]

    select_words = int(sys.argv[2])
    flag = int(sys.argv[3])

    index_list = []
    index_hard_list = []
    file = open(vocalibary,encoding='utf8',mode='r')
    lines = file.readlines()
    file.close()
    print("start")

    max = 10001

    i = 0
    table_of_words = {}
    while i < len(lines):
        if '\t \t' in lines[i]:
            sp = lines[i].strip().split(' ')
            sp1 = []
            sp1.append(sp[0].strip())
            sp1.append(sp[1].strip())
            index  = sp[0].strip()
            word = sp[1].strip()

            if index in table_of_words.keys():
                index = max
                max+=1

            i+=1
            j = i
            label = ""
            while j<len(lines):
                if '\t \t' not in lines[j]:
                    label+=lines[j]
                    j+=1
                else:
                    table_of_words[index] = [word,label.strip()]
                    index_list.append(index)

                    if label.strip()!='':
                        index_hard_list.append(index)
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
            print(index, '\t'+table_of_words[index][0]+'\t',table_of_words[index][1].replace('\n',';'))

    elif flag ==2:
        list_of_random_items = random.sample(index_hard_list, select_words)
        for index in list_of_random_items:
            print(index, table_of_words[index][1].replace('\n',';'))
        print('\n\n\n')
        for index in list_of_random_items:
            print(index, '\t'+table_of_words[index][0]+'\t',)