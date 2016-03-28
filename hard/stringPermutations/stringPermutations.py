import sys

# recursively builds the total n! possible permutations
# of a word with n characters
# DOES NOT ALLOW FOR REPEATED CHARACTERS
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

# joins elements in the 2nd dimension perms array
# and return a 1D array of sorted permutations
def order(perms):
    perms = [''.join(perm) for perm in perms]
    return sorted(perms)

# OTHER METHOD (NOT MINE):

def permutations(prefix, word):
    n = len(word)
    # base case
    if n == 1: 
        print prefix + word
        return
    # recursion step
    for i in range(n):
        permutations(prefix + word[i], word[:i] + word[i+1:])


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
            #permutations("", "mom")
