import sys



def floydTortoiseHare(seq):
    assert len(seq) > 2, "Length of array must be > 2!"

    tort = farray(seq, seq[0])
    hare = farray(seq, tort)
    
    while tort != hare:
        tort = farray(seq, tort)
        hare = farray(seq, farray(seq, hare))

    mu = 0
    tort = seq[0]
    while tort != hare:
        tort = farray(seq, tort)
        hare = farray(seq, hare)
        mu += 1

    l = 1
    hare = farray(seq, hare)
    while tort != hare:
        hare = farray(seq, hare)
        l += 1

    return seq[mu:mu + l]

def farray(arr, x):
    return arr[(arr.index(x) + 1) % len(arr)]


if __name__ == '__main__':
    
    # open data file
    with open(sys.argv[1]) as f:
        for line in f:
            seq = [int(x) for x in line.split()]
            print ''.join(str(x) + ' ' for x in floydTortoiseHare(seq))
