import math

p = int(input("ENter p:"))
q=int(input("Enter q:"))

n = p*q
phi = (p-1)*(q-1)

e = 2
while e<phi:
    if(math.gcd(e,phi)==1):
        break;
    else:
        e = e+1

d = 1

while (d*e)%phi != 1:
    d = d+1

m = int(input("Enter message"))

cipher = pow(m,e,n)

normal = pow(cipher,d,n)

print("Cipher:",cipher)

print("\nNormal:",normal)