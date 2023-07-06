# TODO
from cs50 import get_int

while True:
    n = get_int('Height: ')
    if 1 <= n <= 8:
        break

for i in range(1, n + 1):
    print('{tab}{hash}  {hash}'.format(tab=' '*(n-i), hash='#'*i))
