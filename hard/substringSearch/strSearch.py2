import sys
import re
def searchStr(txt, sub):
    sub = re.sub(r'(?<!\\)(\*){1}', ".*", sub)
    if not re.search(sub, txt):
        return "false"
    return "true"

with open(sys.argv[1], 'r') as f:
    for line in f:
        [txt, sub] = line.strip().split(',')
        print searchStr(txt, sub)
    
