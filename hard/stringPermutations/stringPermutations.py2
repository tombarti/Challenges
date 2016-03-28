import sys

def permute(stubs, chars):
    charset = []
    newStubs = []
    for stub in stubs:
        charset = [c for c in chars if c not in stub]
        for c in charset:
            newStubs.append(stub + [c])
    if len(newStubs[0]) == len(chars):
        return newStubs
    return permute(newStubs, chars)

def order(perms):
    perms = [''.join(perm) for perm in perms]
    return sorted(perms)

if __name__ == '__main__':

    with open(sys.argv[1], 'r') as f:
        for line in f:
            # removes the trailing end of line character
            line = line[:len(line) -1]
            chars = list(line)
            stubs = []
            for e in chars:
                stubs.append([e])
            print ','.join(order(permute(stubs, chars)))
