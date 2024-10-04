import random
import subprocess
import hashlib

def equal_sha(a, b):
    def sha512(x):
        halg = hashlib.sha512() # should work
        with open(x, 'rb') as f:
            while c := f.read(65536):
                halg.update(c)
        return halg.hexdigest()
    return sha512(a) == sha512(b)

def random_string(n: int) -> str:
    return ''.join(random.choices('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789', k=random.randint(1, n)))

if(__name__ == "__main__"):
    rnd_strings = []
    for n in range(1, 50000):
        rnd_strings.append(random_string(1000))
    with open('/tmp/referencehash', 'a+') as f:
        for x in rnd_strings:
            subprocess.run(["rhash --whirlpool -m\"" + x + "\""], shell=True, text=True, stdout=f)
    with open('/tmp/whirlpoolhash', 'a+') as d:
        for x in rnd_strings:
            subprocess.run(["echo -n \"" + x + "\" | ./bin/build_verify"], shell=True, text=True, stdout=d)
    if equal_sha('/tmp/referencehash', '/tmp/whirlpoolhash') == True:
        print("Whirlpool verified, no differences")
