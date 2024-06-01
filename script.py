import hashlib

# Milk Sad 
entropy = [140,151,183,216,154,219,139,216,108,159,165,98,112,76,228,14,246,69,98,122,202,207,135,122,145,100,236,214,18,86,22,165]
#entropy =  [126,78,123,168,226,122,24,232,250,91,134,212,234,167,68,183,83,86,217,244,198,100,233,129,18,124,141,54,63,170,229,96]
h = hashlib.sha256(bytearray(entropy)).hexdigest()

b = bin(int(bytearray(entropy).hex(), 16))[2:].zfill(len(entropy)*8) + bin(int(h,16))[2:].zfill(256)[: len(entropy)* 8//32]

with open("english.txt", "r") as f:
         wordlist = [w.strip() for w in f.readlines()]

seed = []
for i in range(len(b)//11):
    indx = int(b[11*i:11*(i+1)],2)
    seed.append(wordlist[indx])
print(seed)
