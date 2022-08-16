import sys

if __name__ =="__main__":

    file1 = sys.argv[1]
    file2 = sys.argv[2]

    file = open(file1,mode='r')
    lines = file.readlines()
    file.close()

    file_out = open(file2,mode='w')


    for line in lines:
        line = line.strip()
        line = '\t'+line+'\n'
        file_out.write(line)

    file_out.close()